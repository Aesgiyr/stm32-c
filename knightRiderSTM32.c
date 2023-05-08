#include "stm32f10x.h"                  // Device header

void gpioConfig(){
	GPIO_InitTypeDef GPIOInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIOInitStructure);
}

void delay(int32_t time){
	while(time--);
}

int ledArray[3] = {GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_2};

int main(){
	
	gpioConfig();
	
	while(1){
		
//		GPIO_SetBits(GPIOB,GPIO_Pin_0);
//		delay(3600000);
//		GPIO_ResetBits(GPIOB,GPIO_Pin_0);
//		GPIO_SetBits(GPIOB,GPIO_Pin_1);
//		delay(3600000);
//		GPIO_ResetBits(GPIOB,GPIO_Pin_1);
//		GPIO_SetBits(GPIOB,GPIO_Pin_2);
//		delay(3600000);
//		GPIO_ResetBits(GPIOB,GPIO_Pin_2);
//		GPIO_SetBits(GPIOB,GPIO_Pin_1);
//		delay(3600000);
//		GPIO_ResetBits(GPIOB,GPIO_Pin_1);
		
		// with loops
		for(int i = 0 ; i<3 ;i++){
			
			GPIO_SetBits(GPIOB,ledArray[i]);
			delay(3600000);
			GPIO_ResetBits(GPIOB,ledArray[i]);
		}
		
		for(int i = 2 ; i>0 ;i--){
			
			GPIO_SetBits(GPIOB,ledArray[i]);
			delay(3600000);
			GPIO_ResetBits(GPIOB,ledArray[i]);
			
		}
	}
}
