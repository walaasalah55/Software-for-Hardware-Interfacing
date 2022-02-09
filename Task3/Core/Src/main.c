
#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

int main(void) {
   //set pins 5,6,7  output for leds
	for (int i = 5; i < 8; i++)
	  { GPIO_Init('B', i , OUTPUT, PUSH_PULL); }
	//set pin 3 input for button
	GPIO_Init('B', 3 , INPUT, PULL_UP);

//combination colors
unsigned int colors[ ] = {0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0};
unsigned int read1,read2;

while (1) {

for(int a=0;a<8;a++)
  {
read1=GPIO_ReadPin('B', 3);

for(int i=0;i<3000;i++) {}
read2=GPIO_ReadPin('B', 3);

  if((read1&(1<<3))&& (read2!=read1))
   {
   for(int j=5;j<8;j++)
   	  	{
   	  	GPIO_WritePin('B', j,colors[a] & (1<<j) );
   	  	}
   }
}
}
	return 0;
 }


