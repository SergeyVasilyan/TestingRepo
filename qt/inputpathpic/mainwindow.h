#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow();
    QString get_path();
public slots:
    void picoutput();
    void clearline();
private:
    QLabel* pic_label;
    QLabel* plabel;
    QLineEdit* output;

};

#endif

