#include <QMenu>
#include <QAction>
#include <QMainWindow>
#include <QWidget>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWheelEvent>
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
