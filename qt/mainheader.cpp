#include "mainheader.hpp"
#include <QMessageBox>
#include <QLabel>
#include <QPixmap>
MainWindow::MainWindow(){
	action_text=new QAction(tr("Blabla"),this);
	action_image=new QAction(tr("TRalyalya"),this); 

	connect(action_text,SIGNAL(triggered()),this,SLOT(show_text()));
	connect(action_image,SIGNAL(triggered()),this,SLOT(show_image()));

	menu = menuBar()->addMenu("&Actions");
	menu->addAction(action_text);
	menu->addSeparator();
	menu->addAction(action_image);
	label = new QLabel(tr("Aha"));
	setCentralWidget(label);
}

void MainWindow::show_text(){
	QMessageBox::information(this,tr("tadamtadam"),tr("Gor Vardanyan"));
}
void MainWindow::show_image(){
	QPixmap pic;
	pic.load("./index.jpeg");
    label->setPixmap(pic.scaled(label->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
    label->show();
}
