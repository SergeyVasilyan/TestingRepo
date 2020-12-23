#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QAction>
#include <QMenu>

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow();

public slots:
	void show_image();
	void show_text();

private:
	QAction* image_action;
	QAction* text_action;
	QAction* message_action;
	QMenu* menu;
	QPushButton* text_button;
	QWidget* main_widget;

};

#endif
