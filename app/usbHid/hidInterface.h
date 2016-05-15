#ifndef HIDINTERFACE_H
#define HIDINTERFACE_H

#include "usbhid.h"

class hidInterface : public QObject
{
    Q_OBJECT

public:
    static usbHid hidHardwire;
    hidInterface(unsigned short v, unsigned short p);
    ~hidInterface();
};

usbHid hidInterface::hidHardwire();

#endif // HIDINTERFACE_H
