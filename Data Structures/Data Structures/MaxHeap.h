#ifndef MAX_HEAP
#define MAX_HEAP

#include "DynamicArray.h"
#include <iostream>

using namespace std;

template<typename data>
class MaxHeap {
public:
	MaxHeap() {}
	bool insert(data value) {
		if (array.size() == 0) { array.push(value); }
		array.push(value);
		int index = array.size() - 1;
		while (index > 1) {
			cout << "Comparing " << array[index] << " at index " << index << " to " << array[index / 2] << " at index " << (index / 2) << endl;
			if (array[index] > array[index / 2]) {
				data temp = array[index];
				array[index] = array[index/ 2];
				array[index / 2] = temp;
			}
			index = index / 2;
		}
		cout << endl;
		return true;
	}
	void pop(data& val) {
		val = array[1];
		data a;
		array[1] = array[-1];
		array.pop_back(a);
		update(1);
	}
	data top() {
		return array[1];
	}
	void print() {
		for (int i = 1; i < array.size(); i++) {
			cout << array[i] << ", ";
		}
		cout << endl;
	}
	~MaxHeap() {}
private:
	DynamicArray<data> array;
	void update(int index) {
		if (2 * index >= array.size() - 1) { 
			if (2 * index == array.size() - 1 && array[index] < array[2 * index]) {
				data temp = array[index];
				array[index] = array[2 * index];
				array[2 * index] = temp;
				return;
			}
			return; 
		
		}
		if (array[index] > array[2 * index] && array[index] > array[2 * index + 1]) { return; }
		if (array[2 * index] > array[2 * index + 1]) {
			data temp = array[index];
			array[index] = array[2 * index];
			array[2 * index] = temp;
			update(2 * index);
			return;
		}
		data temp = array[index];
		array[index] = array[2 * index + 1];
		array[2 * index + 1] = temp;
		update(2 * index + 1);
	}
};


#endif
