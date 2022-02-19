#include "Queue.h"
using namespace std;

int main() {
	Queue queue;

	for (auto i = 1; i < 6; i++) {
		queue.push(i);
		cout << "value = " << queue.back() << " size = " << queue.size() << endl;
	}
	cout << "==================" << endl;
	for (auto i = 1; i < 6; i++) {
		cout << "value = " << queue.back() << " size = " << queue.size() << endl;
		queue.pop();
	}

	return 0;
}