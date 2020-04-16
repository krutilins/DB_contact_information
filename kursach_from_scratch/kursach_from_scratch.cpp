///главный файл

//подключение заголовков
#include "Header.h"
#include "Input.h"
#include "Output.h"
#include "File.h"
#include "workWithTable.h"
#include "Search.h"
#include "Sort.h"

void showMenu(int pos) {
	int i = 1;
	cout << "МЕНЮ:" << endl;
	
	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ЗАГРУЗИТЬ ДАННЫЕ ИЗ ФАЙЛА" << endl;
	
	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ВЫВОД ТАБЛИЦЫ" << endl;
	
	if (pos == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ДОБАВИТЬ ВРУЧНУЮ" << endl;
	
	if (pos == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ВЫГРУЗИТЬ ДАННЫЕ В ФАЙЛ" << endl;
	
	if (pos == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ОЧИСТКА СПИСКА" << endl;
	
	if (pos == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "РАБОТА С ТАБЛИЦЕЙ" << endl;
	
	if (pos == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ВЫХОД" << endl;
}

int menuItem() {
	int functionKey;
	int pos = 1;
	do {
		showMenu(pos);
		functionKey = _getch();
		if (functionKey == 224) {
			functionKey = _getch();
			if (functionKey == 72) { // вверх
				if (pos != 1) {
					showMenu(pos--);
				}
			}
			else if (functionKey == 80) { // Вниз
				if (pos != 7) {
					showMenu(pos++);
				}
			}
		}
		if (functionKey == 13) { //enter
			system("cls");
			return pos;
		}
		if (functionKey == 27) { //esc
			system("cls");
			return 7;
		}
		system("cls");
	} while (true);
}

int main()
{
	// подключение русской раскладки
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// установка размеров консоли
	system("mode con cols=133 lines=35");
	
	// создание и инициализация списка
	doubly_linked_list* database = (doubly_linked_list*)malloc(0);
	initialize(database);
	
	// главное меню
	char choice;
	char* file = (char*)malloc(sizeof(char) * 51);
	while (true) {
		switch (menuItem())
		{
		case 1: // загрузить из файла
			cout << "Введите название файла(с указанием формата): ";
			cin.getline(file, 50);
			system("cls");
			load_DB(database, file);
			cout << "Данные успешно загруженны." << endl;
			_getch();
			system("cls");
			break;
		case 2: // вывести таблицу
			if (!isEmptyList(database)) {
				display_table(database);
			}
			else {
				cout << "Список пуст.";
			}
			_getch();
			system("cls");
			break;
		case 3: // добавить вручную
			add_information(database);
			break;
		case 4: // выгрузить в файл
			cout << "Введите название файла(с указанием формата): ";
			cin.getline(file, 50);
			system("cls");
			upload_file(database, file);
			cout << "Файл был выгружен." << endl;
			_getch();
			system("cls");
			break;
		case 5: // очистить список
			clearList(database);
			initialize(database);
			cout << "Список был очищен." << endl;
			_getch();
			system("cls");
			break;
		case 6: // эксперимент с таблицей
			table(database);
			system("cls");
			break;
		case 7: // выход c освобождением памяти
			clearList(database);
			free(file);
			cout << "Вы вышли из программы" << endl;
			exit(0);
			break;
		default:
			break;
		}
	}
}