# Buils initialization system
# Microcontroller Processor Architecture:
MACH = cortex-m4
#Flags
WARNS = -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -Wno-unused-parameter -Wno-missing-field-initializers -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu++20 -g
# Compiler variables:
CC = arm-none-eabi-g++

OBJECTS = ../../build/obj

INCLUDES =\
-Iinc\
-I../../inc/generic/\
-I../../inc/autosar/\
-I../fw/inc/\
-I../fw/inc/stm32f429zi/\

MAIN_PATH = main
STUP_PATH = startup

.PHONY: all

all:
	@echo "Building System initilization code...!"
	$(CC) $(CFLAGS) $(WARNS) $(INCLUDES) $(MAIN_PATH)/main.cpp -o $(OBJECTS)/main.o
	$(CC) $(CFLAGS) $(WARNS) $(INCLUDES) $(STUP_PATH)/Stm32f429zi_Startup.cpp -o $(OBJECTS)/Stm32f429zi_Startup.o
