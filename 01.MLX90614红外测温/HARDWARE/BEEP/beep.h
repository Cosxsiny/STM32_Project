#ifndef __BEEP_H
#define __BEEP_H	 
#include "sys.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//��������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

/* ������ʱ�Ӷ˿ڡ����Ŷ��� */
#define BEEP_PORT GPIOB
#define BEEP_PIN GPIO_Pin_4
#define BEEP_PORT_RCC RCC_APB2Periph_GPIOB
#define beep PBout(4)
#define led PAout(5)

void BEEP_Init(void);//��ʼ��		

#endif

