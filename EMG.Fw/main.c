/*
* EMG.Fw.c
*
* Created: 23.07.2017 19:41:19
* Author : gus10
*/

#include "board/board.h"
unsigned int pulse_width = 1000;
unsigned long capture_delay = 0;
unsigned char drive_state = 0;
unsigned char state = 0;

unsigned int pwm_period = 20400;
ISR(TIMER1_OVF_vect)
{
	if(PORTB & (1<<PORTB2)){
		TCNT1 = 65535-pwm_period+pulse_width;
		PORTB &= ~(1<<PORTB2);
		}else{
		PORTB |= (1<<PORTB2);
		TCNT1 = 65535-pulse_width;
	}
	wdt_reset();
}

int main(void)
{
	board_init();
	while (1)
	{
		wdt_reset();
		unsigned char data = adc_get_high_byte();
		if(data>140){
		_delay_us(150);
			data = adc_get_high_byte();
		}
		if (data-150>0){
			capture_delay = 0;
			pulse_width=1500;
			state = 1;
			}else if(data-135>0){
			capture_delay = 0;
			pulse_width=1300;
			state = 1;
			}else if(capture_delay>30000){
			pulse_width=800;
			state = 0x0;
			}else{
			capture_delay++;
		}
		if(state){LED_ON;} else {LED_OFF;}
	}
}

