#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow BankApp;
    BankApp.show();
    return a.exec();
}
