#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include "gamelogic.h"
#include "timer.h"

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
        Timer timer{};
        const char* kHiddenX{"hiddenX"};
        const char* kHiddenY{"hiddenY"};
        // bool startGame_{false};
        void EraseLayout(QGridLayout *layout);
        void setFlagGameStart();
        void setHidePropertyXY(QPushButton *button, uint X, uint Y);
        void clickButton(QPushButton *button);
        std::string getName() const;
};
#endif // MAINWINDOW_H
