#ifndef __DRIVE_SR04_H
#define __DRIVE_SR04_H
#include "main.h"


#define Tirg_ON   HAL_GPIO_WritePin(GPIOB,GPIO_Pin_3,GPIO_Pin_SET);     //ON，引脚SET代表高电平
#define Tirg_OFF   HAL_GPIO_WritePin(GPIOB,GPIO_Pin_3,GPIO_Pin_RESET);     //OFF,RESET代表低电平


void SR04_Trigger(void);
void Delay_us(uint16_t us);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);


#endif
