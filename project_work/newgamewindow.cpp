#include "newgamewindow.h"
#include "ui_newgamewindow.h"
#include <QMessageBox>

newGameWindow::newGameWindow(QWidget *parent) : QDialog(parent) , ui(new Ui::newGameWindow){
    ui->setupUi(this);

    QIntValidator *intValidator = new QIntValidator(min_value_field_size, max_value_filed_size, this);
    ui->le_horizontSize->setValidator(intValidator);
    ui->le_vetricalSize->setValidator(intValidator);

    connect(ui->bt_OK, &QPushButton::clicked, this, &newGameWindow::bt_pressOK);
    connect(ui->bt_Cancel, &QPushButton::clicked, this, &newGameWindow::close);
}

newGameWindow::~newGameWindow(){
    delete ui;
}

// void newGameWindow::setBackgroundColor(){
//     QPalette palette;
//     palette.setColor(QPalette::Window, Qt::gray);
//     setPalette(palette);
// }

void newGameWindow::bt_pressOK(){
    // qDebug() << "Горизонтельный размер=" << ui->le_horizontSize->text();
    // qDebug() << "Вертикальный размер=" << ui->le_vetricalSize->text();
    if(check_field_size()){
        emit send_playing_field_size(ui->le_horizontSize->text().toUInt(), ui->le_vetricalSize->text().toUInt(), ui->le_userName->text());
        this->close();
    }
    else{
        QMessageBox msq;
        msq.warning(this, "Предупрежение", "Размеры игрового поля не могут быть меньше " + QString::number(min_value_field_size));
    }


}

bool newGameWindow::check_field_size(){
    if( (ui->le_horizontSize->text().toUInt() >= min_value_field_size) && (ui->le_vetricalSize->text().toUInt() >= min_value_field_size) ){
        return true;
    }
    else{
        return false;
    }
}
