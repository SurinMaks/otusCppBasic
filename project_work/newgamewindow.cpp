#include "newgamewindow.h"

#include <QMessageBox>

#include "ui_newgamewindow.h"

newGameWindow::newGameWindow(QWidget *parent)
	: QDialog(parent), ui(new Ui::newGameWindow) {
	ui->setupUi(this);

	QIntValidator *intValidator =
		new QIntValidator(kMinValueFieldSize, kMaxValueFiledSize, this);
	ui->le_horizontSize->setValidator(intValidator);
	ui->le_vetricalSize->setValidator(intValidator);

	connect(ui->bt_OK, &QPushButton::clicked, this, &newGameWindow::BtPressOK);
	connect(ui->bt_Cancel, &QPushButton::clicked, this, &newGameWindow::close);
}

newGameWindow::~newGameWindow() { delete ui; }

void newGameWindow::BtPressOK() {
	if (CheckFieldSize()) {
		emit send_playing_field_size(ui->le_horizontSize->text().toUInt(),
									 ui->le_vetricalSize->text().toUInt(),
									 ui->le_userName->text());
		this->close();
	} else {
		QMessageBox msq;
		msq.warning(this, "Предупрежение",
					"Размеры игрового поля не могут быть меньше " +
						QString::number(kMinValueFieldSize));
	}
}

bool newGameWindow::CheckFieldSize() const {
	if ((ui->le_horizontSize->text().toUInt() >= kMinValueFieldSize) &&
		(ui->le_vetricalSize->text().toUInt() >= kMinValueFieldSize)) {
		return true;
	} else {
		return false;
	}
}
