/*
 * board.h
 *
 * Created: 23.07.2017 19:43:45
 *  Author: gus10
 */ 
#ifndef BOARD_H_
#define BOARD_H_

#define F_CPU 8000000
#define BAUD  19200

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/setbaud.h>
#include <util/delay.h>
#include "../libs/bwl_uart.h"

#define PIN_ON  {DDRB |= (1<<DDRB2); PORTB |=  (1<<PORTB2);}
#define PIN_OFF {DDRB |= (1<<DDRB2); PORTB &= ~(1<<PORTB2);}
#define LED_ON  {DDRB |= (1<<DDRB1); PORTB |=  (1<<PORTB1);}
#define LED_OFF {DDRB |= (1<<DDRB1); PORTB &= ~(1<<PORTB1);}

void drive_control(unsigned int pulse_width);
void timer0_init();
void board_init();
unsigned char adc_get_high_byte();
#endif /* BOARD_H_ */