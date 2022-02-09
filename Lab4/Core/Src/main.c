#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

int main(void) {

for (int i = 0; i < 7; i++)
  { GPIO_Init('A', i , OUTPUT, PUSH_PULL); }

unsigned int numbers[ ] = {0x3f,0x30,0x6d,0x79,0x72,0x5b,0x5f,0x31,0x7f,0x7b};

  while (1) {
	for (int x = 0; x < 10; x++)
	  {
	    for (int i = 0; i < 7; i++)
	    {
		 //bit on
		  if (numbers[x] & (1<<i))
		 { GPIO_WritePin('A', i, 1);}
		 //bit off
		 else
		 { GPIO_WritePin('A', i, 0);}
	    }
	   //delay
	   for (int i = 0; i < 1000000; i++)
	  	 { }
     }
  }
    return 0;
  }




