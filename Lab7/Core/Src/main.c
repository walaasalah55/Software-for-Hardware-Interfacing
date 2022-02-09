#include "GPIO.h"
//#include "stm32f401xc.h"
//#include "stm32f401cc_interface.h"

void Toggle();
int x=0;


void Toggle_led(){
	x=~x;
	GPIO_WritePin(1, 3,x);
	*EXTI_PR|=(1<<0); // to clear flag
}

int main(void) {

GPIO_EnableClock(1); //enable port B clk
GPIO_Init(1, 3, OUTPUT, PUSH_PULL);//put bin 3 in port B in output mode
*RCC_APB2ENR|=(1<<14); //enable clk for SYSCFG
*SYSCFG_EXTICR1|=((0x01)<<(4*0)); // enable bin0 in portB
*EXTI_IMR|=(1<<0); // unmask Interrupt register
//*EXTI_RTSR|=(1<<0); // enable Rising trigger selection register
*EXTI_FTSR|=(1<<0); // enable Falling trigger selection register
*NVIC_ISER0=(1<<6); // to enable internal interrupt (position 6)

while(1)
{}
	return 0;
 }

/*A software to perform an LED toggle based on a button press.
The Software shall detect a falling edge event on the button pin
and then toggle the LED in an ISR.*/
