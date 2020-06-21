#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QGraphicsScene>
#include <QDoubleValidator>
#include <QMessageBox>

#include "commands.h"
#include "task_manager.h"
#include "operations.h"
#include "point.h"
#include "transform.h"
#include "draw_interface.h"

void MainWindow::set_binds_input(void)
{
    QDoubleValidator *vld = new QDoubleValidator;

    vld->setLocale(QLocale(QLocale::English));

    ui->dx->setValidator(vld);
    ui->dy->setValidator(vld);
    ui->dz->setValidator(vld);

    ui->center_x->setValidator(vld);
    ui->center_y->setValidator(vld);
    ui->center_z->setValidator(vld);

    ui->ax->setValidator(vld);
    ui->ay->setValidator(vld);
    ui->az->setValidator(vld);

    ui->kx->setValidator(vld);
    ui->ky->setValidator(vld);
    ui->kz->setValidator(vld);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(-1, -1, -1, -1);
    ui->graphicsView->setScene(scene);
    draw_param = init_draw(scene);

    set_binds_input();
    on_actionScanFile_triggered();
}

void MainWindow::show_error(void)
{
    QMessageBox error_message(QMessageBox::Critical, "Error",
                              "Problems reading file");
    error_message.exec();
}

MainWindow::~MainWindow()
{
    delete ui;

    command_t command = create_command_delete();
    task_manager(command);
}

void MainWindow::on_actionScanFile_triggered()
{
    std::string str = ui->fileName->text().toStdString();
    const char *filename = str.c_str();

    command_t command = create_command_readfile(filename);
    code_t code = task_manager(command);
    if (!code)
    {
        command = create_command_draw(draw_param);
        code = task_manager(command);
    }
}

void MainWindow::on_actionMoveModel_triggered()
{
    double move_dx = ui->dx->text().toDouble();
    double move_dy = ui->dy->text().toDouble();
    double move_dz = ui->dz->text().toDouble();

    transform_t move;
    move.center = create_point(move_dx, move_dy, move_dz);
    command_t command = create_command_move(move);
    code_t code = task_manager(command);
    if (!code)
    {
        command = create_command_draw(draw_param);
        code = task_manager(command);
    }
}

void MainWindow::on_actionRotateModel_triggered()
{
    double center_x = ui->center_x->text().toDouble();
    double center_y = ui->center_y->text().toDouble();
    double center_z = ui->center_z->text().toDouble();

    double ax = ui->ax->text().toDouble();
    double ay = ui->ay->text().toDouble();
    double az = ui->az->text().toDouble();

    transform_t rotate;

    rotate.center = create_point(center_x, center_y, center_z);
    rotate.rotate = init_rotate(ax, ay, az);

    command_t command = create_command_rotate(rotate);
    code_t code = task_manager(command);
    if (!code)
    {
        command = create_command_draw(draw_param);
        code = task_manager(command);
    }
}

void MainWindow::on_actionScaleModal_triggered()
{
    double center_x = ui->center_x->text().toDouble();
    double center_y = ui->center_y->text().toDouble();
    double center_z = ui->center_z->text().toDouble();

    double kx = ui->kx->text().toDouble();
    double ky = ui->ky->text().toDouble();
    double kz = ui->kz->text().toDouble();

    transform_t scale;

    scale.center = create_point(center_x, center_y, center_z);
    scale.scale = init_scale(kx, ky, kz);

    command_t command = create_command_scale(scale);
    code_t code = task_manager(command);
    if (!code)
    {
        command = create_command_draw(draw_param);
        code = task_manager(command);
    }
}

