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
    QLineEdit *fileName;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
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
    QPushButton *MoveModel;
    QLineEdit *ax;
    QPushButton *RotateModel;
    QLineEdit *ay;
    QLineEdit *az;
    QLineEdit *kx;
    QPushButton *ScaleModal;
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
        fileName = new QLineEdit(centralWidget);
        fileName->setObjectName(QString::fromUtf8("fileName"));
        fileName->setGeometry(QRect(20, 40, 151, 20));
        QFont font;
        font.setPointSize(10);
        fileName->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 80, 91, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 110, 21, 16));
        label_7->setFont(font1);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 140, 21, 16));
        label_8->setFont(font1);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(30, 170, 21, 21));
        label_13->setFont(font1);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 200, 91, 21));
        label_14->setFont(font1);
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(100, 220, 16, 21));
        label_15->setFont(font1);
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 320, 141, 21));
        label_16->setFont(font1);
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
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(10, 310, 241, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(30, 350, 47, 21));
        label_17->setFont(font1);
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(30, 380, 47, 21));
        label_18->setFont(font1);
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(30, 410, 47, 21));
        label_19->setFont(font1);
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(130, 350, 47, 21));
        label_20->setFont(font1);
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(130, 380, 47, 21));
        label_21->setFont(font1);
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(130, 410, 47, 21));
        label_22->setFont(font1);
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
        line_8->setGeometry(QRect(10, 470, 241, 21));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        pushOk = new QPushButton(centralWidget);
        pushOk->setObjectName(QString::fromUtf8("pushOk"));
        pushOk->setGeometry(QRect(180, 40, 51, 23));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        pushOk->setFont(font2);
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(260, 10, 111, 21));
        label_23->setFont(font1);
        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(20, 10, 161, 21));
        label_24->setFont(font1);
        line_9 = new QFrame(centralWidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(10, 70, 241, 16));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        dx = new QLineEdit(centralWidget);
        dx->setObjectName(QString::fromUtf8("dx"));
        dx->setGeometry(QRect(50, 110, 41, 20));
        dx->setFont(font);
        dy = new QLineEdit(centralWidget);
        dy->setObjectName(QString::fromUtf8("dy"));
        dy->setGeometry(QRect(50, 140, 41, 20));
        dy->setFont(font);
        dz = new QLineEdit(centralWidget);
        dz->setObjectName(QString::fromUtf8("dz"));
        dz->setGeometry(QRect(50, 170, 41, 20));
        dz->setFont(font);
        MoveModel = new QPushButton(centralWidget);
        MoveModel->setObjectName(QString::fromUtf8("MoveModel"));
        MoveModel->setGeometry(QRect(120, 140, 75, 23));
        MoveModel->setFont(font2);
        ax = new QLineEdit(centralWidget);
        ax->setObjectName(QString::fromUtf8("ax"));
        ax->setGeometry(QRect(50, 230, 41, 20));
        ax->setFont(font);
        RotateModel = new QPushButton(centralWidget);
        RotateModel->setObjectName(QString::fromUtf8("RotateModel"));
        RotateModel->setGeometry(QRect(120, 260, 75, 23));
        RotateModel->setFont(font2);
        ay = new QLineEdit(centralWidget);
        ay->setObjectName(QString::fromUtf8("ay"));
        ay->setGeometry(QRect(50, 260, 41, 20));
        ay->setFont(font);
        az = new QLineEdit(centralWidget);
        az->setObjectName(QString::fromUtf8("az"));
        az->setGeometry(QRect(50, 290, 41, 20));
        az->setFont(font);
        kx = new QLineEdit(centralWidget);
        kx->setObjectName(QString::fromUtf8("kx"));
        kx->setGeometry(QRect(80, 350, 41, 20));
        kx->setFont(font);
        ScaleModal = new QPushButton(centralWidget);
        ScaleModal->setObjectName(QString::fromUtf8("ScaleModal"));
        ScaleModal->setGeometry(QRect(120, 440, 75, 23));
        ScaleModal->setFont(font2);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(260, 40, 641, 581));
        graphicsView->setMaximumSize(QSize(10000, 16777215));
        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(100, 250, 16, 21));
        label_25->setFont(font1);
        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(100, 280, 16, 21));
        label_26->setFont(font1);
        label_27 = new QLabel(centralWidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(30, 230, 21, 16));
        label_27->setFont(font1);
        label_29 = new QLabel(centralWidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(30, 260, 21, 16));
        label_29->setFont(font1);
        label_30 = new QLabel(centralWidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(30, 290, 21, 16));
        label_30->setFont(font1);
        ky = new QLineEdit(centralWidget);
        ky->setObjectName(QString::fromUtf8("ky"));
        ky->setGeometry(QRect(80, 380, 41, 20));
        ky->setFont(font);
        kz = new QLineEdit(centralWidget);
        kz->setObjectName(QString::fromUtf8("kz"));
        kz->setGeometry(QRect(80, 410, 41, 20));
        kz->setFont(font);
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
        fileName->setText(QApplication::translate("MainWindow", "input.txt", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201 \320\275\320\260:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "dx", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "dy", nullptr));
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
        MoveModel->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        ax->setText(QApplication::translate("MainWindow", "0", nullptr));
        RotateModel->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        ay->setText(QApplication::translate("MainWindow", "0", nullptr));
        az->setText(QApplication::translate("MainWindow", "0", nullptr));
        kx->setText(QApplication::translate("MainWindow", "1", nullptr));
        ScaleModal->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
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
