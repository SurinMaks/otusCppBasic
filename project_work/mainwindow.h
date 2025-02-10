#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void createMenu();

    private:
        Ui::MainWindow *ui;

    private slots:
        void openNewGameWindow();//Слот открытия окна Новая игра
        void openAboutWindow();
};
#endif // MAINWINDOW_H
