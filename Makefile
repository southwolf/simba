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

.PHONY: tags doc

SIMBA_VERSION ?= $(shell cat VERSION.txt)

BOARD ?= linux

ifeq ($(BOARD), linux)
    TESTS = $(addprefix tst/kernel/, sys \
                                     thrd \
                                     time \
                                     timer)
    TESTS += $(addprefix tst/sync/, bus \
                                    chan \
                                    event \
                                    queue \
                                    rwlock \
                                    sem)
    TESTS += $(addprefix tst/collections/, binary_tree \
                                           bits \
                                           fifo \
                                           hash_map)
    TESTS += $(addprefix tst/alloc/, circular_heap \
                                     heap)
    TESTS += $(addprefix tst/text/, configfile \
				    std \
                                    re)
    TESTS += $(addprefix tst/debug/, log)
    TESTS += $(addprefix tst/oam/, service \
				   settings \
				   shell)
    TESTS += $(addprefix tst/filesystems/, fat16 \
				          fs \
                                          spiffs)
    TESTS += $(addprefix tst/encode/, base64 \
                                      json)
    TESTS += $(addprefix tst/hash/, crc \
                                    sha1)
    TESTS += $(addprefix tst/inet/, http_server \
				    http_websocket_client \
				    http_websocket_server \
				    inet \
				    mqtt_client \
				    ping)
    TESTS += $(addprefix tst/multimedia/, midi)
endif

ifeq ($(BOARD), arduino_due)
    TESTS = $(addprefix tst/kernel/, sys \
                                     thrd \
                                     time \
                                     timer)
    TESTS += $(addprefix tst/sync/, bus \
                                    event \
                                    queue \
                                    rwlock \
                                    sem)
    TESTS += $(addprefix tst/collections/, binary_tree \
                                           bits \
                                           fifo \
                                           hash_map)
    TESTS += $(addprefix tst/alloc/, circular_heap \
                                     heap)
    TESTS += $(addprefix tst/text/, configfile \
				    std \
                                    re)
    TESTS += $(addprefix tst/debug/, log)
    TESTS += $(addprefix tst/oam/, settings \
	        		   shell)
    TESTS += $(addprefix tst/filesystems/, fs \
					  spiffs)
    TESTS += $(addprefix tst/encode/, base64 \
                                      json)
    TESTS += $(addprefix tst/hash/, crc \
                                    sha1)
    TESTS += $(addprefix tst/inet/, http_server \
				    http_websocket_client \
				    http_websocket_server \
				    inet \
				    mqtt_client \
				    ping)
    TESTS += $(addprefix tst/drivers/, chipid \
				       can \
				       flash \
				       pin)
endif

ifeq ($(BOARD), arduino_mega)
    TESTS = $(addprefix tst/kernel/, sys \
                                     thrd \
                                     time \
                                     timer)
    TESTS += $(addprefix tst/sync/, bus \
                                    event \
                                    queue \
                                    rwlock \
                                    sem)
    TESTS += $(addprefix tst/collections/, binary_tree \
                                           bits \
                                           fifo \
                                           hash_map)
    TESTS += $(addprefix tst/alloc/, circular_heap \
                                     heap)
    TESTS += $(addprefix tst/text/, configfile \
				    std \
                                    re)
    TESTS += $(addprefix tst/debug/, log)
    TESTS += $(addprefix tst/oam/, settings \
	        		   shell)
    TESTS += $(addprefix tst/filesystems/, fat16 \
					  fs)
    TESTS += $(addprefix tst/encode/, base64)
    TESTS += $(addprefix tst/hash/, crc \
                                    sha1)
    TESTS += $(addprefix tst/inet/, http_websocket_client \
				    http_websocket_server \
				    inet \
				    mqtt_client \
				    ping)
    TESTS += $(addprefix tst/drivers/, adc \
				       analog_input_pin \
				       ds3231 \
				       sd \
				       pin)
endif

ifeq ($(BOARD), arduino_nano)
    TESTS = $(addprefix tst/drivers/, ds18b20 \
				      analog_output_pin \
				      exti \
				      owi)
endif

ifeq ($(BOARD), arduino_pro_micro)
    TESTS = $(addprefix tst/kernel/, sys \
                                     thrd \
                                     timer)
endif

ifeq ($(BOARD), esp01)
    TESTS = $(addprefix tst/kernel/, sys \
                                     thrd \
                                     timer)
endif

ifeq ($(BOARD), esp12e)
    TESTS = $(addprefix tst/kernel/, sys \
                                     thrd \
                                     timer)
    TESTS += $(addprefix tst/sync/, bus \
                                    event \
                                    queue \
                                    rwlock \
                                    sem)
    TESTS += $(addprefix tst/collections/, binary_tree \
                                           bits \
                                           fifo \
                                           hash_map)
    TESTS += $(addprefix tst/alloc/, circular_heap)
    TESTS += $(addprefix tst/text/, std \
                                    re)
    TESTS += $(addprefix tst/debug/, log)
    TESTS += $(addprefix tst/oam/, shell)
    TESTS += $(addprefix tst/encode/, base64 \
                                      json)
    TESTS += $(addprefix tst/hash/, crc \
                                    sha1)
    TESTS += $(addprefix tst/inet/, http_websocket_client \
				    http_websocket_server \
				    inet \
				    mqtt_client \
				    network_interface/wifi_esp \
				    ping)
    TESTS += $(addprefix tst/drivers/, pin)
    TESTS += $(addprefix tst/filesystems/, fs \
                                           spiffs)
endif

ifeq ($(BOARD), nano32)
    TESTS = $(addprefix tst/kernel/, sys \
                                     thrd \
                                     timer)
    TESTS += $(addprefix tst/sync/, bus \
                                    event \
                                    queue \
                                    rwlock \
                                    sem)
    TESTS += $(addprefix tst/collections/, binary_tree \
                                           bits \
                                           fifo \
                                           hash_map)
    TESTS += $(addprefix tst/alloc/, circular_heap)
    TESTS += $(addprefix tst/text/, std \
                                    re)
    TESTS += $(addprefix tst/debug/, log)
    TESTS += $(addprefix tst/oam/, shell)
    TESTS += $(addprefix tst/encode/, base64 \
                                      json)
    TESTS += $(addprefix tst/hash/, crc \
                                    sha1)
    TESTS += $(addprefix tst/inet/, http_websocket_client \
				    http_websocket_server \
				    inet \
				    network_interface/wifi_esp \
				    ping)
    TESTS += $(addprefix tst/filesystems/, fs \
                                           spiffs)
endif

ifeq ($(BOARD), stm32vldiscovery)
    TESTS = $(addprefix tst/kernel/, sys \
                                     thrd \
                                     timer)
    TESTS += $(addprefix tst/sync/, bus \
                                    event \
                                    queue \
                                    rwlock \
                                    sem)
    TESTS += $(addprefix tst/collections/, binary_tree \
                                           bits \
                                           fifo \
                                           hash_map)
    TESTS += $(addprefix tst/alloc/, circular_heap)
    TESTS += $(addprefix tst/text/, std \
                                    re)
    TESTS += $(addprefix tst/debug/, log)
    TESTS += $(addprefix tst/oam/, shell)
    TESTS += $(addprefix tst/encode/, base64 \
                                      json)
    TESTS += $(addprefix tst/hash/, crc \
                                    sha1)
    TESTS += $(addprefix tst/inet/, http_websocket_client \
				    http_websocket_server \
				    inet \
				    mqtt_client \
				    ping)
    TESTS += $(addprefix tst/drivers/, pin)
endif

ifeq ($(BOARD), photon)
    TESTS = $(addprefix tst/kernel/, sys \
                                     thrd \
				     time \
                                     timer)
    TESTS += $(addprefix tst/sync/, bus \
                                    event \
                                    queue \
                                    rwlock \
                                    sem)
    TESTS += $(addprefix tst/collections/, binary_tree \
                                           bits \
                                           fifo \
                                           hash_map)
    TESTS += $(addprefix tst/alloc/, circular_heap)
    TESTS += $(addprefix tst/text/, std \
                                    re)
    TESTS += $(addprefix tst/debug/, log)
    TESTS += $(addprefix tst/oam/, shell)
    TESTS += $(addprefix tst/encode/, base64 \
                                      json)
    TESTS += $(addprefix tst/hash/, crc \
                                    sha1)
    TESTS += $(addprefix tst/inet/, http_websocket_client \
				    http_websocket_server \
				    inet \
				    mqtt_client \
				    ping)
endif

# List of all application to build
APPS += $(TESTS)

all: $(APPS:%=%.all)

clean: $(APPS:%=%.clean)

rerun:
	for test in $(TESTS) ; do \
	    $(MAKE) -C $$test run || exit 1 ; \
	done

# Depend on 'all' to build all applications (optinally with -j) before
# uploading and running them one at a time.
run: all
	for test in $(TESTS) ; do \
	    if [ ! -e $$test/.$(BOARD).passed ] ; then \
	        $(MAKE) -C $$test run || exit 1 ; \
	        touch $$test/.$(BOARD).passed ; \
	    else \
	        echo ; \
	        echo "$$test already passed." ; \
	        echo ; \
	    fi \
	done

size: $(TESTS:%=%.size)

report:
	for test in $(TESTS) ; do \
	    $(MAKE) -C $(basename $$test) report ; \
	    echo ; \
	done

test: run
	$(MAKE) report

coverage: $(TESTS:%=%.cov)
	lcov $(TESTS:%=-a %/coverage.info) -o coverage.info
	genhtml coverage.info
	@echo
	@echo "Run 'firefox index.html' to open the coverage report in a web browser."
	@echo

codecov-coverage: $(TESTS:%=%.ccc)

jenkins-coverage: $(TESTS:%=%.jc)

travis:
	$(MAKE) cloc
	$(MAKE) pmccabe
	$(MAKE) test

release-test:
	+bin/release.py --test --version $(SIMBA_VERSION)

release:
	+bin/release.py --package --version $(SIMBA_VERSION)

clean-arduino-due:
	$(MAKE) BOARD=arduino_due SERIAL_PORT=/dev/simba-arduino_due clean

clean-arduino-mega:
	$(MAKE) BOARD=arduino_mega SERIAL_PORT=/dev/simba-arduino_mega clean

clean-arduino-nano:
	$(MAKE) BOARD=arduino_nano SERIAL_PORT=/dev/simba-arduino_nano clean

clean-arduino-pro-micro:
	$(MAKE) BOARD=arduino_pro_micro SERIAL_PORT=/dev/simba-arduino_pro_micro clean

clean-esp01:
	$(MAKE) BOARD=esp01 SERIAL_PORT=/dev/simba-esp01 clean

clean-esp12e:
	$(MAKE) BOARD=esp12e SERIAL_PORT=/dev/simba-esp12e clean

clean-nano32:
	$(MAKE) BOARD=nano32 SERIAL_PORT=/dev/simba-nano32 clean

clean-stm32vldiscovery:
	$(MAKE) BOARD=stm32vldiscovery SERIAL_PORT=/dev/simba-stm32vldiscovery clean

clean-photon:
	$(MAKE) BOARD=photon SERIAL_PORT=/dev/simba-photon clean

test-arduino-due:
	@echo "Arduino Due"
	$(MAKE) BOARD=arduino_due SERIAL_PORT=/dev/simba-arduino_due test

test-arduino-mega:
	@echo "Arduino Mega"
	$(MAKE) BOARD=arduino_mega SERIAL_PORT=/dev/simba-arduino_mega test

test-arduino-nano:
	@echo "Arduino Nano"
	$(MAKE) BOARD=arduino_nano SERIAL_PORT=/dev/simba-arduino_nano test

test-arduino-pro-micro:
	@echo "Arduino Pro Micro"
	$(MAKE) BOARD=arduino_pro_micro SERIAL_PORT=/dev/simba-arduino_pro_micro test

test-esp01:
	@echo "ESP-01"
	$(MAKE) BOARD=esp01 SERIAL_PORT=/dev/simba-esp01 test

test-esp12e:
	@echo "ESP12-E"
	$(MAKE) BOARD=esp12e SERIAL_PORT=/dev/simba-esp12e test

test-nano32:
	@echo "Nano32"
	$(MAKE) BOARD=nano32 SERIAL_PORT=/dev/simba-nano32 test

test-stm32vldiscovery:
	@echo "STM32VLDISCOVERY"
	$(MAKE) BOARD=stm32vldiscovery SERIAL_PORT=/dev/simba-stm32vldiscovery test

test-photon:
	@echo "Photon"
	$(MAKE) BOARD=photon SERIAL_PORT=/dev/simba-photon test

clean-arduino-due-platformio:
	@echo "Arduino Due"
	$(MAKE) -C examples/platformio BOARD=arduino_due SERIAL_PORT=/dev/simba-arduino_due clean

clean-arduino-mega-platformio:
	@echo "Arduino Mega"
	$(MAKE) -C examples/platformio BOARD=arduino_mega SERIAL_PORT=/dev/simba-arduino_mega clean

clean-esp12e-platformio:
	@echo "ESP12-E"
	$(MAKE) -C examples/platformio BOARD=esp12e SERIAL_PORT=/dev/simba-esp12e clean

test-arduino-due-platformio:
	@echo "Arduino Due"
	$(MAKE) -C examples/platformio BOARD=arduino_due SERIAL_PORT=/dev/simba-arduino_due test

test-arduino-mega-platformio:
	@echo "Arduino Mega"
	$(MAKE) -C examples/platformio BOARD=arduino_mega SERIAL_PORT=/dev/simba-arduino_mega test

test-esp12e-platformio:
	@echo "ESP12-E"
	$(MAKE) -C examples/platformio BOARD=esp12e SERIAL_PORT=/dev/simba-esp12e test-prompt-after-upload

test-i2c-nano-mega:
	@echo "I2C Nano Mega"
	$(MAKE) -C tst/drivers/i2c/slave BOARD=arduino_nano SERIAL_PORT=/dev/simba-arduino_nano upload
	$(MAKE) -C tst/drivers/i2c/master_soft BOARD=arduino_mega SERIAL_PORT=/dev/simba-arduino_mega run

clean-i2c-nano-mega:
	@echo "I2C Nano Mega"
	$(MAKE) -C tst/drivers/i2c/slave BOARD=arduino_nano clean
	$(MAKE) -C tst/drivers/i2c/master_soft BOARD=arduino_mega clean

test-all-boards:
	$(MAKE) test-arduino-due
	$(MAKE) test-arduino-mega
	$(MAKE) test-arduino-nano
	$(MAKE) test-arduino-pro-micro
	$(MAKE) test-esp01
	$(MAKE) test-esp12e
	$(MAKE) test-nano32
	$(MAKE) test-photon
	$(MAKE) test-arduino-due-platformio
	$(MAKE) test-arduino-mega-platformio
	$(MAKE) test-esp12e-platformio
	$(MAKE) test-i2c-nano-mega

clean-all-boards:
	$(MAKE) clean-arduino-due
	$(MAKE) clean-arduino-mega
	$(MAKE) clean-arduino-nano
	$(MAKE) clean-arduino-pro-micro
	$(MAKE) clean-esp01
	$(MAKE) clean-esp12e
	$(MAKE) clean-nano32
	$(MAKE) clean-photon
	$(MAKE) clean-arduino-due-platformio
	$(MAKE) clean-arduino-mega-platformio
	$(MAKE) clean-esp12e-platformio
	$(MAKE) clean-i2c-nano-mega

doc:
	+bin/dbgen.py > database.json
	+bin/docgen.py database.json
	$(MAKE) -s -C doc

arduino:
	+make/arduino/arduino.py --remove-outdir --version $(SIMBA_VERSION)

platformio:
	+make/platformio/platformio.py --version $(SIMBA_VERSION)

$(APPS:%=%.all):
	$(MAKE) -C $(basename $@) all

$(APPS:%=%.clean):
	$(MAKE) -C $(basename $@) clean
	rm -f $(basename $@)/.$(BOARD).passed

$(APPS:%=%.size):
	$(MAKE) -C $(basename $@) size

$(TESTS:%=%.report):
	$(MAKE) -C $(basename $@) report

$(TESTS:%=%.cov):
	$(MAKE) -C $(basename $@) coverage

$(TESTS:%=%.ccc):
	$(MAKE) -C $(basename $@) codecov-coverage

$(TESTS:%=%.jc):
	$(MAKE) -C $(basename $@) jenkins-coverage

tags:
	echo "Creating tags file .TAGS"
	etags -o .TAGS --declarations $$(git ls-files *.[hci] | xargs) \
	$$(find 3pp/mbedtls -name "*.[hc]" -o -name "*.cpp" | xargs)

cloc:
	cloc $$(git ls-files | grep -v 3pp | xargs)

pmccabe:
	pmccabe $$(git ls-files "src/*.[hic]") | sort -n

print-%:
	@echo $($*)

help:
	@echo "--------------------------------------------------------------------------------"
	@echo "  target                      description"
	@echo "--------------------------------------------------------------------------------"
	@echo "  all                         compile and link the application"
	@echo "  clean                       remove all generated files and folders"
	@echo "  run                         run the application"
	@echo "  report                      print test report"
	@echo "  test                        run + report"
	@echo "  size                        print executable size information"
	@echo "  cloc                        print source code line statistics"
	@echo "  pmccabe                     print source code complexity statistics"
	@echo "  doc                         Generate the documentation."
	@echo "  help                        show this help"
	@echo
