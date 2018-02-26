/*
 * main.h
 *
 *  Created on: Feb 25, 2018
 *      Author: abel
 */

#ifndef MAIN_H_
#define MAIN_H_

#define ROM_SIZE 10
unsigned char rom_contents[ROM_SIZE] = { 0x61, 0x62, 0x30, 0x31, 0x63, 0x64,
		0x32, 0x33, 0x65, 0x66 };

unsigned char Rx_rom_buff[ROM_SIZE] = { 0 };

void timer_init();

void eeprom_read(uint8_t start_addr, uint8_t *data_ptr, uint8_t size);
void eeprom_write(uint8_t start_addr, uint8_t *data_ptr, uint8_t size);

#endif /* MAIN_H_ */
