#include <string>
#include <locale>

#include "Queue1.h"
//#include "Queue2.h"
//#include "Queue3.h"

using namespace std;

int main() {
	setlocale(LC_ALL,"Ru");
	string in;
	int active;

	while (in.empty()) {
		system("cls");
		cout << "¬ыберите очередь с нужным модификатором\n";
		cout << " 1 Ц private\n";
		cout << " 2 Ц protected\n";
		cout << " 3 Ц public\n";
		cout << "\n > ";

		getline(cin, in);
		if (in[0] >= 49 && in[0] <= 51) active = in[0] - 48;
		else {
			cout << "\n „то-то не то . . .\n ѕопробуйте еще раз\n ";
			system("pause");
			in.clear();
		}
	}
	in.clear();

	Queue1 queue1; // private
	//Queue2 queue2; // protected
	//Queue3 queue3; // public

	while (true) {
		while (in.empty()) {
			system("cls");
			cout << " 1 Ц ƒобавление элемента очереди\n";
			cout << " 2 Ц »звлечение элемента очереди\n";
			cout << " 3 Ц ¬ывод очереди на экран\n";
			cout << " 4 Ц ¬ыполнение расчета по варианту\n";
			cout << " 5 Ц —оздание копии очереди\n";
			cout << " 6 Ц —ли€ние двух очередей\n";
			cout << " 7 - ќчистить очередь\n";
			cout << " 8 Ц ¬ыход из программы\n";
			cout << "\n > ";

			getline(cin, in);
			switch (in[0]) {
			case '1':
				queue1.push_UI();
				break;
			case '2':
				queue1.pop_UI();
				break;
			case '3': 
				queue1.print_UI();
				break;
			case '4':
				queue1.task();
				break;
			case '5':
				queue1.copy_UI();
				break;
			case '6':
				queue1.merge_UI();
				break;
			case '7':
				queue1.clear_UI();
				break;
			case '8':
				system("cls");
				return 0;
				break;
			default:
				cout << " „то-то не то . . .\n ѕопробуйте еще раз\n ";
				system("pause");
				system("cls");
				in.clear();
				break;
			}
		}
		in.clear();
	}
}

