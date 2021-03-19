#ifndef D_LIST_H
#define D_LIST_H

#include <iostream>

template<class T>
struct node
{
	T info;
	node<T>* l_link;
	node<T>* r_link;

	node(const T& item, node<T>* lptr = NULL, node<T>* rptr = NULL)
	    : info(item),
	      l_link(lptr),
	      r_link(rptr)
       	{}
};

template <class T>
class List
{
public:
	List();
	~List();
	bool isEmpty();
	int Size();
	void insert(const T&, int);
	void remove(int);
private:
	node<T>* first;
	int size;
};

template <class T>
List<T>::List()
	: first(NULL),
	  size(0)
{}

template <class T>
List<T>::~List()
{
	while (! isEmpty()) {
		remove(0);
	}
}

template <class T>
bool List<T>::isEmpty()
{
	return size == 0;
}

template <class T>
int List<T>::Size()
{
	return size;
}

template <class T>
void List<T>::insert(const T& value, int pos) {
	if (pos < 0 || pos > Size()){
		std::cout<<("Underflow/Overflow")<<std::endl;
	}
	if (isEmpty()) {
		node<T>* p = new node<T>(value);
		this->first = p;
		this->size++;
	}
	node<T>* q = new node<T>(value);
	if (pos == 0) {
		q->l_link = this->first->l_link;
		q->r_link = this->first;
		this->first->l_link = q;
		this->first = q;
	} else {
		node<T>* p = this->first;
		for(int i = 0; i < pos-1; i++){
			p = p->r_link;
		}
		q->r_link = p-> r_link;
		q->l_link = p;
		p->r_link = q;
		if(p->r_link != NULL){
			p->r_link->l_link = q;
		}
	}
	size++;
}

template <class T>
void List<T>::remove(int pos) {
	if (isEmpty()) {
		std::cout<<"List is empty"<<std::endl;
	}
	if (pos < 0 || pos > Size()) {
		throw("out of range");
	}
	node<T>* p = this->first;
	for (int i = 0; i < pos-1; i++) {
		p= p->r_link;
	}
	if (p->l_link != NULL) {
		(p->l_link)->r_link = p->r_link;
	}
	if (p->r_link != NULL) {
		p->r_link->l_link = p->l_link;
	}
	delete p;
	this->size--;
}
#endif
