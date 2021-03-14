#include<iostream>
#include"d_list.h"

template <class T>
DList<T>::List():first(NULL), size(0){ }

template <class T>
DList<T>::~List()
{
        while(this->isEmpty()){
                this->remove(0);
        }
}

template <class T>
bool DList<T>::isEmpty(){
return this->size == 0;
}

template <class T>
int DList<T>::Size(){
return this->size;
}

template <typename T>
void DList<T>::insert(T value, int pos)
{
        if(pos < 0 || pos > size()){
                throw("Underflow/Overflow");
        }
        if(first == NULL)
        {
		node<T>* p = new node<T>(value);
                this->first = p;
		this->size++;
               // return;
        }

	node<T>* q = new node<T>;
        node* p = this->first;
        for(int i=0; i<pos-1; i++){
		p= p->r_link;
	}
	q->info=value;
	q->l_link = p->l_link;
	q->r_link = p->r_link;
	(p->l_link)->r_link = q;
	if(p->r_link == NULL){
        (p->r_link)->l_link =` q;
	}
	this->size++;
}

template <typename T>
void DList<T>::remove(int pos)
{
	if(isEmpty() == NULL){
		throw("List is empty");
	}
	if(pos < 0 || pos >=size()){
                throw("out of range");
        }
	node* p = this->first;
        for(int i=0; i<pos-1; i++){
                p= p->r_link;
        }
	if(p->l_link != NULL){
		(p->l_link)->r_link = p->r_link;
	}
	if(p->r_link != NULL){
		 (p->r_link)->l_link = p->l_link;
	}
        this->size--;
}
