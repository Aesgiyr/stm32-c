#include "stm32f10x.h"                  // Device header
 
uint16_t buttonState=0;
uint16_t counter = 0;
 
void gpioConfig(){
	
	GPIO_InitTypeDef GPIOInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); // Led
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE); // Button
	
	// Led
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIOInitStructure);
	
	// Button
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIOInitStructure);
}

void delay(uint32_t time){
	while(time--);
}

int main(){
	
	gpioConfig();
	
	while(1){
		
		buttonState=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
		
		
		if(buttonState==1){
			counter++;
			delay(3600000);
			
			if((counter%3)==0){
				
				GPIO_SetBits(GPIOB,GPIO_Pin_0);
				GPIO_ResetBits(GPIOB,GPIO_Pin_1);
				GPIO_ResetBits(GPIOB,GPIO_Pin_2);
				
			}else if((counter%3)==1){
				
				GPIO_SetBits(GPIOB,GPIO_Pin_1);
				GPIO_ResetBits(GPIOB,GPIO_Pin_0);
				GPIO_ResetBits(GPIOB,GPIO_Pin_2);
			
			}else if((counter%3)==2){
				
				GPIO_SetBits(GPIOB,GPIO_Pin_2);
				GPIO_ResetBits(GPIOB,GPIO_Pin_0);
				GPIO_ResetBits(GPIOB,GPIO_Pin_1);
			}
		}
	
	
	}


}