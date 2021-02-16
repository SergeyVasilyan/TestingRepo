#include "mainwin.h"
#include "dialog.h"
#include <QMenuBar>
#include <QAbstractItemModel>
#include <QDebug>
#include <QModelIndex>
#include <QVBoxLayout>
#include <QGraphicsItem>
MainWin::MainWin(){
    p_width = 0;
    p_height = 0;
    this->resize(500,500);
    wd = new QWidget();
    setCentralWidget(wd);
    scene = new QGraphicsScene(wd);
    view = new QGraphicsView (wd);

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

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->resize(this->width(),this ->height());
    view->fitInView(0,0,view->width(),view->height());
    view->setScene(scene);
    view->show();
}

void MainWin::import_image() {
    Dialog *dlg = new Dialog(this);
    if (dlg->exec() == QDialog::Accepted){
        QString path = dlg->getpath();
        if(pix.load(path)) {

        p_height = pix.height();
	    p_width = pix.width();
	    scene->addPixmap(pix);
        view->fitInView(0,0,view->width(),view->height());

        }
    }
}
void MainWin::wheelEvent(QWheelEvent* event)
{
	static qreal factor = 1.0;
	const qreal delta = event->delta() / 120.0;
	if(delta < 0)
		factor--;
	else if(delta > 0)
		factor++;
	factor = qBound(1.0, factor, 100.0);
	view->setTransform(QTransform(factor, 0, 0, factor, 0, 0));
}

void MainWin::zoom_out(){

    static qreal factor = 1.0;
    const qreal delta = -1;
    if(delta < 0)
        factor--;
    factor = qBound(1.0, factor, 100.0);
    view->setTransform(QTransform(factor, 0, 0, factor, 0, 0));

}
void MainWin::reset(){
	static qreal factor = 0.0;
    factor = qBound(1.0, factor, 100.0);
    view->setTransform(QTransform(factor, 0, 0, factor, 0, 0));
}
void MainWin::zoom_in(){
    static qreal factor = 2.0;
    factor = qBound(1.0, factor, 100.0);
    view->setTransform(QTransform(factor, 0, 0, factor, 0, 0));
}

void MainWin::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menu = new QMenu(view);
    resetAction = new QAction(tr("Reset"), wd);
    connect(resetAction, SIGNAL(triggered()), this, SLOT(reset()));

    z_inAction = new QAction(tr("Zoom-in"), wd);
    z_inAction->setShortcut(tr("Ctrl++"));
    connect(z_inAction, SIGNAL(triggered()), this, SLOT(zoom_in()));
    z_outAction = new QAction(tr("Zoom-out"), wd);
    z_outAction->setShortcut(tr("Ctrl+-"));
    connect(z_outAction, SIGNAL(triggered()), this, SLOT(zoom_out()));

    menu->addAction(resetAction);
    menu->addAction(z_inAction);
    menu->addAction(z_outAction);
    menu->exec(event->globalPos());
}
