#include "stm32f10x.h"                  // Device header


uint16_t buttonState=0;
uint16_t counter = 0;
uint32_t speed[3]={990000,7200000,360000};

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

int ledArray[3] = {GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_2};

int main(){
	
	gpioConfig();
	
	while(1){
		buttonState=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
		if(buttonState==1){
			counter++;
			delay(720000);
		}
		
		if(counter>=3){
			counter=0;
			}

		for(int i = 0 ; i<3 ;i++){
			buttonState=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
			if(buttonState==1){
				counter++;
				delay(720000);
			}
			
			if(counter>=3){
				counter=0;
				}
	
			GPIO_SetBits(GPIOB,ledArray[i]);
			delay(speed[counter]);
			GPIO_ResetBits(GPIOB,ledArray[i]);
		}
		
		
		for(int i = 2 ; i>0 ;i--){
			buttonState=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
			if(buttonState==1){
				counter++;
				delay(720000);
			}
			
			if(counter>=3){
				counter=0;
				}
			
			GPIO_SetBits(GPIOB,ledArray[i]);
			delay(speed[counter]);
			GPIO_ResetBits(GPIOB,ledArray[i]);
			
		}
		buttonState=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
		if(buttonState==1){
			counter++;
			delay(720000);
		}
		
		if(counter>=3){
			counter=0;
			}
		
		
	}
}


