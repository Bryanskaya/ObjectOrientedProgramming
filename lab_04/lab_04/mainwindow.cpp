#include "mainwindow.h"
#include "ui_mainwindow.h"

#define NUM_FLOORS      9

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), _layout(new QVBoxLayout), _elevator(NUM_FLOORS)
{
    ui->setupUi(this);
    ui->widget->setLayout(_layout);
    _layout->addWidget(_elevator.get_qwidget());
}

MainWindow::~MainWindow()
{
    delete ui;
}
