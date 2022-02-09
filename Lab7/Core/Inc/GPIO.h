/*
 * GPIO.h
 *
 *  Created on: Dec 25, 2021
 *      Author: walaa
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

//#include "stm32f401xc.h"

//ports
#define PORTA ((unsigned char)0)
#define PORTB ((unsigned char)1)

// Result Status
#define OK ((unsigned char)0)
#define NOK ((unsigned char)1)

// Mode Types
#define INPUT ((unsigned char)0x00)
#define OUTPUT ((unsigned char)0x01)
#define ALTERNATE_FUN ((unsigned char)0x02)
#define ANALOG ((unsigned char)0x03)

// Output modes
#define PUSH_PULL ((unsigned char)0x00)
#define OPEN_DRAIN ((unsigned char)0x01)

// Resistor modes
#define NO_PULL_UP_DOWN ((unsigned char)0x00)
#define PULL_UP ((unsigned char)0x02)
#define PULL_DOWN ((unsigned char)0x04)

#define GPIO_REG(PORT_ID, REG_ID) ((unsigned int *)(PORT_ID + REG_ID))

//Regs for interrupt
#define RCC_APB2ENR GPIO_REG(0x40023800 , 0x44)
#define SYSCFG_EXTICR1 GPIO_REG(0x40013800, 0x08)
#define EXTI_IMR GPIO_REG(0x40013C00, 0x00)
#define EXTI_RTSR GPIO_REG(0x40013C00, 0x08)
#define EXTI_FTSR GPIO_REG(0x40013C00, 0x0C)
#define EXTI_PR GPIO_REG(0x40013C00, 0x14)
#define NVIC_ISER0 GPIO_REG(0xE000E100,0x00)


//clock
#define RCC_AHB1ENR ((unsigned int *)(0x40023800 + 0x30))

//portA
#define GPIOA_MODER GPIO_REG(0x40020000, 0x00)
#define GPIOA_OTYPER GPIO_REG(0x40020000, 0x04)
#define GPIOA_OSPEEDER GPIO_REG(0x40020000, 0x08)
#define GPIOA_PUPDR GPIO_REG(0x40020000, 0x0C)
#define GPIOA_IDR GPIO_REG(0x40020000, 0x10)
#define GPIOA_ODR GPIO_REG(0x40020000, 0x14)

//port B
#define GPIOB_MODER GPIO_REG(0x40020400, 0x00)
#define GPIOB_OTYPER GPIO_REG(0x40020400, 0x04)
#define GPIOB_OSPEEDER GPIO_REG(0x40020400, 0x08)
#define GPIOB_PUPDR GPIO_REG(0x40020400, 0x0C)
#define GPIOB_IDR GPIO_REG(0x40020400, 0x10)
#define GPIOB_ODR GPIO_REG(0x40020400, 0x14)



void GPIO_EnableClock(unsigned char PortId);

void GPIO_Init(unsigned char PortId, unsigned char PinNum, unsigned char PinDir,
               unsigned char DefaultState);
unsigned char GPIO_WritePin(unsigned char PortId, unsigned char PinNum,
                            unsigned char Data);

unsigned char GPIO_ReadPin(unsigned char PortId, unsigned char PinNum);



#endif /* INC_GPIO_H_ */
