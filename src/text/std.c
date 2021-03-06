/**
 * @section License
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014-2016, Erik Moqvist
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * This file is part of the Simba project.
 */

#include "simba.h"
#include <stdarg.h>
#include <limits.h>

/* +7 for floating point decimal point and fraction. */
#define VALUE_BUF_MAX (3 * sizeof(long) + 7)

struct buffered_output_t {
    void *chan_p;
    int pos;
    char buffer[CONFIG_STD_OUTPUT_BUFFER_MAX];
    size_t size;
};

struct snprintf_output_t {
    char *dst_p;
    size_t size;
    size_t size_max;
};

/**
 * @return true(1) if the character is part of the string, otherwise
 *         false(0).
 */
static int char_in_string(char c, const char *str_p)
{
    while (*str_p != '\0') {
        if (c == *str_p) {
            return (1);
        }

        str_p++;
    }

    return (0);
}

/**
 * Put characters to buffer.
 */
static void sprintf_putc(char c, void *arg_p)
{
    char **dst_pp = arg_p;

    *(*dst_pp)++ = c;
}

/**
 * Put characters to buffer.
 */
static void snprintf_putc(char c, void *arg_p)
{
    struct snprintf_output_t *output_p;

    output_p = arg_p;

    if (output_p->size < output_p->size_max) {
        output_p->dst_p[output_p->size] = c;
    }

    output_p->size++;
}

/**
 * Put characters to standard output.
 */
static void fprintf_putc(char c, void *arg_p)
{
    struct buffered_output_t *output_p = arg_p;

    output_p->buffer[output_p->pos++] = c;
    output_p->size++;

    if (output_p->pos == membersof(output_p->buffer)) {
        chan_write(output_p->chan_p, output_p->buffer, output_p->pos);
        output_p->pos = 0;
    }
}

/**
 * Flush output buffer to channel.
 */
static void output_flush(struct buffered_output_t *output_p)
{
    if (output_p->pos > 0) {
        chan_write(output_p->chan_p, output_p->buffer, output_p->pos);
        output_p->pos = 0;
    }
}

static void formats(void (*std_putc)(char c, void *arg),
                    void *arg,
                    char *str,
                    char flags,
                    int width,
                    char negative_sign)
{
    char *s = str;

    while (*s++ != '\0') {
        width--;
    }

    /* Right justification. */
    if (flags != '-') {
        if ((negative_sign == 1) && (flags == '0')) {
            std_putc(*str++, arg);
        }

        while (width > 0) {
            std_putc(flags, arg);
            width--;
        }
    }

    /* Number */
    while (*str != '\0') {
        std_putc(*str++, arg);
    }

    /* Left justification. */
    while (width > 0) {
        std_putc(' ', arg);
        width--;
    }
}

static char *formati(char c,
                     char *str_p,
                     char radix,
                     va_list *ap_p,
                     char length,
                     char *negative_sign_p)
{
    unsigned long value;
    char digit;

    /* Get argument. */
    if (length == 0) {
        value = (unsigned long)va_arg(*ap_p, int);
    } else {
        value = (unsigned long)va_arg(*ap_p, long);
    }

    if ((c == 'i') || (c == 'd')) {
        if (value & (1UL << (sizeof(value) * CHAR_BIT - 1))) {
            value *= -1;
            *negative_sign_p = 1;
        }
    }

    if (length == 0) {
        value &= UINT_MAX;
    }

    /* Format number into buffer. */
    do {
        digit = (char)(value % radix);
        value /= radix;
        if (digit > 9) {
            digit += 39;
        }
        *--str_p = ('0' + digit);
    } while (value > 0);

    if (*negative_sign_p == 1) {
        *--str_p = '-';
    }

    return (str_p);
}

static char *formatf(char c,
                     char *str_p,
                     va_list *ap_p,
                     char length,
                     char *negative_sign_p)
{
    double value;
    unsigned long whole_number;
    unsigned long fraction_number;
    int i;

    /* Get argument. */
    value = va_arg(*ap_p, double);

    /* Convert a negative value a to positive. */
#if defined(ARCH_ESP)
    /* This will not work in all cases when the number is close to
     * zero. */
    if ((int)value < 0) {
        value *= -1.0;
        *negative_sign_p = 1;
    }
#else
    if (value < 0.0) {
        value *= -1.0;
        *negative_sign_p = 1;
    }
#endif

    /* Values bigger than 'unsigned long max' are not supported. */
    whole_number = (unsigned long)value;
    /* Always print 6 decimal places. */
    fraction_number = (unsigned long)((value - whole_number) * 1000000.0);

    /* Write fraction number to output buffer. */
    for (i = 0; i < 6; i++) {
        *--str_p = '0' + (fraction_number % 10);
        fraction_number /= 10;
    }

    /* Write the decimal dot. */
    *--str_p = '.';

    /* Write whole number to output buffer. */
    while (whole_number != 0) {
        *--str_p = '0' + (whole_number % 10);
        whole_number /= 10;
    }

    /* Add negative sign if the number is negative. */
    if (*negative_sign_p == 1) {
        *--str_p = '-';
    }

    return (str_p);
}

static void vcprintf(void (*std_putc)(char c, void *arg_p),
                     void *arg_p,
                     FAR const char *fmt_p,
                     va_list *ap_p)
{
    char c, flags, length, negative_sign, buf[VALUE_BUF_MAX], *s_p;
    int width;

    buf[sizeof(buf) - 1] = '\0';

    while ((c = *fmt_p++) != '\0') {
        if (c != '%') {
            std_putc(c, arg_p);
            continue;
        }

        /* Prototype: %[flags][width][length]specifier  */

        /* Parse the flags. */
        flags = ' ';
        c = *fmt_p++;

        if ((c == '0') || (c == '-')) {
            flags = c;
            c = *fmt_p++;
        }

        /* Parse the width. */
        width = 0;

        while ((c >= '0') && (c <= '9')) {
            width *= 10;
            width += (c - '0');
            c = *fmt_p++;
        }

        /* Parse the length. */
        length = 0;

        if (c == 'l') {
            length = 1;
            c = *fmt_p++;
        }

        if (c == '\0') {
            break;
        }

        /* Parse the specifier. */
        negative_sign = 0;
        switch (c) {
        case 's':
            s_p = va_arg(*ap_p, char*);
            break;
        case 'c':
            buf[sizeof(buf) - 2] = (char)va_arg(*ap_p, int);
            s_p = &buf[sizeof(buf) - 2];
            break;
        case 'i':
        case 'd':
        case 'u':
            s_p = formati(c, &buf[sizeof(buf) - 1], 10, ap_p, length, &negative_sign);
            break;
        case 'x':
            s_p = formati(c, &buf[sizeof(buf) - 1], 16, ap_p, length, &negative_sign);
            break;
        case 'f':
            s_p = formatf(c, &buf[sizeof(buf) - 1], ap_p, length, &negative_sign);
            break;
        default:
            std_putc(c, arg_p);
            continue;
        }

        formats(std_putc, arg_p, s_p, flags, width, negative_sign);
    }
}

int std_module_init(void)
{
    return (0);
}

ssize_t std_sprintf(char *dst_p, FAR const char *fmt_p, ...)
{
    va_list ap;
    ssize_t res;

    va_start(ap, fmt_p);
    res = std_vsprintf(dst_p, fmt_p, &ap);
    va_end(ap);

    return (res);
}

ssize_t std_snprintf(char *dst_p,
                     size_t size,
                     FAR const char *fmt_p,
                     ...)
{
    va_list ap;
    ssize_t res;

    va_start(ap, fmt_p);
    res = std_vsnprintf(dst_p, size, fmt_p, &ap);
    va_end(ap);

    return (res);
}

ssize_t std_vsprintf(char *dst_p, FAR const char *fmt_p, va_list *ap_p)
{
    ASSERTN(dst_p != NULL, -EINVAL);
    ASSERTN(fmt_p != NULL, -EINVAL);

    char *d_p = dst_p;

    vcprintf(sprintf_putc, &d_p, fmt_p, ap_p);
    sprintf_putc('\0', &d_p);

    return (d_p - dst_p - 1);
}

ssize_t std_vsnprintf(char *dst_p,
                      size_t size,
                      FAR const char *fmt_p,
                      va_list *ap_p)
{
    ASSERTN(dst_p != NULL, -EINVAL);
    ASSERTN(size > 0, -EINVAL);
    ASSERTN(fmt_p != NULL, -EINVAL);

    struct snprintf_output_t output;

    output.dst_p = dst_p;
    output.size = 0;
    output.size_max = size;

    vcprintf(snprintf_putc, &output, fmt_p, ap_p);
    snprintf_putc('\0', &output);

    return (output.size - 1);
}

ssize_t std_printf(far_string_t fmt_p, ...)
{
    ASSERTN(fmt_p != NULL, -EINVAL);

    va_list ap;
    struct buffered_output_t output;

    output.pos = 0;
    output.size = 0;
    output.chan_p = sys_get_stdout();

    if (output.chan_p != NULL) {
        va_start(ap, fmt_p);
        vcprintf(fprintf_putc, &output, fmt_p, &ap);
        va_end(ap);
        output_flush(&output);
    }

    return (output.size);
}

ssize_t std_vprintf(FAR const char *fmt_p, va_list *ap_p)
{
    ASSERTN(fmt_p != NULL, -EINVAL);
    ASSERTN(ap_p != NULL, -EINVAL);

    struct buffered_output_t output;

    output.pos = 0;
    output.size = 0;
    output.chan_p = sys_get_stdout();

    if (output.chan_p != NULL) {
        vcprintf(fprintf_putc, &output, fmt_p, ap_p);
        output_flush(&output);
    }

    return (output.size);
}

ssize_t std_fprintf(void *chan_p, FAR const char *fmt_p, ...)
{
    ASSERTN(chan_p != NULL, -EINVAL);
    ASSERTN(fmt_p != NULL, -EINVAL);

    va_list ap;
    struct buffered_output_t output;

    output.pos = 0;
    output.size = 0;
    output.chan_p = chan_p;

    va_start(ap, fmt_p);
    vcprintf(fprintf_putc, &output, fmt_p, &ap);
    va_end(ap);
    output_flush(&output);

    return (output.size);
}

ssize_t std_vfprintf(void *chan_p, FAR const char *fmt_p, va_list *ap_p)
{
    ASSERTN(chan_p != NULL, -EINVAL);
    ASSERTN(fmt_p != NULL, -EINVAL);
    ASSERTN(ap_p != NULL, -EINVAL);

    struct buffered_output_t output;

    output.pos = 0;
    output.size = 0;
    output.chan_p = chan_p;

    vcprintf(fprintf_putc, &output, fmt_p, ap_p);
    output_flush(&output);

    return (output.size);
}

const char *std_strtol(const char *str_p, long *value_p)
{
    ASSERTN(str_p != NULL, -EINVAL);
    ASSERTN(value_p != NULL, -EINVAL);

    unsigned char base = 10;
    unsigned char c;
    long sign = 1;

    c = *str_p++;

    /* Find sign. */
    if (c == '-') {
        c = *str_p++;
        sign = -1;
    }

    /* The number must start with a digit. */
    if (isdigit(c) == 0) {
        return (NULL);
    }

    /* Find base based on prefix. */
    if (c == '0') {
        c = *str_p++;

        if (c == 'x') {
            base = 16;
            c = *str_p++;
        } else if (c == 'b') {
            base = 2;
            c = *str_p++;
        } else {
            base = 8;
        }
    }

    /* Get number. */
    *value_p = 0;

    while (((base == 16) && isxdigit(c))
           || ((base == 10) && isdigit(c))
           || ((base == 8) && (c >= '0') && (c < '8'))
           || ((base == 2) && (c >= '0') && (c < '2'))) {
        *value_p *= base;

        /* Special handling of base 16. */
        if (base == 16) {
            if (c >= 'a') {
                c -= ('a' - '0' - 10);
            } else if (c >= 'A') {
                c -= ('A' - '0' - 10);
            }
        }

        /* Bad value in string. */
        c -= '0';

        if (c >= base) {
            return (NULL);
        }

        *value_p += c;
        c = *str_p++;
    }

    *value_p *= sign;

    return (str_p - 1);
}

int std_strcpy(char *dst_p, FAR const char *fsrc_p)
{
    ASSERTN(dst_p != NULL, -EINVAL);
    ASSERTN(fsrc_p != NULL, -EINVAL);

    size_t length = 0;

    while (*fsrc_p != '\0') {
        *dst_p++ = *fsrc_p++;
        length++;
    }

    *dst_p = '\0';

    return (length);
}

int std_strcmp(const char *str_p, FAR const char *fstr_p)
{
    ASSERTN(str_p != NULL, -EINVAL);
    ASSERTN(fstr_p != NULL, -EINVAL);

    while (*str_p++ == *fstr_p++) {
        if (str_p[-1] == '\0') {
            return (0);
        }
    }

    return (str_p[-1] - fstr_p[-1]);
}

int std_strcmp_f(FAR const char *fstr0_p,
                 FAR const char *fstr1_p)
{
    ASSERTN(fstr0_p != NULL, -EINVAL);
    ASSERTN(fstr1_p != NULL, -EINVAL);

    while (*fstr0_p++ == *fstr1_p++) {
        if (fstr0_p[-1] == '\0') {
            return (0);
        }
    }

    return (fstr0_p[-1] - fstr1_p[-1]);
}

int std_strncmp(FAR const char *fstr_p,
                const char *str_p,
                size_t size)
{
    ASSERTN(fstr_p != NULL, -EINVAL);
    ASSERTN(str_p != NULL, -EINVAL);

    FAR const char *fstr_end_p = (fstr_p + size);

    /* Match if no characters are compared. */
    if (size == 0) {
        return (0);
    }

    while (*fstr_p++ == *str_p++) {
        if ((fstr_p[-1] == '\0') || (fstr_p == fstr_end_p)) {
            return (0);
        }
    }

    return (fstr_p[-1] - str_p[-1]);
}

int std_strncmp_f(FAR const char *fstr0_p,
                  FAR const char *fstr1_p,
                  size_t size)
{
    ASSERTN(fstr0_p != NULL, -EINVAL);
    ASSERTN(fstr1_p != NULL, -EINVAL);

    FAR const char *fstr_end_p = (fstr0_p + size);

    /* Match if no characters are compared. */
    if (size == 0) {
        return (0);
    }

    while (*fstr0_p++ == *fstr1_p++) {
        if ((fstr0_p[-1] == '\0') || (fstr0_p == fstr_end_p)) {
            return (0);
        }
    }

    return (fstr0_p[-1] - fstr1_p[-1]);
}

int std_strlen(FAR const char *fstr_p)
{
    ASSERTN(fstr_p != NULL, -EINVAL);

    FAR const char *fstr_start_p = fstr_p;

    while (*fstr_p++ != '\0') {
    }

    return (fstr_p - fstr_start_p - 1);
}

char *std_strip(char *str_p, const char *strip_p)
{
    ASSERTN(str_p != NULL, -EINVAL);

    char *begin_p;
    size_t length;

    /* Strip whitespace characters by default. */
    if (strip_p == NULL) {
        strip_p = "\t\n\x0b\x0c\r ";
    }

    /* String leading characters. */
    while ((*str_p != '\0') && char_in_string(*str_p, strip_p)) {
        str_p++;
    }

    begin_p = str_p;

    /* Strip training characters. */
    length = strlen(str_p);
    str_p += (length - 1);

    while ((str_p >= begin_p) && char_in_string(*str_p, strip_p)) {
        *str_p = '\0';
        str_p--;
    }

    return (begin_p);
}
