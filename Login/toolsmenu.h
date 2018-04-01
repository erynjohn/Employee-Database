#ifndef TOOLSMENU_H
#define TOOLSMENU_H

#include <QDialog>

namespace Ui {
class toolsMenu;
}

class toolsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit toolsMenu(QWidget *parent = 0);
    ~toolsMenu();

private:
    Ui::toolsMenu *ui;
};

#endif // TOOLSMENU_H
