#include "calculator.h"
#include <iostream>
#include "button.h"
#include <cmath>
Calculator::Calculator(QWidget *parent)
    : QWidget(parent), sumInMemory(0.0), sumSoFar(0.0)
    , factorSoFar(0.0), waitingForOperand(true)
{
    hypcount = 1 ;
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

    for (int i = 0; i < NumDigitButtons; ++i)
    digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));

    Button *pointButton = createButton(tr("."), SLOT(pointClicked()));
    Button *changeSignButton = createButton(tr("\302\261"), SLOT(changeSignClicked()));

    Button *backspaceButton = createButton(tr("Backspace"), SLOT(backspaceClicked()));//simvolov poxel
    Button *clearAllButton = createButton(tr("C"), SLOT(clearAll()));

    sinButton = createButton(tr("sin"), SLOT(trigonometricFunc()));
    cosButton = createButton(tr("cos"), SLOT(trigonometricFunc()));
    tanButton = createButton(tr("tan"), SLOT(trigonometricFunc()));
    cotButton = createButton(tr("cot"), SLOT(trigonometricFunc()));

    Button *arcsinButton = createButton(tr("arcsin"), SLOT(trigonometricFunc()));
    Button *arccosButton = createButton(tr("arccos"), SLOT(trigonometricFunc()));
    Button *arctanButton = createButton(tr("arctan"), SLOT(trigonometricFunc()));
    Button *arccotButton = createButton(tr("arccot"), SLOT(trigonometricFunc()));
    Button *hypButton = createButton(tr("hyp"), SLOT(hypClicked()));
    Button *secButton = createButton(tr("sec"), SLOT(trigonometricFunc()));
    Button *cscButton = createButton(tr("csc"), SLOT(trigonometricFunc()));
   
    Button *piButton = createButton(tr("pi"), SLOT(constVal()));//simvolov poxes
    Button *eButton = createButton(tr("e"), SLOT(constVal()));
    Button *leftbracketButton = createButton(tr("("), SLOT(constVal()));//simvolov poxes
    Button *rightbracketButton = createButton(tr(")"), SLOT(constVal()));

    Button *divisionButton = createButton(tr("\303\267"), SLOT(multiplicativeOperatorClicked()));
    Button *timesButton = createButton(tr("\303\227"), SLOT(multiplicativeOperatorClicked()));
    Button *powButton = createButton(tr("x^y"), SLOT(multiplicativeOperatorClicked()));//sinvolov poxes axji
    Button *minusButton = createButton(tr("-"), SLOT(additiveOperatorClicked()));
    Button *plusButton = createButton(tr("+"), SLOT(additiveOperatorClicked()));

    Button *squareRootButton = createButton(tr("Sqrt"), SLOT(unaryOperatorClicked()));//sinvolov poxes
    Button *powerButton = createButton(tr("x\302\262"), SLOT(unaryOperatorClicked()));
    Button *reciprocalButton = createButton(tr("1/x"), SLOT(unaryOperatorClicked()));
    Button *absoluteButton = createButton(tr("|x|"), SLOT(unaryOperatorClicked()));
    Button *expButton = createButton(tr("exp"), SLOT(unaryOperatorClicked()));
    Button *modButton = createButton(tr("mod"), SLOT(unaryOperatorClicked()));
    Button *facButton = createButton(tr("n!"), SLOT(unaryOperatorClicked()));
    Button *pow10Button = createButton(tr("10^x"), SLOT(unaryOperatorClicked()));//ete ka sinvoly,kpoxes
    Button *lnButton = createButton(tr("ln"), SLOT(unaryOperatorClicked()));
    Button *logButton = createButton(tr("log"), SLOT(unaryOperatorClicked()));

    Button *equalButton = createButton(tr("="), SLOT(equalClicked()));


    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    for (int i = 1; i < NumDigitButtons; ++i) {
        int row = ((9 - i) / 3) + 6;
        int column = ((i - 1) % 3) + 1;
        mainLayout->addWidget(digitButtons[i], row, column);
    }

    mainLayout->addWidget(digitButtons[0], 9, 2);
    mainLayout->addWidget(pointButton, 9, 3);
    mainLayout->addWidget(changeSignButton, 9, 1);

    mainLayout->addWidget(divisionButton, 5, 4);
    mainLayout->addWidget(timesButton, 6, 4);
    mainLayout->addWidget(minusButton, 7, 4);
    mainLayout->addWidget(plusButton, 8, 4);

    mainLayout->addWidget(squareRootButton, 5, 0);
    mainLayout->addWidget(powerButton, 4, 0);
    mainLayout->addWidget(reciprocalButton, 4, 1);
    mainLayout->addWidget(equalButton, 9, 4);
    
    mainLayout->addWidget(sinButton, 1, 0);
    mainLayout->addWidget(cosButton, 1, 1);
    mainLayout->addWidget(tanButton, 1, 2);
    mainLayout->addWidget(cotButton, 1, 3);
    mainLayout->addWidget(arcsinButton, 2, 0);
    mainLayout->addWidget(arccosButton, 2, 1);
    mainLayout->addWidget(arctanButton, 2, 2);
    mainLayout->addWidget(arccotButton, 2, 3);
    mainLayout->addWidget(hypButton, 1, 4);
    mainLayout->addWidget(secButton, 2, 4);
    mainLayout->addWidget(cscButton, 3, 0);

    mainLayout->addWidget(piButton, 3, 1);
    mainLayout->addWidget(eButton, 3, 2);
    mainLayout->addWidget(clearAllButton, 3, 3);
    mainLayout->addWidget(backspaceButton, 3, 4);

    mainLayout->addWidget(absoluteButton, 4, 2);
    mainLayout->addWidget(expButton, 4, 3);
    mainLayout->addWidget(modButton, 4, 4);

    mainLayout->addWidget(leftbracketButton, 5, 1);
    mainLayout->addWidget(rightbracketButton, 5, 2);
    mainLayout->addWidget(facButton, 5, 3);

    mainLayout->addWidget(powButton, 6, 0);
    mainLayout->addWidget(pow10Button, 7, 0);
    mainLayout->addWidget(logButton, 8, 0);
    mainLayout->addWidget(lnButton, 9, 0);
    mainLayout->addWidget(display,0,0,1,5);
    setLayout(mainLayout);

    setWindowTitle(tr("Calculator"));
}
void Calculator::constVal(){
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString text = clickedButton->text();
    if(text == "pi"){
	 display->setText(QString::number(M_PI));
         }
    if(text == "e"){
         display->setText(QString::number(std::exp(1.0)));
         }
}
void Calculator::trigonometricFunc()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();
    double result = 0.0;

    if (clickedOperator == tr("sin")) 
        result = std::sin(operand);
    else if (clickedOperator == tr("cos")) 
        result = std::cos(operand);
    else if (clickedOperator == tr("tan")) 
        result = std::tan(operand);
    else if (clickedOperator == tr("cot"))
    {
        double temp = std::tan(operand);
    	if (temp == 0.0){
	  abortOperation();
            return;
	}
    result = 1/temp;}
    else if (clickedOperator == tr("sec"))
    {
        double temp = std::cos(operand);
        if (temp == 0.0){
          abortOperation();
            return;
        }
    result = 1/temp;}

    else if (clickedOperator == tr("csc"))
    {
        double temp = std::sin(operand);
        if (temp == 0.0){
          abortOperation();
            return;
        }
    result = 1/temp;}
    else if (clickedOperator == tr("arcsin")) 
        result = std::asin(operand);
    else if (clickedOperator == tr("arccos")) 
        result = std::acos(operand);
    else if (clickedOperator == tr("arctan")) 
        result = std::atan(operand);
    else if (clickedOperator == tr("arccot"))
    {
        double temp = std::atan(operand);
        if (temp == 0.0){
          abortOperation();
            return;
        }
    result = 1/temp;}
    if (clickedOperator == tr("sinh")) 
        result = std::sinh(operand);
    else if (clickedOperator == tr("cosh")) 
        result = std::cosh(operand);
    else if (clickedOperator == tr("tanh")) 
        result = std::tanh(operand);
    else if (clickedOperator == tr("coth"))
    {
        double temp = std::tanh(operand);
        if (temp == 0.0){
          abortOperation();
            return;
        }
    result = 1/temp;}

    display->setText(QString::number(result));
    return ;

}

void Calculator::digitClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    int digitValue = clickedButton->text().toInt();
    if (display->text() == "0" && digitValue == 0.0)
        return;

    if (waitingForOperand) {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
}

void Calculator::hypClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString text = clickedButton->text();
    if ( text == "hyp" ){
    	if( hypcount == 1 ) {
	    sinButton->setText("sinh");
	    cosButton->setText("cosh");
	    tanButton->setText("tanh");
	    cotButton->setText("coth");

	    hypcount = 2; 
            return;
   	}

    	if(hypcount == 2 ){
     	    sinButton->setText("sin");
	    cosButton->setText("cos");
            tanButton->setText("tan");
            cotButton->setText("cot");
      	    hypcount = 1;
      	    return ;
     	 }
   }
}
void Calculator::unaryOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();
    double result = 0.0;

    if (clickedOperator == tr("Sqrt")) {
        if (operand < 0.0) {
            abortOperation();
            return;
        }
        result = std::sqrt(operand);
    } else if (clickedOperator == tr("x\302\262")) {
        result = std::pow(operand, 2.0);
    } else if (clickedOperator == tr("1/x")) {
        if (operand == 0.0) {
            abortOperation();
            return;
        }
        result = 1.0 / operand;
    }
    display->setText(QString::number(result));
    waitingForOperand = true;
}
void Calculator::additiveOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    if (!clickedButton)
      return;
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();
        if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(factorSoFar));
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
	  if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(sumSoFar));
    } else {
        sumSoFar = operand;
    }
	      pendingAdditiveOperator = clickedOperator;
    waitingForOperand = true;
}

void Calculator::multiplicativeOperatorClicked()
{
    Button *clickedButton = qobject_cast<Button *>(sender());
    if (!clickedButton)
      return;
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        display->setText(QString::number(factorSoFar));
    } else {
        factorSoFar = operand;
    }

    pendingMultiplicativeOperator = clickedOperator;
    waitingForOperand = true;
}
void Calculator::equalClicked()
{
    double operand = display->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        pendingAdditiveOperator.clear();
    } else {
        sumSoFar = operand;
    }

    display->setText(QString::number(sumSoFar));
    sumSoFar = 0.0;
    waitingForOperand = true;
}

void Calculator::pointClicked()
{
    if (waitingForOperand)
        display->setText("0");
    if (!display->text().contains('.'))
        display->setText(display->text() + tr("."));
    waitingForOperand = false;
}

void Calculator::changeSignClicked()
{
    QString text = display->text();
    double value = text.toDouble();

    if (value > 0.0) {
        text.prepend(tr("-"));
    } else if (value < 0.0) {
        text.remove(0, 1);
    }
    display->setText(text);
}

void Calculator::backspaceClicked()
{
    if (waitingForOperand)
        return;

    QString text = display->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    display->setText(text);
}

void Calculator::clear()
{
    if (waitingForOperand)
        return;

    display->setText("0");
    waitingForOperand = true;
}

void Calculator::clearAll()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    display->setText("0");
    waitingForOperand = true;
}

void Calculator::clearMemory()
{
    sumInMemory = 0.0;
}

void Calculator::readMemory()
{
    display->setText(QString::number(sumInMemory));
    waitingForOperand = true;
}

void Calculator::setMemory()
{
    equalClicked();
    sumInMemory = display->text().toDouble();
}

void Calculator::addToMemory()
{
    equalClicked();
    sumInMemory += display->text().toDouble();
}

Button *Calculator::createButton(const QString &text, const char *member)
{
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void Calculator::abortOperation()
{
    clearAll();
    display->setText(tr("####"));
}
bool Calculator::calculate(double rightOperand, const QString &pendingOperator)
{
    if (pendingOperator == tr("+")) {
        sumSoFar += rightOperand;
    } else if (pendingOperator == tr("-")) {
        sumSoFar -= rightOperand;
    } else if (pendingOperator == tr("\303\227")) {
        factorSoFar *= rightOperand;
    } else if (pendingOperator == tr("\303\267")) {
        if (rightOperand == 0.0)
            return false;
        factorSoFar /= rightOperand;
    }
    return true;
}

