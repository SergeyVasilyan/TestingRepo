#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QMainWindow>
#include <QWidget>
#include <QPixmap>

class MainWin: public QMainWindow {
    Q_OBJECT

public:
        MainWin();
        int pic_height();
        int pic_width();

private slots:
        void import_image();

private:
        int count ;
        QPixmap pix;
        QWidget *wd;
        QLabel *plabel;
        QAction *importAction;
        QAction *exitAction;
        QMenu *fileMenu;
};