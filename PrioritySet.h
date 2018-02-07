#ifndef PRIORITYSET_H
#define PRIORITYSET_H

#include <set>
#include <vector>
#include <iostream>

template <class T>
class PrioritySet {
public:
	PrioritySet();
	PrioritySet(const std::vector<T> &items);
	void enque(T value);
	T deque();
	int size();
	void print();
	T peek();
private:
	std::vector<T> _v;
	std::set<T> _s;
	int _length;
	void _heapify();
	void _shift_left(int index);
	void _shift_right(int index);
};

template <class T>
PrioritySet<T>::PrioritySet() {
	_length = 0;
}

template <class T>
PrioritySet<T>::PrioritySet(const std::vector<T>& items)
{
	if (items.size() > 0){
		_s.insert(items.begin(), items.end());
		for (auto it = _s.begin(); it != _s.end(); ++it) {
			_v.insert(_v.begin(), *it);
			++_length;
		}
		_heapify();
	}
}

template<class T>
inline void PrioritySet<T>::enque(T value)
{
	_s.insert(value);
	if (_s.size() != size()) {
		_v.push_back(value);
		_shift_left(_length);
		++_length;
	}
}

template<class T>
inline T PrioritySet<T>::deque()
{
	T temp = _v[0];
	_v[0] = _v[_length - 1]; 
	_v.pop_back();
	_length--;
	_shift_right(0);	
	return temp;
}

template<class T>
inline int PrioritySet<T>::size()
{
	return _v.size();
}

template<class T>
inline void PrioritySet<T>::print()
{
	for (int i = 0; i < _length; ++i) {
		std::cout << ' ' << _v[i];
	}
	std::cout << std::endl;
}

template<class T>
inline T PrioritySet<T>::peek()
{
	return v[0];
}

template<class T>
inline void PrioritySet<T>::_heapify()
{
	for (int i = size() - 1; i >= 0; --i) {
		_shift_left(i);
	}
}

template<class T>
inline void PrioritySet<T>::_shift_left(int index)
{
	while (index != 0) 
	{
		int parent_index = (index - (2 - (index % 2))) / 2;
		if (_v[parent_index] < _v[index])
		{
			T temp = _v[index];
			_v[index] = _v[parent_index];
			_v[parent_index] = temp;
		}
		else {
			break;
		}
	}
}

template<class T>
inline void PrioritySet<T>::_shift_right(int index)
{
	int left_index = 2 * index + 1;
	int right_index = 2 * index + 2;
	int largest_index = index;

	if (left_index >= size()){
		return;
	}
	if (_v[left_index] > _v[index]) {
		largest_index = left_index;
	}
	if ((right_index < size()) ) {
		if (_v[right_index] > _v[largest_index]) {
			largest_index = right_index;
		}
	}
	if (largest_index != index) {
		T temp = _v[index];
		_v[index] = _v[largest_index];
		_v[largest_index] = temp;
		_shift_right(largest_index);
	}
}

#endif
