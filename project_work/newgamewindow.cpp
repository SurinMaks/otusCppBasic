#include "newgamewindow.h"
#include "ui_newgamewindow.h"

newGameWindow::newGameWindow(QWidget *parent) : QDialog(parent) , ui(new Ui::newGameWindow){
    ui->setupUi(this);
    connect(ui->bt_OK, &QPushButton::clicked, this, &newGameWindow::bt_pressOK);
    connect(ui->bt_Cancel, &QPushButton::clicked, this, &newGameWindow::close);
}

newGameWindow::~newGameWindow(){
    delete ui;
}

void newGameWindow::setBackgroundColor(){
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::gray);
    setPalette(palette);
}

void newGameWindow::bt_pressOK(){
    this->close();
}
