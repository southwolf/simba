#
# @section License
#
# The MIT License (MIT)
# 
# Copyright (c) 2014-2016, Erik Moqvist
# 
# Permission is hereby granted, free of charge, to any person
# obtaining a copy of this software and associated documentation
# files (the "Software"), to deal in the Software without
# restriction, including without limitation the rights to use, copy,
# modify, merge, publish, distribute, sublicense, and/or sell copies
# of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
# BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
# ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
# This file is part of the Simba project.
#

NAME = wifi_esp_suite

ifneq ($(SSID),)
CDEFS += SSID=$(SSID)
endif

ifneq ($(PASSWORD),)
CDEFS += PASSWORD=$(PASSWORD)
endif

ifneq ($(ESP8266_IP),)
CDEFS += ESP8266_IP=$(ESP8266_IP)
endif

ifeq ($(BOARD), nano32)
RUN_PY = run_esp32.py
else
RUN_PY = run_esp.py
endif

CDEFS += CONFIG_MINIMAL_SYSTEM=1 \
	CONFIG_FS_CMD_FS_COUNTERS_LIST=1 \
	CONFIG_FS_CMD_NETWORK_INTERFACE_LIST=1 \
	CONFIG_FS_CMD_ESP_WIFI_STATUS=1
TIMEOUT ?= 100
SIMBA_ROOT ?= ../../../..
include $(SIMBA_ROOT)/make/app.mk
