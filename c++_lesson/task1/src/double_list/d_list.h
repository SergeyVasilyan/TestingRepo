#ifndef D_LIST_H
#define D_LIST_H
#include <iostream>

template<class T>
struct node
{
	T info;
	node<T>* l_link;
	node<T>* r_link;

	node(T item, node<T>* lptr = NULL, node<T>* rptr = NULL): info(item), l_link(lptr), r_link(rptr) { }
};

template <class T>
class DList
{
public:
	DList();
	bool isEmpty();
	int Size();
	void insert(T, int);
	void remove(int);
private:
	node<T>* first;
	int size;
};
#endif
