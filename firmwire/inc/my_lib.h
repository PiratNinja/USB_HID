#include "stdint.h"
#include "stm32f10x.h"

//################################################################
#define BUF_SIZE_TR 512
#define BUF_MASK (BUF_SIZE_TR-1)

//################################################################
typedef struct
{
	uint8_t ringBuffer[512];
	uint8_t WB;
	uint16_t indexBegin, indexEnd, size;
}transport_buffer;

//################################################################
extern __IO int32_t SysTime_ms;
uint8_t buffer[BUF_SIZE_TR];

//################################################################

static transport_buffer transportBuf = {0,0,0,0,0};

//################################################################
uint16_t WTRB(const uint8_t* buffer, uint16_t count);
uint16_t RTRB(uint8_t* buffer, uint16_t count);
uint16_t GetSizeRingBuf(void);

void myprintf(const char* fmt, ...);

void delay_ms(uint32_t dtms);

/*void printf(const char* fmt, ...);*/
