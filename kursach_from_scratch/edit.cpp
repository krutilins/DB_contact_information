#include "edit.h"

void edit(Contact* item)
{
	char str[100];
	// ���� ����������
	do {
		cout << "������� ���" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_FIO(str) == false);
	strcpy_s(item->FIO, str);

	do {
		cout << "������� ����� ��������" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_phone(str) == false);
	strcpy_s(item->phone, str);

	do {
		cout << "������� �������� ������" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_city(str) == false);
	strcpy_s(item->city, str);

	do {
		cout << "������� �������� �����" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_street(str) == false);
	strcpy_s(item->street, str);

	do {
		cout << "������� ����� ����" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_house(str) == false);
	item->house = atoi(str);

	do {
		cout << "������� ����� ��������" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_flat(str) == false);
	item->flat = atoi(str);
}
