/*
 * main.c
 *
 *  Created on: Feb 24, 2018
 *      Author: abel
 */

#include "usart.h"
#include "spi_drv.h"

#define ROM_SIZE 10
unsigned char rom_contents[ROM_SIZE] = { 0x61, 0x62, 0x30, 0x31, 0x63, 0x64,
		0x32, 0x33, 0x65, 0x66 };

unsigned char Rx_rom_buff[ROM_SIZE] = { 0 };

//static uint8_t rx_data;

void eeprom_read(uint8_t start_addr, uint8_t *data_ptr, uint8_t size);
void eeprom_write(uint8_t start_addr, uint8_t *data_ptr, uint8_t size);

void eeprom_write(uint8_t start_addr, uint8_t *data_ptr, uint8_t size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		write_to_mem(start_addr + i, (*(data_ptr + i)));
		_delay_us(2000);

	}
}

void eeprom_read(uint8_t start_addr, uint8_t *data_ptr, uint8_t size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		*(data_ptr + i) = read_from_mem(start_addr + i);
		_delay_us(200);
	}
}

int main()
{

	uint8_t *rom_ptr;
	rom_ptr = &rom_contents[0];

	usart_init(BAUD_VAL);

	init_spi_master();

	//spi_TxByte(0);

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
