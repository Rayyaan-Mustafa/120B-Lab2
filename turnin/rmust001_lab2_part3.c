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
   	DDRA - 0x00; PORTA = 0xFF; //Configure port A's 8 pins as inputs
        DDRC = 0xFF; // configure port C's 8 pins as outputs
	PORTC = 0x00; //Initialize PORTB output to 0's
    /* Insert your solution below */
    	unsigned char cntavail = 0x00;
	unsigned char A0, A1, A2, A3 = 0x00;
	while (1) {
		A0 = PINA & 0x01;
		A1 = PINA & 0x02; A1 = A1 >> 1;
		A2 = PINA & 0x04; A2 = A2 >> 2;
		A3 = PINA & 0x08; A3 = A3 >> 3;
		cntavail = 4-(A0 + A1 + A2 + A3);
		if(cntavail == 0){
			PORTC = 0x80;
		}
		else  {
			PORTC = cntavail;
		}
//
////
///
		
   	}
	return 0;
}
