#include "stm32f10x.h"
#include "platform_config.h"
#include "math.h"
#include "stdint.h"
#include "stdlib.h"

#define SINDSCR 100
#define pi 3.1415926535

uint16_t sin_ar[SINDSCR];

/*void fill_sine(void)
{
	for(int i = 0; i<SINDSCR; i++)
 		 sin_ar[i] = (uint16_t)(sin((i + 2) * pi / SINDSCR)* 1000);
}*/

void initTimer(void){

	//настройка на выход таймера, ноги PA8 (TIM1_CH1)

	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
	GPIOA->CRH |= GPIO_CRH_MODE8;

	GPIOA->CRH &= ~GPIO_CRH_CNF8;
	GPIOA->CRH |= GPIO_CRH_CNF8_1;

	RCC->CFGR &= ~RCC_CFGR_PPRE2;
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;  		//предделитель APB1

	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;		//Тактирование таймера TIM2
	TIM1->PSC = 72-1;						//Настройка предделителя таймера, 1MHz
	TIM1->ARR = 1000;						//регистр автоперезагрузки 1kHz
	TIM1->CCR1 = 500;
	TIM1->CCMR1 &= ~TIM_CCMR1_OC1M;							//mode CH1 is
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;		//PWM

	TIM1->CCER |= TIM_CCER_CC1E;
	TIM1->BDTR |= TIM_BDTR_MOE;

	TIM1->CR1 |= TIM_CR1_DIR;
	TIM1->CR1 |= TIM_CR1_CEN;				//Запускаем счет
}
