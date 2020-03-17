#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

using namespace std;

template<typename data>
class DynamicArray {
public:
	DynamicArray() {
		head = nullptr;
		m_size = 0;
	}
	bool push(data value) {
		if (head == nullptr) { m_size++; head = new DataContainer(value); return true; }
		get(-1)->next = new DataContainer(value);
		m_size++;
	}
	bool insert(data value, int index) {
		if (head == nullptr) { head = new DataContainer(value); m_size++; return true;  }
		DataContainer* node = get(index);
		get(index-1)->next = new DataContainer(value);
		get(index)->next = node;
		m_size++;
	}
	bool remove(int index) {
		if (head == nullptr) { return false; }
		if (m_size == 1) { delete head; head = nullptr; m_size--; return true; }
		if (mod(index) != 0) {
			DataContainer* temp = get(index);
			get(index - 1)->next = get(index - 1)->next->next;
			delete temp;
			m_size--;
			return true;
		}
		else {
			DataContainer* temp = head;
			head = head->next;
			temp->next = nullptr;
			delete temp;
			m_size--;
			return true;
		}
	}
	bool pop_back(data& t) {
		if (m_size == 0) { return false; }
		data temp = get(-1)->value;
		if (remove(-1)) {
			t = temp;
			return true;
		}
		return false;
	}
	bool pop_front(data& t) {
		if (m_size == 0) { return false; }
		data temp = get(0)->value;
		if (remove(0)) {
			t = temp;
			return true;
		}
		return false;
	}
	bool insertAfter(data value, data key) {
		if (head == nullptr) { head = new DataContainer(value); return true; m_size++; }
		DataContainer* node = head;
		while (node->next != nullptr && node->value != key) { node = node->next; }
		DataContainer* temp = node->next;
		node->next = new DataContainer(value);
		node->next->next = temp;
		m_size++;
	}
	data& operator[](int val) {
		return get(val)->value;
	}
	int size() { return m_size; }
	~DynamicArray() {
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

	DataContainer* get(int index) {
		DataContainer* node = head;
		for (int i = 0; i < mod(index); i++) {
			if (node->next == nullptr) { return nullptr; }
			node = node->next;
		}
		return node;
	}

	unsigned int mod(int i) { while (i < 0) { i += m_size; } i = i % m_size; return i; }

	int m_size;
	DataContainer* head;
};


#endif
