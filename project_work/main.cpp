#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainWindow::connect(&w, &MainWindow::game_is_on, &MainWindow::CreateGameField);
    w.CreateMenu();
    w.show();
    return a.exec();
}
