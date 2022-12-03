#@copyright: Ali Taima
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -mthumb -gdwarf-2 -g  #release all debug information
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o) #same as OBJS = $(patsubst$.c, $.o, $SRC)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name=unit3_lab4_cortexM4

all: $(Project_name).bin
	@echo "----------Build is Done------------"
%.o: %.s
	$(CC)as.exe $(CFLAGS) $<  -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf # as uvision use this extension

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clear_all:
	rm *.o *.elf *.bin

clear:
	rm *.elf *.bin
