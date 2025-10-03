# Application module build
SRC_DIR := src
OBJ_DIR  = ../../../build/obj

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

INCLUDES =\
-Iinc\
-I../../fw/inc\
-I../../fw/inc/stm32f334r8\
-I../../../inc/generic/\
-I../../../inc/autosar/\

# Microcontroller Processor Architecture:
MACH = cortex-m4
#Flags
WARNS = -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -Wno-unused-parameter -Wno-missing-field-initializers -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu++17 -g
# Compiler variables:
CC = arm-none-eabi-g++

all: $(OBJECTS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	@echo "Building module...!"
	$(CC) $(CFLAGS) $(WARNS) $(INCLUDES) $< -o $@

.PHONY: all