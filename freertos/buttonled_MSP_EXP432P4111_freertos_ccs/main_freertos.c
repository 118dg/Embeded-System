/* Driver configuration */
#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/drivers/Board.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

/* function prototypes */
void Task1( void *pvParameters );
void Task2( void *pvParameters );


void main(void)
{
    /* Configuring S1 & S2 buttons / Red LED & RGB LED in mainboard */
    P1->DIR = BIT0;
    P1->DIR &= ~(BIT1|BIT4);
    P2->DIR |= 1<<2 | 1<< 1 | 1<<0;
    P1->REN |= (BIT1|BIT4);
    P1->OUT |= (BIT1|BIT4);
    P2->OUT = 0x00;

    xTaskCreate( Task1,                   /* The function that implements the task. */
                 "Task 1",                /* The text name assigned to the task - for debug only as it is not used by the kernel. */
                 configMINIMAL_STACK_SIZE,/* The size of the stack to allocate to the task. */
                 ( void * ) 0,            /* The parameter passed to the task - just to check the functionality. */
                 5,                      /* The priority assigned to the task. */
                 NULL );                  /* The task handle is not required, so NULL is passed. */

    xTaskCreate( Task2, "Task 2", configMINIMAL_STACK_SIZE, (void*)0, 5, NULL);


    /* Start the tasks and timer running. */
    vTaskStartScheduler();

    while (1)
    {
    }
}

void Task1( void *pvParameters )
{
    int i;
    while (1)
    {
       P1->OUT = BIT1|BIT4 | BIT0;
       for (i=0;i<100000;i++);
       P1->OUT = BIT1|BIT4;
       for (i=0;i<100000;i++);
    }
}

void Task2( void *pvParameters )
{
    int i;
    while (1)
    {
        P2->OUT = BIT0;
        for (i=0;i<100000;i++) ;
        P2->OUT = 0x00;
        for (i=0;i<100000;i++) ;
    }
}

