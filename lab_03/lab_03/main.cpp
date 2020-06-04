#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#include "Array/array.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Array<int> a1{1, 2, 3};
    for (auto val : a1)
        cout << val << " ";
    cout << endl;
    a1.append(-100);
    for (auto val : a1)
        cout << val << " ";


    return a.exec();
}
