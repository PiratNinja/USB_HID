#ifndef USBHID_H
#define USBHID_H

#include <QObject>
#include <QString>
#include <QMessageBox>
#include <QTimer>
#include <QVector>

#include <stdio.h>
#include <stdlib.h>

#include "hidapi.h"

#define MAX_STR 255
#define PacketSize 64


class usbHid : public QObject
{
    Q_OBJECT

public:
    unsigned short vid, pid;
    unsigned char buf[PacketSize-1];

    usbHid(unsigned short v=0x0, unsigned short p=0x0);
    ~usbHid();
    bool statDev(void) { return openDevice; }

private:
    bool openDevice;
    hid_device* handle;
    QTimer* waitPluginDevTimer;

public slots:
    void enumerate();
    bool hidOpen();
    void hidClose();
    void hid_send_feature(size_t);
    int  hid_get_feature(size_t);
    void waitPluginDev(void);
    void stopWaitPluginDev(void);

signals:
    void valueChanged(const QString&);
    void devDisconnect(void);
    void devConnected(void);
};

class req;

class hidInterface : public QObject
{
    Q_OBJECT

public:
    static usbHid hidHardwire;
    hidInterface(unsigned short v, unsigned short p);
    ~hidInterface();

    QVector<req*> vReq;

public slots:
    void autoPlug(bool);              // true/false - enable/disable wait for plugin HID device
};

class req {
public:
    req(unsigned char idReport = 0, size_t pSize = 0, size_t payloadSize = 0): idR(idReport), pS(pSize), plS(payloadSize) { };
    ~req();

    unsigned short int countOfByte;
    unsigned char idR;
    size_t pS, plS;
    usbHid* interface = &hidInterface::hidHardwire;

    virtual size_t execReqIn(void) = 0;
};

#endif // USBHID_H
