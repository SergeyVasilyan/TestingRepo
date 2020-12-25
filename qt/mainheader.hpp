#include <QMainWindow>
#include <QPushButton>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QWidget>
#include <QLabel>
class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow();
public slots: 
	void show_image();
	void show_text();
private:
	QPushButton* m_button;
	QMenu* menu;
	QAction* action_text;
	QAction* action_image;
	QWidget* widget;
	QLabel* label;
};
