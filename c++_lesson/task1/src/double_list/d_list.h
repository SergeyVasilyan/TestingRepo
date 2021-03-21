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
	List(List&);
	~List();
	bool isEmpty();
	int size();
	void insert(const T&, unsigned int);
	void remove(unsigned int);
	T& operator[](unsigned int);
private:
	node<T>* first;
	int msize;
};

template <class T>
List<T>::List()
	: first(NULL),
	  msize(0)
{}

template<class T>
List<T>::List(List& cpylist) {
	int i=0;
	node<T>* temp = cpylist.first;
	while (temp->r_link) {
		this->insert(temp->info, i);
		temp = temp->r_link;
		i++;
	}
}

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
	return msize == 0;
}

template <class T>
int List<T>::size()
{
	return msize;
}

template <class T>
void List<T>::insert(const T& value, unsigned int pos) {
	if (pos < 0 || pos > size()) {
		std::cout<<("Underflow/Overflow")<<std::endl;
	}
	if (isEmpty()) {
		node<T>* temp = new node<T>(value);
		this->first = temp;
	} else {
		node<T>* q = new node<T>(value);
		if (pos == 0) {
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
	}
	msize++;
}

template <class T>
void List<T>::remove(unsigned int pos) {
	if (isEmpty()) {
		std::cout<<"List is empty"<<std::endl;
	}
	if (pos < 0 || pos >= size()) {
		std::cout<<" Out of range. "<<std::endl;
	}
	node<T>* p = this->first;
	for (int i = 0; i < pos; i++) {
		p = p->r_link;
	}
	if (p->l_link != NULL) {
		(p->l_link)->r_link = p->r_link;
	}
	if (p->r_link != NULL) {
		p->r_link->l_link = p->l_link;
		if (pos == 0) {
		this->first = p->r_link;
		}
	}
	delete p;
	this->msize--;
}
template<class T>
T& List<T>::operator[](unsigned int index) {
	if (index >= 0 && index < this->size()) {
		node<T>* temp = this->first;
			for (unsigned int i = 0; i < index; i++) {
				temp = temp->r_link;
			}
		return temp->info;
	}
	else {
		std::cout<<" Invalid argument type.\n ";
	}
}
#endif
