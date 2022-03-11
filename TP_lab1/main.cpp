#include <string>
#include <locale>
#include "Queue1.h"
#include "Queue2.h"
#include "Queue3.h"

using namespace std;

int main() {
	setlocale(LC_ALL,"Ru");
	string in;
	int active;

	while (in.empty()) {
		system("cls");
		cout << "�������� ������� � ������ �������������\n";
		cout << " 1 � private\n";
		cout << " 2 � protected\n";
		cout << " 3 � public\n";
		cout << "\n > ";

		cin >> in;
		if (in[0] >= 49 && in[0] <= 51) active = in[0] - 48;
		else {
			cout << "\n ���-�� �� �� . . .\n ���������� ��� ���\n ";
			system("pause");
			in.clear();
		}
	}
	in.clear();

	Queue1 queue1; // private
	Queue2 queue2; // protected
	Queue3 queue3; // public

	while (true) {
		while (in.empty()) {
			system("cls");
			cout << " 1 � ���������� �������� �������\n";
			cout << " 2 � ���������� �������� �������\n";
			cout << " 3 � ����� ������� �� �����\n";
			cout << " 4 � ���������� ������� �� ��������\n";
			cout << " 5 � �������� ����� �������\n";
			cout << " 6 � ������� ���� ��������\n";
			cout << " 7 � ����� �� ���������\n";
			cout << "\n > ";

			cin >> in;
			float sum = 0;
			int counter = 0, num = 0;
			switch (in[0]) {
			case '1':
				system("cls");
				active == 1 ? queue1.print() : (active == 2 ? queue2.print() : queue3.print());
				cout << "������� �������� ��� ���������� � �������: ";
				cin >> num;
				active == 1 ? queue1.push(num) : (active == 2 ? queue2.push(num) : queue3.push(num));
				cout << "� ������� ��������� ��������: " << num << endl;
				active == 1 ? queue1.print() : (active == 2 ? queue2.print() : queue3.print());
				system("pause");
				break;
			case '2':
				system("cls");
				if (active == 1 ? queue1.isEmpty() : (active == 2 ? queue2.isEmpty() : queue3.isEmpty())) {
					cout << "������� �����!" << endl;
					system("pause");
					break;
				}
				active == 1 ? queue1.print() : (active == 2 ? queue2.print() : queue3.print());
				cout << "�� ������� ��������� ��������: " <<
					(active == 1 ? queue1.pop() : (active == 2 ? queue2.pop() : queue3.pop())) << endl;
				active == 1 ? queue1.print() : (active == 2 ? queue2.print() : queue3.print());
				system("pause");
				break;
			case '3': 
				system("cls");
				active == 1 ? queue1.print() : (active == 2 ? queue2.print() : queue3.print());
				system("pause");
				break;
			case '4':
				system("cls");
				if (active == 1 ? queue1.isEmpty() : (active == 2 ? queue2.isEmpty() : queue3.isEmpty())) {
					cout << "������� �����!" << endl;
					system("pause");
					break;
				}
				active == 1 ? queue1.print() : (active == 2 ? queue2.print() : queue3.print());
				cout << "������� �������� ��������������� ��� ��������� � �������� ���������� �������" << endl;
				while (!(active == 1 ? queue1.isEmpty() : (active == 2 ? queue2.isEmpty() : queue3.isEmpty()))) {
					if (counter % 2 == 0)
						sum += active == 1 ? queue1.pop() : (active == 2 ? queue2.pop() : queue3.pop());
					else
						active == 1 ? queue1.pop() : (active == 2 ? queue2.pop() : queue3.pop());
					counter++;
				}
				counter /= 2;
				sum /= counter;
				cout << "���������: " << sum << endl;
				system("pause");
				break;
			case '5':
				active == 1 ? queue1.copy() : (active == 2 ? queue2.copy() : queue3.copy());
				break;
			case '6':
				active == 1 ? queue1.merge() : (active == 2 ? queue2.merge() : queue3.merge());
				break;
			case '7':
				system("cls");
				return 0;
				break;
			default:
				cout << " ���-�� �� �� . . .\n ���������� ��� ���\n ";
				system("pause");
				system("cls");
				in.clear();
				break;
			}
		}
		in.clear();
	}
}