#include "stm32f10x.h"                  // Device header
#include "delay.h"

int main(void)
{
	GPIO_InitTypeDef CPIO_Initstructuer;					//定义GPIO结构体
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);			//打开连接GPIO外设的时钟
	
	CPIO_Initstructuer.GPIO_Mode = GPIO_Mode_Out_PP;			//设置GPIO推挽输出模式
	CPIO_Initstructuer.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;//指定设置的GPIO端口
	CPIO_Initstructuer.GPIO_Speed = GPIO_Speed_50MHz;			//设置GPIO频率（一般50HZ就够了）
	GPIO_Init(GPIOB,&CPIO_Initstructuer);					//结构体初始化的最后一步
	
	
	while(1)								//流水灯循环函数
	{
		GPIO_WriteBit(GPIOB,GPIO_Pin_4,Bit_SET);	
		Delay_ms(500);
		GPIO_WriteBit(GPIOB,GPIO_Pin_4,Bit_SET);
		Delay_ms(500);							//GPIO4所连接的流水灯不闪烁
		
		GPIO_WriteBit(GPIOB,GPIO_Pin_5,Bit_SET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOB,GPIO_Pin_5,Bit_RESET);
		Delay_ms(500);							//GPIO5、6、7所连接的流水灯闪烁
		
		GPIO_WriteBit(GPIOB,GPIO_Pin_6,Bit_SET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOB,GPIO_Pin_6,Bit_RESET);
		
		
		GPIO_WriteBit(GPIOB,GPIO_Pin_7,Bit_SET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOB,GPIO_Pin_7,Bit_RESET);
		
	}
}
