#ifndef _Button_h_
#define _Button_h_
#include <Qt>
#include <QToolButton>
#include <QWidget>
class Button : public QToolButton
{
    Q_OBJECT

public:
    explicit Button(const QString &text, QWidget *parent = nullptr);
    void rename(QString str);
    QSize sizeHint() const override;
    QString text1;
};

#endif
