#ifndef QUEUE
#define QUEUE

#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

template<typename data>
class Queue {
public:
	Queue() {
		head = nullptr;
		m_size = 0;
	}
	bool push(data value) {
		if (head == nullptr) {
			head = new DataContainer(value);
		}
		DataContainer* node = head;
		while (node->next != nullptr) { node = node->next; }
		node->next = new DataContainer(value);
		m_size++;
		return true;
	}
	data front() {
		return head->value;
	}
	data pop() {
		data returnData = head->value;
		DataContainer* temp = head;
		head = head->next;
		temp->next = nullptr;
		delete temp;
		m_size--;
		return returnData;
	}
	int size() { return m_size; }
	~Queue() {
		if (head != nullptr) {
			delete head;
		}
	}
private:
	struct DataContainer {
		DataContainer(data val) {
			next = nullptr;
			value = val;
		}
		~DataContainer() {
			if (next != nullptr) {
				delete next;
			}
		}
		DataContainer* next;
		data value;
	};

	int m_size;
	DataContainer* head;
};


#endif
