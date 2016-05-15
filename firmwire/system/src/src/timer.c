#include "stm32f10x.h"
#include "platform_config.h"
#include "math.h"
#include "stdint.h"
#include "stdlib.h"
#include "timer.h"
#include "hw_config.h"

//uint16_t sin_ar[SINDSCR];

//void fill_sine(void)
//{
//	for(int i = 0; i<SINDSCR; i++)
// 		 sin_ar[i] = (uint16_t)(sin((i + 2) * pi / SINDSCR)* mag);
//}

void initTimer(void){
	// Configure SysTick
	SysTick->LOAD=TimerTick;
	SysTick->VAL=TimerTick;
	SysTick->CTRL=	SysTick_CTRL_CLKSOURCE_Msk |
	                SysTick_CTRL_TICKINT_Msk   |
					SysTick_CTRL_ENABLE_Msk;

	// настройка порта А на "AFIO output Push-pull"
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;

	GPIOA->CRH &= ~(GPIO_CRH_MODE8 | GPIO_CRH_MODE9 | GPIO_CRH_MODE10 | GPIO_CRH_MODE11); 		// Input mode (reset state)
	GPIOA->CRH |= GPIO_CRH_MODE8_0 | GPIO_CRH_MODE9_0 | GPIO_CRH_MODE10_0 | GPIO_CRH_MODE11_0; 	// Output mode, max speed 10 MHz
	GPIOA->CRH &= ~(GPIO_CRH_CNF8 | GPIO_CRH_CNF9 | GPIO_CRH_CNF10 | GPIO_CRH_CNF11);			// reset bits CNF
	GPIOA->CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_CNF9_1 | GPIO_CRH_CNF10_1 | GPIO_CRH_CNF11_1;		// In output mode (MODE[1:0] > 00): Alternate function output Push-pull

	RCC->CFGR &= ~RCC_CFGR_PPRE2;
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;  		//предделитель APB1

	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;		//Тактирование таймера TIM2
	TIM1->PSC = 72-1;						//Настройка предделителя таймера
	TIM1->ARR = 1000;						//регистр автоперезагрузки 1kHz
	TIM1->CCMR1 &= ~TIM_CCMR1_OC1M;							//mode CH1 is
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;		//PWM
	TIM1->CCMR1 &= ~TIM_CCMR1_OC2M;							//mode CH1 is
	TIM1->CCMR1 |= TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC1M_1;		//PWM
	TIM1->CCMR1 &= ~TIM_CCMR1_OC1M;							//mode CH1 is
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;		//PWM
	TIM1->CCMR1 &= ~TIM_CCMR1_OC1M;							//mode CH1 is
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;		//PWM*/

	TIM1->CCER |= TIM_CCER_CC1E;
	TIM1->BDTR |= TIM_BDTR_MOE;

	TIM1->CR1 |= TIM_CR1_CEN;				//Запускаем счет
}
