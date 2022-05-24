#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"	 
#include "mlx90614.h" 
#include "oled.h"
#include "hc.h"
#include "beep.h"


//温度的单位 ℃
unsigned char TempCompany[][16]=
{
	0x06,0x09,0x09,0xE6,0xF8,0x0C,0x04,0x02,0x02,0x02,0x02,0x02,0x04,0x1E,0x00,0x00,
	0x00,0x00,0x00,0x07,0x1F,0x30,0x20,0x40,0x40,0x40,0x40,0x40,0x20,0x10,0x00,0x00,/*"℃",0*/	

};

int main(void)
{	
	uint8_t i,j;	
	float Temperature = 0;    //温度数据变量（浮点型）
	char TempValue[80] = {0}; //温度值（字符串）
	float length;
	delay_init();	  //延时函数初始化	  
	//NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(9600);//串口初始化为115200
	
	OLED_Init()	;
	OLED_Clear() ;
 	LED_Init();		//LED端口初始化
	Hcsr04Init();

  SMBus_Init();
  display();
	BEEP_Init();         	//初始化蜂鸣器端口
	while(1)
	{		
		length = Hcsr04GetLength();
     //printf("距离为:%.3fcm\n",length);
		Temperature = SMBus_ReadTemp();
		//printf("Temperature = %f\r\n",Temperature);	//在串口调试助手上打印结果
		delay_ms(100);//不加延时的话在电脑串口助手上看不到效果
		sprintf(TempValue,"%.1f", Temperature); //浮点型转换成字符串	
		if(Temperature>25)
		{
			GPIO_SetBits(GPIOC,GPIO_Pin_13); //LED引脚拉低， 等同LED=0;
			beep=0; //BEEP引脚拉低， 等同BEEP=0;
			led=0;
		}
		else
		{
			GPIO_ResetBits(GPIOC,GPIO_Pin_13);
			beep=1;
			led=1;
		}
		//温度单位显示 （℃）
		for(i = 6;i < 7;i++)
		{
			j = i - 6;
			OLED_ShowCHinese16x16(i*16,2,j,TempCompany);			
		}
		OLED_ShowString(40,2,(uint8_t *)TempValue,16);//在OLED上显示实际测量的温度
		OLED_Float(6,40,length,2);
		OLED_ShowString(90,7,"CM",2);
		delay_ms(50);
	}
}


