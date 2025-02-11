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
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::createMenu(){
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
    connect(about, &QAction::triggered,this, &MainWindow::openAboutWindow);
    connect(rules, &QAction::triggered, this, &MainWindow::openRuleWindow);
}

void MainWindow::openNewGameWindow(){
    newGameWindow *newGame = new class newGameWindow(this);
    newGame->exec();
}

void MainWindow::openAboutWindow(){
    QMessageBox::about(this, "О программе", "Данная игра разработанна в рамках выполнения проектой работы на курсе Otus. C++.Basic");
}

void MainWindow::openRuleWindow(){
    ruleWindow *ruleWindow = new class ruleWindow(this);
    ruleWindow->exec();
}

