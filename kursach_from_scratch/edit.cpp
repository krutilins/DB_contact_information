#include "edit.h"

void edit(Contact* item)
{
	char str[100];
	// ввод информации
	do {
		cout << "Введите ФИО" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_FIO(str) == false);
	strcpy_s(item->FIO, str);

	do {
		cout << "Введите номер телефона" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_phone(str) == false);
	strcpy_s(item->phone, str);

	do {
		cout << "Введите название города" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_city(str) == false);
	strcpy_s(item->city, str);

	do {
		cout << "Введите название улицы" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_street(str) == false);
	strcpy_s(item->street, str);

	do {
		cout << "Введите номер дома" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_house(str) == false);
	item->house = atoi(str);

	do {
		cout << "Введите номер квартиры" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_flat(str) == false);
	item->flat = atoi(str);
}
