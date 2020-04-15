///главный файл

//подключение заголовков
#include "Header.h"
#include "Input.h"
#include "Output.h"
#include "File.h"
#include "Search.h"
#include "Sort.h"


void showMenu() {
	cout << "Меню:" << endl;
	cout << "1. Загрузить данные из файла." << endl;
	cout << "2. Вывод таблицы" << endl;
	cout << "3. Добавить вручную." << endl;
	cout << "5. вывод списка" << endl;
	cout << "6. Выгрузить данные в файл." << endl;
	cout << "7. Очистка списка." << endl;
	cout << "0. Выход" << endl;
}

int main()
{
	// подключение русской раскладки
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// установка размеров консоли
	system("mode con cols=131 lines=70");
	
	// создание и инициализация списка
	doubly_linked_list* database = (doubly_linked_list*)malloc(0);
	initialize(database);
	
	// главное меню
	char choice;
	char* file = (char*)malloc(sizeof(char) * 50);
	while (true) {
		showMenu();
		choice = _getch();
		system("cls");

		if (choice == '1') { // загрузить из файла
			cout << "Введите название файла(с указанием формата): ";
			cin.getline(file,50);
			system("cls");
			load_DB(database, file);
			cout << "Данные успешно загруженны." << endl;
			_getch();
			system("cls");
		}
		
		if (choice == '2') { // вывести таблицу
			if (!isEmptyList(database)) {
				display_table(database);
			}
			else {
				cout << "Список пуст.";
			}
			_getch();
			system("cls");
		}
		
		if (choice == '3') { // добавить вручную
			add_information(database);
		}
		
		if (choice == '5') { // вывести список
			if (!isEmptyList(database)) {
				display_list(database);
			}
			else {
				cout << "Список пуст.";
			}
			_getch();
			system("cls");
		}
		
		if (choice == '6') { // выгрузить в файл
			cout << "Введите название файла(с указанием формата): ";
			cin.getline(file, 50);
			system("cls");
			upload_file(database, file);
			cout << "Файл был выгружен." << endl;
			_getch();
			system("cls");
		}
		
		if (choice == '7') { // очистить список
			clearList(database);
			initialize(database);
			cout << "Список был очищен." << endl;
			_getch();
			system("cls");
		}
		
		if (choice == '0') { // выход c освобождением памяти
			clearList(database);
			free(file);
			cout << "Вы вышли из программы" << endl;
			exit(0);
		}
	}
}