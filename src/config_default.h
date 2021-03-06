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

#ifndef __CONFIG_DEFAULT_H__
#define __CONFIG_DEFAULT_H__

/**
 * The system configuration string contains a list of all configration
 * varialbes and their values.
 */
#ifndef CONFIG_SYS_CONFIG_STRING
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_SYS_CONFIG_STRING                    0
#    else
#        define CONFIG_SYS_CONFIG_STRING                    1
#    endif
#endif

/**
 * Main thread stack size for ports with a fixed size main thread
 * stack.
 */
#ifndef CONFIG_SYS_SIMBA_MAIN_STACK_MAX
#    define CONFIG_SYS_SIMBA_MAIN_STACK_MAX              4096
#endif

/**
 * Assertions are used to check various conditions during the
 * application execution. A typical usage is to validate function
 * input arguments.
 */
#ifndef CONFIG_ASSERT
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_ASSERT                               0
#    else
#        define CONFIG_ASSERT                               1
#    endif
#endif

/**
 * Include more debug information.
 */
#ifndef CONFIG_DEBUG
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_DEBUG                                0
#    else
#        define CONFIG_DEBUG                                1
#    endif
#endif

/**
 * Debug file system command to list all DS18B20 sensors on the bus.
 */
#ifndef CONFIG_FS_CMD_DS18B20_LIST
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_DS18B20_LIST                  0
#    else
#        define CONFIG_FS_CMD_DS18B20_LIST                  1
#    endif
#endif

/**
 * Debug file system command to print the Espressif WiFi status.
 */
#ifndef CONFIG_FS_CMD_ESP_WIFI_STATUS
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_ESP_WIFI_STATUS               0
#    elif defined(BOARD_ESP12E) || defined(BOARD_ESP01) || defined(BOARD_NODEMCU)
#        define CONFIG_FS_CMD_ESP_WIFI_STATUS               1
#    else
#        define CONFIG_FS_CMD_ESP_WIFI_STATUS               0
#    endif
#endif

/**
 * Debug file system command to append to a file.
 */
#ifndef CONFIG_FS_CMD_FS_APPEND
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_FS_APPEND                     0
#    else
#        define CONFIG_FS_CMD_FS_APPEND                     1
#    endif
#endif

/**
 * Debug file system command to list all counters.
 */
#ifndef CONFIG_FS_CMD_FS_COUNTERS_LIST
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_FS_COUNTERS_LIST              0
#    else
#        define CONFIG_FS_CMD_FS_COUNTERS_LIST              1
#    endif
#endif

/**
 * Debug file system command to set all counters to zero.
 */
#ifndef CONFIG_FS_CMD_FS_COUNTERS_RESET
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_FS_COUNTERS_RESET             0
#    else
#        define CONFIG_FS_CMD_FS_COUNTERS_RESET             1
#    endif
#endif

/**
 * Debug file system command to list all registered file systems.
 */
#ifndef CONFIG_FS_CMD_FS_FILESYSTEMS_LIST
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_FS_FILESYSTEMS_LIST           0
#    else
#        define CONFIG_FS_CMD_FS_FILESYSTEMS_LIST           1
#    endif
#endif

/**
 * Debug file system command to list all registered file systems.
 */
#ifndef CONFIG_FS_CMD_FS_LIST
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_FS_LIST                       0
#    else
#        define CONFIG_FS_CMD_FS_LIST                       1
#    endif
#endif

/**
 * Debug file system command to format a file system.
 */
#ifndef CONFIG_FS_CMD_FS_FORMAT
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_FS_FORMAT                     0
#    else
#        define CONFIG_FS_CMD_FS_FORMAT                     1
#    endif
#endif

/**
 * Debug file system command to list all parameters.
 */
#ifndef CONFIG_FS_CMD_FS_PARAMETERS_LIST
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_FS_PARAMETERS_LIST            0
#    else
#        define CONFIG_FS_CMD_FS_PARAMETERS_LIST            1
#    endif
#endif

/**
 * Debug file system command to read from a file.
 */
#ifndef CONFIG_FS_CMD_FS_READ
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_FS_READ                       0
#    else
#        define CONFIG_FS_CMD_FS_READ                       1
#    endif
#endif

/**
 * Debug file system command to remove a file.
 */
#ifndef CONFIG_FS_CMD_FS_REMOVE
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_FS_REMOVE                     0
#    else
#        define CONFIG_FS_CMD_FS_REMOVE                     1
#    endif
#endif

/**
 * Debug file system command to write to a file.
 */
#ifndef CONFIG_FS_CMD_FS_WRITE
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_FS_WRITE                      0
#    else
#        define CONFIG_FS_CMD_FS_WRITE                      1
#    endif
#endif

/**
 * Debug file system command to read from a i2c bus.
 */
#ifndef CONFIG_FS_CMD_I2C_READ
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_I2C_READ                      0
#    else
#        define CONFIG_FS_CMD_I2C_READ                      1
#    endif
#endif

/**
 * Debug file system command to write to a i2c bus.
 */
#ifndef CONFIG_FS_CMD_I2C_WRITE
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_I2C_WRITE                     0
#    else
#        define CONFIG_FS_CMD_I2C_WRITE                     1
#    endif
#endif

/**
 * Debug file system command to list all log objects.
 */
#ifndef CONFIG_FS_CMD_LOG_LIST
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_LOG_LIST                      0
#    else
#        define CONFIG_FS_CMD_LOG_LIST                      1
#    endif
#endif

/**
 * Debug file system command to create a log entry and print
 * it. Mainly used for debugging.
 */
#ifndef CONFIG_FS_CMD_LOG_PRINT
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_LOG_PRINT                     0
#    else
#        define CONFIG_FS_CMD_LOG_PRINT                     1
#    endif
#endif

/**
 * Debug file system command to set the log mask of a log object.
 */
#ifndef CONFIG_FS_CMD_LOG_SET_LOG_MASK
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_LOG_SET_LOG_MASK              0
#    else
#        define CONFIG_FS_CMD_LOG_SET_LOG_MASK              1
#    endif
#endif

/**
 * Debug file system command to list all network interfaces.
 */
#ifndef CONFIG_FS_CMD_NETWORK_INTERFACE_LIST
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_NETWORK_INTERFACE_LIST        0
#    else
#        define CONFIG_FS_CMD_NETWORK_INTERFACE_LIST        1
#    endif
#endif

/**
 * Debug file system command to read the current value of a pin.
 */
#ifndef CONFIG_FS_CMD_PIN_READ
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_PIN_READ                      0
#    else
#        define CONFIG_FS_CMD_PIN_READ                      1
#    endif
#endif

/**
 * Debug file system command to set the mode of a pin.
 */
#ifndef CONFIG_FS_CMD_PIN_SET_MODE
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_PIN_SET_MODE                  0
#    else
#        define CONFIG_FS_CMD_PIN_SET_MODE                  1
#    endif
#endif

/**
 * Debug file system command to write a value to a pin.
 */
#ifndef CONFIG_FS_CMD_PIN_WRITE
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_PIN_WRITE                     0
#    else
#        define CONFIG_FS_CMD_PIN_WRITE                     1
#    endif
#endif

/**
 * Debug file system command to ping a host.
 */
#ifndef CONFIG_FS_CMD_PING_PING
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_PING_PING                         0
#    else
#        define CONFIG_FS_CMD_PING_PING                         1
#    endif
#endif

/**
 * Debug file system command to list all services.
 */
#ifndef CONFIG_FS_CMD_SERVICE_LIST
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_SERVICE_LIST                      0
#    else
#        define CONFIG_FS_CMD_SERVICE_LIST                      1
#    endif
#endif

/**
 * Debug file system command to start a service.
 */
#ifndef CONFIG_FS_CMD_SERVICE_START
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_SERVICE_START                     0
#    else
#        define CONFIG_FS_CMD_SERVICE_START                     1
#    endif
#endif

/**
 * Debug file system command to stop a services.
 */
#ifndef CONFIG_FS_CMD_SERVICE_STOP
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_SERVICE_STOP                      0
#    else
#        define CONFIG_FS_CMD_SERVICE_STOP                      1
#    endif
#endif

/**
 * Debug file system command to list all settings.
 */
#ifndef CONFIG_FS_CMD_SETTINGS_LIST
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_SETTINGS_LIST                 0
#    else
#        define CONFIG_FS_CMD_SETTINGS_LIST                 1
#    endif
#endif

/**
 * Debug file system command to read the value of a setting.
 */
#ifndef CONFIG_FS_CMD_SETTINGS_READ
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_SETTINGS_READ                 0
#    else
#        define CONFIG_FS_CMD_SETTINGS_READ                 1
#    endif
#endif

/**
 * Debug file system command to reset the settings to their original
 * values.
 */
#ifndef CONFIG_FS_CMD_SETTINGS_RESET
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_SETTINGS_RESET                0
#    else
#        define CONFIG_FS_CMD_SETTINGS_RESET                1
#    endif
#endif

/**
 * Debug file system command to write a value to a setting.
 */
#ifndef CONFIG_FS_CMD_SETTINGS_WRITE
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_SETTINGS_WRITE                0
#    else
#        define CONFIG_FS_CMD_SETTINGS_WRITE                1
#    endif
#endif

/**
 * Debug file system command to print the system configuration.
 */
#ifndef CONFIG_FS_CMD_SYS_CONFIG
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_SYS_CONFIG                    0
#    else
#        define CONFIG_FS_CMD_SYS_CONFIG                    1
#    endif
#endif

/**
 * Debug file system command to print the system information.
 */
#ifndef CONFIG_FS_CMD_SYS_INFO
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_SYS_INFO                      0
#    else
#        define CONFIG_FS_CMD_SYS_INFO                      1
#    endif
#endif

/**
 * Debug file system command to print the system uptime.
 */
#ifndef CONFIG_FS_CMD_SYS_UPTIME
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_SYS_UPTIME                    0
#    else
#        define CONFIG_FS_CMD_SYS_UPTIME                    1
#    endif
#endif

/**
 * Debug file system command to reboot the system uptime.
 */
#ifndef CONFIG_FS_CMD_SYS_REBOOT
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_SYS_REBOOT                    0
#    else
#        define CONFIG_FS_CMD_SYS_REBOOT                    1
#    endif
#endif

/**
 * Debug file system command to list threads' information.
 */
#ifndef CONFIG_FS_CMD_THRD_LIST
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_THRD_LIST                     0
#    else
#        define CONFIG_FS_CMD_THRD_LIST                     1
#    endif
#endif

/**
 * Debug file system command to set the log mask of a thread.
 */
#ifndef CONFIG_FS_CMD_THRD_SET_LOG_MASK
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_THRD_SET_LOG_MASK             0
#    else
#        define CONFIG_FS_CMD_THRD_SET_LOG_MASK             1
#    endif
#endif

/**
 * Debug file system command to list all USB devices.
 */
#ifndef CONFIG_FS_CMD_USB_DEVICE_LIST
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_USB_DEVICE_LIST               0
#    else
#        define CONFIG_FS_CMD_USB_DEVICE_LIST               1
#    endif
#endif

/**
 * Debug file system command to list all USB devices connected to the
 * USB host.
 */
#ifndef CONFIG_FS_CMD_USB_HOST_LIST
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_FS_CMD_USB_HOST_LIST                 0
#    else
#        define CONFIG_FS_CMD_USB_HOST_LIST                 1
#    endif
#endif

/**
 * The maximum length of an absolute path in the file system.
 */
#ifndef CONFIG_FS_PATH_MAX
#    define CONFIG_FS_PATH_MAX                             64
#endif

/**
 * Start the monitor thread to gather statistics of the scheulder.
 */
#ifndef CONFIG_MONITOR_THREAD
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(BOARD_ESP12E) || defined(BOARD_ESP01) || defined(BOARD_NODEMCU) || defined(BOARD_NANO32) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_MONITOR_THREAD                       0
#    else
#        define CONFIG_MONITOR_THREAD                       1
#    endif
#endif

/**
 * Use a preemptive scheduler.
 */
#ifndef CONFIG_PREEMPTIVE_SCHEDULER
#    define CONFIG_PREEMPTIVE_SCHEDULER                     0
#endif

/**
 * Profile the stack usage in runtime. It's a cheap operation and is
 * recommended to have enabled.
 */
#ifndef CONFIG_PROFILE_STACK
#    define CONFIG_PROFILE_STACK                            1
#endif

/**
 * Size of the settings area. This size *MUST* have the same size as
 * the settings generated by the settings.py script.
 */
#ifndef CONFIG_SETTINGS_AREA_SIZE
#    define CONFIG_SETTINGS_AREA_SIZE                     256
#endif

/**
 * Maximum number of characters in a shell command.
 */
#ifndef CONFIG_SHELL_COMMAND_MAX
#    define CONFIG_SHELL_COMMAND_MAX                       64
#endif

/**
 * Size of the shell history buffer.
 */
#ifndef CONFIG_SHELL_HISTORY_SIZE
#    define CONFIG_SHELL_HISTORY_SIZE                     768
#endif

/**
 * Minimal shell functionality to minimize the code size of the shell
 * module.
 */
#ifndef CONFIG_SHELL_MINIMAL
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_SHELL_MINIMAL                        1
#    else
#        define CONFIG_SHELL_MINIMAL                        0
#    endif
#endif

/**
 * The shell prompt string.
 */
#ifndef CONFIG_SHELL_PROMPT
#    define CONFIG_SHELL_PROMPT "$ "
#endif

/**
 * Raw socket support.
 */
#ifndef CONFIG_SOCKET_RAW
#    define CONFIG_SOCKET_RAW                               1
#endif

/**
 * SPIFFS is a flash file system applicable for boards that has a
 * reasonably big modifiable flash.
 */
#ifndef CONFIG_SPIFFS
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_SPIFFS                               0
#    elif defined(BOARD_ARDUINO_DUE) || defined(ARCH_LINUX) || defined(ARCH_ESP) || defined(ARCH_ESP32)
#        define CONFIG_SPIFFS                               1
#    else
#        define CONFIG_SPIFFS                               0
#    endif
#endif

#define CONFIG_START_CONSOLE_NONE                           0
#define CONFIG_START_CONSOLE_UART                           1
#define CONFIG_START_CONSOLE_USB_CDC                        2

/**
 * Start the console device (UART/USB CDC) on system startup.
 */
#ifndef CONFIG_START_CONSOLE
#    if defined(BOARD_ARDUINO_PRO_MICRO)
#        define CONFIG_START_CONSOLE   CONFIG_START_CONSOLE_USB_CDC
#    else
#        define CONFIG_START_CONSOLE      CONFIG_START_CONSOLE_UART
#    endif
#endif

/**
 * Console device index.
 */
#ifndef CONFIG_START_CONSOLE_DEVICE_INDEX
#    define CONFIG_START_CONSOLE_DEVICE_INDEX               0
#endif

/**
 * Console UART baudrate.
 */
#ifndef CONFIG_START_CONSOLE_UART_BAUDRATE
#    if defined(BOARD_ESP01) || defined(BOARD_ESP12E) || defined(BOARD_NODEMCU)
#        define CONFIG_START_CONSOLE_UART_BAUDRATE      76800
#    elif defined(BOARD_NANO32)
#        define CONFIG_START_CONSOLE_UART_BAUDRATE     115200
#    else
#        define CONFIG_START_CONSOLE_UART_BAUDRATE      38400
#    endif
#endif

/**
 * Console USB CDC control interface number.
 */
#ifndef CONFIG_START_CONSOLE_USB_CDC_CONTROL_INTERFACE
#    define CONFIG_START_CONSOLE_USB_CDC_CONTROL_INTERFACE  0
#endif

/**
 * Console USB CDC input endpoint.
 */
#ifndef CONFIG_START_CONSOLE_USB_CDC_ENDPOINT_IN
#    define CONFIG_START_CONSOLE_USB_CDC_ENDPOINT_IN        2
#endif

/**
 * Console USB CDC output endpoint.
 */
#ifndef CONFIG_START_CONSOLE_USB_CDC_ENDPOINT_OUT
#    define CONFIG_START_CONSOLE_USB_CDC_ENDPOINT_OUT       3
#endif

/**
 * Wait for the host to connect after starting the console.
 */
#ifndef CONFIG_START_CONSOLE_USB_CDC_WAIT_FOR_CONNETION
#    define CONFIG_START_CONSOLE_USB_CDC_WAIT_FOR_CONNETION 1
#endif

/**
 * Configure a default file system.
 */
#ifndef CONFIG_START_FILESYSTEM
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_START_FILESYSTEM                     0
#    elif defined(BOARD_ARDUINO_DUE) || defined(ARCH_LINUX) || defined(ARCH_ESP) || defined(ARCH_ESP32)
#        define CONFIG_START_FILESYSTEM                     1
#    else
#        define CONFIG_START_FILESYSTEM                     0
#    endif
#endif

/**
 * Configure a default file system start address.
 */
#ifndef CONFIG_START_FILESYSTEM_ADDRESS
#    if defined(BOARD_ARDUINO_DUE)
#        define CONFIG_START_FILESYSTEM_ADDRESS    0x000e0000
#    elif defined(BOARD_ESP01)
#        define CONFIG_START_FILESYSTEM_ADDRESS    0x0006b000
#    elif defined(BOARD_ESP12E) || defined(BOARD_NODEMCU)
#        define CONFIG_START_FILESYSTEM_ADDRESS    0x00300000
#    elif defined(BOARD_NANO32)
#        define CONFIG_START_FILESYSTEM_ADDRESS    0x00300000
#    else
#        define CONFIG_START_FILESYSTEM_ADDRESS             0
#    endif
#endif

/**
 * Configure a default file system size.
 */
#ifndef CONFIG_START_FILESYSTEM_SIZE
#    if defined(BOARD_ARDUINO_DUE)
#        define CONFIG_START_FILESYSTEM_SIZE            32768
#    elif defined(BOARD_ESP01)
#        define CONFIG_START_FILESYSTEM_SIZE          0x10000
#    elif defined(BOARD_ESP12E) || defined(BOARD_NODEMCU)
#        define CONFIG_START_FILESYSTEM_SIZE          0xFB000
#    elif defined(ARCH_ESP32)
#        define CONFIG_START_FILESYSTEM_SIZE            32768
#    else
#        define CONFIG_START_FILESYSTEM_SIZE            65536
#    endif
#endif

/**
 * Setup the ip stack and connect to all configured networks.
 */
#ifndef CONFIG_START_NETWORK
#    define CONFIG_START_NETWORK                            0
#endif

/**
 * WiFi connect timeout is seconds.
 */
#ifndef CONFIG_START_NETWORK_INTERFACE_WIFI_CONNECT_TIMEOUT
#    define CONFIG_START_NETWORK_INTERFACE_WIFI_CONNECT_TIMEOUT 30
#endif

/**
 * SSID of the WiFi to connect to.
 */
#ifndef CONFIG_START_NETWORK_INTERFACE_WIFI_SSID
#    define CONFIG_START_NETWORK_INTERFACE_WIFI_SSID   MyWiFiSSID
#endif

/**
 * Password of the WiFi to connect to.
 */
#ifndef CONFIG_START_NETWORK_INTERFACE_WIFI_PASSWORD
#    define CONFIG_START_NETWORK_INTERFACE_WIFI_PASSWORD MyWiFiPassword
#endif

/**
 * Start a shell thread communication over the console channels.
 */
#ifndef CONFIG_START_SHELL
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_START_SHELL                          0
#    else
#        define CONFIG_START_SHELL                          1
#    endif
#endif

/**
 * Shell thread priority.
 */
#ifndef CONFIG_START_SHELL_PRIO
#    define CONFIG_START_SHELL_PRIO                        30
#endif

/**
 * Shell thread stack size in words.
 */
#ifndef CONFIG_START_SHELL_STACK_SIZE
#    if defined(BOARD_ARDUINO_DUE) || defined(ARCH_ESP)
#        define CONFIG_START_SHELL_STACK_SIZE            1536
#    elif defined(ARCH_ESP32)
#        define CONFIG_START_SHELL_STACK_SIZE            4096
#    else
#        define CONFIG_START_SHELL_STACK_SIZE             768
#    endif
#endif

/**
 * Maximum number of bytes in the print output buffer.
 */
#ifndef CONFIG_STD_OUTPUT_BUFFER_MAX
#    define CONFIG_STD_OUTPUT_BUFFER_MAX                   16
#endif

/**
 * System tick frequency in Hertz.
 */
#ifndef CONFIG_SYSTEM_TICK_FREQUENCY
#    define CONFIG_SYSTEM_TICK_FREQUENCY                  100
#endif

/**
 * System tick using a software timer instead of a hardware
 * timer. Suitable for ESP8266 to enable software PWM.
 */
#ifndef CONFIG_SYSTEM_TICK_SOFTWARE
#    define CONFIG_SYSTEM_TICK_SOFTWARE                     0
#endif

/**
 * Calculate thread CPU usage.
 */
#ifndef CONFIG_THRD_CPU_USAGE
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_THRD_CPU_USAGE                       0
#    else
#        define CONFIG_THRD_CPU_USAGE                       1
#    endif
#endif

/**
 * Each thread has a list of environment variables associated with
 * it. A typical example of an environment variable is "CWD" - Current
 * Working Directory.
 */
#ifndef CONFIG_THRD_ENV
#    if defined(BOARD_ARDUINO_NANO) || defined(BOARD_ARDUINO_UNO) || defined(BOARD_ARDUINO_PRO_MICRO) || defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_THRD_ENV                             0
#    else
#        define CONFIG_THRD_ENV                             1
#    endif
#endif

/**
 * Stack size of the idle thread.
 */
#ifndef CONFIG_THRD_IDLE_STACK_SIZE
#    if defined(ARCH_ARM)
#        define CONFIG_THRD_IDLE_STACK_SIZE               384
#    elif defined(ARCH_AVR)
#        define CONFIG_THRD_IDLE_STACK_SIZE               156
#    elif defined(ARCH_ESP)
#        define CONFIG_THRD_IDLE_STACK_SIZE               768
#    else
#        define CONFIG_THRD_IDLE_STACK_SIZE              1024
#    endif
#endif

/**
 * Count the number of times each thread has been scheduled.
 */
#ifndef CONFIG_THRD_SCHEDULED
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_THRD_SCHEDULED                       0
#    else
#        define CONFIG_THRD_SCHEDULED                       1
#    endif
#endif

/**
 * Threads are allowed to terminate.
 */
#ifndef CONFIG_THRD_TERMINATE
#    if defined(CONFIG_MINIMAL_SYSTEM)
#        define CONFIG_THRD_TERMINATE                       0
#    else
#        define CONFIG_THRD_TERMINATE                       1
#    endif
#endif

/**
 * USB device vendor id.
 */
#ifndef CONFIG_USB_DEVICE_VID
#    define CONFIG_USB_DEVICE_VID                      0x2341
#endif

/**
 * USB device product id.
 */
#ifndef CONFIG_USB_DEVICE_PID
#    define CONFIG_USB_DEVICE_PID                      0x8037
#endif

/**
 * Number of colums in Emacs text editor.
 */
#ifndef CONFIG_EMACS_COLUMNS_MAX
#    define CONFIG_EMACS_COLUMNS_MAX                       80
#endif

/**
 * Number of rows in Emacs text editor.
 */
#ifndef CONFIG_EMACS_ROWS_MAX
#    define CONFIG_EMACS_ROWS_MAX                          24
#endif

/**
 * Heap size of the emacs  text editor.
 */
#ifndef CONFIG_EMACS_HEAP_SIZE
#    define CONFIG_EMACS_HEAP_SIZE                      32768
#endif

/* Configuration validation. */
#if (CONFIG_START_SHELL == 1) &&  (CONFIG_START_CONSOLE == CONFIG_START_CONSOLE_NONE)
#    error "CONFIG_START_SHELL == 1 requires CONFIG_START_CONSOLE != CONFIG_START_CONSOLE_NONE. Please change the configuration."
#endif

#endif
