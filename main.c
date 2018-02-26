/*
 * main.c
 *
 *  Created on: Feb 24, 2018
 *      Author: abel
 */

#include "usart.h"
#include "spi_drv.h"
#include "mod_timer.h"
#include "main.h"

//static uint8_t rx_data;

void eeprom_write(uint8_t start_addr, uint8_t *data_ptr, uint8_t size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		write_to_mem(start_addr + i, (*(data_ptr + i)));
		while ((uint8_t) 0 != (read_status()))
			;

	}
}

void eeprom_read(uint8_t start_addr, uint8_t *data_ptr, uint8_t size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		*(data_ptr + i) = read_from_mem(start_addr + i);

	}
}

int main()
{
	sei();
	DDRC |= 1 << DDC5;  // Set Pin PC5 as Output
	PORTC |= 1 << PC5;  // Enable internal pull-up resistor PC5

	OCR1A = 31250;      // Corresponds to foc=1Hz;

	uint8_t *rom_ptr;
	rom_ptr = &rom_contents[0];

	timer_init();

	usart_init(BAUD_VAL);

	init_spi_master();

	eeprom_write(0x00, rom_ptr, ROM_SIZE);

	eeprom_read(0x00, &(Rx_rom_buff[0]), ROM_SIZE);

	for (int j = 0; j < ROM_SIZE; j++)
	{
		USART_Tx_byte((char) Rx_rom_buff[j]);
	}

	while (1)
	{
	}

	return 0;
}

ISR(TIMER1_COMPA_vect)
{

	PORTC ^= 1 << PC5; // Timepass
}

