#ifndef __BEEP_H
#define __BEEP_H	 
#include "sys.h" 
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

/* 蜂鸣器时钟端口、引脚定义 */
#define BEEP_PORT GPIOB
#define BEEP_PIN GPIO_Pin_4
#define BEEP_PORT_RCC RCC_APB2Periph_GPIOB
#define beep PBout(4)
#define led PAout(5)

void BEEP_Init(void);//初始化		

#endif

