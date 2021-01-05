#include <iostream>
#include <QPushButton>
#include <QDialog>
#include <QWidget>
#include <QLayout>
class Calculator: public QDialog
{
	Q_OBJECT
public:
	explicit Calculator();
/*public slots:
	void digit_clicked();
	void multiply();
	void add();
	void divide();
	void power();
	void substract();
	void mod();
	void factorial();
	void point_clicked();
	void clear();
	void logarithm();
	void ln_log();
	void pi_number();
	void e_number();
	void exponential();*/
private:
	QGridLayout* main_layout;
	QPushButton* seconds_degree_button;
	QPushButton* pi_num_button;
	QPushButton* e_num_button;
	QPushButton* clear_button;
	QPushButton* backspace_button;
	QPushButton* second_power_button;
	QPushButton* one_divide_x_button;
	QPushButton* abs_button;
	QPushButton* exp_button;
	QPushButton* mod_button;
	QPushButton* sqrt_button;
	QPushButton* left_scope_button;
	QPushButton* right_scope_button;
	QPushButton* factorial_button;
	QPushButton* divide_button;
	QPushButton* x_pow_y_button;
	QPushButton* num_9_button;
	QPushButton* num_8_button;
	QPushButton* num_7_button;
	QPushButton* num_6_button;
	QPushButton* num_5_button;
	QPushButton* num_4_button;
	QPushButton* num_3_button;
	QPushButton* num_2_button;
	QPushButton* num_1_button;
	QPushButton* num_0_button;
	QPushButton* multiply_button;
	QPushButton* substrackt_button;
	QPushButton* add_button;
	QPushButton* ten_pow_button;
	QPushButton* log_button;
	QPushButton* ln_button;
	QPushButton* dot_button;
	QPushButton* equal_button;
	QPushButton* sign_button;
};

