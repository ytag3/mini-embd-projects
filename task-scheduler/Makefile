CC=arm-none-eabi-gcc
MACH=cortex-m4
OPT_LEV=0

CFLAGS= -c -mcpu=$(MACH) -std=gnu11 -mthumb -O0$(OPT_LEV) -Wall
#LDFLAGS= --specs=nano.specs -T stm32_ls.ld -Wl,-Map=final.map -mfloat-abi=soft -mthumb -mcpu=$(MACH)
LDFLAGS_SEMI = --specs=rdimon.specs -T stm32_ls.ld -Wl,-Map=final.map -mfloat-abi=soft -mthumb -mcpu=$(MACH)

all: main.o stm32_startup.o syscalls.o final.elf led.o

semi: main.o stm32_startup.o final_SH.elf led.o

main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@

led.o: led.c
	$(CC) $(CFLAGS) $^ -o $@

stm32_startup.o : stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

syscalls.o : syscalls.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf: main.o stm32_startup.o syscalls.o led.o
	$(CC) $(LDFLAGS) -o $@ $^

final_SH.elf: main.o stm32_startup.o led.o
	$(CC) $(LDFLAGS_SEMI) -o $@ $^

clean:
	rm -rf *.o *.elf *.map

load:
	openocd -f board/stm32f4discovery.cfg
