#ifndef NEWGAMEWINDOW_H
#define NEWGAMEWINDOW_H

#include <QDialog>
#include <QIntValidator>

namespace Ui {
class newGameWindow;
}

class newGameWindow : public QDialog{
    Q_OBJECT

    public:
        explicit newGameWindow(QWidget *parent = nullptr);
        ~newGameWindow();

    private:
        Ui::newGameWindow *ui;
        // void setBackgroundColor();

    private slots:
        void bt_pressOK();//Слот для кнопки ОК

    signals:
        void send_playing_field_size(int length, int width);//отправка размера игрового поля

};

#endif // NEWGAMEWINDOW_H
