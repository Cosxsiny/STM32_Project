#include "beep.h" 
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

//��ʼ��PF8Ϊ�����		    
//BEEP IO��ʼ��
void BEEP_Init(void)
{   
  
  //��ʼ����������Ӧ����GPIOA5
	
	 GPIO_InitTypeDef  GPIO_InitStructure;		
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PA�˿�ʱ��		
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //BEEP-->PA.5 �˿�����
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ100MHz
	 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.5
	 
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE); 						 
//=============================================================================
//LED -> PC13
//=============================================================================			 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(BEEP_PORT_RCC,ENABLE); // ���� GPIO ʱ�� 
	// ���� GPIO ��ģʽ�� IO �� 
	GPIO_InitStructure.GPIO_Pin=BEEP_PIN; //ѡ����Ҫ���õ� IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_OD; //���ÿ�©���ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; //���ô�������
	GPIO_Init(BEEP_PORT,&GPIO_InitStructure); // ��ʼ�� GPIO
}


