
#include <stdint.h>

#define PERIPH_BASE			(0x40000000UL)
#define AHB1PERIPH_OFFSET	(0x00020000UL)
#define AHB1PERIPH_BASE		(PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOB_OFFSET		(0x00000400UL)
#define GPIOB_BASE			(AHB1PERIPH_BASE + GPIOB_OFFSET)
#define RCC_OFFSET			(0x00003800UL)
#define RCC_BASE			(AHB1PERIPH_BASE + RCC_OFFSET)
#define AHB1EN_R_OFFSET		(0x30UL)
#define RCC_AHB1EN_R		(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))
#define MODE_R_OFFSET		(0x00UL)
#define GPIOB_MODE_R		(*(volatile unsigned int *)(GPIOB_BASE + MODE_R_OFFSET))
#define OD_R_OFFSET			(0x14UL)
#define GPIOB_OD_R			(*(volatile unsigned int *)(GPIOB_BASE + OD_R_OFFSET))
#define GPIOBEN				(1U<<1)
#define PIN0				(1U<<0)
#define	LED_PIN 			PIN0
#define __IO				volatile

typedef struct
{
	volatile uint32_t DUMMY[12];
	volatile uint32_t AHB1EN_R;
}RCC_TypeDef;

typedef struct
{
	volatile uint32_t MODE_R;
	volatile uint32_t DUMMY[4];
	volatile uint32_t ODR;
}GPIO_TypeDef;

#define RCC					((RCC_TypeDef*)RCC_BASE)
#define GPIOB				((GPIO_TypeDef*)GPIOB_BASE)

int main(void)
{
    /* Loop forever */
	//RCC_AHB1EN_R |= GPIOBEN;
	RCC->AHB1EN_R |=GPIOBEN;

	//GPIOB_MODE_R |= (1U<<0);
	//GPIOB_MODE_R &= ~(1U<<1);
	GPIOB->MODE_R |= (1U<<0);
	GPIOB->MODE_R &= ~(1U<<1);


	for(;;){
		GPIOB->ODR ^= LED_PIN;
		for(volatile long i = 0; i<1000000; i++){}
		//GPIOB_OD_R &= ~(LED_PIN);
		//for(volatile long i =0; i<1000000; i++){}
	}
}
