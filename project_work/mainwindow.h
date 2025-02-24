#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>

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
        void create_menu();
        void create_game_field();
        void print_field_size() const;//временный метод для проверка результатов

    signals:
        void game_is_on(); //сигнал что игра началась

    public slots:
        void receive_data_from_newGameWindow(const uint length, const uint width, const QString name);
        void openNewGameWindow();//Слот открытия окна Новая игра
        void open_about_window();//Слот открытия окна "О программе"
        void open_rule_window();//Слот открытия окна "Правила"
        void onButtonClicked();//Слот обработки нажатия на кнопки игрового поля

    private:
        Ui::MainWindow *ui;
        QGridLayout *layout = nullptr;
        uint m_length{0};
        uint m_width{0};
        QString m_name{};
        bool m_start_game{false};
        void erase_layout(QGridLayout *layout);
        void set_flag_game_start();
        bool check_moves(int row, int col);
        const int m_dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        const int m_dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

};
#endif // MAINWINDOW_H
