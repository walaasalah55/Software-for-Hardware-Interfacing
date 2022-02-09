#include "stm32f401cc_interface.h"


int main(void) {
	//enable GPIOB
	RCC_AHB1ENR |=(1<<1);

	//set input pin for button
	GPIOB_MODER &=~((0x03)<<(2*3));
	//pull-up for button
	GPIOB_PUPDR |=((0x01)<<(2*3));

	//set output pins for leds
	GPIOB_MODER &=~((0x15)<<(2*5));    //clear
	GPIOB_MODER |=((0x15)<<(2*5));
    //push-pull for leds
	GPIOB_OTYPER &=~(0x07<<5);

//combination colors
unsigned int colors[ ] = {0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0};
unsigned int read1,read2;

while (1) {

 for(int a=0;a<8;a++)
  {
read1=GPIOB_IDR;
//if (read1==1)
for(int i=0;i<3000;i++) {}
read2=GPIOB_IDR;

  if((read1&(1<<3))&& (read2!=read1))
   {GPIOB_ODR=colors[a];
   }
}
}
	return 0;
 }

