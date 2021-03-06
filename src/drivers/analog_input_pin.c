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

int analog_input_pin_module_init(void)
{
    return (adc_module_init());
}

int analog_input_pin_init(struct analog_input_pin_t *self_p,
                          struct pin_device_t *pin_p)
{
    return (adc_init(&self_p->adc,
                     &adc_device[0],
                     pin_p,
                     ADC_REFERENCE_VCC,
                     1));
}

int analog_input_pin_read(struct analog_input_pin_t *self_p)
{
    uint16_t sample;
    
    if (adc_convert(&self_p->adc, &sample, 1) == 0) {
        return (sample);
    }

    return (-1);
}

int analog_input_pin_read_isr(struct analog_input_pin_t *self_p)
{
    uint16_t sample;
    
    if (adc_convert_isr(&self_p->adc, &sample) == 0) {
        return (sample);
    }

    return (-1);
}
