#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
class priority_queue {
public:
	priority_queue() {}
	virtual ~priority_queue() {}

	void push(T t) {
		data.push_back(t);
		push_heap(data.begin(), data.end());
	}
	void pop() {
		pop_heap(data.begin(), data.end());
		data.pop_back();
	}

	T top() { return data.front(); }
	int size() { return data.size(); }

private:
	vector<T> data;
};