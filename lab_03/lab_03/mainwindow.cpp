#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDoubleValidator>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), _scene(new QGraphicsScene(-1, -1, 1, 1)),
    _facade(new Facade(new Scene()))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&(*_scene));

    _set_binds_input();

    try
    {
        AddCamera add_camera(5, -5, 500);
        _facade->execute(add_camera);

        LoadModel load_model(ui->fileName->text().toStdString());
        _facade->execute(load_model);

        QDrawScene draw_scene(_scene, QPen(Qt::red), QPen(Qt::black));
        _facade->execute(draw_scene);
    }
    catch (error::BaseError &err)
    {
        cout << err.what() << endl;
        _show_error(err.what());
    }
    catch(...)
    {
        cout << "Undefinied error!" << endl;
    }
}

void MainWindow::_set_binds_input(void)
{
    QDoubleValidator *vld = new QDoubleValidator;

    vld->setLocale(QLocale(QLocale::English));

    ui->dx->setValidator(vld);
    ui->dy->setValidator(vld);
    ui->dz->setValidator(vld);

    ui->ax->setValidator(vld);
    ui->ay->setValidator(vld);
    ui->az->setValidator(vld);

    ui->kx->setValidator(vld);
    ui->ky->setValidator(vld);
    ui->kz->setValidator(vld);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushOk_clicked()
{
    try
    {
        LoadModel load_model(ui->fileName->text().toStdString());
        _facade->execute(load_model);

        RemoveCommand remove(1);
        _facade->execute(remove);

        QDrawScene draw_scene(_scene, QPen(Qt::red), QPen(Qt::black));
        _facade->execute(draw_scene);
    }
    catch (error::BaseError &err)
    {
        cout << err.what() << endl;
        _show_error(err.what());
    }
    catch(...)
    {
        cout << "Undefinied error!" << endl;
    }
}

void MainWindow::on_MoveModel_clicked()
{
    try
    {
        _facade->execute(*_move());

        QDrawScene draw_scene(_scene, QPen(Qt::red), QPen(Qt::black));
        _facade->execute(draw_scene);
    }
    catch (error::BaseError &err)
    {
        cout << err.what() << endl;
        _show_error(err.what());
    }
    catch(...)
    {
        cout << "Undefinied error!" << endl;
    }
}


void MainWindow::on_RotateModel_clicked()
{
    try
    {
        _facade->execute(*_rotate());

        QDrawScene draw_scene(_scene, QPen(Qt::red), QPen(Qt::black));
        _facade->execute(draw_scene);
    }
    catch (error::BaseError &err)
    {
        cout << err.what() << endl;
        _show_error(err.what());
    }
    catch(...)
    {
        cout << "Undefinied error!" << endl;
    }
}


void MainWindow::on_ScaleModal_clicked()
{
    try
    {
        _facade->execute(*_scale());

        QDrawScene draw_scene(_scene, QPen(Qt::red), QPen(Qt::black));
        _facade->execute(draw_scene);
    }
    catch (error::BaseError &err)
    {
        cout << err.what() << endl;
        _show_error(err.what());
    }
    catch(...)
    {
        cout << "Undefinied error!" << endl;
    }
}


shared_ptr<BaseCommand> MainWindow::_move(void)
{
    double x, y, z;

    x = ui->dx->text().toDouble();
    y = ui->dy->text().toDouble();
    z = ui->dz->text().toDouble();

    return shared_ptr<BaseCommand>(new MoveCommand(x, y, z, 1));
}

shared_ptr<BaseCommand> MainWindow::_scale(void)
{
    double x, y, z;

    x = ui->kx->text().toDouble();
    y = ui->ky->text().toDouble();
    z = ui->kz->text().toDouble();

    return shared_ptr<BaseCommand>(new ScaleCommand(x, y, z, 1));
}

shared_ptr<BaseCommand> MainWindow::_rotate(void)
{
    double x, y, z;

    x = ui->ax->text().toDouble();
    y = ui->ay->text().toDouble();
    z = ui->az->text().toDouble();

    return shared_ptr<BaseCommand>(new RotateCommand(x, y, z, 1));
}

void MainWindow::_show_error(const char *error)
{
    QMessageBox error_message(QMessageBox::Critical, "Error", error);
    error_message.exec();
}

