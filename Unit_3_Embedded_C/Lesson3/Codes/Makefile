#@copyright: Ali Taima
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I .
LIBS=
all: learn-in-depth.bin
	@echo "----------Build is Done------------"
startup.o: startup.s
	$(CC)as.exe $(CFLAGS) startup.s  -o startup.o

app.o: app.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) app.c -o app.o

uart.o: uart.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) uart.c -o uart.o

learn-in-depth.elf: startup.o app.o uart.o
	$(CC)ld.exe -T linker_script.ld $(LIBS) startup.o app.o uart.o -o learn-in-depth.elf

learn-in-depth.bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary learn-in-depth.elf learn-in-depth.bin

clear_all:
	rm *.o *.elf *.bin

clear:
	rm *.elf *.bin
