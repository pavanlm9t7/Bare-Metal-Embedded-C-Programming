
#include <stdint.h>
#include "stm32f767xx.h"

#define GPIOBEN				(1U<<1)
#define PIN0				(1U<<0)
#define	LED_PIN 			PIN0

int main(void)
{
	RCC->AHB1ENR |=GPIOBEN;

	GPIOB->MODER |= (1U<<0);
	GPIOB->MODER &= ~(1U<<1);


	for(;;){
		GPIOB->ODR ^= LED_PIN;
		for(volatile long i = 0; i<1000000; i++){}
	}
}
