#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushOk_clicked()
{

}

void MainWindow::on_MoveModel_clicked()
{

}


void MainWindow::on_RotateModel_clicked()
{

}


void MainWindow::on_ScaleModal_clicked()
{

}


