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

	fillFIO(str);
	strcpy_s(Item->FIO, str);

	fillPhone(str);
	strcpy_s(Item->phone, str);

	fillCity(str);
	strcpy_s(Item->city, str);

	fillStreet(str);
	strcpy_s(Item->street, str);

	fillHouse(str);
	Item->house = atoi(str);

	fillFlat(str);
	Item->flat = atoi(str);
}

void fillFIO(char(&str)[100]) {
	do {
		cout << "¬ведите ‘»ќ" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_FIO(str) == false);
}

void fillPartFIO(char(&str)[100])
{
	do {
		cout << "¬ведите часть ‘»ќ" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (checkPartFIO(str) == false);
}

void fillPhone(char(&str)[100])
{
	do {
		cout << "¬ведите номер телефона" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_phone(str) == false);
}

void fillCity(char(&str)[100])
{
	do {
		cout << "¬ведите название города" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_city(str) == false);
}

void fillStreet(char(&str)[100])
{
	do {
		cout << "¬ведите название улицы" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_street(str) == false);
}

void fillHouse(char(&str)[100])
{
	do {
		cout << "¬ведите номер дома" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_house(str) == false);
}

void fillFlat(char(&str)[100])
{
	do {
		cout << "¬ведите номер квартиры" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_flat(str) == false);
}
