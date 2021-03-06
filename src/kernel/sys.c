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

struct sys_t sys = {
    .tick = 0,
    .on_fatal_callback = sys_stop,
    .stdin_p = NULL,
    .stdout_p = NULL,
    .interrupt = {
        .start = 0,
        .time = 0
    }
};

struct module_t {
    int initialized;
#if CONFIG_FS_CMD_SYS_INFO == 1
    struct fs_command_t cmd_info;
#endif
#if CONFIG_FS_CMD_SYS_CONFIG == 1
    struct fs_command_t cmd_config;
#endif
#if CONFIG_FS_CMD_SYS_UPTIME == 1
    struct fs_command_t cmd_uptime;
#endif
#if CONFIG_FS_CMD_SYS_REBOOT == 1
    struct fs_command_t cmd_reboot;
#endif
};

static struct module_t module;

static const FAR char config[] =
    "config: sys-config-string=" STRINGIFY(CONFIG_SYS_CONFIG_STRING) "\r\n"

#if CONFIG_SYS_CONFIG_STRING == 1

    "        assert=" STRINGIFY(CONFIG_ASSERT) "\r\n"
    "        debug=" STRINGIFY(CONFIG_DEBUG) "\r\n"
    "        fs-cmd-ds18b20-list=" STRINGIFY(CONFIG_FS_CMD_DS18B20_LIST) "\r\n"
    "        fs-cmd-fs-counters-list=" STRINGIFY(CONFIG_FS_CMD_FS_COUNTERS_LIST) "\r\n"
    "        fs-cmd-fs-counters-reset=" STRINGIFY(CONFIG_FS_CMD_FS_COUNTERS_RESET) "\r\n"
    "        fs-cmd-fs-filesystems-append=" STRINGIFY(CONFIG_FS_CMD_FS_APPEND) "\r\n"
    "        fs-cmd-fs-filesystems-list=" STRINGIFY(CONFIG_FS_CMD_FS_LIST) "\r\n"
    "        fs-cmd-fs-filesystems-read=" STRINGIFY(CONFIG_FS_CMD_FS_READ) "\r\n"
    "        fs-cmd-fs-filesystems-write=" STRINGIFY(CONFIG_FS_CMD_FS_WRITE) "\r\n"
    "        fs-cmd-fs-parameters-list=" STRINGIFY(CONFIG_FS_CMD_FS_PARAMETERS_LIST) "\r\n"
    "        fs-cmd-i2c-read=" STRINGIFY(CONFIG_FS_CMD_I2C_READ) "\r\n"
    "        fs-cmd-i2c-write=" STRINGIFY(CONFIG_FS_CMD_I2C_WRITE) "\r\n"
    "        fs-cmd-log-list=" STRINGIFY(CONFIG_FS_CMD_LOG_LIST) "\r\n"
    "        fs-cmd-log-print=" STRINGIFY(CONFIG_FS_CMD_LOG_PRINT) "\r\n"
    "        fs-cmd-log-set-log-mask=" STRINGIFY(CONFIG_FS_CMD_LOG_SET_LOG_MASK) "\r\n"
    "        fs-cmd-network-interface-list=" STRINGIFY(CONFIG_FS_CMD_NETWORK_INTERFACE_LIST) "\r\n"
    "        fs-cmd-pin-read=" STRINGIFY(CONFIG_FS_CMD_PIN_READ) "\r\n"
    "        fs-cmd-pin-set-mode=" STRINGIFY(CONFIG_FS_CMD_PIN_SET_MODE) "\r\n"
    "        fs-cmd-pin-write=" STRINGIFY(CONFIG_FS_CMD_PIN_WRITE) "\r\n"
    "        fs-cmd-settings-list=" STRINGIFY(CONFIG_FS_CMD_SETTINGS_LIST) "\r\n"
    "        fs-cmd-settings-read=" STRINGIFY(CONFIG_FS_CMD_SETTINGS_READ) "\r\n"
    "        fs-cmd-settings-reset=" STRINGIFY(CONFIG_FS_CMD_SETTINGS_RESET) "\r\n"
    "        fs-cmd-settings-write=" STRINGIFY(CONFIG_FS_CMD_SETTINGS_WRITE) "\r\n"
    "        fs-cmd-sys-info=" STRINGIFY(CONFIG_FS_CMD_SYS_INFO) "\r\n"
    "        fs-cmd-sys-uptime=" STRINGIFY(CONFIG_FS_CMD_SYS_UPTIME) "\r\n"
    "        fs-cmd-thrd-list=" STRINGIFY(CONFIG_FS_CMD_THRD_LIST) "\r\n"
    "        fs-cmd-thrd-set-log-mask=" STRINGIFY(CONFIG_FS_CMD_THRD_SET_LOG_MASK) "\r\n"
    "        fs-cmd-usb-device-list=" STRINGIFY(CONFIG_FS_CMD_USB_DEVICE_LIST) "\r\n"
    "        fs-cmd-usb-host-list=" STRINGIFY(CONFIG_FS_CMD_USB_HOST_LIST) "\r\n"
    "        monitor-thread=" STRINGIFY(CONFIG_MONITOR_THREAD) "\r\n"
    "        preemptive-scheduler=" STRINGIFY(CONFIG_PREEMPTIVE_SCHEDULER) "\r\n"
    "        profile-stack=" STRINGIFY(CONFIG_PROFILE_STACK) "\r\n"
    "        settings-area-size=" STRINGIFY(CONFIG_SETTINGS_AREA_SIZE) "\r\n"
    "        shell-command-max=" STRINGIFY(CONFIG_SHELL_COMMAND_MAX) "\r\n"
    "        shell-history-size=" STRINGIFY(CONFIG_SHELL_HISTORY_SIZE) "\r\n"
    "        shell-minimal=" STRINGIFY(CONFIG_SHELL_MINIMAL) "\r\n"
    "        shell-prompt=" STRINGIFY(CONFIG_SHELL_PROMPT) "\r\n"
    "        spiffs=" STRINGIFY(CONFIG_SPIFFS) "\r\n"
    "        start-console=" STRINGIFY(CONFIG_START_CONSOLE) "\r\n"
    "        start-console-device-index=" STRINGIFY(CONFIG_START_CONSOLE_DEVICE_INDEX) "\r\n"
    "        start-console-uart-baudrate=" STRINGIFY(CONFIG_START_CONSOLE_UART_BAUDRATE) "\r\n"
    "        start-console-usb-cdc-control-interface=" STRINGIFY(CONFIG_START_CONSOLE_USB_CDC_CONTROL_INTERFACE) "\r\n"
    "        start-console-usb-cdc-endpoint-in=" STRINGIFY(CONFIG_START_CONSOLE_USB_CDC_ENDPOINT_IN) "\r\n"
    "        start-console-usb-cdc-endpoint-out=" STRINGIFY(CONFIG_START_CONSOLE_USB_CDC_ENDPOINT_OUT) "\r\n"
    "        start-console-usb-cdc-wait-for-connetion=" STRINGIFY(CONFIG_START_CONSOLE_USB_CDC_WAIT_FOR_CONNETION) "\r\n"
    "        start-filesystem=" STRINGIFY(CONFIG_START_FILESYSTEM) "\r\n"
    "        start-filesystem-address=" STRINGIFY(CONFIG_START_FILESYSTEM_ADDRESS) "\r\n"
    "        start-filesystem-size=" STRINGIFY(CONFIG_START_FILESYSTEM_SIZE) "\r\n"
    "        start-network=" STRINGIFY(CONFIG_START_NETWORK) "\r\n"
    "        start-network-interface-wifi-ssid=" STRINGIFY(CONFIG_START_NETWORK_INTERFACE_WIFI_SSID) "\r\n"
    "        start-network-interface-wifi-password=********\r\n"
    "        start-shell=" STRINGIFY(CONFIG_START_SHELL) "\r\n"
    "        start-shell-prio=" STRINGIFY(CONFIG_START_SHELL_PRIO) "\r\n"
    "        start-shell-stack-size=" STRINGIFY(CONFIG_START_SHELL_STACK_SIZE) "\r\n"
    "        std-output-buffer-max=" STRINGIFY(CONFIG_STD_OUTPUT_BUFFER_MAX) "\r\n"
    "        system-tick-frequency=" STRINGIFY(CONFIG_SYSTEM_TICK_FREQUENCY) "\r\n"
    "        usb-device-vid=" STRINGIFY(CONFIG_USB_DEVICE_VID) "\r\n"
    "        usb-device-pid=" STRINGIFY(CONFIG_USB_DEVICE_PID) "\r\n"

#endif

    "";

extern void time_tick_isr(void);
extern void timer_tick_isr(void);
extern void thrd_tick_isr(void);
extern const FAR char sysinfo[];

static void RAM_CODE sys_tick_isr(void)
{
    sys.tick++;
    time_tick_isr();
    timer_tick_isr();
    thrd_tick_isr();
}

#include "sys_port.i"

#if CONFIG_START_CONSOLE != CONFIG_START_CONSOLE_NONE

static int start_console(void)
{
    console_module_init();
    console_init();
    console_start();

    sys_set_stdin(console_get_input_channel());
    sys_set_stdout(console_get_output_channel());
    log_set_default_handler_output_channel(console_get_output_channel());

    return (0);
}

#endif

#if CONFIG_START_SHELL == 1

static struct shell_t shell;
static THRD_STACK(shell_stack, CONFIG_START_SHELL_STACK_SIZE);

static int start_shell(void)
{
    shell_init(&shell,
               sys_get_stdin(),
               sys_get_stdout(),
               NULL,
               NULL,
               NULL,
               NULL);

    thrd_spawn(shell_main,
               &shell,
               CONFIG_START_SHELL_PRIO,
               shell_stack,
               sizeof(shell_stack));

    return (0);
}

#endif

#if CONFIG_START_FILESYSTEM == 1
#    include "sys/filesystem.i"
#endif

#if CONFIG_START_NETWORK == 1
#    include "sys/network.i"
#endif

#if CONFIG_FS_CMD_SYS_INFO == 1

static int cmd_info_cb(int argc,
                       const char *argv[],
                       void *out_p,
                       void *in_p,
                       void *arg_p,
                       void *call_arg_p)
{
    std_fprintf(out_p, sysinfo);

    return (0);
}

#endif

#if CONFIG_FS_CMD_SYS_CONFIG == 1

static int cmd_config_cb(int argc,
                         const char *argv[],
                         void *out_p,
                         void *in_p,
                         void *arg_p,
                         void *call_arg_p)
{
    std_fprintf(out_p, config);

    return (0);
}

#endif

#if CONFIG_FS_CMD_SYS_UPTIME == 1

static int cmd_uptime_cb(int argc,
                         const char *argv[],
                         void *out_p,
                         void *in_p,
                         void *arg_p,
                         void *call_arg_p)
{
    struct time_t now;

    time_get(&now);

    std_fprintf(out_p,
                FSTR("%lu.%lu seconds\r\n"),
                now.seconds,
                now.nanoseconds / 1000000ul);

    return (0);
}

#endif

#if CONFIG_FS_CMD_SYS_REBOOT == 1

static int cmd_reboot_cb(int argc,
                         const char *argv[],
                         void *out_p,
                         void *in_p,
                         void *arg_p,
                         void *call_arg_p)
{
    sys_reboot();

    return (0);
}

#endif

int sys_module_init(void)
{
    /* Return immediately if the module is already initialized. */
    if (module.initialized == 1) {
        return (0);
    }

    module.initialized = 1;

#if CONFIG_FS_CMD_SYS_INFO == 1
    fs_command_init(&module.cmd_info,
                    FSTR("/kernel/sys/info"),
                    cmd_info_cb,
                    NULL);
    fs_command_register(&module.cmd_info);
#endif

#if CONFIG_FS_CMD_SYS_CONFIG == 1
    fs_command_init(&module.cmd_config,
                    FSTR("/kernel/sys/config"),
                    cmd_config_cb,
                    NULL);
    fs_command_register(&module.cmd_config);
#endif

#if CONFIG_FS_CMD_SYS_UPTIME == 1
    fs_command_init(&module.cmd_uptime,
                    FSTR("/kernel/sys/uptime"),
                    cmd_uptime_cb,
                    NULL);
    fs_command_register(&module.cmd_uptime);
#endif

#if CONFIG_FS_CMD_SYS_REBOOT == 1
    fs_command_init(&module.cmd_reboot,
                    FSTR("/kernel/sys/reboot"),
                    cmd_reboot_cb,
                    NULL);
    fs_command_register(&module.cmd_reboot);
#endif

    return (sys_port_module_init());
}

int sys_start(void)
{
    rwlock_module_init();
    fs_module_init();
    settings_module_init();
    std_module_init();
    sem_module_init();
    timer_module_init();
    log_module_init();
    chan_module_init();
    thrd_module_init();
    shell_module_init();
    sys_module_init();

#if CONFIG_START_CONSOLE != CONFIG_START_CONSOLE_NONE
    start_console();
#endif

#if CONFIG_START_SHELL == 1
    start_shell();
#endif

# if CONFIG_START_FILESYSTEM == 1
    start_filesystem();
#endif

# if CONFIG_START_NETWORK == 1
    start_network();
#endif

    return (0);
}

void sys_stop(int error)
{
    sys_port_stop(error);
}

void sys_reboot(void)
{
    sys_port_reboot();
}

void sys_set_on_fatal_callback(void (*callback)(int error))
{
    sys.on_fatal_callback = callback;
}

void sys_set_stdin(void *chan_p)
{
    sys.stdin_p = chan_p;
}

void *sys_get_stdin()
{
    return (sys.stdin_p);
}

void sys_set_stdout(void *chan_p)
{
    sys.stdout_p = chan_p;
}

void *sys_get_stdout()
{
    return (sys.stdout_p);
}

void sys_lock()
{
    sys_port_lock();
}

void sys_unlock()
{
    sys_port_unlock();
}

void RAM_CODE sys_lock_isr()
{
    sys_port_lock_isr();
}

void RAM_CODE sys_unlock_isr()
{
    sys_port_unlock_isr();
}

far_string_t sys_get_info()
{
    return (sysinfo);
}

far_string_t sys_get_config()
{
    return (config);
}

float sys_interrupt_cpu_usage_get()
{
    return (sys_port_interrupt_cpu_usage_get());
}

void sys_interrupt_cpu_usage_reset()
{
    sys_port_interrupt_cpu_usage_reset();
}
