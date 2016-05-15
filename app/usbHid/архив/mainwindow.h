#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include "usbhid.h"
#include "usb_debug.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    usb_debug *device;
    QTimer *timer, *timer1, *timer2;
    Ui::MainWindow *ui;
public slots:
    void ledRoutine1();
    void ledRoutine2();
    void devOpenRoutine();
    void rb1(void);
    void rb2(void);
    void send_to_dev(void);
    void get_from_dev(void);
    void autoPlugOn(void);
    void autoPlugOff(void);
};

#endif // MAINWINDOW_H
