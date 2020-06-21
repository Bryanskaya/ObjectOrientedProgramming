#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "draw_interface.h"

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
    void on_actionScanFile_triggered();

    void on_actionMoveModel_triggered();

    void on_actionRotateModel_triggered();

    void on_actionScaleModal_triggered();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;

    void set_binds_input(void);

    void show_error(void);

    draw_params_t draw_param;
};

#endif // MAINWINDOW_H
