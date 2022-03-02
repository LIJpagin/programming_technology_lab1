#include "Queue1.h"
using namespace std;

void Queue1::push_UI() {
	system("cls");
	print_UI();
	cout << "������� �������� ��� ���������� � �������: ";
	int num;
	cin >> num, push(num);
	cout << "� ������� ��������� ��������: " << back()->data << endl;
	print_UI();
	system("pause");
}

void Queue1::pop_UI() {
	system("cls");
	if (isEmpty()) {
		cout << "������� �����!" << endl;
		system("pause");
		return;
	}
	print_UI();
	cout << "�� ������� ��������� ��������: " << pop() << endl;
	print_UI();
	system("pause");
}

void Queue1::print_UI() const {
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

void Queue1::task() {
	system("cls");

	system("pause");
}

void Queue1::copy_UI() {
	system("cls");
	this->print_UI();
	this->clear();
	Queue queue;
	queue.random(20);
	cout << "������� ����� �������: " << queue << endl;
	Item* temp = queue.front();
	do this->push(temp->data), temp = temp->next;
	while (temp != NULL);
	cout << "������� �����������!" << endl;
	this->print_UI();
	system("pause");
}

void Queue1::merge_UI() {
	system("cls");
	this->print_UI();
	Queue queue;
	queue.random(20);
	cout << "������� ����� �������: " << queue << endl;
	Item* temp = queue.front();
	do this->push(temp->data), temp = temp->next;
	while (temp != NULL);
	cout << "������� �������� �����������!" << endl;
	this->print_UI();
	system("pause");
}

void Queue1::clear_UI() {
	system("cls");
	clear();
	cout << "������� �������!" << endl;
	system("pause");
}