#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "rc522.h"

/**
*   ����˵����
*   1--SDA  <----->PA4
*   2--SCK  <----->PA5
*   3--MOSI <----->PA7
*   4--MISO <----->PA6
*   5--IRQ  <----->����
*   6--GND <----->GND
*   7--RST <----->PB0
*   8--VCC <----->3.3V
*		9--LED <----->PB1
**/

int main(void)
{
    delay_init();	    	 //��ʱ������ʼ��
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
    uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
    RC522_Init();       //��ʼ����Ƶ��ģ��
    while(1)
    {
        RC522_Handel();
    }
}


