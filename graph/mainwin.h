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
#include <QContextMenuEvent>

class QGraphicsView;

class MainWin: public QMainWindow {
    Q_OBJECT

public:
        MainWin();

private slots:
    void import_image();
	void reset();
	void zoom_in();
	void zoom_out();
protected:
	virtual void wheelEvent(QWheelEvent* event);
    virtual void contextMenuEvent(QContextMenuEvent *event);

private:
	int p_width;
	int p_height;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QPixmap pix;
    QWidget *wd;
    QAction *importAction;
    QAction *exitAction;
    QAction *resetAction;
    QAction *z_inAction;
    QAction *z_outAction;
    QMenu *fileMenu;
};
