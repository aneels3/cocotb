ifeq ($(SIM),)
all:
	@echo "Skipping example mixed_language since Icarus doesn't support this"
clean::
else ifeq ($(shell echo $(SIM) | tr A-Z a-z),icarus)
all:
	@echo "Skipping example mixed_language since Icarus doesn't support this"
clean::
else

# Override this variable to use a VHDL toplevel instead of SystemVerilog
TOPLEVEL_LANG ?= verilog

TOPLEVEL = endian_swapper_mixed

PWD=$(shell pwd)

VERILOG_SOURCES = $(PWD)/../../endian_swapper/hdl/endian_swapper.sv
VHDL_SOURCES    = $(PWD)/../../endian_swapper/hdl/endian_swapper.vhdl

ifeq ($(TOPLEVEL_LANG),verilog)
    VERILOG_SOURCES += $(PWD)/../hdl/toplevel.sv
else ifeq ($(TOPLEVEL_LANG),vhdl)
    $(error "VHDL toplevel not yet implemented")
    VHDL_SOURCES += $(PWD)/../hdl/toplevel.vhdl
else
    $(error "A valid value (verilog or vhdl) was not provided for TOPLEVEL_LANG=$(TOPLEVEL_LANG)")
endif


MODULE=test_mixed_language

ifneq ($(filter $(SIM),ius xcelium),)
    SIM_ARGS += -v93
endif

include $(shell cocotb-config --makefiles)/Makefile.inc
include $(shell cocotb-config --makefiles)/Makefile.sim

endif
