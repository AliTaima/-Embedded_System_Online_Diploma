#@copyright: Ali Taima
CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o) #same as OBJS = $(patsubst$.c, $.o, $SRC)

all: learn-in-depth.bin
	@echo "----------Build is Done------------"
startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $<  -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

learn-in-depth.elf: $(OBJ) startup.o
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) startup.o -o $@

learn-in-depth.bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary $< $@

clear_all:
	rm *.o *.elf *.bin

clear:
	rm *.elf *.bin
