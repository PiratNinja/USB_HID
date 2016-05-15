/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *enumerate;
    QPushButton *openDev;
    QLabel *label;
    QPushButton *closeDev;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_4;
    QTextBrowser *textBrowser_2;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit;
    QPushButton *send_to_;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    QLCDNumber *lcdNumber;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *led1;
    QLabel *label_3;
    QPushButton *led2;
    QLabel *label_4;
    QPushButton *readFromDev;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(1135, 902);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setMouseTracking(false);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
#ifndef QT_NO_STATUSTIP
        MainWindow->setStatusTip(QStringLiteral(""));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        MainWindow->setWhatsThis(QStringLiteral(""));
#endif // QT_NO_WHATSTHIS
        MainWindow->setAnimated(true);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Triangular);
        MainWindow->setDockNestingEnabled(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 731, 547));
        QPalette palette;
        QBrush brush(QColor(0, 255, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        groupBox_2->setPalette(palette);
        groupBox_2->setAutoFillBackground(true);
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        textBrowser->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        textBrowser->setFont(font);

        verticalLayout_2->addWidget(textBrowser);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton_1 = new QRadioButton(groupBox);
        radioButton_1->setObjectName(QStringLiteral("radioButton_1"));

        verticalLayout->addWidget(radioButton_1);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setCheckable(true);
        radioButton_2->setChecked(false);
        radioButton_2->setAutoExclusive(true);

        verticalLayout->addWidget(radioButton_2);


        horizontalLayout_4->addLayout(verticalLayout);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        enumerate = new QPushButton(groupBox);
        enumerate->setObjectName(QStringLiteral("enumerate"));

        horizontalLayout->addWidget(enumerate);

        openDev = new QPushButton(groupBox);
        openDev->setObjectName(QStringLiteral("openDev"));

        horizontalLayout->addWidget(openDev);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        closeDev = new QPushButton(groupBox);
        closeDev->setObjectName(QStringLiteral("closeDev"));

        horizontalLayout->addWidget(closeDev);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_5->addLayout(verticalLayout_2);


        horizontalLayout_6->addWidget(groupBox);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_8->addWidget(pushButton_4);


        verticalLayout_4->addLayout(horizontalLayout_8);

        textBrowser_2 = new QTextBrowser(groupBox_4);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));

        verticalLayout_4->addWidget(textBrowser_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lineEdit = new QLineEdit(groupBox_4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_7->addWidget(lineEdit);

        send_to_ = new QPushButton(groupBox_4);
        send_to_->setObjectName(QStringLiteral("send_to_"));

        horizontalLayout_7->addWidget(send_to_);

        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_7->addWidget(pushButton_3);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_9->addWidget(label_5);

        lcdNumber = new QLCDNumber(groupBox_4);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        lcdNumber->setFont(font1);
        lcdNumber->setFrameShadow(QFrame::Plain);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_9->addWidget(lcdNumber);


        verticalLayout_4->addLayout(horizontalLayout_9);


        horizontalLayout_6->addWidget(groupBox_4);


        verticalLayout_5->addLayout(horizontalLayout_6);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy2);
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        led1 = new QPushButton(groupBox_3);
        led1->setObjectName(QStringLiteral("led1"));

        horizontalLayout_3->addWidget(led1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        led2 = new QPushButton(groupBox_3);
        led2->setObjectName(QStringLiteral("led2"));

        horizontalLayout_3->addWidget(led2);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        readFromDev = new QPushButton(groupBox_3);
        readFromDev->setObjectName(QStringLiteral("readFromDev"));

        horizontalLayout_3->addWidget(readFromDev);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_4);

        verticalSpacer = new QSpacerItem(20, 59, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_5->addWidget(groupBox_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout_5);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(enumerate, SIGNAL(clicked()), textBrowser, SLOT(clear()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_2->setTitle(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260 \320\272\320\273\320\260\321\201\321\201\320\260 HID  \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\320\265", 0));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Courier'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400;\"><br /></p></body></html>", 0));
        radioButton_1->setText(QApplication::translate("MainWindow", "\320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "\320\262 \321\200\321\203\321\207\320\275\321\203\321\216", 0));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        enumerate->setText(QApplication::translate("MainWindow", "Enumerate", 0));
        openDev->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", 0));
        label->setText(QString());
        closeDev->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\321\200\320\274\320\270\320\275\320\260\320\273", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "clear", 0));
        send_to_->setText(QApplication::translate("MainWindow", "send", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "get", 0));
        label_5->setText(QApplication::translate("MainWindow", "size ext. buffer", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\224\320\265\320\271\321\201\321\202\320\262\320\270\321\217", 0));
        led1->setText(QApplication::translate("MainWindow", "Led 1", 0));
        label_3->setText(QString());
        led2->setText(QApplication::translate("MainWindow", "Led 2", 0));
        label_4->setText(QString());
        readFromDev->setText(QApplication::translate("MainWindow", "Read", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
