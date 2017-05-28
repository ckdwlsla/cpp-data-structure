#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>


template<typename T>
struct queue_node {
	T value;
	struct queue_node<T> *next;
};

template<typename T>
class Queue {
private:
	struct queue_node<T> *head;
	struct queue_node<T> *tail;
	int length;
public:
	Queue();
	~Queue();
	bool empty();
	int size();
	T front();
	T back();
	void push(T x);
	void pop();
	void print();
};



#endif // !QUEUE_H

template<typename T>
inline Queue<T>::Queue()
{
	length = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
inline Queue<T>::~Queue()
{
	struct node<T> *ptr;
	while (head) {
		ptr = head->next;
		delete head;
		head = ptr;
	}
	delete ptr;
}

template<typename T>
inline bool Queue<T>::empty()
{
	return length == 0;
}

template<typename T>
inline int Queue<T>::size()
{
	return length;
}

template<typename T>
inline T Queue<T>::front()
{
	return head->value;
}

template<typename T>
inline T Queue<T>::back()
{
	return tail->value;
}

template<typename T>
inline void Queue<T>::push(T x)
{
	struct queue_node<T> *new_node = new queue_node<T>;
	new_node->value = x;
	new_node->next = nullptr;
	if (size() == 0) {
		head = new_node;
		tail = new_node;
	}
	else {
		tail->next = new_node;
		tail = new_node;
	}
	length += 1;
}

template<typename T>
inline void Queue<T>::pop()
{
	if (empty())
		return;
	struct queue_node<T> *temp = head->next;
	delete head;
	head = temp;

	--length;

}

template<typename T>
inline void Queue<T>::print()
{
	int count = 0;
	struct queue_node<T> *ptr = head;
	while (ptr) {
		cout << count  << ":" << ptr->value << endl;
		ptr = ptr->next;
		++count;
	}
	std::cout << "_____________" << std::endl;
	

}
