#ifndef node.h
#define node.h

#include <iostream>

using namespace std;


template<typename T>
struct Node {

	T data;

	Node<T>* next;

};

#endif // node.h
