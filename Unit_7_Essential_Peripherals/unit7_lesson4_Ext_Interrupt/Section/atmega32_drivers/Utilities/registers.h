/*
 * registers.h
 *
 * Created: 9/14/2022 10:48:40 AM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

// I/O base address
#define IO_BASE	0x20
/************************************************************************/
/* PORTA Registers                                                      */
/************************************************************************/
#define PORTA	*(volatile uint8_t *)(IO_BASE + 0x1B) // 8-bit register
#define DDRA	*(volatile uint8_t *)(IO_BASE + 0x1A)  // 8-bit register
#define PINA	*(volatile uint8_t *)(IO_BASE + 0x19)  // 8-bit register

/************************************************************************/
/* PORTB Registers                                                      */
/************************************************************************/
#define PORTB	*(volatile uint8_t *)(IO_BASE + 0x18) // 8-bit register
#define DDRB	*(volatile uint8_t *)(IO_BASE + 0x17)  // 8-bit register
#define PINB	*(volatile uint8_t *)(IO_BASE + 0x16)  // 8-bit register

// PORTC Registers
#define PORTC	*(volatile uint8_t *)(IO_BASE + 0x15) // 8-bit register
#define DDRC	*(volatile uint8_t *)(IO_BASE + 0x14)  // 8-bit register
#define PINC	*(volatile uint8_t *)(IO_BASE + 0x13)  // 8-bit register

/************************************************************************/
/* PORTD Registers                                                     */
/************************************************************************/
#define PORTD	*(volatile uint8_t *)(IO_BASE + 0x12) // 8-bit register
#define DDRD	*(volatile uint8_t *)(IO_BASE + 0x11)  // 8-bit register
#define PIND	*(volatile uint8_t *)(IO_BASE + 0x10)  // 8-bit register

/************************************************************************/
/* Timer 0 Registers                                                    */
/************************************************************************/
#define TCNT0	*(volatile uint8_t *)(0x52) // 8-bit register
#define TCCR0	*(volatile uint8_t *)(0x53) // 8-bit register
#define TIFR	*(volatile uint8_t *)(0x58)  // 8-bit register

/************************************************************************/
/* External Interrupts registers                                        */
/************************************************************************/
#define MCUCR	*(volatile uint8_t *)(IO_BASE + 0x35)  // 8-bit register
#define MCUCSR	*(volatile uint8_t *)(IO_BASE + 0x34) // 8-bit register
#define GIFR	*(volatile uint8_t *)(IO_BASE + 0x3A)   // 8-bit register
#define GICR	*(volatile uint8_t *)(IO_BASE + 0x3B)   // 8-bit register
#endif /* REGISTERS_H_ */