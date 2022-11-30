/*startup.c for CortexM3
Eng.Ali Taima*/
#include <stdint.h>
#define STACK_Start_SP 0x20001000
// I tell the compiler that it define in another file
extern int main(void);
void Reset_Handler(void)
{
	main();
}
void NMI_Handler(void)
{
	Reset_Handler();
}
void H_fault_Handler(void)
{
	Reset_Handler();
}
void NM_Fault_Handler(void)
{
	Reset_Handler();
}
void Bus_Fault_Handler(void)
{
	Reset_Handler();
}
void Usage_Fault_Handler(void)
{
	Reset_Handler();
}
uint32_t vectors[] __attribute__((section(".vectors"))) ={
	STACK_Start_SP,
	(uint32_t) &Reset_Handler, 
	(uint32_t) &NMI_Handler, 
	(uint32_t) &H_fault_Handler, 
	(uint32_t) &NM_Fault_Handler, 
	(uint32_t) &Bus_Fault_Handler, 
	(uint32_t) &Usage_Fault_Handler, 
};