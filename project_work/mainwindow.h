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


    public slots:
        void print_field_size() const;//временный метод для проверка результатов
        void receive_data_from_newGameWindow(const uint length, const uint width, const QString name);

    private:
        Ui::MainWindow *ui;
        uint m_length{0};
        uint m_width{0};
        QString m_name{};
        bool start_game{false};

    private slots:
        void openNewGameWindow();//Слот открытия окна Новая игра
        void openAboutWindow();//Слот открытия окна "О программе"
        void openRuleWindow();//Слот открытия окна "Правила"
};
#endif // MAINWINDOW_H
