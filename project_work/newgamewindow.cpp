#include "newgamewindow.h"
#include "ui_newgamewindow.h"

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
    emit send_playing_field_size(ui->le_horizontSize->text().toUInt(), ui->le_vetricalSize->text().toUInt(), ui->le_userName->text());
    this->close();
}
