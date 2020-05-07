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
		fcnPtrShowCurrentMenu = showFieldMenu;
		lastMenuItem = 8;
	}
	else if (currentMenu == 3) {
		fcnPtrShowCurrentMenu = showOderMenu;
		lastMenuItem = 3;
	}
	else if (currentMenu == 4) {
		fcnPtrShowCurrentMenu = showFieldMenu;
		lastMenuItem = 8;
	}
	else if (currentMenu == 5) {
		fcnPtrShowCurrentMenu = showPartFIOMenu;
		lastMenuItem = 4;
	}
	else if (currentMenu == 6) {
		fcnPtrShowCurrentMenu = showFieldMenu;
		lastMenuItem = 8;
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

	while (true) {
		switch (choiceMenu(mainMenu))
		{
		case 1: // загрузить из файла
			load_DB(database);
			break;
		case 2: // вывести таблицу
			table(database);
			break;
		case 3: // добавить вручную
			add_end(database);
			break;
		case 4: // выгрузить в файл
			upload_file(database);
			break;
		case 5: // очистить список
			clearList(database);
			initialize(database);
			cout << "Список был очищен." << endl;
			_getch();
			system("cls");
			break;
		case 6: // сортировка
			sortMenu(database);
			break;
		case 7: // поиск
			searchMenu(database);
			break;
		case 8: // фильтрация
			filtrationMenu(database);
			break;
		case 9:
			return;
		}
	}
}

void sortMenu(doubly_linked_list* database) {
	const int sortMenu = 2;
	const int oderMenu = 3;
	const int partFIOMenu = 5;

	while (true) {
		switch (choiceMenu(sortMenu))
		{
		case 1: // ФИО
			switch (choiceMenu(oderMenu))
			{
			case 1: // возрастание
				fioAscending(database);
				break;
			case 2: // убывание
				fioDescending(database);
				break;
			case 3:
				break;
			}
			break;
		case 2: // часть фио
			cout << "Сортировка по части ФИО не реализована" << endl;
			system("pause");
			//switch (choiceMenu(partFIOMenu))
			//{
			//case 1: // имя
			//	switch (choiceMenu(oderMenu))
			//	{
			//	case 1: // возрастание
			//		fioAscending(database);
			//		break;
			//	case 2: // убывание
			//		fioDescending(database);
			//		break;
			//	case 3:
			//		break;
			//	}
			//	break;
			//case 2: // имя
			//	switch (choiceMenu(oderMenu))
			//	{
			//	case 1: // возрастание
			//		fioAscending(database);
			//		break;
			//	case 2: // убывание
			//		fioDescending(database);
			//		break;
			//	case 3:
			//		break;
			//	}
			//	break;
			//case 3: // отчество
			//	switch (choiceMenu(oderMenu))
			//	{
			//	case 1: // возрастание
			//		fioAscending(database);
			//		break;
			//	case 2: // убывание
			//		fioDescending(database);
			//		break;
			//	case 3:
			//		break;
			//	}
			//	break;
			//case 4: // меню сортировки
			//	break;
			//}
			break;
		case 3: // номер телефона
			switch (choiceMenu(oderMenu))
			{
			case 1: // возрастание
				phoneAscending(database);
				break;
			case 2: // убывание
				phoneDescending(database);
				break;
			case 3:
				break;
			}
			break;
		case 4: // город
			switch (choiceMenu(oderMenu))
			{
			case 1: // возрастание
				cityAscending(database);
				break;
			case 2: // убывание
				cityDescending(database);
				break;
			case 3:
				break;
			}
			break;
		case 5: // улица
			switch (choiceMenu(oderMenu))
			{
			case 1: // возрастание
				streetAscending(database);
				break;
			case 2: // убывание
				streetDescending(database);
				break;
			case 3:
				break;
			}
			break;
		case 6: // дом
			switch (choiceMenu(oderMenu))
			{
			case 1: // возрастание
				houseAscending(database);
				break;
			case 2: // убывание
				houseDescending(database);
				break;
			case 3:
				break;
			}
			break;
		case 7: // квартира
			switch (choiceMenu(oderMenu))
			{
			case 1: // возрастание
				flatAscending(database);
				break;
			case 2: // убывание
				flatDescending(database);
				break;
			case 3:
				break;
			}
			break;
		case 8: // главное меню
			return;
		}
	}
}
void searchMenu(doubly_linked_list* database) {
	const int searchMenu = 4;
	const int partFIOMenu = 5;

	while (true) {
		switch (choiceMenu(searchMenu))
		{
		case 1: // фио
			searchFIO(database);
			break;
		case 2: // часть фио
			switch (choiceMenu(partFIOMenu))
			{
			case 1: // фамилия
				searchSecondName(database);
				break;
			case 2: // имя
				searchFirstName(database);
				break;
			case 3: // отчество
				searchMiddleName(database);
				break;
			case 4: // меню поиска
				break;
			default:
				break;
			}
			break;
		case 3: // телефон
			searchPhone(database);
			break;
		case 4: // город
			searchCity(database);
			break;
		case 5: // улица
			searchStreet(database);
			break;
		case 6: // дом
			searchHouse(database);
			break;
		case 7: // квартира
			searchFlat(database);
			break;
		case 8: // главное меню
			return;
		}
	}
}
void filtrationMenu(doubly_linked_list* database) {
	const int filtrationMenu = 6;
	const int partFIOMenu = 5;

	while (true) {
		switch (choiceMenu(filtrationMenu))
		{
		case 1: // фио
			filtrFIO(database);
			break;
		case 2: // часть фио
			switch (choiceMenu(partFIOMenu))
			{
			case 1: // фамилия
				filtrSecondName(database);
				break;
			case 2: // имя
				filtrFirstName(database);
				break;
			case 3: // отчество
				filtrMiddleName(database);
				break;
			case 4: // меню поиска
				break;
			default:
				break;
			}
			break;
		case 3: // телефон
			filtrPhone(database);
			break;
		case 4: // город
			filtrCity(database);
			break;
		case 5: // улица
			filtrStreet(database);
			break;
		case 6: // дом
			filtrHouse(database);
			break;
		case 7: // квартира
			filtrFlat(database);
			break;
		case 8: // главное меню
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
void showFieldMenu(int currentPosition) {
	int i = 1;
	cout << "МЕНЮ ФИЛЬТРАЦИИ:" << endl;

	if (currentPosition == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ФИО" << endl;

	if (currentPosition == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ПО ЧАСТИ ФИО" << endl;

	if (currentPosition == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "НОМЕР ТЕЛЕФОНА" << endl;

	if (currentPosition == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ГОРОД" << endl;

	if (currentPosition == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "УЛИЦА" << endl;

	if (currentPosition == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ДОМ" << endl;

	if (currentPosition == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "КВАРТИРА" << endl;

	if (currentPosition == 8) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ВЕРНУТЬСЯ В ГЛАВНОЕ МЕНЮ" << endl;
}
void showPartFIOMenu(int currentPosition) {
	int i = 1;
	cout << "ВЫБЕРИТЕ ЧАСТЬ ФИО:" << endl;

	if (currentPosition == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ФАМИЛИЯ" << endl;

	if (currentPosition == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ИМЯ" << endl;

	if (currentPosition == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ОТЧЕСТВО" << endl;

	if (currentPosition == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "ВЕРНУТЬСЯ В МЕНЮ ПОИСКА" << endl;
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
	cout << "ВЕРНУТЬСЯ В МЕНЮ СОРТИРОВКИ" << endl;
}