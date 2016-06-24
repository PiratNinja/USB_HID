#include "my_lib.h"
#include "stdarg.h"


void delay_ms(uint32_t dtms) {
	uint32_t holdST = SysTime_ms;
	uint8_t holdFlag = 0;

	while(SysTime_ms-holdST<dtms) {
		if (holdFlag==0) holdFlag=1;    //�������� ����� ������� �������� �������
		continue;
	}
}

uint16_t WTRB(const uint8_t* buffer, uint16_t count) {
	uint16_t i=0;

	if(transportBuf.WB) return 0;						//����� �� ������� ���� ������ � �������� �� ���������

	if(BUF_SIZE_TR - transportBuf.size < count) return 0; 		//�������� ������ ����������� ����� � ������, ���������� ������ �������

	transportBuf.WB = 1;									//��������� ����� ������� ������ � ��������

	for(; i<count; i++){
		transportBuf.ringBuffer[transportBuf.indexEnd++]=buffer[i];	//��������� �������� � ������
		transportBuf.indexEnd &= BUF_MASK;
	}
	transportBuf.size += i;

	transportBuf.WB = 0;									//����� ����� ������� ������ � ��������

	return count;
}

uint16_t RTRB(uint8_t* buffer, uint16_t count) {
	uint16_t i=0;

	if(transportBuf.WB) return 0;						//����� �� ������� ���� ������ �� ������� �� ���������

	if(transportBuf.size < count) count = transportBuf.size; 	//������ ������ � ������� ������ ��������������, ��������� ��� ��� ����

	transportBuf.WB = 1;									//��������� ����� ������� ������ � ��������

	for(;i<count; i++) {
		buffer[i]=transportBuf.ringBuffer[transportBuf.indexBegin++];	//���������� �������� �� �������
		transportBuf.indexBegin &= BUF_MASK;
	}
	transportBuf.size -= i;

	transportBuf.WB = 0;									//����� ����� ������� ������ � ��������

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

