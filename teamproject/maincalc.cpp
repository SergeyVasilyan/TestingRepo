#include "maincalc.hpp"

Calculator::Calculator()
{
	sum=0.0;
	mul=1.0;
	waiting_for_operand=true;
	display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

	main_layout= new QGridLayout(this);
	seconds_degree_button=new QPushButton(tr("2nd"),this);
	pi_num_button=new QPushButton(tr("pi"),this);
	e_num_button=new QPushButton(tr("e"),this);
	clear_button=new QPushButton(tr("C"),this);
	backspace_button=new QPushButton(tr("<-"),this);
	second_power_button=new QPushButton(tr("x\302\262"),this);
	one_divide_x_button=new QPushButton(tr("1/x"),this);
	abs_button=new QPushButton(tr("|x|"),this);
	exp_button=new QPushButton(tr("exp"),this);
	mod_button=new QPushButton(tr("mod"),this);
	sqrt_button=new QPushButton(tr("Sqrt"),this);
	left_scope_button=new QPushButton(tr("("),this);
	right_scope_button=new QPushButton(tr(")"),this);
	factorial_button=new QPushButton(tr("n!"),this);
	divide_button=new QPushButton(tr("/"),this);
	x_pow_y_button=new QPushButton(tr("x^y"),this);
	num_9_button=new QPushButton(tr("9"),this);
	num_8_button=new QPushButton(tr("8"),this);
	num_7_button=new QPushButton(tr("7"),this);
	num_6_button=new QPushButton(tr("6"),this);
	num_5_button=new QPushButton(tr("5"),this);
	num_4_button=new QPushButton(tr("4"),this);
	num_3_button=new QPushButton(tr("3"),this);
	num_2_button=new QPushButton(tr("2"),this);
	num_1_button=new QPushButton(tr("1"),this);
	num_0_button=new QPushButton(tr("0"),this);
	multiply_button=new QPushButton(tr("*"),this);
	substrackt_button=new QPushButton(tr("-"),this);
	add_button=new QPushButton(tr("+"),this);
	ten_pow_button=new QPushButton(tr("10^x"),this);
	log_button=new QPushButton(tr("log"),this);
	ln_button=new QPushButton(tr("ln"),this);
	dot_button=new QPushButton(tr("."),this);
	equal_button=new QPushButton(tr("="),this);
	sign_button=new QPushButton(tr("+/-"),this);
	main_layout->addWidget(display,0,0,1,5);
	main_layout->addWidget(seconds_degree_button,1,0);
	main_layout->addWidget(pi_num_button,1,1);
	main_layout->addWidget(e_num_button,1,2);
	main_layout->addWidget(clear_button,1,3);
	main_layout->addWidget(backspace_button,1,4);
	main_layout->addWidget(second_power_button,2,0);
	main_layout->addWidget(one_divide_x_button,2,1);
	main_layout->addWidget(abs_button,2,2);
	main_layout->addWidget(exp_button,2,3);
	main_layout->addWidget(mod_button,2,4);
	main_layout->addWidget(sqrt_button,3,0);
	main_layout->addWidget(left_scope_button,3,1);
	main_layout->addWidget(right_scope_button,3,2);
	main_layout->addWidget(factorial_button,3,3);
	main_layout->addWidget(divide_button,3,4);
	main_layout->addWidget(x_pow_y_button,4,0);
	main_layout->addWidget(num_7_button,4,1);
	main_layout->addWidget(num_8_button,4,2);
	main_layout->addWidget(num_9_button,4,3);
	main_layout->addWidget(multiply_button,4,4);
	main_layout->addWidget(ten_pow_button,5,0);
	main_layout->addWidget(num_4_button,5,1);
	main_layout->addWidget(num_5_button,5,2);
	main_layout->addWidget(num_6_button,5,3);
	main_layout->addWidget(substrackt_button,5,4);
	main_layout->addWidget(log_button,6,0);
	main_layout->addWidget(num_1_button,6,1);
	main_layout->addWidget(num_2_button,6,2);
	main_layout->addWidget(num_3_button,6,3);
	main_layout->addWidget(add_button,6,4);
	main_layout->addWidget(ln_button,7,0);
	main_layout->addWidget(sign_button,7,1);
	main_layout->addWidget(num_0_button,7,2);
	main_layout->addWidget(dot_button,7,3);
	main_layout->addWidget(equal_button,7,4);
	connect(num_0_button,SIGNAL(clicked()),this,SLOT(digit_clicked()));
	connect(num_1_button,SIGNAL(clicked()),this,SLOT(digit_clicked()));
	connect(num_2_button,SIGNAL(clicked()),this,SLOT(digit_clicked()));
	connect(num_3_button,SIGNAL(clicked()),this,SLOT(digit_clicked()));
	connect(num_4_button,SIGNAL(clicked()),this,SLOT(digit_clicked()));
	connect(num_5_button,SIGNAL(clicked()),this,SLOT(digit_clicked()));
	connect(num_6_button,SIGNAL(clicked()),this,SLOT(digit_clicked()));
	connect(num_7_button,SIGNAL(clicked()),this,SLOT(digit_clicked()));
	connect(num_8_button,SIGNAL(clicked()),this,SLOT(digit_clicked()));
	connect(num_9_button,SIGNAL(clicked()),this,SLOT(digit_clicked()));
	connect(dot_button,SIGNAL(clicked()),this,SLOT(dot_clicked()));
	connect(sign_button,SIGNAL(clicked()),this,SLOT(change_sign()));
	connect(abs_button,SIGNAL(clicked()),this,SLOT(unary_operator()));
	connect(one_divide_x_button,SIGNAL(clicked()),this,SLOT(unary_operator()));
	connect(second_power_button,SIGNAL(clicked()),this,SLOT(unary_operator()));
	connect(sqrt_button,SIGNAL(clicked()),this,SLOT(unary_operator()));
	connect(seconds_degree_button,SIGNAL(clicked()),this,SLOT(unary_operator()));
	connect(pi_num_button,SIGNAL(clicked()),this,SLOT(unary_operator()));
	connect(e_num_button,SIGNAL(clicked()),this,SLOT(unary_operator()));
	connect(exp_button,SIGNAL(clicked()),this,SLOT(unary_operator()));
	connect(ten_pow_button,SIGNAL(clicked()),this,SLOT(unary_operator()));
	connect(log_button,SIGNAL(clicked()),this,SLOT(unary_operator()));
	connect(ln_button,SIGNAL(clicked()),this,SLOT(unary_operator()));
	connect(factorial_button,SIGNAL(clicked()),this,SLOT(unary_operator()));
	connect(backspace_button,SIGNAL(clicked()),this,SLOT(backspace_clicked()));
	connect(clear_button,SIGNAL(clicked()),this,SLOT(clear()));
	connect(equal_button,SIGNAL(clicked()),this,SLOT(equal_clicked()));
	connect(add_button,SIGNAL(clicked()),this,SLOT(additive_operator()));
	connect(substrackt_button,SIGNAL(clicked()),this,SLOT(additive_operator()));
	connect(multiply_button,SIGNAL(clicked()),this,SLOT(multiplicative_operator()));
	connect(divide_button,SIGNAL(clicked()),this,SLOT(multiplicative_operator()));
	connect(mod_button,SIGNAL(clicked()),this,SLOT(multiplicative_operator()));
	connect(x_pow_y_button,SIGNAL(clicked()),this,SLOT(multiplicative_operator()));
}

void Calculator::digit_clicked(){
	QPushButton *clickedButton = (QPushButton*)sender();
    int digitValue = clickedButton->text().toInt();
    if (display->text() == "0" && digitValue == 0.0)
        return;

    if (waiting_for_operand) {
        display->clear();
        waiting_for_operand = false;
    }
    display->setText(display->text() + QString::number(digitValue));
}

void Calculator::dot_clicked(){
    if (waiting_for_operand)
        display->setText("0");
    if (!display->text().contains('.'))
        display->setText(display->text() + tr("."));
    waiting_for_operand = false;
}

void Calculator::change_sign(){
	QString text = display->text();
    double value = text.toDouble();

    if (value > 0.0) {
        text.prepend(tr("-"));
    } else if (value < 0.0) {
        text.remove(0, 1);
    }
    display->setText(text);
}

void Calculator::unary_operator(){
    QPushButton *clicked_button = (QPushButton*)sender();
    QString clicked_operator = clicked_button->text();
    double operand = display->text().toDouble();
    double result = 0.0;

    if (clicked_operator == tr("Sqrt")) {
        if (operand < 0.0) {
            abort_operation();
            return;
        }
        result = std::sqrt(operand);
    } else if (clicked_operator == tr("x\302\262")) {
        result = std::pow(operand, 2.0);
    } else if (clicked_operator == tr("1/x")) {
        if (operand == 0.0) {
            abort_operation();
            return;
        }
        result = 1.0 / operand;
    }else if(clicked_operator == tr("|x|")){
		result=std::abs(operand);
	}else if(clicked_operator == tr("2nd")){
		result=std::pow(2.0,operand);
	}else if(clicked_operator == tr("10^x")){
		result=std::pow(10.0,operand);
	}else if(clicked_operator == tr("ln")){
		if(operand < 1){
			abort_operation();
			return;
		}
		result=std::log(operand);
	}else if(clicked_operator == tr("log")){
		if(operand < 1){
			abort_operation();
			return;
		}
		result=std::log10(operand);
	}else if(clicked_operator == tr("exp")){
		result=std::exp(operand);
	}else if(clicked_operator == tr("pi")){
		result=M_PI;
	}else if(clicked_operator == tr("e")){
		result=std::exp(1.0);
	}else if(clicked_operator == tr("n!")){
		if(operand<0 || int(operand)!=operand){
			abort_operation();
			return;
		}
		result=double(factorial(operand));
	}
    display->setText(QString::number(result));
    waiting_for_operand = true;
}

void Calculator::multiplicative_operator(){
    QPushButton *clicked_button = (QPushButton*)sender();
    if (!clicked_button)
      return;
    QString clicked_operator = clicked_button->text();
    double operand = display->text().toDouble();

    if (!pending_multipl.isEmpty()) {
        if (!calculate(operand, pending_multipl)) {
            abort_operation();
            return;
        }
        display->setText(QString::number(mul));
    } else {
        mul = operand;
    }

    pending_multipl = clicked_operator;
    waiting_for_operand = true;
}

void Calculator::additive_operator(){
    QPushButton *clicked_button = (QPushButton*)sender();
    if (!clicked_button)
      return;
    QString clicked_operator = clicked_button->text();
    double operand = display->text().toDouble();
        if (!pending_multipl.isEmpty()) {
        if (!calculate(operand, pending_multipl)) {
            abort_operation();
            return;
        }
        display->setText(QString::number(mul));
        operand = mul;
        mul = 0.0;
        pending_multipl.clear();
    }
	  if (!pending_additive.isEmpty()) {
        if (!calculate(operand, pending_additive)) {
            abort_operation();
            return;
        }
        display->setText(QString::number(sum));
    } else {
        sum = operand;
    }
	      pending_additive = clicked_operator;
    waiting_for_operand = true;
}

void Calculator::equal_clicked(){
    double operand = display->text().toDouble();

    if (!pending_multipl.isEmpty()) {
        if (!calculate(operand, pending_multipl)) {
            abort_operation();
            return;
        }
        operand = mul;
        mul = 0.0;
        pending_multipl.clear();
    }
    if (!pending_additive.isEmpty()) {
        if (!calculate(operand, pending_additive)) {
            abort_operation();
            return;
        }
        pending_additive.clear();
    } else {
        sum = operand;
    }

    display->setText(QString::number(sum));
    sum = 0.0;
    waiting_for_operand = true;
}

void Calculator::backspace_clicked(){
    if (waiting_for_operand)
        return;

    QString text = display->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waiting_for_operand = true;
    }
    display->setText(text);
}

void Calculator::clear(){
    if (waiting_for_operand)
        return;

    display->setText("0");
    waiting_for_operand = true;
}

void Calculator::clear_all(){
    sum = 0.0;
    mul = 0.0;
    pending_additive.clear();
    pending_multipl.clear();
    display->setText("0");
    waiting_for_operand = true;
}

void Calculator::abort_operation(){
    clear_all();
    display->setText(tr("####"));
}

int Calculator::factorial(int number){
	if(number > 1)
        return number * factorial(number - 1);
    else
        return 1;
}

bool Calculator::calculate(double right_operand, const QString &pending_operator){
    if (pending_operator == tr("+")) {
        sum += right_operand;
    } else if (pending_operator == tr("-")) {
        sum -= right_operand;
    } else if (pending_operator == tr("*")) {
        mul *= right_operand;
    } else if (pending_operator == tr("/")) {
        if (right_operand == 0.0)
            return false;
        mul /= right_operand;
    }else if (pending_operator == tr("mod")) {
        if (right_operand == 0.0)
            return false;
		mul =std::fmod(mul,right_operand);
	}else if (pending_operator == tr("x^y")) {
        mul = std::pow(mul,right_operand);
	}
    return true;
}

Calculator::~Calculator(){
		delete display;
		delete main_layout;
	  	delete seconds_degree_button;
    	delete pi_num_button;
    	delete e_num_button;
    	delete clear_button;
    	delete backspace_button;
    	delete second_power_button;
    	delete one_divide_x_button;
    	delete abs_button;
    	delete exp_button;
    	delete mod_button;
    	delete sqrt_button;
    	delete left_scope_button;
    	delete right_scope_button;
    	delete factorial_button;
    	delete divide_button;
    	delete x_pow_y_button;
    	delete num_9_button;
    	delete num_8_button;
    	delete num_7_button;
    	delete num_6_button;
    	delete num_5_button;
    	delete num_4_button;
    	delete num_3_button;
    	delete num_2_button;
    	delete num_1_button;
    	delete num_0_button;
    	delete multiply_button;
    	delete substrackt_button;
    	delete add_button;
    	delete ten_pow_button;
    	delete log_button;
    	delete ln_button;
    	delete dot_button;
    	delete equal_button;
    	delete sign_button;
}
