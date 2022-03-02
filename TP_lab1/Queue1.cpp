#include "Queue1.h"
using namespace std;

void Queue1::push_UI() {
	system("cls");
	cout << "Введите значение для добавления в очередь: ";
	int num;
	cin >> num, push(num);
	cout << "В очередь добавлено значение: " << back() << endl;
	cout << "Размер очереди: " << size() << endl;
	print_UI();
	system("pause");
}

void Queue1::pop_UI() {
	system("cls");
	if (isEmpty()) {
		cout << "Очередь пуста!" << endl;
		system("pause");
		return;
	}
	cout << "Из очереди извлечено значение: " << pop() << endl;
	cout << "Размер очереди: " << size() << endl;
	print_UI();
	system("pause");
}

void Queue1::print_UI() const {
	if (isEmpty()) {
		cout << "Очередь пуста!" << endl;
		system("pause");
		return;
	}
	cout << "Вывод очереди: " << this << endl;
}

void Queue1::task() {
	system("cls");

}

void Queue1::copy_UI() {
	system("cls");
	Queue1 temp;
	temp.fillQueue();
	temp.clear();
	cout << "Очередь скопирована" << endl;
	system("pause");
}

void Queue1::merge_UI() {
	//system("cls");
	//string in;
	//while (in.empty()) {
	//	system("cls");
	//	cout << "Выберите как провести слияние:\n";
	//	cout << " 1 – новая очеред + текущая очередь\n";
	//	cout << " 2 – текущая очередь + новая очередь\n";
	//	cout << "\n > ";

	//	cin >> in;
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
	cout << "Очередь очищена" << endl;
	system("pause");
}

Queue1& Queue1::fillQueue() {
	system("cls");
	cout << "Вводите значения, чтобы создать новую очередь\n" <<
		"Для завершения ввода, нажмите Ctrl + Z, затем Enter" << endl;
	Queue1 temp;
	string str;
	while (str[0] != '^') {
		cin >> str;
		temp.push(atoi(str.c_str()));
		str.clear();
	}
	cout << "Размер очереди: " << size() << endl;
	print_UI();
	return temp;
}