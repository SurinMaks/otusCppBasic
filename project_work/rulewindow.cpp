#include "rulewindow.h"

#include "ui_rulewindow.h"

ruleWindow::ruleWindow(QWidget *parent)
	: QDialog(parent), ui(new Ui::ruleWindow) {
	ui->setupUi(this);
}

ruleWindow::~ruleWindow() { delete ui; }
