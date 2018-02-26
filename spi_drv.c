/*
 * spi_drv.c
 *
 *  Created on: Feb 24, 2018
 *      Author: abel
 */

#include "spi_drv.h"

void init_spi_slave(void)
{
	DDRB = 0x00;
	DDRB &= ~(1 << DDB4);

	SPCR = 0x00;
	SPCR = ((1 << SPE) | (1 << SPR1));

}

void init_spi_master(void)
{

	DDRB |= 1 << DDB5;      // SCK DDR->OUT
	DDRB &= ~(1 << DDB4);  // MISO DDR->IN
	DDRB |= 1 << DDB3;    // MOSI DDR->OUT
	DDRB |= 1 << DDB2;    // /SS DDR -> OUT

	PORTB = 0xFF;
	PORTB &= ~(1 << PB4);

	SPCR = ((1 << SPE) | (1 << MSTR) | (1 << SPR0));
}

void spi_TxByte(char byte)
{

	SPDR = byte;
	while (!(SPSR & (1 << SPIF)))
		;
}

char spi_RxByte(void)
{
	char Rx_byte;

	spi_TxByte(0);         // Send dummy byte to initialize clock

	while (!(SPSR & (1 << SPIF)))
		;

	Rx_byte = SPDR;

	return Rx_byte;

}

void write_to_mem(char addr, char data)
{

	SET_SS_PIN(LOW);
	spi_TxByte(WRITE_EN_CMD);
	SET_SS_PIN(HIGH);

	SET_SS_PIN(LOW);
	spi_TxByte(WRITE_CMD);

	spi_TxByte(addr);
	spi_TxByte(data);
	SET_SS_PIN(HIGH);

}

char read_from_mem(char addr)
{

	uint8_t Rx_data;

	SET_SS_PIN(LOW);
	spi_TxByte(READ_CMD);
	spi_TxByte(addr);
	Rx_data = spi_RxByte();
	SET_SS_PIN(HIGH);

	return Rx_data;

}

uint8_t read_status(void)
{
	char status;

	SET_SS_PIN(LOW);
	spi_TxByte(READ_STATUS);
	status = spi_RxByte();
	SET_SS_PIN(HIGH);

	return (uint8_t) status;
}

