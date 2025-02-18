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
        const uint min_value_field_size {3};
        const uint max_value_filed_size {99};
        bool check_field_size() const;

    private slots:
        void bt_pressOK();//Слот для кнопки ОК

    signals:
        void send_playing_field_size(uint length, uint width, QString name);//отправка размера игрового поля

};

#endif // NEWGAMEWINDOW_H
