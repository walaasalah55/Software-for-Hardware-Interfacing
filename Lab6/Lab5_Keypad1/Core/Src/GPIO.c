
#include "GPIO.h"

// #include "stm32f401cc_interface.h"

#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

unsigned int *lookup[2][6]={ {GPIOA_MODER,GPIOA_OTYPER,GPIOA_OSPEEDER,
		                     GPIOA_PUPDR,GPIOA_IDR,GPIOA_ODR} ,
	                       	{GPIOB_MODER,GPIOB_OTYPER,GPIOB_OSPEEDER,
	   		                     GPIOB_PUPDR,GPIOB_IDR,GPIOB_ODR}
                           };


void GPIO_EnableClock(unsigned char PortId) {

	*RCC_AHB1ENR |= (0x01 <<PortId );

}

void GPIO_Init(unsigned char PortId, unsigned char PinNum, unsigned char PinMode,
               unsigned char DefaultState) {

      //MODERhttps://www.youtube.com/watch?v=dcp_px8Ybas
	*lookup[PortId][0] &= ~(0x03 << 2 * PinNum);
	*lookup[PortId][0] |= PinMode << 2 * PinNum;
     //OTYPER
	*lookup[PortId][1] &= ~(1 << PinNum);
	*lookup[PortId][1] |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;
	 //PUPDR
	*lookup[PortId][3] &= ~(0x03 << 2 * PinNum);
	*lookup[PortId][3] |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);

}

unsigned char GPIO_WritePin(unsigned char PortId, unsigned char PinNum,
                            unsigned char Data) {
  unsigned char result;

      if (((*lookup[PortId][0] & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
        if (Data) {
        	*lookup[PortId][5] |= (1 << PinNum);
        } else {
        	*lookup[PortId][5] &= ~(1 << PinNum);
        }
        result = OK;
      } else {
        result = NOK;
      }

  return result;
}

unsigned char GPIO_ReadPin(unsigned char PortId, unsigned char PinNum) {
  unsigned char data = 0;

      data = (*lookup[PortId][4] & (1 << PinNum)) >> PinNum;
  return data;
}


