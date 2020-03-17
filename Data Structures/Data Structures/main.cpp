#include "MaxHeap.h"
#include "DynamicArray.h"
#include <iostream>

using namespace std;

int main() {
	MaxHeap<int> m;
	m.insert(1);
	m.insert(4);
	m.insert(2);
	m.insert(3);
	m.insert(9);
	m.insert(8);
	m.insert(-1);
	m.insert(11);

	m.print();
	int a;
	m.pop(a);
	m.print();
	m.pop(a);
	m.print();
	m.pop(a);
	m.print();
	m.pop(a);
	m.print();
	m.pop(a);
	m.print();
	m.pop(a);
	m.print();
	m.pop(a);
	m.print();
}