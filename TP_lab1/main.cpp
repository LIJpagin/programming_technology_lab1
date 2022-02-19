#include "Queue.h"
using namespace std;

int main() {
	Queue queue1, queue2, queue3;

	for (auto i = 1; i < 6; i++) {
		queue1.push(i);
		cout << "value = " << queue1.back() << " size = " << queue1.size() << endl;
	}
	cout << "==================" << endl;
	queue2.copy(queue1);
	queue3.merge(queue1, queue2);
	for (auto i = 0; i < 10; i++) {
		cout << "value = " << queue3.pop() << " size = ";
		cout << queue3.size() << endl;
	}
		
	return 0;
}