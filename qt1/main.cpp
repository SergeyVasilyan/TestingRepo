#include <QApplication>
#include "mainwin.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MainWin *win = new MainWin();
    win->show();

    return app.exec();

}
