#include "usb_debug.h"

/*------------------------usb_debug-----------------------------*/

usb_debug::usb_debug(unsigned short v, unsigned short p) : hidInterface(v, p) {
    vReq.append(new get_num_bytes_to_rx(6,3,2));
    vReq.append(new get_byte_secquence_of_ext_buff(5,64,61));

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
    pollTimerExternalBuffer->start(1);
}

void usb_debug::offPullingExtBuffer(void) {
    pollTimerExternalBuffer->stop();
}

void usb_debug::getSizeExtBuffer(void) {
    sizeExtBuff = vReq[0]->execReqIn();
    if (sizeExtBuff > 0) emit sizeExtBuff_NZS();
}

void usb_debug::getSeqOfByteExtBuff(void) {
    int i=0;
    do {
        i++;
        size_t size = vReq[1]->execReqIn();
        copyToInputBuffer(3, 3 + size);
        sizeExtBuff-=size;
    } while(sizeExtBuff > 0);
    onPullingExtBuffer();
}

/*-----------------------requests-------------------------*/

size_t get_num_bytes_to_rx::execReqIn(void) {                       //idReport, pSize, payloadSize - 6,3,2
    interface->buf[0] = idR;

    if (interface->openDevice) {
        interface->hid_get_feature(pS);
        countOfByte=(unsigned short int)interface->buf[2];                          //get H byte  (end payload)
        countOfByte=(countOfByte<<8)|(unsigned short int)interface->buf[1];         //get L byte  (begin payload)
    }
    return countOfByte;
}

size_t get_byte_secquence_of_ext_buff::execReqIn(void) {            //idReport, pSize, payloadSize - 5, PacketSize(64), 61
    interface->buf[0] = idR;

    if (interface->openDevice) {
        interface->hid_get_feature(pS);
        countOfByte=(unsigned short int)interface->buf[2];                          //get H byte  (end payload)
        countOfByte=(countOfByte<<8)|(unsigned short int)interface->buf[1];         //get L byte  (begin payload)
    }
    return countOfByte;
}

/*    if (interface->openDevice){
        //-----------get count Rx byte
        interface->buf[0] = 6;
        interface->hid_get_feature(3);
        temp=(unsigned short int)interface->buf[2];
        temp=(temp<<8)|(unsigned short int)interface->buf[1];

        if(temp == 0) return ;

        //ui->lcdNumber->display(temp);
        cycleCount = (unsigned short int) temp /(PacketSize-4);
        remain = (unsigned short int) temp % (PacketSize-4);

        QVector<unsigned char> rxBuffer;

        interface->buf[0] = 5;
        while(cycleCount--){
            do{
                interface->hid_get_feature(PacketSize);

                temp=(unsigned short int)interface->buf[2];
                temp=(temp<<8)|(unsigned short int)interface->buf[1];
            }while(temp == 0);

            for(unsigned short int i = 3; i<PacketSize-4+3; i++)
                rxBuffer.push_back((char)interface->buf[i]);
        }

        interface->buf[0] = 5;
        if (remain){
            do{
                interface->hid_get_feature(PacketSize);

                temp=(unsigned short int)interface->buf[2];
                temp=(temp<<8)|(unsigned short int)interface->buf[1];
            }while(temp == 0);

            for(unsigned short int i = 3; i < remain+3; i++)
                rxBuffer.push_back((char)interface->buf[i]);
        }

        if(rxBuffer.size() == 0) return;

        QString tempStr;
        ui->textBrowser_2->append("DEV-> ");
        for(auto i = rxBuffer.begin(); i != rxBuffer.end(); i++)
            if(*i=='\n') {
                ui->textBrowser_2->append("<font color = red> <b> " + tempStr + "</b> </font>");
                tempStr.clear();
            } else {
                tempStr.append(*i);
            }
    }
}*/
