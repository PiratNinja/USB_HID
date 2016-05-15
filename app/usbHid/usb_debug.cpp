#include "usb_debug.h"
#include <iostream>

/*------------------------usb_debug-----------------------------*/

usb_debug::usb_debug(unsigned short v, unsigned short p) : hidInterface(v, p) {
    vReq.append(new get_num_bytes_to_rx(0x6, 3, 2));
    vReq.append(new get_byte_secquence_of_ext_buff(0x5, 64, 61));

    pollTimerExternalBuffer = new QTimer(this);

    connect(pollTimerExternalBuffer, SIGNAL(timeout()), this, SLOT(getSizeExtBuffer()));
    connect(this, SIGNAL(sizeExtBuff_NZS()), this, SLOT(getSeqOfByteExtBuff()));

    sizeExtBuff = 0;
}

usb_debug::~usb_debug() {

}

void usb_debug::copyToInputBuffer(const size_t indexBegin, const size_t indexEnd) {
    for(size_t i = indexBegin; i<=indexEnd; i++)
        inputBuffer.append(hidHardwire.buf[i]);
    emit inputBufferUPD();
}

/*----------------------slots--------------------*/

void usb_debug::onPullingExtBuffer(void) {
    pollTimerExternalBuffer->start(10);
}

void usb_debug::offPullingExtBuffer(void) {
    pollTimerExternalBuffer->stop();
}

void usb_debug::getSizeExtBuffer(void) {
    sizeExtBuff = vReq[0]->execReqIn();
    if (sizeExtBuff > 0) {
        offPullingExtBuffer();        //отключаем проверку количества байт на прием
        emit sizeExtBuff_NZS();
    }
}

void usb_debug::getSeqOfByteExtBuff(void) {
    size_t countCycle = sizeExtBuff/61;
    size_t numOfBytesReceived, temp;

    if(sizeExtBuff % 60 > 0) countCycle++;

    while(countCycle) {
        numOfBytesReceived = vReq[1]->execReqIn();
        if (numOfBytesReceived) {
            //temp = vReq[0]->execReqIn();
            copyToInputBuffer(3, 3 + numOfBytesReceived);
            countCycle--;
        }
    }
    onPullingExtBuffer();
}

/*-----------------------requests-------------------------*/

size_t get_num_bytes_to_rx::execReqIn(void) {                       //idReport, pSize, payloadSize - 6,PacketSize(64),2
    interface->buf[0] = idR;
    interface->buf[1] = 0;
    interface->buf[2] = 0;

    interface->hid_get_feature(pS);
    countOfByte=(unsigned short int)interface->buf[2];                          //get H byte  (end payload)
    countOfByte=(countOfByte<<8)|(unsigned short int)interface->buf[1];         //get L byte  (begin payload)
    return countOfByte;
}

size_t get_byte_secquence_of_ext_buff::execReqIn(void) {            //idReport, pSize, payloadSize - 5, PacketSize(64), 61
    interface->buf[0] = idR;
    interface->buf[1] = 0;
    interface->buf[2] = 0;

    interface->hid_get_feature(pS);
    countOfByte=(unsigned short int)interface->buf[2];                          //get H byte  (end payload)
    countOfByte=(countOfByte<<8)|(unsigned short int)interface->buf[1];         //get L byte  (begin payload)
    return countOfByte;
}
