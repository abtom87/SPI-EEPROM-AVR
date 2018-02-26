/*
 * mod_timer.c
 *
 *  Created on: Feb 25, 2018
 *      Author: abel
 */

#include "mod_timer.h"

void timer_init()
{
	TIMSK1 |= 1 << OCIE1A;                 // Enable output compare match

#ifdef PWM_MODE_256_PSC
	TCCR1A|= 1<<WGM10;
	TCCR1B = ( (1<<WGM13) | (1<<CS12) ); // Prescaler is fclk/256, CTC Mode
#endif

#ifdef CTC_MODE_256_PSC
	TCCR1B = ((1 << WGM12) | (1 << CS12)); // Prescaler is fclk/256, CTC Mode
#endif

	TIFR1 |= 1 << OCF1A;                   //Clear Output compare match flag
}
