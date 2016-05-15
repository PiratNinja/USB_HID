#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "usb_debug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    device = new usb_debug(0x0483, 0x5711);

    device->autoPlug(true);

    timer = new QTimer(this);
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    ui->setupUi(this);
    setCentralWidget(ui->groupBox_2);
    ui->statusBar->hide();

    QString lb = QString("vid - %1, pid - %2").arg(device->hidHardwire.vid, 0, 16).arg(device->hidHardwire.pid, 0, 16);
    ui->label->setText(lb);
    //ui->label_2->setStyleSheet("qproperty-alignment: 'AlignCenter | AlignCenter';");
    ui->label_2->clear();
    ui->radioButton_1->setChecked(true);
    ui->groupBox_3->setEnabled(false);
    ui->openDev->setEnabled(false);
    ui->closeDev->setEnabled(false);
    ui->label_3->setFixedSize(20,20);
    ui->label_3->setStyleSheet( "border-radius: 10px; background-color: black;" );
    ui->label_4->setFixedSize(20,20);
    ui->label_4->setStyleSheet( "border-radius: 10px; background-color: black;" );

    connect(ui->enumerate, SIGNAL(clicked()), &device->hidHardwire, SLOT(enumerate()));
    connect(&device->hidHardwire, SIGNAL(valueChanged(const QString&)), ui->textBrowser, SLOT(append(const QString&)));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->openDev, SIGNAL(clicked()), this, SLOT(autoPlugOn()));
    connect(ui->closeDev, SIGNAL(clicked()), this, SLOT(autoPlugOff()));
    connect(&device->hidHardwire, SIGNAL(devConnected()), this, SLOT(devOpenRoutine()));
    connect(&device->hidHardwire, SIGNAL(devDisconnect()), this, SLOT(devOpenRoutine()));
    connect(ui->radioButton_1, SIGNAL(clicked()), this, SLOT(rb1()));
    connect(ui->radioButton_2, SIGNAL(clicked()), this, SLOT(rb2()));
    connect(ui->send_to_, SIGNAL(clicked()),this, SLOT(send_to_dev()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(get_from_dev()));
    connect(ui->readFromDev, SIGNAL(clicked()), device, SLOT(onPullingExtBuffer()));
    connect(device, SIGNAL(inputBufferUPD()),this, SLOT(get_from_dev()));
    connect(device, SIGNAL(debug()), this, SLOT(debug()));
}

MainWindow::~MainWindow()
{
    if (device->hidHardwire.statDev())device->hidHardwire.hidClose();
    delete device;
    delete ui;
}

void MainWindow::devOpenRoutine()
{
    if (device->hidHardwire.statDev()){
        ui->label_2->setText("<font SIZE=7 color=blue> <b> Devce online. </b> </font>");
        ui->groupBox_3->setEnabled(true);
        device->onPullingExtBuffer();
    }
    else {
        ui->label_2->setText("<font size=7> <b> Device offline. </b> </font>");
        ui->groupBox_3->setEnabled(false);
    }
}

void MainWindow::rb1()
{
    ui->openDev->setEnabled(false);
    ui->closeDev->setEnabled(false);
    device->hidHardwire.waitPluginDev();
}

void MainWindow::rb2()
{
    ui->openDev->setEnabled(true);
    ui->closeDev->setEnabled(true);
    device->hidHardwire.stopWaitPluginDev();
}

void MainWindow::autoPlugOn() {
    device->autoPlug(true);
}

void MainWindow::autoPlugOff() {
    device->autoPlug(false);
    device->hidHardwire.hidClose();
}


void MainWindow::send_to_dev(void)
{
    // Send a Feature Report to the device ()
    device->hidHardwire.buf[0] = 5; // First byte is report number
    if(ui->lineEdit->text().isEmpty()) return;
    QByteArray Qba = (ui->lineEdit->text().toUtf8());
    int sizePkg = Qba.size();
    char* Rv = Qba.data();
    for(int i=1; i<sizePkg; i++){
        unsigned char t = (unsigned char)*Rv;
        Rv++;
        device->hidHardwire.buf[i] = t;
    }

    device->hidHardwire.hid_send_feature(PacketSize);
}

void MainWindow::get_from_dev(){
    QString tempStr;
    ui->lcdNumber->display(device->inputBuffer.size());

    while(device->inputBuffer.size())
        tempStr.append(device->inputBuffer.dequeue());

    ui->textBrowser_2->insertPlainText(tempStr);
    tempStr.clear();
}

void MainWindow::debug() {
    ui->lcdNumber->display((int) device->size2);
}

