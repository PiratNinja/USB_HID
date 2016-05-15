#include "my_lib.h"
#include "stdarg.h"


void delay_ms(uint32_t dtms) {
	uint32_t holdST = SysTime_ms;
	uint8_t holdFlag = 0;

	while(SysTime_ms-holdST<dtms) {
		if (holdFlag==0) holdFlag=1;    //проверка флага захвата текущего времени
		continue;
	}
}

uint16_t WTRB(const uint8_t* buffer, uint16_t count) {
	uint16_t i=0;

	if(transportBuf.WB) return 0;						//выход из функции если работа с буффером не завершена

	if(BUF_SIZE_TR - transportBuf.size < count) return 0; 		//превышен размер оставшегося места в буфере, завершение работы функции

	transportBuf.WB = 1;									//установка флага текущей работы с буффером

	for(; i<count; i++){
		transportBuf.ringBuffer[transportBuf.indexEnd++]=buffer[i];	//помещение значения в буффер
		transportBuf.indexEnd &= BUF_MASK;
	}
	transportBuf.size += i;

	transportBuf.WB = 0;									//сброс флага текущей работы с буффером

	return count;
}

uint16_t RTRB(uint8_t* buffer, uint16_t count) {
	uint16_t i=0;

	if(transportBuf.WB) return 0;						//выход из функции если чтение из буффера не завершено

	if(transportBuf.size < count) count = transportBuf.size; 	//размер данных в буффере меньше запрашиваемого, выгружаем все что есть

	transportBuf.WB = 1;									//установка флага текущей работы с буффером

	for(;i<count; i++) {
		buffer[i]=transportBuf.ringBuffer[transportBuf.indexBegin++];	//извлечение значения из буффера
		transportBuf.indexBegin &= BUF_MASK;
	}
	transportBuf.size -= i;

	transportBuf.WB = 0;									//сброс флага текущей работы с буффером

	return count;
}

uint16_t GetSizeRingBuf() {
	return transportBuf.size;
}

void myprintf(const char* fmt, ...)
{
	va_list arp;

	unsigned char buffer[256];
	uint8_t i = 0;

	va_start(arp, fmt);
	xsprintf_mv(buffer, fmt, arp);
	while(buffer[++i]);

	WTRB((uint8_t*)buffer, i);
}

