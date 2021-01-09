#ifndef _Calculator_h_
#define _Calculator_h_
#include <QWidget>
#include <QStack>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QKeyEvent>
#include <QLineEdit>
#include "button.h"
class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void digitClicked();
    void hypClicked();
    void unaryOperatorClicked();
    void additiveOperatorClicked();
    void multiplicativeOperatorClicked();
    void equalClicked();
    void pointClicked();
    void changeSignClicked();
    void backspaceClicked();
    void clear();
    void clearAll();
    void clearMemory();
    void readMemory();
    void setMemory();
    void addToMemory(); 
    void trigonometricFunc();
    void constVal();
private:
    Button *sinButton ;
    Button *cosButton ;
    Button *tanButton ;
    Button *cotButton ;
    Button *createButton(const QString &text, const char *member);
    void abortOperation();
    bool calculate(double rightOperand, const QString &pendingOperator);
    double sumInMemory;
    double sumSoFar;
    double factorSoFar;
    QString pendingAdditiveOperator;
    QString pendingMultiplicativeOperator;
    bool waitingForOperand;
    QLineEdit *display;
    enum { NumDigitButtons = 10 };
    Button *digitButtons[NumDigitButtons];
    int hypcount;
};
#endif
