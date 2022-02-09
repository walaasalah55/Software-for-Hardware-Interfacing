#include "GPIO.h"
#include "Interrupt.h"
//#include "stm32f401xc.h"
//#include "stm32f401cc_interface.h"
void seven_segment ();
void increment_counter();
void decrement_counter();
unsigned char numbers[ ] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int count=0;
void seven_segment (int x) {
	for (int i = 0; i < 7; i++) {
			 GPIO_WritePin(0, i, (numbers[x] & (1 << i)) >> i); }
}

void increment_counter(){
	count+=1;
	if (count>=9)
		{count=9;}
    
	*EXTI_PR|=(1<<0); // to clear flag on bin 0
}

void decrement_counter(){
	count-=1;
	if (count<=0)
		{count=0;}
	*EXTI_PR|=(1<<1); // to clear flag on bin 1
}

int main(void) {

int local;
GPIO_EnableClock(0); //enable port A clk
GPIO_EnableClock(1); //enable port B clk
//put bins from 0 to 6 in port A in output mode
for (int i = 0; i < 7; i++)
  { GPIO_Init(0, i , OUTPUT, PUSH_PULL); }

*RCC_APB2ENR|=(1<<14); //enable clk for SYSCFG
*SYSCFG_EXTICR1|=((0x01)<<(4*0)); // enable bin0 in portB
*SYSCFG_EXTICR1|=((0x01)<<(4*1)); // enable bin1 in portB
*EXTI_FTSR|=(3<<0); // enable Falling trigger selection register
*NVIC_ISER0=(1<<6); // to enable internal interrupt (position 6)
*NVIC_ISER0=(1<<7); // to enable internal interrupt (position 6)


while(1)
{ *EXTI_IMR&=~(3<<0);
  local=count;
  *EXTI_IMR|=(3<<0);
  seven_segment (local);
	}
	return 0;
 }


/*A software to perform a decimal counter on a 7-segment display.
 * System inputs shall be two push buttons. System output shall be 1 seven segment display.
 * Two interrupts to be configured on GPIO falling edge, one for each button.
 * The first ISR shall increment the counter. The second ISR shall decrement the counter.
 * The main function shall perform the display actions. Race condition shall be taken
 * into consideration to protect the counters from being corrupted.*/
