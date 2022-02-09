/*
 * Interrupt.h
 *
 *  Created on: 28 Dec 2021
 *      Author: walaa
 */

#ifndef INC_INTERRUPT_H_
#define INC_INTERRUPT_H_
#include "GPIO.h"

//Regs for interrupt
#define RCC_APB2ENR GPIO_REG(0x40023800 , 0x44)
#define SYSCFG_EXTICR1 GPIO_REG(0x40013800, 0x08)
#define EXTI_IMR GPIO_REG(0x40013C00, 0x00)
#define EXTI_RTSR GPIO_REG(0x40013C00, 0x08)
#define EXTI_FTSR GPIO_REG(0x40013C00, 0x0C)
#define EXTI_PR GPIO_REG(0x40013C00, 0x14)
#define NVIC_ISER0 GPIO_REG(0xE000E100,0x00)

#endif /* INC_INTERRUPT_H_ */
