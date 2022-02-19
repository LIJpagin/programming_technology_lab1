#include "Queue.h"
using namespace std;

int main() {
	Queue queue1, queue2;

	for (auto i = 1; i < 6; i++) {
		queue1.push(i);
		cout << "value = " << queue1.back() << " size = " << queue1.size() << endl;
	}
	cout << "==================" << endl;
	queue2.copy(queue1);
	for (auto i = 1; i < 6; i++) {
		cout << "value = " << queue2.front() << " size = " << queue2.size() << endl;
		queue2.pop();
	}

	return 0;
}