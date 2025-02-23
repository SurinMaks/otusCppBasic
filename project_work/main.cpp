#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainWindow::connect(&w, &MainWindow::game_is_on, &MainWindow::create_game_field);
    w.create_menu();
    w.show();
    return a.exec();
}
