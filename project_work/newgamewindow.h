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
        const uint kMinValueFieldSize {3};
        const uint kMaxValueFiledSize {99};
        bool CheckFieldSize() const;

    private slots:
        void BtPressOK();//Слот для кнопки ОК

    signals:
        void send_playing_field_size(uint length, uint width, QString name);//отправка размера игрового поля

};

#endif // NEWGAMEWINDOW_H
