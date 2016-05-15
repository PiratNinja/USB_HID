#ifndef USB_DEBUG_H
#define USB_DEBUG_H

#include "usbhid.h"
#include <QQueue>
#include <QTimer>

class usb_debug : public hidInterface {
    Q_OBJECT

public:
    usb_debug(unsigned short v, unsigned short p);
    ~usb_debug();

public:
    QQueue <unsigned char> inputBuffer;
    QQueue <unsigned char> outputBuffer;

    QTimer* pollTimerExternalBuffer;
    size_t  sizeExtBuff;
    //debug

    size_t size2;

public slots:
    void copyToInputBuffer(const size_t indexBegin, const size_t indexEnd);
    void onPullingExtBuffer(void);
    void offPullingExtBuffer(void);
    void getSizeExtBuffer(void);
    void getSeqOfByteExtBuff(void);

signals:
    void inputBufferUPD(void);
    void outputBufferUPD(void);
    void sizeExtBuff_NZS(void);
    void debug(void);
};

class get_num_bytes_to_rx : public req {
public:
    get_num_bytes_to_rx(unsigned char idReport = 0, size_t pSize = 0, size_t payloadSize = 0) : req(idReport, pSize, payloadSize) { }
    size_t execReqIn(void);
};

class get_byte_secquence_of_ext_buff : public req {
public:
    get_byte_secquence_of_ext_buff(unsigned char idReport = 0, size_t pSize = 0, size_t payloadSize = 0) : req(idReport, pSize, payloadSize) { }
    size_t execReqIn(void);
};

#endif // USB_DEBUG_H
