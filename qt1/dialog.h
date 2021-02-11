#ifndef _DIALOG_H_
#define _DIALOG_H_

#include <QDialog>
#include <QLabel>
#include<QLineEdit>
class Qstring;

class Dialog : public QDialog {

    Q_OBJECT

public:

        Dialog(QWidget *parent=0);
        QString getpath();
public slots:

        void path_image();
private:

        QString imageFile;
        QLabel *path ;
        QLabel *path_string;

};
#endif // _DIALOG_H_
