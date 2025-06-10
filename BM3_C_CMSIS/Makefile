# Toolchain settings
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m7 -mthumb -std=gnu11
CFLAGS += -DSTM32F767xx
CFLAGS += -ISTM32CubeF7/Drivers/CMSIS/Include/
CFLAGS += -ISTM32CubeF7/Drivers/CMSIS/Device/ST/STM32F7xx/cmsis-device-f7/Include/
CFLAGS += -ISTM32CubeF7/Drivers/STM32F7xx_HAL_Driver/Inc/


# Files
TARGET = BM3_C_CMSIS.elf
MAP = BM3_C_CMSIS.map
LD_SCRIPT = stm32_ls.ld
OBJS = main.o stm32f767_startup.o

# Build target
all: $(TARGET)

# Object files
main.o: main.c
	$(CC) -c $(CFLAGS) main.c -o main.o

stm32f767_startup.o: stm32_startup.c
	$(CC) -c $(CFLAGS) stm32_startup.c -o stm32f767_startup.o

# ELF build
$(TARGET): $(OBJS)
	$(CC) -nostdlib -T $(LD_SCRIPT) $(OBJS) -o $(TARGET) -Wl,-Map=$(MAP)

# Flashing with OpenOCD
load:
	openocd -f interface/stlink.cfg -f target/stm32f7x.cfg -c "program $(TARGET) verify reset exit"

# Clean up
clean:
	rm -f *.o *.elf *.map