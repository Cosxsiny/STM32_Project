#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"	 
#include "mlx90614.h" 
#include "oled.h"
#include "hc.h"
#include "beep.h"


//�¶ȵĵ�λ ��
unsigned char TempCompany[][16]=
{
	0x06,0x09,0x09,0xE6,0xF8,0x0C,0x04,0x02,0x02,0x02,0x02,0x02,0x04,0x1E,0x00,0x00,
	0x00,0x00,0x00,0x07,0x1F,0x30,0x20,0x40,0x40,0x40,0x40,0x40,0x20,0x10,0x00,0x00,/*"��",0*/	

};

int main(void)
{	
	uint8_t i,j;	
	float Temperature = 0;    //�¶����ݱ����������ͣ�
	char TempValue[80] = {0}; //�¶�ֵ���ַ�����
	float length;
	delay_init();	  //��ʱ������ʼ��	  
	//NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(9600);//���ڳ�ʼ��Ϊ115200
	
	OLED_Init()	;
	OLED_Clear() ;
 	LED_Init();		//LED�˿ڳ�ʼ��
	Hcsr04Init();

  SMBus_Init();
  display();
	BEEP_Init();         	//��ʼ���������˿�
	while(1)
	{		
		length = Hcsr04GetLength();
     //printf("����Ϊ:%.3fcm\n",length);
		Temperature = SMBus_ReadTemp();
		//printf("Temperature = %f\r\n",Temperature);	//�ڴ��ڵ��������ϴ�ӡ���
		delay_ms(100);//������ʱ�Ļ��ڵ��Դ��������Ͽ�����Ч��
		sprintf(TempValue,"%.1f", Temperature); //������ת�����ַ���	
		if(Temperature>25)
		{
			GPIO_SetBits(GPIOC,GPIO_Pin_13); //LED�������ͣ� ��ͬLED=0;
			beep=0; //BEEP�������ͣ� ��ͬBEEP=0;
			led=0;
		}
		else
		{
			GPIO_ResetBits(GPIOC,GPIO_Pin_13);
			beep=1;
			led=1;
		}
		//�¶ȵ�λ��ʾ ���棩
		for(i = 6;i < 7;i++)
		{
			j = i - 6;
			OLED_ShowCHinese16x16(i*16,2,j,TempCompany);			
		}
		OLED_ShowString(40,2,(uint8_t *)TempValue,16);//��OLED����ʾʵ�ʲ������¶�
		OLED_Float(6,40,length,2);
		OLED_ShowString(90,7,"CM",2);
		delay_ms(50);
	}
}


