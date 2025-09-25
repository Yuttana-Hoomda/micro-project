#define STM32F411xE
#include "stm32f4xx.h"
#include "sub_function.h"

void seven_segment(int number) {
		GPIOC->MODER &= ~(GPIO_MODER_MODER7);
		GPIOC->MODER |= (0b01 << GPIO_MODER_MODER7_Pos);
		GPIOC->OTYPER &= ~(GPIO_OTYPER_OT7);
		GPIOC->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED7);

		GPIOB->MODER &= ~(GPIO_MODER_MODER10);
		GPIOB->MODER |= (0b01 << GPIO_MODER_MODER10_Pos);
		GPIOB->OTYPER &= ~(GPIO_OTYPER_OT10);
		GPIOB->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED10);

		GPIOA->MODER &= ~(GPIO_MODER_MODER8);
		GPIOA->MODER |= (0b01 << GPIO_MODER_MODER8_Pos);
		GPIOA->OTYPER &= ~(GPIO_OTYPER_OT8);
		GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED8);

		GPIOA->MODER &= ~(GPIO_MODER_MODER9);
		GPIOA->MODER |= (0b01 << GPIO_MODER_MODER9_Pos);
		GPIOA->OTYPER &= ~(GPIO_OTYPER_OT9);
		GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED9);

		GPIOC->BSRR = (1 << (7 + 16));
		GPIOA->BSRR = (1 << (8 + 16));
		GPIOB->BSRR = (1 << (10 + 16));
		GPIOA->BSRR = (1 << (9 + 16));

		if(number == 1) {
			GPIOC->BSRR = (1 << 7);
		} else if(number == 2) {
			GPIOA->BSRR = (1 << 8);
		} else if (number == 3) {
			GPIOC->BSRR = (1 << 7);
			GPIOA->BSRR = (1 << 8);
		} else if (number == 4) {
			GPIOB->BSRR = (1 << 10);
		} else if (number == 5) {
			GPIOB->BSRR = (1 << 10);
			GPIOC->BSRR = (1 << 7);
		} else {
			GPIOC->BSRR = (1 << (7 + 16));
			GPIOA->BSRR = (1 << (8 + 16));
			GPIOB->BSRR = (1 << (10 + 16));
			GPIOA->BSRR = (1 << (9 + 16));
		}
}
