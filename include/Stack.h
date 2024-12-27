#include <iostream>
#include <vector>

template <class T>
class Stack {

private:
	std::vector<T> data;

public:

	void push(const T val) {
		data.push_back(val);

	}

	void pop() {
		if (empty()) throw "Stack is empty";
		data.pop_back();

	}

	T top() {
		if (empty()) throw "Stack is empty";
		return data.back();
	}

	size_t get_size() {
		return data.size();
	}

	bool empty() {
		return (data.empty());
	}

};



