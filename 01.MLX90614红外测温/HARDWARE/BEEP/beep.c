#include "beep.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//蜂鸣器驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/3
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 

//初始化PF8为输出口		    
//BEEP IO初始化
void BEEP_Init(void)
{   
  
  //初始化蜂鸣器对应引脚GPIOA5
	
	 GPIO_InitTypeDef  GPIO_InitStructure;		
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PA端口时钟		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //BEEP-->PA.5 端口配置
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为100MHz
	 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.5
	 
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE); 						 
//=============================================================================
//LED -> PC13
//=============================================================================			 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(BEEP_PORT_RCC,ENABLE); // 开启 GPIO 时钟 
	// 配置 GPIO 的模式和 IO 口 
	GPIO_InitStructure.GPIO_Pin=BEEP_PIN; //选择你要设置的 IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_OD; //设置开漏输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; //设置传输速率
	GPIO_Init(BEEP_PORT,&GPIO_InitStructure); // 初始化 GPIO
}


