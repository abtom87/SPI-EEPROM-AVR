
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define FOSC_FOR_USART        16000000
#define BAUD_RATE     9600
#define BAUD_VAL      FOSC_FOR_USART/16/BAUD_RATE-1


void USART_Tx_byte(char c );

void usart_init(unsigned int );

void USART_Tx_string( char*);
