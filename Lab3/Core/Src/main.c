#include "stm32f401cc_interface.h"


int main(void){

	RCC_AHB1ENR |= (1 << 0); // enable GPIOA clock 
	GPIOA_MODER |= (1 << 0); // make PA0 as general purpose output 
	GPIOA_OTYPER &= ~(0 << 0); // Output push-pull 

	while(1){
		GPIOA_ODR |= (1 << 0);
		//delay
		for(int i=0;i<3000;i++) {}
		GPIOA_ODR &= ~(1 << 0);
		//delay
		for(int i=0;i<3000;i++) {}
	}
}


