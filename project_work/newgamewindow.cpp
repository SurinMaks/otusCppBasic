#include "newgamewindow.h"
#include "ui_newgamewindow.h"
#include <QMessageBox>

newGameWindow::newGameWindow(QWidget *parent) : QDialog(parent) , ui(new Ui::newGameWindow){
    ui->setupUi(this);

    QIntValidator *intValidator = new QIntValidator(kMinValueFieldSize, kMaxValueFiledSize, this);
    ui->le_horizontSize->setValidator(intValidator);
    ui->le_vetricalSize->setValidator(intValidator);

    connect(ui->bt_OK, &QPushButton::clicked, this, &newGameWindow::BtPressOK);
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

void newGameWindow::BtPressOK(){
    // qDebug() << "Горизонтельный размер=" << ui->le_horizontSize->text();
    // qDebug() << "Вертикальный размер=" << ui->le_vetricalSize->text();
    if(CheckFieldSize()){
        emit send_playing_field_size(ui->le_horizontSize->text().toUInt(), ui->le_vetricalSize->text().toUInt(), ui->le_userName->text());
        this->close();
    }
    else{
        QMessageBox msq;
        msq.warning(this, "Предупрежение", "Размеры игрового поля не могут быть меньше " + QString::number(kMinValueFieldSize));
    }


}

bool newGameWindow::CheckFieldSize() const {
    if( (ui->le_horizontSize->text().toUInt() >= kMinValueFieldSize) && (ui->le_vetricalSize->text().toUInt() >= kMinValueFieldSize) ){
        return true;
    }
    else{
        return false;
    }
}
