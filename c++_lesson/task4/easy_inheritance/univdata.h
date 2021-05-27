#include <iostream>

class Person
{
private :
	std::string name;
	std::string lname;
	std::string mname;

public:
	Person(std::string nm, std::string lnm, std::string mnm)
		: name(nm),
		lname(lnm),
		mname(mnm)
	{};
	virtual void showdata() {
		std::cout << "Name: " << name <<std::endl;
		std::cout << "Last name: " << lname <<std::endl;
		std::cout << "Middle name: " << mname <<std::endl;
	}
};

class Student : public Person
{
private :
	unsigned int mgrade;
public:
	Student(std::string nm, std::string lnm, std::string mnm, unsigned int mgr)
		: Person(nm, lnm, mnm),
		mgrade(mgr)
	{};
	virtual void showdata() {
		Person::showdata();
		std::cout << "Average grade: " << mgrade <<std::endl;
	}
};

class Professor : public Person
{
private :
	unsigned int num_pub;
	std::string position;
    unsigned int age;
public:
     Professor(std::string nm, std::string lnm, std::string mnm, unsigned int n_pub, std::string pos, unsigned int years)
        : Person(nm, lnm, mnm),
		num_pub(n_pub),
		position(pos),
		age(years)
    {};
    virtual void showdata() {
        Person::showdata();
        std::cout << "Number of publications: " << num_pub <<std::endl;
		std::cout << "Position: " << position <<std::endl;
        std::cout << "Age: " << age <<std::endl;
    }
};
