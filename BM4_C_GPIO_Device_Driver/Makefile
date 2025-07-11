# Toolchain
CC = arm-none-eabi-gcc

# Flags
CFLAGS = -mcpu=cortex-m7 -mthumb -std=gnu11
CFLAGS += -DSTM32F767xx
CFLAGS += -ISTM32CubeF7/Drivers/CMSIS/Include/
CFLAGS += -ISTM32CubeF7/Drivers/CMSIS/Device/ST/STM32F7xx/cmsis-device-f7/Include/
CFLAGS += -ISTM32CubeF7/Drivers/STM32F7xx_HAL_Driver/Inc/
CFLAGS += -IInc/

# Files
TARGET = BM3_C_CMSIS.elf
MAP = BM3_C_CMSIS.map
LD_SCRIPT = stm32_ls.ld

# All C source files (you can exclude startup file here if needed)
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Build ELF file
$(TARGET): $(OBJS)
	$(CC) -nostdlib -T $(LD_SCRIPT) $(OBJS) -o $@ -Wl,-Map=$(MAP)

# Pattern rule for compiling .c to .o
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Flash target (using OpenOCD)
load:
	openocd -f interface/stlink.cfg -f target/stm32f7x.cfg -c "program $(TARGET) verify reset exit"

# Clean target
clean:
	rm -f *.o *.elf *.map
