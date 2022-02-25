#include "Queue1.h"

void Queue1::push_UI() {
	system("cls");
	std::cout << "Введите значение для добавления в очередь: ";
	std::string str;
	std::cin >> str;
	this->push(atoi(str.c_str()));
	std::cout << "В очередь добавлено значение: " << this->back() << std::endl;
	std::cout << "Размер очереди: " << this->size() << std::endl;
	this->print_UI();
	system("pause");
}

void Queue1::pop_UI() {
	system("cls");
	if (empty()) {
		std::cout << "Очередь пуста!" << std::endl;
		system("pause");
		return;
	}
	std::cout << "Из очереди извлечено значение: " << pop() << std::endl;
	std::cout << "Размер очереди: " << size() << std::endl;
	print_UI();
	system("pause");
}

void Queue1::print_UI() const {
	if (empty()) {
		std::cout << "Очередь пуста!" << std::endl;
		system("pause");
		return;
	}
	int* arr = getArray();
	std::cout << "Вывод очереди: ";
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
	std::cout << "Очередь скопирована" << std::endl;
	system("pause");
}

void Queue1::merge_UI() {
	//system("cls");
	//std::string in;
	//while (in.empty()) {
	//	system("cls");
	//	std::cout << "Выберите как провести слияние:\n";
	//	std::cout << " 1 – новая очеред + текущая очередь\n";
	//	std::cout << " 2 – текущая очередь + новая очередь\n";
	//	std::cout << "\n > ";

	//	std::cin >> in;
	//	if (in[0] == '1') merge(fillQueue(), this);
	//	else if (in[0] == '2') merge(queue1, queue2);
	//	else {
	//		cout << "\n Что-то не то . . .\n Попробуйте еще раз\n ";
	//		system("pause");
	//		in.clear();
	//	}
	//}
	//merge(queue1, queue2);
	//cout << "Слияние очередей " << endl;
	//system("pause");
}

void Queue1::clear_UI() {
	system("cls");
	clear();
	std::cout << "Очередь очищена" << std::endl;
	system("pause");
}

Queue& Queue1::fillQueue() {
	system("cls");
	std::cout << "Вводите значения, чтобы создать новую очередь\n" <<
		"Для завершения ввода, нажмите Ctrl + Z, затем Enter" << std::endl;
	Queue temp;
	std::string str;
	while (str[0] != '^') {
		std::cin >> str;
		temp.push(atoi(str.c_str()));
	}
	std::cout << "Размер очереди: " << size() << std::endl;
	print_UI();
	return temp;
}