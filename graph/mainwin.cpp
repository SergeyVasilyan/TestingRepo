#include "mainwin.h"
#include "dialog.h"
#include <QMenuBar>
#include <QDebug>

MainWin::MainWin(){
    wd = new QWidget();
    setCentralWidget(wd);
    plabel = new QLabel(wd);
    importAction = new QAction(tr("Import"), wd);
    importAction->setStatusTip(tr("Import "));
    connect(importAction, SIGNAL(triggered()), this, SLOT(import_image()));

    exitAction = new QAction(tr("Exit"), wd);
    exitAction->setStatusTip(tr("Exit "));
    exitAction->setShortcut(tr("Ctrl+Q"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(importAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

}
/*
void MainWin::import_image() {
    Dialog *dlg = new Dialog(this);
    if (dlg->exec() == QDialog::Accepted){
        QString path = dlg->getpath();
        if(pix.load(path)) {
            plabel->clear();
            plabel->setGeometry( 0, 0, pix.width(), pix.height());
            plabel->setPixmap(pix);
            qDebug() << pix.width();
            qDebug() << pix.height();
            resize(pix.width(), pix.height());
        }
    }
}

void MainWin::import_image() {

    Dialog *dlg = new Dialog(this);
    if (dlg->exec() == QDialog::Accepted){
        QString path = dlg->getpath();
        if(pix.load(path)) {

            graphicsView = new  QGraphicsView(wd);
            scene = new QGraphicsScene(wd);
            scene->addPixmap(pix);
            scene->setSceneRect(pix.rect());
            graphicsView->setScene(scene);
        }
    }
i}

*/

void MainWin::import_image() {
    Dialog *dlg = new Dialog(this);
    if (dlg->exec() == QDialog::Accepted){
        QString path = dlg->getpath();
        if(pix.load(path)) {
            QGraphicsView * view = new QGraphicsView (wd);
            QGraphicsScene *scene = new QGraphicsScene(wd);
            scene->addPixmap(pix);
            view->setScene(scene);
            view->show();
            view->resize(this->width(),this ->height());

            qDebug() << this->width();
            qDebug() << this->height();

            // coll from some slot to see the effect
            view->scale(200,200);   //zoom in
            view->scale(.5,.5); //zoom out

        }
    }
}

