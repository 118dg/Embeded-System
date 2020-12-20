#include "msp.h"


/**
 * main.c
 */
void main(void)
{
    int i;

	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	P1->DIR |= BIT0; // P1.0 set as output

	while (1) // continuous loop
	{
	    P1->OUT = BIT0; // Turn P1.0 LED on
	    for (i=0; i<100000; i++)
	        ;
	    P1->OUT = 0; // Turn P1.0 LED off
        for (i=0; i<100000; i++)
            ;
	}
}
