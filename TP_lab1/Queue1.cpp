#include "Queue1.h"

void Queue1::push_UI() {
	system("cls");
	std::cout << "������� �������� ��� ���������� � �������: ";
	std::string str;
	std::cin >> str;
	this->push(atoi(str.c_str()));
	std::cout << "� ������� ��������� ��������: " << this->back() << std::endl;
	std::cout << "������ �������: " << this->size() << std::endl;
	this->print_UI();
	system("pause");
}

void Queue1::pop_UI() {
	system("cls");
	if (empty()) {
		std::cout << "������� �����!" << std::endl;
		system("pause");
		return;
	}
	std::cout << "�� ������� ��������� ��������: " << pop() << std::endl;
	std::cout << "������ �������: " << size() << std::endl;
	print_UI();
	system("pause");
}

void Queue1::print_UI() const {
	if (empty()) {
		std::cout << "������� �����!" << std::endl;
		system("pause");
		return;
	}
	int* arr = getArray();
	std::cout << "����� �������: ";
	for (auto i = 0; i < size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void Queue1::task() {
	system("cls");

}

void Queue1::copy_UI() {
	system("cls");
	Queue1 temp;
	temp.fillQueue();
	copy(temp);
	temp.clear();
	std::cout << "������� �����������" << std::endl;
	system("pause");
}

void Queue1::merge_UI() {
	//system("cls");
	//std::string in;
	//while (in.empty()) {
	//	system("cls");
	//	std::cout << "�������� ��� �������� �������:\n";
	//	std::cout << " 1 � ����� ������ + ������� �������\n";
	//	std::cout << " 2 � ������� ������� + ����� �������\n";
	//	std::cout << "\n > ";

	//	std::cin >> in;
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
	std::cout << "������� �������" << std::endl;
	system("pause");
}

Queue& Queue1::fillQueue() {
	system("cls");
	std::cout << "������� ��������, ����� ������� ����� �������\n" <<
		"��� ���������� �����, ������� Ctrl + Z, ����� Enter" << std::endl;
	Queue temp;
	std::string str;
	while (str[0] != '^') {
		std::cin >> str;
		temp.push(atoi(str.c_str()));
	}
	std::cout << "������ �������: " << size() << std::endl;
	print_UI();
	return temp;
}