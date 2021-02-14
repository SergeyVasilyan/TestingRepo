#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QMainWindow>
#include <QWidget>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QTableView>
//#include <QStandardItemModel>
class MainWin: public QMainWindow {
    Q_OBJECT

public:
        MainWin();

private slots:
        void import_image();
	void customMenuRequested(QPoint pos);
	void reset();
	void zoom_in();
	void zoom_out();
protected:
	virtual void wheelEvent(QWheelEvent* event);

private:
//	QStandardItemModel *model;
	int p_width;
	int p_height;
        QTableView *table;
        QGraphicsScene *scene;
        QGraphicsView *view;
        QPixmap pix;
        QWidget *wd;
        //QLabel *plabel;
        QAction *importAction;
        QAction *exitAction;
        QMenu *fileMenu;
};
