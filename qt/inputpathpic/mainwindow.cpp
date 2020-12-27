#include<QLabel>
#include<QVBoxLayout>
#include<QDialogButtonBox>
#include<QLineEdit>
#include "mainwindow.h"

MainWindow::MainWindow(){

    output = new QLineEdit("", this);
    pic_label = new QLabel("Picture:");
    output->setPlaceholderText(("enter the absolute path of the picture"));

    QDialogButtonBox *dbb = new QDialogButtonBox(Qt::Horizontal, this);
    dbb->addButton(QDialogButtonBox::Ok);
    dbb->addButton(QDialogButtonBox::Close);

    connect(dbb, SIGNAL(accepted()), this, SLOT(picoutput()));
    connect(dbb, SIGNAL(rejected()), this, SLOT(clearline()));
    QWidget* wd = new QWidget();
    setCentralWidget(wd);
    plabel = new QLabel(wd);
    QVBoxLayout *v_layout = new QVBoxLayout(wd);
    QGridLayout *g_layout = new QGridLayout(wd);

    g_layout->addWidget(pic_label,0,0);
    g_layout->addWidget(output,0,1);
    
    v_layout->addLayout(g_layout);
    v_layout->addWidget(dbb);
    v_layout->addWidget(plabel);
    setLayout(v_layout);
}
QString MainWindow::get_path(){
    return output->text();
}
void MainWindow :: picoutput(){
    QPixmap pix;
    QString path=get_path();
    if(pix.load(path)){
        pix = pix.scaled(plabel->size(),Qt::KeepAspectRatio);
        plabel->setPixmap(pix);
    }
}
void MainWindow :: clearline(){
    output->clear();
}
