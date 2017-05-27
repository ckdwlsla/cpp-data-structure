#ifndef  STACK_H
#define STACK_H

#include <iostream>

template<typename T>
struct node {
	struct node *next;
	T val;
};

template<typename T>
class Stack {
private:
	struct node<T> *head;
	int length;

public:
	Stack();
	int size();
	bool empty();
	T top();
	void push(T x);
	void pop();
	void print();
	

};

#endif // ! STACK_H

template<typename T>
inline Stack<T>::Stack()
{
	head = nullptr;
	length = 0;
}

template<typename T>
inline Stack<T>::~Stack()
{
	for (struct node<T> ptr = head; head; head = head->next) {
		delete ptr;
	}
}

template<typename T>
inline int Stack<T>::size()
{
	return length;
}

template<typename T>
inline void Stack<T>::push(T x)
{
	struct node<T> *new_node = new node<T>;
	new_node->val = x;
	new_node->next = head;
	head = new_node;
	length += 1;
}

template<typename T>
inline void Stack<T>::pop()
{
	if (empty())
		return;
	struct node<T> *temp = head->next;
	delete head;
	head = temp;
	length -= 1;
}

template<typename T>
inline void Stack<T>::print()
{
	struct node<T> *it = head;
	int count = 0;
	while (it) {
		std::cout << count << ":" << it->val << std::endl;
		it = it->next;
		++count;
	}
}

template<typename T>
inline T Stack<T>::top()
{
	if (!empty())
		return head->val;
	else
		return -1;

}

template<typename T>
inline bool Stack<T>::empty()
{
	return length == 0;
}

