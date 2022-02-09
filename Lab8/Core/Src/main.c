#include "GPIO.h"

void USART_INIT(void);
void USART_Transmit(char data);
int i = 0;
char Data[] ={ 'H','e','l','l','o',' ','W','o','r','l','d'};

int main(void) {
GPIO_EnableClock(0); //enable port A clk
GPIO_Init(0, 2 , ALTERNATE_FUN, PUSH_PULL);
USART_INIT();
USART_Transmit(Data[i]);

while(1)
{	}
	return 0; }

void USART_INIT(void)
{
	*RCC_APB1ENR|=(1<<17); //enable clk for USART2
	*USART_BRR=0x683; // to get 9600 baud_rate
	*USART_CR1|=(1<<3); // 1 to enable transmitter
	*USART_CR1&=~(1<<12);// 0 to (8 data bits) word length
	*USART_CR1|=(1<<13); // 1 to enable USART
	*USART_CR1&=~(1<<15); //0  to oversample by 16
	*USART_CR2 &=~((0x03)<<12); // to get 1 stop bit
	*GPIOA_AFRL|=((0x07)<<8); // AF7
}

void USART_Transmit(char data)
{
	while(i<=11)
	 {   	// to check the transmission of 1 bit completed
		   while((((*USART_SR) >> 6)&1))
		   {*USART_DR = Data[i];
		    (i++);
		   }
	 }
}

