#include "menu.h"

int choiceMenu(int currentMenu) {
	int functionKey;
	int position = 1;

	void (*fcnPtrShowCurrentMenu)(int);
	int lastMenuItem;
	if (currentMenu == 1) {
		fcnPtrShowCurrentMenu = showMainMenu;
		lastMenuItem = 9;
	}
	else if (currentMenu == 2) {
		fcnPtrShowCurrentMenu = showFileMenu;
		lastMenuItem = 2;
	}
	else if (currentMenu == 3) {
		fcnPtrShowCurrentMenu = showFieldMenu;
		lastMenuItem = 10;
	}
	else if (currentMenu == 4) {
		fcnPtrShowCurrentMenu = showOderMenu;
		lastMenuItem = 3;
	}
	else {
		exit(0);
	}

	
	do {
		(*fcnPtrShowCurrentMenu)(position);
	
		functionKey = _getch();
		if (functionKey == 224) {
			functionKey = _getch();
			if (functionKey == 72) { // вверх
				if (position != 1) {
					position--;
				}
			}
			else if (functionKey == 80) { // Вниз
				if (position != lastMenuItem) {
					position++;
				}
			}
		}
		if (functionKey == 13) { //enter
			system("cls");
			return position;
		}
		if (functionKey == 27) { //esc
			system("cls");
			return lastMenuItem;
		}
		
		system("cls");
	} while (true);
}

void mainMenu(doubly_linked_list* database) {
	const int mainMenu = 1;
	const int fileMenu = 2;

	while (true) {
		switch (choiceMenu(mainMenu))
		{
		case 1: // загрузить из файла
			if (!isEmptyList(database)) {
				switch (choiceMenu(fileMenu)) {
				case 1:
					clearList(database);
					initialize(database);
					break;
				}
			}
			load_DB(database);
			break;
		case 2: // вывести таблицу
			table(database);
			break;
		case 3: // добавить вручную
			add_end(database);
			break;
		case 4: // выгрузить в файл
			if (isEmptyList(database)) {
				cout << "Список пуст." << endl;
				_getch();
				system("cls");
				break;
			}
			upload_file(database);
			break;
		case 5: // очистить список
			if (isEmptyList(database)) {
				cout << "Список пуст." << endl;
				_getch();
				system("cls");
				break;
			}
			clearList(database);
			initialize(database);
			cout << "Список был очищен." << endl;
			_getch();
			system("cls");
			break;
		case 6: // сортировка
			if (isEmptyList(database) || numElements(database) == 1) {
				cout << "Недостаточно элементов для сортировки." << endl;
				_getch();
				system("cls");
				break;
			}
			sortMenu(database);
			break;
		case 7: // поиск
			if (isEmptyList(database) || numElements(database) == 1) {
				cout << "Недостаточно элементов для поиска." << endl;
				_getch();
				system("cls");
				break;
			}
			searchMenu(database);
			break;
		case 8: // фильтрация
			if (isEmptyList(database) || numElements(database) == 1) {
				cout << "Недостаточно элементов для фильтрации." << endl;
				_getch();
				system("cls");
				break;
			}
			filtrationMenu(database);
			break;
		case 9:
			return;
		}
	}
}

void sortMenu(doubly_linked_list* database) {
	const int fieldMenu = 3;
	const int oderMenu = 4;

	while(true) {
		switch (choiceMenu(oderMenu))
		{
		case 1:
			switch (choiceMenu(fieldMenu))
			{
			case 1:
				Ascending(database, 1);
				break;
			case 2:
				Ascending(database, 2);
				break;
			case 3:
				Ascending(database, 3);
				break;
			case 4:
				Ascending(database, 4);
				break;
			case 5:
				Ascending(database, 5);
				break;
			case 6:
				Ascending(database, 6);
				break;
			case 7:
				Ascending(database, 7);
				break;
			case 8:
				Ascending(database, 8);
				break;
			case 9:
				Ascending(database, 9);
				break;
			case 10:
				break;
			}
			break;
		case 2:
			switch (choiceMenu(fieldMenu))
			{
			case 1:
				Descending(database, 1);
				break;
			case 2:
				Descending(database, 2);
				break;
			case 3:
				Descending(database, 3);
				break;
			case 4:
				Descending(database, 4);
				break;
			case 5:
				Descending(database, 5);
				break;
			case 6:
				Descending(database, 6);
				break;
			case 7:
				Descending(database, 7);
				break;
			case 8:
				Descending(database, 8);
				break;
			case 9:
				Descending(database, 9);
				break;
			case 10:
				break;
			}
			break;
		case 3:
			return;
		}
	}
}
void searchMenu(doubly_linked_list* database) {
	const int fieldMenu = 3;

	while (true) {
		switch (choiceMenu(fieldMenu))
		{
		case 1: // фио
			search(database, 1);
			break;
		case 2: // фамилия
			search(database, 2);
			break;
		case 3: // имя
			search(database, 3);
			break;
		case 4: // отчество
			search(database, 4);
			break;
		case 5: // телефон
			search(database, 5);
			break;
		case 6: // город
			search(database, 6);
			break;
		case 7: // улица
			search(database, 7);
			break;
		case 8: // дом
			search(database, 8);
			break;
		case 9: // квартира
			search(database, 9);
			break;
		case 10: // главное меню
			return;
		}
	}
}
void filtrationMenu(doubly_linked_list* database) {
	const int fieldMenu = 3;

	while (true) {
		switch (choiceMenu(fieldMenu))
		{
		case 1: // фио
			filtrFIO(database);
			break;
		case 2: // фамилия
			filtrSecondName(database);
			break;
		case 3: // имя
			filtrFirstName(database);
			break;
		case 4: // отчество
			filtrMiddleName(database);
			break;
		case 5: // телефон
			filtrPhone(database);
			break;
		case 6: // город
			filtrCity(database);
			break;
		case 7: // улица
			filtrStreet(database);
			break;
		case 8: // дом
			filtrHouse(database);
			break;
		case 9: // квартира
			filtrFlat(database);
			break;
		case 10: // главное меню
			return;
		}
	}
}

void showMainMenu(int currentPosition) {
	int i = 1;
	cout << "МЕНЮ:" << endl;

	if (currentPosition == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ЗАГРУЗИТЬ ДАННЫЕ ИЗ ФАЙЛА" << endl;

	if (currentPosition == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "РАБОТА С ТАБЛИЦЕЙ" << endl;

	if (currentPosition == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ДОБАВИТЬ ВРУЧНУЮ" << endl;

	if (currentPosition == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ВЫГРУЗИТЬ ДАННЫЕ В ФАЙЛ" << endl;

	if (currentPosition == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ОЧИСТКА СПИСКА" << endl;

	if (currentPosition == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "СОРТИРОВКА" << endl;

	if (currentPosition == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ПОИСК" << endl;

	if (currentPosition == 8) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ФИЛЬТРАЦИЯ" << endl;

	if (currentPosition == 9) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ВЫХОД" << endl;
}
void showFileMenu(int currentPosition) {
	int i = 1;
	cout << "На данный момент вы уже работаете с некой базой данных." << endl;
	cout << "Желанете очистить базу перед загрузкой новых данных? (1 - да / 0 - нет)" << endl;

	if (currentPosition == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ДА" << endl;

	if (currentPosition == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "НЕТ" << endl;
}
void showFieldMenu(int currentPosition) {
	int i = 1;
	cout << "ВЫБЕРИТЕ ПОЛЕ:" << endl;

	if (currentPosition == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ФИО" << endl;

	if (currentPosition == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ФАМИЛИЯ" << endl;

	if (currentPosition == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ИМЯ" << endl;

	if (currentPosition == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ОТЧЕСТВО" << endl;

	if (currentPosition == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "НОМЕР ТЕЛЕФОНА" << endl;

	if (currentPosition == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ГОРОД" << endl;

	if (currentPosition == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "УЛИЦА" << endl;

	if (currentPosition == 8) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ДОМ" << endl;

	if (currentPosition == 9) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "КВАРТИРА" << endl;

	if (currentPosition == 10) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "НАЗАД" << endl;
}
void showOderMenu(int currentPosition) {
	int i = 1;
	cout << "ВЫБЕРИТЕ МОНОТОННОСТЬ СОРТИРОВКИ:" << endl;

	if (currentPosition == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ПО ВОЗРАСТАНИЮ" << endl;

	if (currentPosition == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ПО УБЫВАНИЮ" << endl;

	if (currentPosition == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "НАЗАД" << endl;
}