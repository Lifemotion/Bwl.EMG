/*
* board.c
*
* Created: 23.07.2017 19:43:31
*  Author: gus10
*/

#include "board.h"

void timer_init()
{
	TCCR1B |=  (1 << CS11);
	TIMSK1 |=  (1 << TOIE1);	
}

void adc_init()
{
	ADMUXA = 0x07;
	ADMUXB = (1<<REFS1|1<<REFS2|1<<REFS0);
	ADCSRA |= (1<<ADEN)|(1<<ADPS1);
	ADCSRB |= (1<<ADLAR);
}

unsigned char adc_get_high_byte()
{
	ADCSRA |= 1<<ADSC;
	while(ADCSRA&(1<<ADSC));
	return ADCH;
}
void board_init()
{
	wdt_enable(WDTO_8S);
	DDRB |= (1<<DDRB2);
	PORTB |= (1<<PORTB2);
	adc_init();
	timer_init();
	sei();
}



void drive_control(unsigned int pulse_width)
{

}

