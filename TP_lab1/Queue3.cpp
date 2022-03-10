#include "Queue3.h"
using namespace std;

void Queue3::copy() {
	system("cls");
	this->print();
	this->clear();
	Queue queue;
	queue.random(20);
	cout << "������� ����� �������: " << queue << endl;
	Item* temp = queue.front();
	do this->push(temp->data), temp = temp->next;
	while (temp != NULL);
	cout << "������� �����������!" << endl;
	this->print();
	system("pause");
}

void Queue3::merge() {
	system("cls");
	this->print();
	Queue queue;
	queue.random(20);
	cout << "������� ����� �������: " << queue << endl;
	Item* temp = queue.front();
	do this->push(temp->data), temp = temp->next;
	while (temp != NULL);
	cout << "������� �������� �����������!" << endl;
	this->print();
	system("pause");
}

void Queue3::print() const {
	cout << "����� �������: ";
	if (isEmpty()) {
		cout << "������� �����!" << endl;
		return;
	}
	int* array = getArray();
	int size = this->size();
	for (auto i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}