#include "Queue1.h"
using namespace std;

void Queue1::push(int value) {
	Queue::push(value);
}

int Queue1::pop() {
	return Queue::pop();
}

void Queue1::print() const {
	cout << "Вывод очереди: ";
	if (isEmpty()) {
		cout << "очередь пуста!" << endl;
		return;
	}
	int* array = getArray();
	int size = this->size();
	for (auto i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

void Queue1::copy() {
	system("cls");
	this->print();
	this->clear();
	Queue queue;
	queue.random(20);
	cout << "Создана новая очередь: " << queue << endl;
	Item* temp = queue.front();
	do this->push(temp->data), temp = temp->next;
	while (temp != NULL);
	cout << "Очередь скопирована!" << endl;
	this->print();
	system("pause");
}

void Queue1::merge() {
	system("cls");
	this->print();
	Queue queue;
	queue.random(20);
	cout << "Создана новая очередь: " << queue << endl;
	Item* temp = queue.front();
	do this->push(temp->data), temp = temp->next;
	while (temp != NULL);
	cout << "Слияние очередей произведено!" << endl;
	this->print();
	system("pause");
}

bool Queue1::isEmpty() const {
	return Queue::isEmpty();
}