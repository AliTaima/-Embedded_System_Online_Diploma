#@copyright: Ali Taima
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I .
LIBS=
all: learn-in-depth.bin
	@echo "----------Build is Done------------"
startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $<  -o $@

app.o: app.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

uart.o: uart.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

learn-in-depth.elf: startup.o app.o uart.o
	$(CC)ld.exe -T linker_script.ld $(LIBS) startup.o app.o uart.o -o $@

learn-in-depth.bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary $< $@

clear_all:
	rm *.o *.elf *.bin

clear:
	rm *.elf *.bin
