#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWidget w;
    w.clean();
    w.show();

    return a.exec();
}
