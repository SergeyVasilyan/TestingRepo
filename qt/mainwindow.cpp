#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QMenuBar>
#include <QPixmap>

MainWindow::MainWindow() {
	label = new QLabel();
	image_action = new QAction(tr("Show image"), this);
	image_action->setStatusTip(tr("Show image"));
	connect(image_action, SIGNAL(triggered()), this, SLOT(show_image()));

	text_action = new QAction(tr("Show text"), this);
	text_action->setStatusTip(tr("Show text"));
	connect(text_action, SIGNAL(triggered()), this, SLOT(show_text()));

	menu = menuBar()->addMenu(tr("&Action"));
	menu->addAction(image_action);
	menu->addSeparator();
	menu->addAction(text_action);

	text_button = new QPushButton(tr("Show text"), this);
	setCentralWidget(text_button);
	connect(text_button, SIGNAL(clicked()), this, SLOT(show_text()));

	setFixedSize(width(), height());
}

void MainWindow::show_text(){
	QMessageBox::information(this, tr("Title"),
			   	tr("Some Text."));
}

void MainWindow::show_image(){
	QPixmap pix;
	pix.load("./picture/a.jpg");
    label->setPixmap(pix.scaled(label->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
	label->show();
}
