/**
  ******************************************************************************
  * @file    main.c
  * @author  MCD Application Team
  * @version V1
  * @date    02-05-2016
  * @brief   Jackal
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "stm32f10x.h"
#include "hw_config.h"
//#include "usb_lib.h"
//#include "usb_pwr.h"
#include "my_lib.h"
//#include "usb_desc.h"
//#include "xprintf.h"
//#include "timer.h"

#define SYSCLK_FREQ  		8e6
#define TimerTick			SYSCLK_FREQ/1000-1
#define PWM_FREQ 			10e3
#define DELAY 				50
#define NUMOFPLAYERS 		4
#define NUMOFBUTTONS 		4
#define TIMEOUTKEY			1500
#define BLINKTIME 			200
#define RUNFIRETIME			1000
#define MINBRIGHTLVL		10
#define BLINKACTGAMER		100

typedef enum {
	inQueue,
	outQueue
} QueueEn;

typedef enum {
	activity,
	notActivity,
} signOfActivity;

typedef enum {
	button1 = GPIO_IDR_IDR3,
	button2 = GPIO_IDR_IDR4,
	button3 = GPIO_IDR_IDR5,
	button4 = GPIO_IDR_IDR6,
	errorButton
} buttonGamer;

typedef struct {
	signOfActivity activityFlag;
	uint16_t* led;
	buttonGamer button;
	QueueEn presenceFL;
} gamerJkl;

gamerJkl gamer[NUMOFPLAYERS] = {{notActivity, (uint16_t*) &TIM1->CCR1, button1, inQueue},
		 	 	 	 			{notActivity, (uint16_t*) &TIM1->CCR2, button2, inQueue},
								{notActivity, (uint16_t*) &TIM1->CCR3, button3, inQueue},
								{notActivity, (uint16_t*) &TIM1->CCR4, button4, inQueue}};

__IO uint16_t brightLevel;
__IO uint8_t pushFlag = 0;

/***************************************debug****************************************/
__IO int32_t SysTime_ms;

/************************************************************************************/

void enableEXTI3_6() {
	NVIC_EnableIRQ(EXTI3_IRQn);
	NVIC_EnableIRQ(EXTI4_IRQn);
	NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void disableEXTI3_6(){
	NVIC_DisableIRQ(EXTI3_IRQn);
	NVIC_DisableIRQ(EXTI4_IRQn);
	NVIC_DisableIRQ(EXTI9_5_IRQn);
}

uint8_t countGamersInQueuef() {
	uint8_t count = 0;
	for (uint8_t i = 0; i < NUMOFPLAYERS; i++) {
		if (gamer[i].presenceFL == inQueue) count++;
	}
	return count;
}

void ledSwitchActGamer() {
	for(uint8_t i = 0; i < NUMOFPLAYERS ; i++){
		if(gamer[i].activityFlag == activity) *gamer[i].led = brightLevel;
		else *gamer[i].led = 0;
	}
}

inline void onLedGamersInQueoe() {
	for(uint8_t i = 0; i < NUMOFPLAYERS; i++)
		*gamer[i].led = (gamer[i].presenceFL == inQueue) ? brightLevel : 0;
}

inline void ledAllGamersOFF() {
	for(uint8_t i = 0; i < NUMOFPLAYERS; i++)
		*gamer[i].led = 0;
}

inline void ledSwitch() {
	for(uint8_t i = 0; i < NUMOFPLAYERS && pushFlag == 0; i++) {
		*gamer[i].led = brightLevel;
		delay_ms(RUNFIRETIME);
		ledAllGamersOFF();
	}
}

inline void resetActivityflagAllGamers(){
	for(uint8_t i = 0; i < NUMOFPLAYERS; i++)
		gamer[i].activityFlag = notActivity;
}

void shiftGamerTurn() {
	uint8_t countCycle = 0;

	for(uint8_t i = 0; i < NUMOFPLAYERS; i++){
		if (gamer[i].activityFlag == activity) {
			gamer[i].activityFlag = notActivity;
			i = (i < NUMOFPLAYERS - 1) ? i+1 : 0;
			while(gamer[i].presenceFL != inQueue && countCycle < NUMOFPLAYERS){ // перебор проделжается пока не находится
				i = (i < NUMOFPLAYERS - 1) ? i+1 : 0;							// присутствующий в очереди и кол.
				countCycle++;													// циклов перебора не больше количества игроков.
			}
			gamer[i].activityFlag = (countCycle < NUMOFPLAYERS) ? activity : notActivity;
			ledSwitchActGamer();
			delay_ms(BLINKACTGAMER);
			ledAllGamersOFF();
			delay_ms(BLINKACTGAMER);
			ledSwitchActGamer();
			delay_ms(BLINKACTGAMER);
			ledAllGamersOFF();
			delay_ms(BLINKACTGAMER);
			ledSwitchActGamer();
			delay_ms(BLINKACTGAMER);
			ledAllGamersOFF();
			break;
		}
	}
}

buttonGamer buttonScan() {
	uint8_t countKey = 0, numKey = 0;

	for (uint8_t i = 0 ; i < NUMOFBUTTONS; i++){
		if((GPIOB->IDR >> (3 + i) & 0x01) == 0x00) {
			countKey++;
			numKey = i;
		}
	}
	if (countKey == 1) {
		switch (numKey) {
		case 0:
			return button1;
			break;
		case 1:
			return button2;
			break;
		case 2:
			return button3;
			break;
		case 3:
			return button4;
			break;
		}
	} else
		return errorButton;
}

void resetPendingBitsOf_EXTI(){
	EXTI->PR |= EXTI_PR_PR3 | EXTI_PR_PR4 | EXTI_PR_PR5 | EXTI_PR_PR6;
}

void enRemQueueGamer(buttonGamer b){
	uint8_t i = 0;
	while(gamer[i].button != b && i < NUMOFPLAYERS + 1 ) i++;
	if (i != NUMOFPLAYERS) {
		if (gamer[i].presenceFL == outQueue) {
			//добавляем, мигаем три раза, делаем активным добавленного
			gamer[i].presenceFL = inQueue;
			ledAllGamersOFF();
			delay_ms(BLINKTIME);
			onLedGamersInQueoe();
			delay_ms(BLINKTIME);
			ledAllGamersOFF();
			delay_ms(BLINKTIME);
			onLedGamersInQueoe();
			delay_ms(BLINKTIME);
			ledAllGamersOFF();
			delay_ms(BLINKTIME);
			onLedGamersInQueoe();
			delay_ms(BLINKTIME);
			ledAllGamersOFF();
			resetActivityflagAllGamers();
			gamer[i].activityFlag = activity;
		} else {
			//удаляем, мигаем два раза; делаем переход хода, если удаленный из очереди был активным;
			gamer[i].presenceFL = outQueue;
			//if (gamer[i].activityFlag == activity) shiftGamerTurn();
			ledAllGamersOFF();
			delay_ms(BLINKTIME);
			onLedGamersInQueoe();
			delay_ms(BLINKTIME);
			ledAllGamersOFF();
			delay_ms(BLINKTIME);
			onLedGamersInQueoe();
			delay_ms(BLINKTIME);
			ledAllGamersOFF();
			if (gamer[i].activityFlag == activity) shiftGamerTurn();
		}
	}
}

uint8_t getNumActivity() {
	uint8_t i;
	for(i = 0; i < NUMOFPLAYERS; i++)
		if(gamer[i].activityFlag == activity) break;
	return i;
}

/*******************************************************************************
* Function Name  : main.
* Description    : main routine.
* Input          : None.
* Output         : None.
* Return         : ************************************************************/
int main(void)
{
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
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;  			//предделитель APB1

	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;			//Тактирование таймера TIM2
	TIM1->PSC = SYSCLK_FREQ/10e5 - 1;			//Настройка предделителя таймера
	TIM1->ARR = 1000;							//регистр автоперезагрузки 1kHz
	TIM1->CCMR1 &= ~TIM_CCMR1_OC1M;							//mode CH1 is
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;		//PWM
	TIM1->CCMR1 &= ~TIM_CCMR1_OC2M;							//mode CH2 is
	TIM1->CCMR1 |= TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1;		//PWM
	TIM1->CCMR2 &= ~TIM_CCMR2_OC3M;							//mode CH3 is
	TIM1->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1;		//PWM
	TIM1->CCMR2 &= ~TIM_CCMR2_OC4M;							//mode CH4 is
	TIM1->CCMR2 |= TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1;		//PWM*/

	TIM1->CCER 	|= TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E | TIM_CCER_CC4E |
				   TIM_CCER_CC1P | TIM_CCER_CC2P | TIM_CCER_CC3P | TIM_CCER_CC4P; //разрешение и инвертирование выходного сигнала
	TIM1->BDTR |= TIM_BDTR_MOE;

	TIM1->CR1 |= TIM_CR1_CEN;			//Запускаем счет

	//настройка вывода 3 порта А на вход аналогового сигнала
	GPIOA->CRL &= ~ GPIO_CRL_CNF3;
	GPIOA->CRL &= ~ GPIO_CRL_MODE3;

	//настройка ADC1
	RCC->CFGR &= ~RCC_CFGR_ADCPRE;		//предделитель
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV2;	//=2
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; //разрешение тактирования

	ADC1->CR1 |= ADC_CR1_EOCIE;			//разрешение прерывания по окончанию преобраования

	ADC1->CR2 |= ADC_CR2_ADON;

	ADC1->CR2 |= ADC_CR2_EXTSEL;		//старт по SWSTART
	ADC1->CR2 |= ADC_CR2_EXTTRIG;

	ADC1->CR2 |= ADC_CR2_CONT;			//Continuous conversion mode
	ADC1->SQR1 &= ~ADC_SQR1_L;			//количество каналов на преобразование - 1
	ADC1->SQR3 &= ~ADC_SQR3_SQ1;			 		//select chanel is
	ADC1->SQR3 |= ADC_SQR3_SQ1_0 | ADC_SQR3_SQ1_1; 	//num 3.

	ADC1->SMPR2 |= ADC_SMPR2_SMP3_2 | ADC_SMPR2_SMP3_1 | ADC_SMPR2_SMP3_0;		//chanel 3 is 239.5 cycles

	ADC1->CR2 |= ADC_CR2_RSTCAL;
	while ((ADC1->CR2 & ADC_CR2_RSTCAL) == ADC_CR2_RSTCAL) {}

	ADC1->CR2 |= ADC_CR2_CAL;
	while ((ADC1->CR2 & ADC_CR2_CAL) == ADC_CR2_CAL) {}

	ADC1->CR2 |= ADC_CR2_ADON;

	//конфиг входов для кнопок (floating input), PB3, PB4, PB5, PB6
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_DISABLE;

	GPIOB->CRL &= ~(GPIO_CRL_MODE3 | GPIO_CRL_MODE4 | GPIO_CRL_MODE5 | GPIO_CRL_MODE6 );
	GPIOB->CRL &= ~(GPIO_CRL_CNF3 | GPIO_CRL_CNF4 | GPIO_CRL_CNF5 | GPIO_CRL_CNF6);
	GPIOB->CRL |= GPIO_CRL_CNF3_0 | GPIO_CRL_CNF4_0 | GPIO_CRL_CNF5_0 |GPIO_CRL_CNF6_0;
	//конфиг EXTI на прерывания от PB3, PB4, PB5, PB6
	AFIO->EXTICR[0] &= ~AFIO_EXTICR1_EXTI3;
	AFIO->EXTICR[1] &= ~AFIO_EXTICR2_EXTI4;
	AFIO->EXTICR[1] &= ~AFIO_EXTICR2_EXTI5;
	AFIO->EXTICR[1] &= ~AFIO_EXTICR2_EXTI6;
	AFIO->EXTICR[0] |= AFIO_EXTICR1_EXTI3_PB;
	AFIO->EXTICR[1] |= AFIO_EXTICR2_EXTI4_PB;
	AFIO->EXTICR[1] |= AFIO_EXTICR2_EXTI5_PB;
	AFIO->EXTICR[1] |= AFIO_EXTICR2_EXTI6_PB;
	//конфиг прерываний маскирование прерываний конф. EXTI
	EXTI->IMR |= EXTI_IMR_MR3;
	EXTI->IMR |= EXTI_IMR_MR4;
	EXTI->IMR |= EXTI_IMR_MR5;
	EXTI->IMR |= EXTI_IMR_MR6;
	//настройка прерываний по отриц. фронту
	EXTI->FTSR |= EXTI_FTSR_TR3;
	EXTI->FTSR |= EXTI_FTSR_TR4;
	EXTI->FTSR |= EXTI_FTSR_TR5;
	EXTI->FTSR |= EXTI_FTSR_TR6;

	//включение/настройка прерываний
	NVIC_SetPriority(EXTI3_IRQn, 0xFF);
	NVIC_SetPriority(EXTI4_IRQn, 0xFF);
	NVIC_SetPriority(EXTI9_5_IRQn, 0xFF);
	NVIC_SetPriority(ADC1_2_IRQn, 0xEF);
	enableEXTI3_6();
	NVIC_EnableIRQ(ADC1_2_IRQn);

	//конф. режима пониженного энергопотребления (Sleep-now mode)
	SCB->SCR &= (uint32_t)~((uint32_t)SCB_SCR_SLEEPDEEP);
	SCB->SCR &= (uint32_t)~((uint32_t)SCB_SCR_SLEEPONEXIT);


	while (1) {
		if (pushFlag == 0) ledSwitch();
		else { //есть присутствующие в очереди
			ledSwitchActGamer();
			__WFI();		//вход в Sleep-now mode
		}
	}
}

//Обработка прерываний
void ADC1_2_IRQHandler (void) {
	brightLevel = ((ADC1->DR >> 2) < MINBRIGHTLVL) ? MINBRIGHTLVL : (ADC1->DR >> 2);
}

void gen_handler_EXTI_3_6(void) {
	__IO uint32_t i = 0;
	__IO uint32_t i2 = 0;
	__IO buttonGamer temp = buttonScan();

	if (temp != errorButton && pushFlag == 1) {
		while(buttonScan() == temp  && i < TIMEOUTKEY + 2){
			delay_ms(1);
			i++;
		}
		if(i > TIMEOUTKEY) { 			//добавление/удаление игрока из очереди
			enRemQueueGamer(temp);
		}
		else if (temp == gamer[getNumActivity()].button) shiftGamerTurn();
	}
	else if (temp != errorButton && pushFlag == 0) { //активирование игрока нажавшего клвишу
		while(gamer[i2].button != temp && i2 < NUMOFPLAYERS + 1 ) i2++;
		gamer[i2].activityFlag = activity;
	}
	pushFlag = 1;
	resetPendingBitsOf_EXTI();
}

void EXTI3_IRQHandler(void) {
	gen_handler_EXTI_3_6();
}

void EXTI4_IRQHandler(void) {
	gen_handler_EXTI_3_6();
}

void EXTI9_5_IRQHandler(void) {
	gen_handler_EXTI_3_6();
}
