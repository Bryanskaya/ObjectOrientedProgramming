/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionScanFile;
    QAction *actionMoveModel;
    QAction *actionRotateModel;
    QAction *actionScaleModal;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *fileName;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QPushButton *pushOk;
    QLabel *label_23;
    QLabel *label_24;
    QFrame *line_9;
    QLineEdit *dx;
    QLineEdit *dy;
    QLineEdit *dz;
    QLineEdit *center_x;
    QLineEdit *center_y;
    QLineEdit *center_z;
    QPushButton *MoveModel;
    QLineEdit *ax;
    QPushButton *RotateModel;
    QLineEdit *ay;
    QLineEdit *az;
    QLineEdit *kx;
    QPushButton *ScaleModal;
    QPushButton *StartPosition;
    QGraphicsView *graphicsView;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_29;
    QLabel *label_30;
    QLineEdit *ky;
    QLineEdit *kz;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(925, 676);
        actionScanFile = new QAction(MainWindow);
        actionScanFile->setObjectName(QString::fromUtf8("actionScanFile"));
        actionMoveModel = new QAction(MainWindow);
        actionMoveModel->setObjectName(QString::fromUtf8("actionMoveModel"));
        actionRotateModel = new QAction(MainWindow);
        actionRotateModel->setObjectName(QString::fromUtf8("actionRotateModel"));
        actionScaleModal = new QAction(MainWindow);
        actionScaleModal->setObjectName(QString::fromUtf8("actionScaleModal"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 190, 121, 41));
        label->setMinimumSize(QSize(0, 41));
        label->setMaximumSize(QSize(200, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 220, 141, 16));
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 240, 16, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(22);
        font1.setBold(false);
        font1.setWeight(50);
        label_3->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 240, 16, 51));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setWeight(50);
        label_4->setFont(font2);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(230, 240, 16, 51));
        QFont font3;
        font3.setPointSize(20);
        label_5->setFont(font3);
        fileName = new QLineEdit(centralWidget);
        fileName->setObjectName(QString::fromUtf8("fileName"));
        fileName->setGeometry(QRect(20, 40, 151, 20));
        QFont font4;
        font4.setPointSize(10);
        fileName->setFont(font4);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 80, 91, 21));
        label_6->setFont(font);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 110, 21, 16));
        label_7->setFont(font);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 140, 21, 16));
        label_8->setFont(font);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(60, 240, 16, 21));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Times New Roman"));
        font5.setPointSize(13);
        font5.setBold(true);
        font5.setWeight(75);
        label_9->setFont(font5);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(130, 240, 21, 21));
        label_10->setFont(font5);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(200, 240, 16, 21));
        label_11->setFont(font5);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(160, 240, 16, 51));
        label_12->setFont(font2);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(30, 170, 21, 21));
        label_13->setFont(font);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 290, 91, 21));
        label_14->setFont(font);
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(100, 310, 16, 21));
        label_15->setFont(font);
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 430, 141, 21));
        label_16->setFont(font);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 190, 241, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 0, 20, 621));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, -10, 241, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(10, 280, 241, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(10, 410, 241, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(30, 460, 47, 21));
        label_17->setFont(font);
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(30, 490, 47, 21));
        label_18->setFont(font);
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(30, 520, 47, 21));
        label_19->setFont(font);
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(130, 460, 47, 21));
        label_20->setFont(font);
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(130, 490, 47, 21));
        label_21->setFont(font);
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(130, 520, 47, 21));
        label_22->setFont(font);
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(10, 610, 241, 21));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(240, 0, 20, 621));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(10, 570, 241, 21));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        pushOk = new QPushButton(centralWidget);
        pushOk->setObjectName(QString::fromUtf8("pushOk"));
        pushOk->setGeometry(QRect(180, 40, 51, 23));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Times New Roman"));
        font6.setPointSize(9);
        font6.setBold(true);
        font6.setWeight(75);
        pushOk->setFont(font6);
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(260, 10, 111, 21));
        label_23->setFont(font);
        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(20, 10, 161, 21));
        label_24->setFont(font);
        line_9 = new QFrame(centralWidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(10, 70, 241, 16));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        dx = new QLineEdit(centralWidget);
        dx->setObjectName(QString::fromUtf8("dx"));
        dx->setGeometry(QRect(50, 110, 41, 20));
        dx->setFont(font4);
        dy = new QLineEdit(centralWidget);
        dy->setObjectName(QString::fromUtf8("dy"));
        dy->setGeometry(QRect(50, 140, 41, 20));
        dy->setFont(font4);
        dz = new QLineEdit(centralWidget);
        dz->setObjectName(QString::fromUtf8("dz"));
        dz->setGeometry(QRect(50, 170, 41, 20));
        dz->setFont(font4);
        center_x = new QLineEdit(centralWidget);
        center_x->setObjectName(QString::fromUtf8("center_x"));
        center_x->setGeometry(QRect(40, 260, 41, 20));
        center_x->setFont(font4);
        center_y = new QLineEdit(centralWidget);
        center_y->setObjectName(QString::fromUtf8("center_y"));
        center_y->setGeometry(QRect(110, 260, 41, 20));
        center_y->setFont(font4);
        center_z = new QLineEdit(centralWidget);
        center_z->setObjectName(QString::fromUtf8("center_z"));
        center_z->setGeometry(QRect(180, 260, 41, 20));
        center_z->setFont(font4);
        MoveModel = new QPushButton(centralWidget);
        MoveModel->setObjectName(QString::fromUtf8("MoveModel"));
        MoveModel->setGeometry(QRect(120, 140, 75, 23));
        MoveModel->setFont(font6);
        ax = new QLineEdit(centralWidget);
        ax->setObjectName(QString::fromUtf8("ax"));
        ax->setGeometry(QRect(50, 320, 41, 20));
        ax->setFont(font4);
        RotateModel = new QPushButton(centralWidget);
        RotateModel->setObjectName(QString::fromUtf8("RotateModel"));
        RotateModel->setGeometry(QRect(120, 350, 75, 23));
        RotateModel->setFont(font6);
        ay = new QLineEdit(centralWidget);
        ay->setObjectName(QString::fromUtf8("ay"));
        ay->setGeometry(QRect(50, 350, 41, 20));
        ay->setFont(font4);
        az = new QLineEdit(centralWidget);
        az->setObjectName(QString::fromUtf8("az"));
        az->setGeometry(QRect(50, 380, 41, 20));
        az->setFont(font4);
        kx = new QLineEdit(centralWidget);
        kx->setObjectName(QString::fromUtf8("kx"));
        kx->setGeometry(QRect(80, 460, 41, 20));
        kx->setFont(font4);
        ScaleModal = new QPushButton(centralWidget);
        ScaleModal->setObjectName(QString::fromUtf8("ScaleModal"));
        ScaleModal->setGeometry(QRect(120, 550, 75, 23));
        ScaleModal->setFont(font6);
        StartPosition = new QPushButton(centralWidget);
        StartPosition->setObjectName(QString::fromUtf8("StartPosition"));
        StartPosition->setGeometry(QRect(50, 590, 151, 23));
        StartPosition->setFont(font6);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(260, 40, 641, 581));
        graphicsView->setMaximumSize(QSize(10000, 16777215));
        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(100, 340, 16, 21));
        label_25->setFont(font);
        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(100, 370, 16, 21));
        label_26->setFont(font);
        label_27 = new QLabel(centralWidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(30, 320, 21, 16));
        label_27->setFont(font);
        label_29 = new QLabel(centralWidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(30, 350, 21, 16));
        label_29->setFont(font);
        label_30 = new QLabel(centralWidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(30, 380, 21, 16));
        label_30->setFont(font);
        ky = new QLineEdit(centralWidget);
        ky->setObjectName(QString::fromUtf8("ky"));
        ky->setGeometry(QRect(80, 490, 41, 20));
        ky->setFont(font4);
        kz = new QLineEdit(centralWidget);
        kz->setObjectName(QString::fromUtf8("kz"));
        kz->setGeometry(QRect(80, 520, 41, 20));
        kz->setFont(font4);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 925, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushOk, SIGNAL(clicked()), actionScanFile, SLOT(trigger()));
        QObject::connect(StartPosition, SIGNAL(clicked()), actionScanFile, SLOT(trigger()));
        QObject::connect(MoveModel, SIGNAL(clicked()), actionMoveModel, SLOT(trigger()));
        QObject::connect(RotateModel, SIGNAL(clicked()), actionRotateModel, SLOT(trigger()));
        QObject::connect(ScaleModal, SIGNAL(clicked()), actionScaleModal, SLOT(trigger()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 1", nullptr));
        actionScanFile->setText(QApplication::translate("MainWindow", "ScanFile", nullptr));
#ifndef QT_NO_TOOLTIP
        actionScanFile->setToolTip(QApplication::translate("MainWindow", "ScanFile", nullptr));
#endif // QT_NO_TOOLTIP
        actionMoveModel->setText(QApplication::translate("MainWindow", "MoveModel", nullptr));
#ifndef QT_NO_TOOLTIP
        actionMoveModel->setToolTip(QApplication::translate("MainWindow", "MoveModel", nullptr));
#endif // QT_NO_TOOLTIP
        actionRotateModel->setText(QApplication::translate("MainWindow", "RotateModel", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRotateModel->setToolTip(QApplication::translate("MainWindow", "RotateModel", nullptr));
#endif // QT_NO_TOOLTIP
        actionScaleModal->setText(QApplication::translate("MainWindow", "ScaleModal", nullptr));
#ifndef QT_NO_TOOLTIP
        actionScaleModal->setToolTip(QApplication::translate("MainWindow", "ScaleModal", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260/", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "[", nullptr));
        label_4->setText(QApplication::translate("MainWindow", ";", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "]", nullptr));
        fileName->setText(QApplication::translate("MainWindow", "input.txt", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201 \320\275\320\260:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "dx", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "dy", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "x", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "y", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "z", nullptr));
        label_12->setText(QApplication::translate("MainWindow", ";", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "dz", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202 \320\275\320\260:", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\302\260", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\320\277\320\276 \321\205 \320\262", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\320\277\320\276 \321\203 \320\262", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\320\277\320\276 z \320\262", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "\321\200\320\260\320\267/\320\260", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\321\200\320\260\320\267/\320\260", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "\321\200\320\260\320\267/\320\260", nullptr));
        pushOk->setText(QApplication::translate("MainWindow", "\320\236\320\232", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217 \321\204\320\260\320\271\320\273\320\260:", nullptr));
        dx->setText(QApplication::translate("MainWindow", "0", nullptr));
        dy->setText(QApplication::translate("MainWindow", "0", nullptr));
        dz->setText(QApplication::translate("MainWindow", "0", nullptr));
        center_x->setText(QApplication::translate("MainWindow", "0", nullptr));
        center_y->setText(QApplication::translate("MainWindow", "0", nullptr));
        center_z->setText(QApplication::translate("MainWindow", "0", nullptr));
        MoveModel->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        ax->setText(QApplication::translate("MainWindow", "0", nullptr));
        RotateModel->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        ay->setText(QApplication::translate("MainWindow", "0", nullptr));
        az->setText(QApplication::translate("MainWindow", "0", nullptr));
        kx->setText(QApplication::translate("MainWindow", "1", nullptr));
        ScaleModal->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        StartPosition->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\320\276\320\265 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "\302\260", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\302\260", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "ax", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "ay", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "az", nullptr));
        ky->setText(QApplication::translate("MainWindow", "1", nullptr));
        kz->setText(QApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
