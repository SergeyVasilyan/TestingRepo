#include <QApplication>
#include "mainwin.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MainWin *win = new MainWin();
    //win -> resize(500,500);
    win->show();

    return app.exec();

}
