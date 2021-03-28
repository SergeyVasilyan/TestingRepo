#ifndef D_LIST_H
#define D_LIST_H

#include <iostream>
#include <cassert>

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
	List(const List&);
	~List();
	bool isEmpty() const;
	int size() const;
	void clear();
	node<T>* get_node(int) const;
	void insert(const T&, unsigned int);
	void remove(unsigned int);
	List<T>& operator=(const List&);
	T& operator[](unsigned int) const;
	bool operator==(const List&) const;
private:
	node<T>* first;
	int m_size;
};

template <class T>
List<T>::List()
	: first(NULL)
	, m_size(0)
{}

template<class T>
List<T>::List(const List& cpylist)
	: first(NULL)
	, m_size(0)
{
	if (cpylist.isEmpty()) {
		return;
	}
	int i = 0;
	node<T>* temp = cpylist.first;
	assert(NULL != temp);
	while (temp->r_link) {
		insert(temp->info, i);
		temp = temp->r_link;
		i++;
	}
	insert(temp->info, i);
}

template <class T>
List<T>::~List()
{
	clear();
}

template <class T>
void List<T>::clear()
{
        while (! isEmpty()) {
                remove(0);
        }
		assert(NULL == first);
		assert(0 == size());
}

template <class T>
bool List<T>::isEmpty() const
{
	return m_size == 0;
}

template <class T>
int List<T>::size() const
{
	return m_size;
}

template <class T>
node<T>* List<T>::get_node(int index) const
{
	assert(index >= 0);
        assert(index < size());
	node<T>* temp = first;
        for (unsigned int i = 0; i < index; i++) {
                temp = temp->r_link;
        }
	return  temp;
}

template <class T>
void List<T>::insert(const T& value, unsigned int pos) {
	if (pos < 0 || pos > size()) {
		std::cout<<("Underflow/Overflow")<<std::endl;
		return;
	}
	if (isEmpty()) {
		first = new node<T>(value);
		assert(NULL == first->r_link);
		assert(NULL == first->l_link);
	} else {
		node<T>* q = new node<T>(value);
		if (pos == 0) {
			q->r_link = first;
			first->l_link = q;
			first = q;
		} else {
			node<T>* p = first;
			p = get_node(pos-1);//avelocvoxi naxord dirqy
			q->r_link = p->r_link;
			q->l_link = p;
			p->r_link = q;
			if (p->r_link != NULL) {
				p->r_link->l_link = q;
			}
		}
	}
	m_size++;
}

template <class T>
void List<T>::remove(unsigned int pos) {
	if (isEmpty()) {
		std::cout<<"List is empty"<<std::endl;
		return;
	}
	if (pos < 0 || pos >= size()) {
		std::cout<<" Out of range. "<<std::endl;
		return;
	}
	node<T>* p = first;
	p = get_node(pos);//heracvox node  
	if (p->l_link != NULL) {
		p->l_link->r_link = p->r_link;
	} else {
		assert(0 == pos);
		first = p->r_link;
	}
	if (p->r_link != NULL) {
		p->r_link->l_link = p->l_link;
	}
	delete p;
	m_size--;
	assert(m_size >= 0);
}

template<class T>
List<T>& List<T>::operator = (const List<T>& dlist)
{
	if (this != &dlist) {
		this->clear();
		node<T>* temp = dlist.first;
		for (int i = 0; i < dlist.size(); i++) {
			this->insert(temp->info, i);
			temp = temp->r_link;
		}
		return *this;
	}
}

template<class T>
T& List<T>::operator[](unsigned int index) const
{
        node<T>* temp = get_node(index);
	return temp->info;
}

template<class T>
bool List<T>::operator == (const List& other_list) const
{
	if (size() != other_list.size()) {
		return false;
	}
	for (int i = 0; i < size(); i++) {
		if (this->operator[](i) != other_list[i]) {
			return false;
	   	}
	}
	return true;
}
#endif
