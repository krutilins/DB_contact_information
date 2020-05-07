#include "Input.h"

void add_start(doubly_linked_list* L)
{
	Contact new_info;
	fillItem(&new_info);
	beginPtr(L);
	postPut(L, &new_info);
}

void add_end(doubly_linked_list* L)
{
	Contact new_info;
	fillItem(&new_info);
	endPtr(L);
	prevPut(L, &new_info);
}

void add_prev(doubly_linked_list* L) {
	Contact new_info;
	fillItem(&new_info);
	prevPut(L, &new_info);
}

void add_next(doubly_linked_list* L) {
	Contact new_info;
	fillItem(&new_info);
	postPut(L, &new_info);
}

void fillItem(Contact* Item) {
	char str[100];
	// ввод информации
	cin.getline(Item->FIO, 40);

	do {
		cout << "Введите ФИО" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_FIO(str) == false);
	strcpy_s(Item->FIO, str);

	do {
		cout << "Введите номер телефона" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_phone(str) == false);
	strcpy_s(Item->phone, str);

	do {
		cout << "Введите название города" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_city(str) == false);
	strcpy_s(Item->city, str);

	do {
		cout << "Введите название улицы" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_street(str) == false);
	strcpy_s(Item->street, str);

	do {
		cout << "Введите номер дома" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_house(str) == false);
	Item->house = atoi(str);

	do {
		cout << "Введите номер квартиры" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_flat(str) == false);
	Item->flat = atoi(str);
}