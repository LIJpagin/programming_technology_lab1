#include "Queue1.h"
using namespace std;

void Queue1::push_UI() {
	system("cls");
	cout << "������� �������� ��� ���������� � �������: ";
	int num;
	cin >> num, push(num);
	cout << "� ������� ��������� ��������: " << back() << endl;
	cout << "������ �������: " << size() << endl;
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
	cout << "�� ������� ��������� ��������: " << pop() << endl;
	cout << "������ �������: " << size() << endl;
	print_UI();
	system("pause");
}

void Queue1::print_UI() const {
	if (isEmpty()) {
		cout << "������� �����!" << endl;
		system("pause");
		return;
	}
	cout << "����� �������: " << this << endl;
}

void Queue1::task() {
	system("cls");

}

void Queue1::copy_UI() {
	system("cls");
	Queue1 temp;
	temp.fillQueue();
	temp.clear();
	cout << "������� �����������" << endl;
	system("pause");
}

void Queue1::merge_UI() {
	//system("cls");
	//string in;
	//while (in.empty()) {
	//	system("cls");
	//	cout << "�������� ��� �������� �������:\n";
	//	cout << " 1 � ����� ������ + ������� �������\n";
	//	cout << " 2 � ������� ������� + ����� �������\n";
	//	cout << "\n > ";

	//	cin >> in;
	//	if (in[0] == '1') merge(fillQueue(), this);
	//	else if (in[0] == '2') merge(queue1, queue2);
	//	else {
	//		cout << "\n ���-�� �� �� . . .\n ���������� ��� ���\n ";
	//		system("pause");
	//		in.clear();
	//	}
	//}
	//merge(queue1, queue2);
	//cout << "������� �������� " << endl;
	//system("pause");
}

void Queue1::clear_UI() {
	system("cls");
	clear();
	cout << "������� �������" << endl;
	system("pause");
}

Queue1& Queue1::fillQueue() {
	system("cls");
	cout << "������� ��������, ����� ������� ����� �������\n" <<
		"��� ���������� �����, ������� Ctrl + Z, ����� Enter" << endl;
	Queue1 temp;
	string str;
	while (str[0] != '^') {
		cin >> str;
		temp.push(atoi(str.c_str()));
		str.clear();
	}
	cout << "������ �������: " << size() << endl;
	print_UI();
	return temp;
}