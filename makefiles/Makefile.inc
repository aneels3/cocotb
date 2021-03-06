# Copyright cocotb contributors
# Licensed under the Revised BSD License, see LICENSE for details.
# SPDX-License-Identifier: BSD-3-Clause

COCOTB_CONFIG_CMD := $(shell :; command -v cocotb-config)
ifeq ($(COCOTB_CONFIG_CMD),)
    $(error 'cocotb-config not found! Cocotb is not installed (or is installed but not on the PATH). \
             Please refer to https://cocotb.readthedocs.io/en/latest/quickstart.html#installing-cocotb \
             for installation instructions.')
endif

$(error 'Deprecated cocotb file structure detected. \
         Use "include $$(shell cocotb-config --makefile)/Makefile.inc" instead. \
         Please refer to https://cocotb.readthedocs.io/en/latest/quickstart.html#creating-a-makefile \
         for instructions.')
