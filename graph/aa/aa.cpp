// Qt header:
#include <QtWidgets>

// main application
int main(int argc, char **argv)
{
  qDebug() << "Qt Version:" << QT_VERSION_STR;
  QApplication app(argc, argv);
  // setup data
  QGraphicsScene qGScene;
  QGraphicsItemGroup qGItemGrp;
  QImage qImgCat("cat.jpeg");
  QGraphicsPixmapItem qGItemImg(QPixmap::fromImage(qImgCat));
  qGItemImg.setTransform(
    QTransform().translate(-0.5 * qImgCat.width(), -0.5 * qImgCat.height()));
  qGItemGrp.addToGroup(&qGItemImg);
  qGScene.addItem(&qGItemGrp);
  // setup GUI
  QWidget qWinMain;
  qWinMain.setWindowTitle("QGraphicsView - Scale Image");
  QVBoxLayout qVBox;
  QGraphicsView qGView;
  qGView.setScene(&qGScene);
  qVBox.addWidget(&qGView, 1);
  QSlider qSlider(Qt::Horizontal);
  qSlider.setRange(-100, 100);
  qVBox.addWidget(&qSlider);
  qWinMain.setLayout(&qVBox);
  qWinMain.show();
  // install signal handlers
  auto scaleImg = [&](int value) {
    const double exp = value * 0.01;
    const double scl = pow(10.0, exp);
    qGItemGrp.setTransform(QTransform().scale(scl, scl));
  };
  QObject::connect(&qSlider, &QSlider::valueChanged,
    scaleImg);
  // runtime loop
  return app.exec();
}

