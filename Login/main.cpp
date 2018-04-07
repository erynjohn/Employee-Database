#include "loginpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //Displays login page as first window //
    QApplication a(argc, argv);
    LoginPage w;
    w.show();
return a.exec();
}
