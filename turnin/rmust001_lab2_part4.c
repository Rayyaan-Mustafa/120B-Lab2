/*	Author: rmust001
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab 1  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
   	DDRA = 0x00; PORTA = 0xFF; //Configure port A's 8 pins as inputs
        DDRB = 0x00; PORTB = 0xFF; 
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
    
	unsigned wA, wB, wC = 0x00;
	unsigned wTotal = 0x00;
	
	while (1) {
		wA = PINA; wB = PINB; wC= PINC;
		wTotal = wA + wB + wC;
		PORTD = 0x00;
		if(wTotal > 0x8c){
			PORTD = 0x01;
		}
		if((wA-wC > 0x50)||(wC-wA > 0x50)){
			PORTD |= 0x02;
		}
		PORTD |= (wTotal >> 2) & 0xFC;
		
   	}
	return 0;
}
