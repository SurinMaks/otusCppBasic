#ifndef RULEWINDOW_H
#define RULEWINDOW_H

#include <QDialog>

namespace Ui {
class ruleWindow;
}

class ruleWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ruleWindow(QWidget *parent = nullptr);
    ~ruleWindow();

private:
    Ui::ruleWindow *ui;
};

#endif // RULEWINDOW_H
