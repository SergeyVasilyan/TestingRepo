#include<iostream>
#include"d_list.h"

template <class T>
List<T>::List()
	:first(NULL),
       	size(0)
   {}

template <class T>
List<T>::~List()
{
        while(!this->isEmpty()){
                this->remove(0);
        }
}

template <class T>
bool List<T>::isEmpty(){
return this->size == 0;
}

template <class T>
int List<T>::Size(){
	return this->size;
}

template <class T>
void List<T>::insert(T value, int pos)
{
	if( pos < 0 || pos > Size() ){
		throw("Underflow/Overflow");
	}
	if(isEmpty())
	{
		node<T>* p = new node<T>(value);
		this->first = p;
		this->size++;
	}

	node<T>* q = new node<T>(value);
	if(pos == 0){
		q->l_link = this->first->l_link;
		q->r_link = this->first;
		this->first->l_link = q;
		this->first = q;
	}
	else{
		node<T>* p = this->first;
		for(int i=0; i<pos-1; i++){
			p= p->r_link;
		}
		q->r_link = p-> r_link;
		q->l_link = p;
		p->r_link = q;
		if(p->r_link != NULL){
			p->r_link->l_link = q;
		}
	}
	this->size++;
}

template <class T>
void List<T>::remove(int pos)
{
	if(isEmpty()){
		throw("List is empty");
	}
	if(pos < 0 || pos > Size()){
                throw("out of range");
        }
	node<T>* p = this->first;
        for(int i=0; i<pos-1; i++){
                p= p->r_link;
        }
	if(p->l_link != NULL){
		(p->l_link)->r_link = p->r_link;
	}
	if(p->r_link != NULL){
		 (p->r_link)->l_link = p->l_link;
	}
	delete p;
        this->size--;
}
