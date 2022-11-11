#@copyright: Ali Taima
learn-in-depth.bin: uart.c app.c startup.s
	arm-none-eabi-as.exe -mcpu=arm926ej-s startup.s -g -o startup.o
	arm-none-eabi-gcc.exe -c -g -I . -mcpu=arm926ej-s app.c -o app.o
	arm-none-eabi-gcc.exe -c -g -I . -mcpu=arm926ej-s uart.c -o uart.o
	arm-none-eabi-ld.exe -T linker_script.ld startup.o app.o uart.o -o learn-in-depth.elf
	arm-none-eabi-objcopy.exe -O binary learn-in-depth.elf learn-in-depth.bin
 	