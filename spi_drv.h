/*
 * spi_drv.h
 *
 *  Created on: Feb 24, 2018
 *      Author: abel
 */

#ifndef SPI_DRV_H_
#define SPI_DRV_H_

#include <avr/io.h>
#include <util/delay.h>

#define WRITE_EN_CMD 0x06
#define WRITE_CMD    0x02
#define READ_CMD     0x03
#define READ_STATUS  0x05

#define HIGH 1
#define LOW  0
#define SET_SS_PIN(state) ( (state)?(PORTB |= (1 << PB2) ):(PORTB &= ~(1 << PB2) ) )

void init_spi_master(void);
void init_spi_slave(void);

void spi_TxByte(char byte);
char spi_RxByte(void);

void write_to_mem(char addr, char data);
uint8_t read_status(void);
char read_from_mem(char addr);

#endif /* SPI_DRV_H_ */
