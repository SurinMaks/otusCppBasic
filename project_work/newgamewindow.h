#ifndef NEWGAMEWINDOW_H
#define NEWGAMEWINDOW_H

#include <QDialog>

namespace Ui {
class newGameWindow;
}

class newGameWindow : public QDialog{
    Q_OBJECT

    public:
        explicit newGameWindow(QWidget *parent = nullptr);
        ~newGameWindow();
        void setBackgroundColor();


    private:
        Ui::newGameWindow *ui;

    private slots:
        void bt_pressOK();//Слот для кнопки ОК

};

#endif // NEWGAMEWINDOW_H
