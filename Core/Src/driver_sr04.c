#include "driver_sr04.h"

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

uint32_t distance_cm = 0;      //定义一个距离的变量

void Delay_us(uint16_t us)
{
	uint16_t differ = 0xffff-5;
	__HAL_TIM_SET_COUNTER(&htim3,differ);
	HAL_TIM_Base_Start(&htim3);     //将定时器3打开
	
	while(0xffff-5)
	{
		differ = __HAL_TIM_GET_COUNTER(&htim3);
	}                  //用于获取定时器 htim3 的当前计数值
	
	HAL_TIM_Base_Stop(&htim3);     //将定时器3关闭
}

void SR04_Trigger(void)   //触发型号
{
	Tirg_ON;
	Delay_us(10);
	Tirg_OFF;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)       //外部中断的回调函数
{
	static int count = 0;        //计数变量
	
	if(GPIO_Pin == GPIO_PIN_4)
	{
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4))         //高电平时就开始计数
		{
			HAL_TIM_Base_Start(&htim4);
			__HAL_TIM_SetCounter(&htim4,0);//清空计时器
		}
		else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4) == 0)   //低电平
		{
			HAL_TIM_Base_Stop(&htim4);         //关闭定时器
			count = __HAL_TIM_GetCounter(&htim4);//读取计数值
			distance_cm = count*340/2*0.0000001*100;     //公式求距离
		}
	}
}
