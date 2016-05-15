#include "usbhid.h"

usbHid::usbHid(unsigned short v, unsigned short p)
{
    waitPluginDevTimer = new QTimer();

    connect(waitPluginDevTimer, SIGNAL(timeout()), this, SLOT(hidOpen()));
    connect(this, SIGNAL(devConnected()), this, SLOT(stopWaitPluginDev()));

    vid = v; pid = p;
}

usbHid::~usbHid()
{

}

void usbHid::enumerate()
{
    // Enumerate and print the HID devices on the system
    struct hid_device_info *devs, *cur_dev;
    QString devinf;

    devs = hid_enumerate(0x0, 0x0);
    cur_dev = devs;

    while (cur_dev) {
        devinf.clear();
        devinf.append(QString("Device Found\n type: %1h %2h").arg(cur_dev->vendor_id,0,16).arg(cur_dev->product_id,0,16));
        devinf.append(QString("\n path: %1").arg(cur_dev->path));
        devinf.append(QString("\n Manufacturer:\t") + QString::fromWCharArray(cur_dev->manufacturer_string));
        devinf.append(QString("\n Product:\t") + QString::fromWCharArray(cur_dev->product_string));
        devinf.append("\n\n");

        cur_dev = cur_dev->next;
        emit valueChanged(devinf);
    }
    hid_free_enumeration(devs);
}

bool usbHid::hidOpen()
{
    if(!openDevice){
        if((handle = hid_open(vid, pid, NULL)) == NULL) {
            openDevice = false;
            emit devDisconnect();
            return false;
        }
        else {
            openDevice = true;
            emit devConnected();
            return true;
        }
    }
    else return true;
}

void usbHid::hidClose()
{
    if(openDevice){
        hid_close(handle);
        openDevice=false;
        emit devDisconnect();
    }
}

void usbHid::hid_send_feature(size_t length)
{
    res = hid_send_feature_report(handle, buf, length);
}

int usbHid::hid_get_feature(size_t length)
{
    return hid_get_feature_report(handle, buf, length);
}

void usbHid::waitPluginDev(void)
{
    if (!openDevice) {
         waitPluginDevTimer->start(1000);
    }
}

void usbHid::stopWaitPluginDev(void)
{
    waitPluginDevTimer->stop();
}

/*----------------------------------------------------------*/

usbHid hidInterface::hidHardwire(0x0, 0x0);

hidInterface::hidInterface(unsigned short v, unsigned short p)
{
    if(!hidHardwire.openDevice && (hidHardwire.vid == 0 || hidHardwire.pid == 0)){
        hidHardwire.vid = v;
        hidHardwire.pid = p;
    }
}

hidInterface::~hidInterface()
{
    if(hidHardwire.openDevice) hidHardwire.hidClose();
}

void hidInterface::autoPlug(bool enable)
{
    if(enable) {
        hidHardwire.waitPluginDev();
        connect(&hidHardwire, SIGNAL(devDisconnect()), &hidHardwire, SLOT(waitPluginDev()));
    }
    else {
        hidHardwire.stopWaitPluginDev();
        disconnect(&hidHardwire, SIGNAL(devDisconnect()), &hidHardwire, SLOT(waitPluginDev()));
    }
}
