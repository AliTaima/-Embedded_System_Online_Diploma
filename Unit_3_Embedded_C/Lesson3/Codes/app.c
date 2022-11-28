#include "uart.h"

unsigned char string_buffer[100] = "Learn-in-depth:<AliTaima>";
unsigned char const string_buffer2[100] = "to create a rodate section";
unsigned char const string_buffer3[100] = "to create a rodate section";
void main(void)
{
	// Send on physical board
	Uart_Send_String(string_buffer);
}