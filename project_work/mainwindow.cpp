#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "newgamewindow.h"
#include "rulewindow.h"
#include "GameStatus.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked, this, &MainWindow::PrintFieldSize);//временное подключени для проверок
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::CreateMenu(){
    // Создаем строку меню
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    // Создаем пункты меню
    QMenu *fileMenu = menuBar->addMenu("Файл");
    QMenu *helpMemu = menuBar->addMenu("Справка");

    //Создаем пункты меню файл
    QAction *newGame = new QAction("Новая игра", this);
    QAction *exitGame = new QAction("Выход", this);

    // Создаем пункты меню справка
    QAction *about = new QAction("О программе",this);
    QAction *rules = new QAction("Правила",this);

    // Добавляем пункты в меню "Файл"
    fileMenu->addAction(newGame);
    fileMenu->addSeparator(); // Добавляем разделитель
    fileMenu->addAction(exitGame);

    // Добавляем пункты в меню справка
    helpMemu->addAction(about);
    helpMemu->addAction(rules);

    // Подключаем действия
    connect(exitGame, &QAction::triggered, this, &MainWindow::close);
    connect(newGame, &QAction::triggered, this, &MainWindow::OpenNewGameWindow);
    connect(about, &QAction::triggered,this, &MainWindow::OpenAboutWindow);
    connect(rules, &QAction::triggered, this, &MainWindow::OpenRuleWindow);
}

void MainWindow::OpenNewGameWindow(){
    newGameWindow *newGame = new class newGameWindow(this);
    connect(newGame, &newGameWindow::send_playing_field_size, this, &MainWindow::ReceiveDataFromNewGameWindow);// Подключаем сигнал к слоту
    newGame->exec();
}

void MainWindow::OpenAboutWindow(){
    QMessageBox::about(this, "О программе", "Данная игра разработанна в рамках выполнения проектой работы на курсе Otus. C++.Basic");
}

void MainWindow::OpenRuleWindow(){
    ruleWindow *ruleWindow = new class ruleWindow(this);
    ruleWindow->exec();
}

//временный метод для проверка результатов
void MainWindow::PrintFieldSize() const {
    qDebug()<<"11=" << length_;
    qDebug()<<"22=" << width_;
    qDebug()<<"33=" << name_;
}

void MainWindow::ReceiveDataFromNewGameWindow(const uint length, const uint width, const QString name){
    length_ = length;
    width_ = width;
    name_ = name;
    gameLogic_.setFieldSize(length, width);
    setFlagGameStart();
}

void MainWindow::CreateGameField(){
    if (layout_){
        EraseLayout(layout_);
    }
    layout_ = new QGridLayout(centralWidget());
    for(int row = 0; row < width_; ++ row){
        for(int len = 0; len < length_; ++len){
            // QPushButton *button = new QPushButton(QString("%1 %2").arg(row).arg(len), this);
            QPushButton *button = new QPushButton("", this);
            setHidePropertyXY(button, row, len);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);//политика растяжения кнопки
            connect(button, &QPushButton::clicked, this, &MainWindow::OnButtonClicked);
            layout_->setRowStretch(row,1);//растягиваем столбцы
            layout_->setColumnStretch(len,1);//растягиваем строки
            layout_->setSpacing(0);//убираем промежутки между ячейками
            layout_->addWidget(button,row,len);

        }
    }
}

void MainWindow::setFlagGameStart(){
    startGame_ = true;
    // emit game_is_on(m_start_game);
    emit game_is_on();
}

void MainWindow::EraseLayout(QGridLayout *layout){
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            delete item->widget(); // Удаляем виджет
        }
        delete item; // Удаляем элемент layout
    }
    // Удаляем сам layout
    delete layout;
}

void MainWindow::OnButtonClicked(){
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    bool turns{false};
    QMessageBox msq;
    GameStatus status;
    if (button) {
        QVariant hiddenX =button->property(kHiddenX);
        QVariant hiddenY =button->property(kHiddenY);
        if(!hiddenX.isValid() || !hiddenY.isValid()){
            //обдумать эту ветку. Возможно в данном случае нужно будет остановить игру, ибо не сможем обсчитывать ходы
        }
        status = gameLogic_.CheckMoves(hiddenX.toUInt(),hiddenY.toUInt());
        switch (status) {
        case GameStatus::Continue:
            button->setCheckable(true); // Включаем режим "checkable"
            button->setChecked(true); // Оставляем кнопку в нажатом состоянии
            button->setEnabled(false);
            break;
        case GameStatus::Win:
            msq.warning(this, "Победа", "Поздавляем, вы выйграли!");
            break;
        // case GameStatus::Fail:
        //     msq.critical(this, "Проигрыш", "К сожалению, вы проиграли.");
        //     break;
        default:
            break;
        }
    }
    gameLogic_.PrintInformation();
}

void MainWindow::setHidePropertyXY(QPushButton *button, uint X, uint Y){
    button->setProperty(kHiddenX, X);
    button->setProperty(kHiddenY, Y);
}

