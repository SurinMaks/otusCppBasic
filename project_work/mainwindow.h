#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include "gamelogic.h"

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
        void CreateMenu();
        void CreateGameField();
        void PrintFieldSize() const;//временный метод для проверка результатов

    signals:
        void game_is_on(); //сигнал что игра началась

    public slots:
        void ReceiveDataFromNewGameWindow(const uint length, const uint width, const QString name);
        void OpenNewGameWindow();//Слот открытия окна Новая игра
        void OpenAboutWindow();//Слот открытия окна "О программе"
        void OpenRuleWindow();//Слот открытия окна "Правила"
        void OnButtonClicked();//Слот обработки нажатия на кнопки игрового поля

    private:
        Ui::MainWindow *ui;
        QGridLayout *layout_ = nullptr;
        uint length_{0};
        uint width_{0};
        QString name_{};
        GameLogic gameLogic_{};
        bool startGame_{false};
        void EraseLayout(QGridLayout *layout);
        void SetFlagGameStart();
};
#endif // MAINWINDOW_H
