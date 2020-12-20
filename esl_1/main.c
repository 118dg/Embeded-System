#include "msp.h"


/**
 * main.c
 */
void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer

    int i, wait=100000;
    P1->DIR |= BIT0; // P1.0 set as output

    while (1) // continuous loop
        {
            P1->OUT = 1<<0; // Turn P1.0 LED on
            for (i=0; i<wait; i++)
                ;
            P1->OUT = 0; // Turn P1.0 LED off
            for (i=0; i<wait; i++)
                ;

            wait *= 2;
            if(wait == 1600000) wait = 100000;
        }
}

