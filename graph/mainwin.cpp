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
    wd = new QWidget();
    setCentralWidget(wd);
    view = new QGraphicsView (wd);
    scene = new QGraphicsScene(wd);

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

    QVBoxLayout *l=new QVBoxLayout(wd);
    table=new QTableView(view);
    table->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(table, SIGNAL(customContextMenuRequested(QPoint)),
           SLOT(customMenuRequested(QPoint)));
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //l->addWidget(table);
    l->addWidget(view);

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
        view->setScene(scene);
        //view->resize(this->width(),this ->height());
	    view->show();
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

void MainWin::customMenuRequested(QPoint pos){

    QMenu *menu=new QMenu(wd);
    QAction *resetAction = new QAction(tr("Reset"),scene);
    QAction *inAction = new QAction(tr("Zoom in"),  scene);
    QAction *outAction = new QAction(tr("Zoom out"), scene);
    inAction->setShortcut(tr("Ctrl++"));
    outAction->setShortcut(tr("Ctrl+-"));

    connect(resetAction, SIGNAL(triggered()), wd, SLOT(reset()));
    connect(inAction, SIGNAL(triggered()), wd, SLOT(zoom_in()));
    connect(outAction, SIGNAL(triggered()), wd, SLOT(zoom_out));

    menu->addAction(resetAction);
    menu->addAction(inAction);
    menu->addAction(outAction);
    menu->popup(table->viewport()->mapToGlobal(pos));
}
void MainWin::reset(){

    pix.scaled(QSize(p_width,p_height), Qt::KeepAspectRatio);
    scene->addPixmap(pix);  
}
void MainWin::zoom_out(){
	static qreal factor = 0.0;
    factor = qBound(1.0, factor, 100.0);
    view->setTransform(QTransform(factor, 0, 0, factor, 0, 0));
}
void MainWin::zoom_in(){
    static qreal factor = 2.0;
    factor = qBound(1.0, factor, 100.0);
    view->setTransform(QTransform(factor, 0, 0, factor, 0, 0));
}
/*
void MainWin::contextMenuEvent(QContextMenuEvent *event)
{
    QPointF p=event->pos();

    QGraphicsItem *item = itemAt(p.x(),p.y());
    if (item != NULL) {

            //QGraphicsView::contextMenuEvent(event);
            contextMenuEvent(event);

            return;
        }

   // QMenu menu();
    //menu.addAction(tr("Action 1"));
    //menu.addAction(tr("Action 2"));
    //menu.exec(event->globalPos());
    QMenu *menu=new QMenu();
    menu->addAction(tr("Action 1"));
    menu->addAction(tr("Action 2"));
    menu->exec(event->globalPos());


}*/
