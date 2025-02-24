#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "newgamewindow.h"
#include "rulewindow.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked, this, &MainWindow::print_field_size);//временное подключени для проверок
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::create_menu(){
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
    connect(newGame, &QAction::triggered, this, &MainWindow::openNewGameWindow);
    connect(about, &QAction::triggered,this, &MainWindow::open_about_window);
    connect(rules, &QAction::triggered, this, &MainWindow::open_rule_window);
}

void MainWindow::openNewGameWindow(){
    newGameWindow *newGame = new class newGameWindow(this);
    connect(newGame, &newGameWindow::send_playing_field_size, this, &MainWindow::receive_data_from_newGameWindow);// Подключаем сигнал к слоту
    newGame->exec();
}

void MainWindow::open_about_window(){
    QMessageBox::about(this, "О программе", "Данная игра разработанна в рамках выполнения проектой работы на курсе Otus. C++.Basic");
}

void MainWindow::open_rule_window(){
    ruleWindow *ruleWindow = new class ruleWindow(this);
    ruleWindow->exec();
}

//временный метод для проверка результатов
void MainWindow::print_field_size() const {
    qDebug()<<"11=" << m_length;
    qDebug()<<"22=" << m_width;
    qDebug()<<"33=" << m_name;
}

void MainWindow::receive_data_from_newGameWindow(const uint length, const uint width, const QString name){
    m_length = length;
    m_width = width;
    m_name = name;
    set_flag_game_start();
}

void MainWindow::create_game_field(){
    if (layout != nullptr){
        erase_layout(layout);
    }
    layout = new QGridLayout(centralWidget());
    for(int row = 0; row < m_width; ++ row){
        for(int len = 0; len < m_length; ++len){
            QPushButton *button = new QPushButton(QString("Button %1, %2").arg(row).arg(len), this);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);//политика растяжения кнопки
            connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
            layout->setRowStretch(row,1);//растягиваем столбцы
            layout->setColumnStretch(len,1);//растягиваем строки
            layout->addWidget(button,row,len);
            layout->setSpacing(0);//убираем промежутки между ячейками
        }
    }
}

void MainWindow::set_flag_game_start(){
    m_start_game = true;
    // emit game_is_on(m_start_game);
    emit game_is_on();
}

void MainWindow::erase_layout(QGridLayout *layout){
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

void MainWindow::onButtonClicked(){
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        qDebug() << "Button clicked:" << button->text();
    }
}

