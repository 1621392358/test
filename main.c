#include "stm32f10x.h"                  // Device header
#include "delay.h"

int main(void)
{
	GPIO_InitTypeDef CPIO_Initstructuer;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	CPIO_Initstructuer.GPIO_Mode = GPIO_Mode_Out_PP;
	CPIO_Initstructuer.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	CPIO_Initstructuer.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&CPIO_Initstructuer);
	
	
	while(1)
	{
		GPIO_WriteBit(GPIOB,GPIO_Pin_4,Bit_SET);	
		Delay_ms(500);
		GPIO_WriteBit(GPIOB,GPIO_Pin_4,Bit_SET);
		Delay_ms(500);
		
		GPIO_WriteBit(GPIOB,GPIO_Pin_5,Bit_SET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOB,GPIO_Pin_5,Bit_RESET);
		Delay_ms(500);
		
		GPIO_WriteBit(GPIOB,GPIO_Pin_6,Bit_SET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOB,GPIO_Pin_6,Bit_RESET);
		
		
		GPIO_WriteBit(GPIOB,GPIO_Pin_7,Bit_SET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOB,GPIO_Pin_7,Bit_RESET);
		
	}
}
