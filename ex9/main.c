#include "msp.h"
void SysTick_Handler(void)
{
    P1->OUT ^= BIT0; // Toggle P1.0 LED
}

int main(void)
{
    SystemCoreClockUpdate();
    // Configure GPIO
    P1->DIR |= BIT0;
    P1->OUT &= ~BIT0;
    // Enable SysTick Module
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
    SysTick->LOAD = SystemCoreClock/20 - 1;
    // Clear the SysTick current value register by writing
    // a dummy value
    SysTick->VAL = 0x01;
    // Enable SysTick interrupt
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
    while (1)
    {
    }
}
