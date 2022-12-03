/*startup.c for CortexM3
Eng.Ali Taima*/
#include <stdint.h>
#define STACK_Start_SP 0x20001000
// I tell the compiler that it define in another file

extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;
extern int main(void);
void Reset_Handler(void);
void Default_Handler()
{
	Reset_Handler;
}
void NMI_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void H_fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;

// booking 1024 bytes located by .bss through un-initialized array of int with 256 elements (256 * 4 = 1024)
static unsigned long Stack_top[256];


void (* const g_p_fn_Vectors[])()__attribute__((section(".vectors"))) =
{
	(void (*)()) ((unsigned long) Stack_top + sizeof(Stack_top)),
	&Reset_Handler, 
	&NMI_Handler, 
	&H_fault_Handler
};

void Reset_Handler(void)
{
	//copy data from ROM to RAM
	unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* P_src = (unsigned char*)&_E_text;
	unsigned char* P_dst = (unsigned char*)&_S_DATA;
	int i;
	for(i = 0; i<DATA_size; i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}
	// init the .bss with zero
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char*)&_S_bss;
	for(i = 0; i<bss_size ;i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0;
	}
	// jump to main
	main();
}