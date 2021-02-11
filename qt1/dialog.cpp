#include "dialog.h"
#include <QPushButton>
#include <QGridLayout>
#include <QFileDialog>
#include <QDialogButtonBox>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent) {

        path = new QLabel(tr("Path"), this);
        //m_le = new QLineEdit("", this);
        path_string = new QLabel("" ,this);
        QDialogButtonBox *dbb = new QDialogButtonBox(Qt::Horizontal, this);
        dbb->addButton(QDialogButtonBox::Ok);
        connect(dbb, SIGNAL(accepted()), this, SLOT(accept()));
        QPushButton *browse = new QPushButton(tr("Browse"));
        connect(browse, SIGNAL(clicked()), this, SLOT(path_image()));


        QGridLayout *layout = new QGridLayout(this);
        layout->addWidget(path, 0,0);
        layout->addWidget(path_string, 0,1);
        layout->addWidget(browse, 1,0);
        layout->addWidget(dbb, 1,1);
        setLayout(layout);

    }

void Dialog:: path_image(){

    imageFile = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));
    path_string->setText(imageFile);
}

QString Dialog:: getpath()
{
    return imageFile;

}
