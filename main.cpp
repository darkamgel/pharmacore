#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LOGIN w;
    w.show();

    return a.exec();
}
