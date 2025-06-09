#final : BM2_C.elf 
#
#main.o : main.c
#	arm-none-eabi-gcc -c -mcpu=cortex-m7 -mthumb -std=gnu11 main.c -o main.o
#	
#stm32startup.o : stm32startup.c
#	arm-none-eabi-gcc -c -mcpu=cortex-m7 -mthumb -std=gnu11 stm32startup.c -o stm32startup.o
#	
#BM2_C.elf : main.o stm32startup.o
#	arm-none-eabi-gcc -nostdlib -T stm32_ls.ld *.o -o BM2_C.elf -Wl,-Map=BM2_C.map
#
#load :
#	openocd -f board/st_nucleo_f7.cfg
#clean:
#	rm -f *.o *.elf *.map

# Toolchain settings
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m7 -mthumb -std=gnu11

# Files
TARGET = BM2_C.elf
MAP = BM2_C.map
LD_SCRIPT = stm32_ls.ld
OBJS = main.o stm32_startup.o

# Build target
all: $(TARGET)

# Object files
main.o: main.c
	$(CC) -c $(CFLAGS) main.c -o main.o

stm32f767_startup.o: stm32_startup.c
	$(CC) -c $(CFLAGS) stm32_startup.c -o stm32_startup.o

# ELF build
$(TARGET): $(OBJS)
	$(CC) -nostdlib -T $(LD_SCRIPT) $(OBJS) -o $(TARGET) -Wl,-Map=$(MAP)

# Flashing with OpenOCD
load:
	openocd -f interface/stlink.cfg -f target/stm32f7x.cfg -c "program BM2_C.elf verify reset exit"

# Clean up
clean:
	rm -f *.o *.elf *.map
