#include "gpio.h"

#define GPIOBEN				(1U<<1)
#define PIN0				  (1U<<0)
#define	LED_PIN 			PIN0
#define BTN_PIN		    (1U<<13)

void led_init(void)
{
  RCC->AHB1ENR |=GPIOBEN;
	GPIOB->MODER |= (1U<<0);
	GPIOB->MODER &= ~(1U<<1);
}

void led_on(void)
{
  GPIOB->BSRR = LED_PIN;
}

void led_off(void)
{
  GPIOB->BSRR = (LED_PIN<<16);
}

void button_init(void)
{
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
  GPIOC->MODER &= ~(3U << (13 * 2));         // Input mode
  GPIOC->PUPDR &= ~(3U << (13 * 2));         // Clear pull resistors
  GPIOC->PUPDR |=  (2U << (13 * 2));         // Enable pull-down
}

bool get_btn_state(void)
{
  return (GPIOC->IDR & (1U << 13)) != 0;
}