#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST
TARGET = c1m2

ifeq ($(PLATFORM),MSP432)
	
	# Architectures Specific Flags

	LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs

        # Compiler Flags and Defines
	
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl -Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGES = -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard  --specs=$(SPECS) -mfpu=fpv4-sp-d16  -Wall -g -O0 -std=c99
	CPPFLAGS = -DMSP432 
else
	CC = x86_64-linux-gnu-gcc
	LD = x86_64-linux-gnu-ld
	CFLAGS = -Wall -g -O0 -std=c99
	CPPFLAGS = -DHOST

endif

OBJS = $(SOURCES:.c=.o)
	
DEPS = $(SOURCES:.c=.d)

-include DEPS

DEPSFLAGS = -MMD -MF $(@:.o=.d)

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(DEPSFLAGS) -o $@

%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

%.asm : %.c
	$(CC) -S $< -o $@

.PHONY: compile-all
compile all: $(SOURCES)
	$(CC) -c $< $(CFLAGS) -o $(OBJS)

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(DEPFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map *.o *.asm *.i




