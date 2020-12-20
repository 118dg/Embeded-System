#include "msp.h"
#define S1BUT ((P1->IN & (1<<1)) == 0x00)
#define S2BUT ((P1->IN & (1<<4)) == 0x00)
#define BS_INIT 1
#define BS_DOWN 2
#define BS_UP 3

/**
 * main.c
 */
void main(void)
{
    int s1but_bs = BS_INIT;
    int s2but_bs = BS_INIT;
    int i, wait = 100000;

    P1->DIR &= ~(1<<1 | 1<<4);
    P2->DIR |= 1<<2 | 1<< 1 | 1<<0;
    P1->REN = (1<<1 | 1<<4);
    P1->OUT = (1<<1 | 1<<4);

    while (1) {

        while(wait == 100000) { //default
            P2->OUT = 1<<1; // Turn P2.1 LED on. Green(1)
            for (i=0; i<wait && wait>0; i++);
            P2->OUT = 0; // Turn P2.1 LED off
            for (i=0; i<wait && wait>0; i++);

            //slow
            if (S1BUT) { // S1 button down
                s1but_bs=BS_DOWN;
            } else { // S1 button up
                if (s1but_bs==BS_DOWN) {
                    if(wait<800000) wait *= 2;
                    s1but_bs=BS_UP;
                }
            }

            //fast
            if (S2BUT) { // S2 button down
                s2but_bs=BS_DOWN;
            } else { // S2 button up
                if (s2but_bs==BS_DOWN) {
                    if(wait>12500) wait /= 2;
                    s2but_bs=BS_UP;
                }
            }
        }

        /* while slow */
        while(wait > 100000){
            P2->OUT = 1<<2; // Turn P2.2 LED on. Blue(2)
            for (i=0; i<wait && wait>0; i++);
            P2->OUT = 0; // Turn P2.1 LED off
            for (i=0; i<wait && wait>0; i++);

            //slow
            if (S1BUT) { // S1 button down
                s1but_bs=BS_DOWN;
            } else { // S1 button up
                if (s1but_bs==BS_DOWN) {
                    if(wait<800000) wait *= 2;
                    s1but_bs=BS_UP;
                }
            }

            //fast
            if (S2BUT) { // S2 button down
                s2but_bs=BS_DOWN;
            } else { // S2 button up
                if (s2but_bs==BS_DOWN) {
                    if(wait>12500) wait /= 2;
                    s2but_bs=BS_UP;
                }
            }
        }

        /* while fast */
        while(wait < 100000){
            P2->OUT = 1<<0; // Turn P2.2 LED on. Red(2)
            for (i=0; i<wait && wait>0; i++);
            P2->OUT = 0; // Turn P2.1 LED off
            for (i=0; i<wait && wait>0; i++);

            //slow
            if (S1BUT) { // S1 button down
                s1but_bs=BS_DOWN;
            } else { // S1 button up
                if (s1but_bs==BS_DOWN) {
                    if(wait<800000) wait *= 2;
                    s1but_bs=BS_UP;
                }
            }

            //fast
            if (S2BUT) { // S2 button down
                s2but_bs=BS_DOWN;
            } else { // S2 button up
                if (s2but_bs==BS_DOWN) {
                       if(wait>12500) wait /= 2;
                       s2but_bs=BS_UP;
                }
            }
        }

    }
}
