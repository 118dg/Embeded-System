#include "msp.h"
#define S2BUT ((P1->IN & (1<<4)) == 0x00)
#define BS_INIT 1
#define BS_DOWN 2
#define BS_UP 3
void main(void)
{
int s1but_bs = BS_INIT;
int pos=0;
P1->DIR &= ~(1<<4);
P2->DIR |= 1<<2 | 1<< 1 | 1<<0;
P1->REN = 1<<4;
P1->OUT = 1<<4;
P2->OUT = 1<<pos;
while (1) {
if (S2BUT) { // button down
s1but_bs=BS_DOWN;
} else { // button up
if (s1but_bs==BS_DOWN) {
if (pos < 2) pos++;
else pos=0;
P2->OUT = 1<<pos;
s1but_bs=BS_UP;
}
}
}
}
