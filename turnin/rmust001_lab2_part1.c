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
        DDRB = 0xFF; // configure port B's 8 pins as outputs
	PORTB = 0x00; //Initialize PORTB output to 0's
    /* Insert your solution below */
    	unsigned char tmpB = 0x00;//temp variable to hold the value of B
	unsigned char tmpA = 0x00;//temp variable to hold value of A
	while (1) {
		//1)Read input
		tmpA = PINA & 0x03;
		//2) Perform Computation
		//if PA0 is 1, set PB1PB0 = 01, else = 10
		if(tmpA == 0x01) {//True if PA0 is 1
			tmpB = 0x01; 
		}
		else {
			tmpB = 0x00;
		}
		// 3) Write output
		PORTB = tmpB;
//
////
///
		
   	}
	return 0;
}
