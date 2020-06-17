#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <QGraphicsScene>

#include "Scene/facade.h"
#include "Scene/scene.h"
#include "Commands/commands.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushOk_clicked();

    void on_MoveModel_clicked();

    void on_RotateModel_clicked();

    void on_ScaleModal_clicked();

private:
    Ui::MainWindow *ui;

    void _set_binds_input(void);
    void _show_error(const char* error);

    shared_ptr<QGraphicsScene> _scene;
    shared_ptr<Facade> _facade;

    shared_ptr<BaseCommand> _move(void);
    shared_ptr<BaseCommand> _scale(void);
    shared_ptr<BaseCommand> _rotate(void);
};

#endif // MAINWINDOW_H
