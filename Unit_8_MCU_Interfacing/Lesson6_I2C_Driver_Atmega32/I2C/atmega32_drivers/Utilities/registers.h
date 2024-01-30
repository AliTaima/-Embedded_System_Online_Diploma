/*
 * registers.h
 *
 * Created: 9/14/2022 10:48:40 AM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

/************************************************************************/
/* define helpful macros                                               */
/************************************************************************/
// set pin macro(make PIN_NO = 1)
#define SET_PIN(reg, PIN_NO) reg |= (1 << PIN_NO)
// clear pin macro(make PIN_NO = 0)
#define CLR_PIN(reg, PIN_NO) reg &= ~(1 << PIN_NO)
// toggle pin macro(make PIN_NO = 0 then PIN_NO = 1 and so on...)
#define TOGGLE_PIN(reg, PIN_NO) reg ^= (1 << PIN_NO)
// get status of the pin(read pin) to see it high or low( reg--> the PIN_name)for example(PINA, PIN4)
#define READ_PIN(reg, PIN_NO) (reg & (1 << PIN_NO)) >> PIN_NO

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
#define TCNT0	*(volatile uint8_t *)(IO_BASE + 0x32) // 8-bit register
#define TCCR0	*(volatile uint8_t *)(IO_BASE + 0x33) // 8-bit register
#define TIFR	*(volatile uint8_t *)(IO_BASE + 0x38)  // 8-bit register

/************************************************************************/
/* External Interrupts registers                                        */
/************************************************************************/
#define MCUCR	*(volatile uint8_t *)(IO_BASE + 0x35)  // 8-bit register
#define MCUCSR	*(volatile uint8_t *)(IO_BASE + 0x34) // 8-bit register
#define GIFR	*(volatile uint8_t *)(IO_BASE + 0x3A)   // 8-bit register
#define GICR	*(volatile uint8_t *)(IO_BASE + 0x3B)   // 8-bit register

/************************************************************************/
/*					UART Registers                                      */
/************************************************************************/
//UCSRC and UBRRH have the same address but we can control them by another pin
#define UDR		*(volatile uint8_t *)(IO_BASE + 0x0C)
#define UCSRA	*(volatile uint8_t *)(IO_BASE + 0x0B)
#define UCSRB	*(volatile uint8_t *)(IO_BASE + 0x0A)
#define UCSRC	*(volatile uint8_t *)(IO_BASE + 0x20)
#define UBRRL	*(volatile uint8_t *)(IO_BASE + 0x09)
#define UBRRH	*(volatile uint8_t *)(IO_BASE + 0x20)

/************************************************************************/
/*					SPI Registers                                       */
/************************************************************************/
#define SPCR	*(volatile uint8_t *)(IO_BASE + 0x0D)
#define SPSR	*(volatile uint8_t *)(IO_BASE + 0x0E)
#define SPDR	*(volatile uint8_t *)(IO_BASE + 0x0F)

/************************************************************************/
/*					I2C(TWI) Registers                                  */
/************************************************************************/
#define TWBR	*(volatile uint8_t *)(IO_BASE + 0x00)
#define TWSR	*(volatile uint8_t *)(IO_BASE + 0x01)
#define TWAR	*(volatile uint8_t *)(IO_BASE + 0x02)
#define TWDR	*(volatile uint8_t *)(IO_BASE + 0x03)
#define TWCR	*(volatile uint8_t *)(IO_BASE + 0x36)



/* Bit numbers */
/*-----SPI--------*/
//SPCR reg
#define SPR0	0
#define SPR1	1
#define CPHA	2
#define CPOL	3
#define MSTR	4
#define DORC	5
#define SPE		6
#define SPIE	7

//SPSR reg
#define SPI2X	0
#define WCOL	6
#define SPIF	7
/*-----I2C--------*/
//TWBR reg
#define TWBR0	0
#define TWBR1	1
#define TWBR2	2
#define TWBR3	3
#define TWBR4	4
#define TWBR5	5
#define TWBR6	6
#define TWBR7	7
//TWCR reg
#define TWIE	0
#define TWEN	2
#define TWWC	3
#define TWSTO	4
#define TWSTA	5
#define TWEA	6
#define TWINT	7
//TWSR reg
#define TWPS0	0
#define TWPS1	1
#define TWS0	3
#define TWS1	4
#define TWS2	5
#define TWS3	6
#define TWS4	7
//TWDR reg
#define TWD0	0
#define TWD1	1
#define TWD2	2
#define TWD3	3
#define TWD4	4
#define TWD5	5
#define TWD6	6
#define TWD7	7
//TWAR reg
#define TWGCE	0
#define TWA0	1
#define TWA1	2
#define TWA2	3
#define TWA3	4
#define TWA4	5
#define TWA5	6
#define TWA6	7
#endif /* REGISTERS_H_ */