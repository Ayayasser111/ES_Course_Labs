#include "../SERVICES/STD_TYPES.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"


void delay(unsigned int num)
{
    unsigned int i;
    for(i = 0; i < num; i++);
}

void main()
{

    unsigned int blink_counter = 0;
    GPIO_Init();
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    while(1)
    {
        delay(1000);
        blink_counter++;
        if(blink_counter >= 50)
        {
            LED_Toggle(GPIO_PORTB, GPIO_PIN0);
            blink_counter = 0;
        }
    }
}