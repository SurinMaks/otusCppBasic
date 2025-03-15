#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow window;
	try {
		MainWindow::connect(&window, &MainWindow::game_is_on,
						&MainWindow::CreateGameField);
		window.CreateMenu();
		window.show();
	} catch (...) {
		const QMessageBox msq;
		msq.critical(nullptr, "Критическая ошибка", "Обратитесь к разработчику!");
		QApplication::closeAllWindows();
	}

	return a.exec();
}
