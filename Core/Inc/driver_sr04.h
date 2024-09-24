#ifndef __DRIVE_SR04_H
#define __DRIVE_SR04_H
#include "main.h"
#include "stdint.h"

#define Tirg_ON   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET);     //ON，引脚SET代表高电平
#define Tirg_OFF   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);     //OFF,RESET代表低电平


void SR04_Trigger(void);
void Delay_us(uint16_t us);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);


#endif
