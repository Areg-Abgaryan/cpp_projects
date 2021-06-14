#include "widget.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("Color Picker");
    w.show();
    return a.exec();
}
