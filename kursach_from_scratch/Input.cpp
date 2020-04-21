#include "Input.h"

void add_information(doubly_linked_list* L)
{
	Contact new_info;
	char str[100];
	// ���� ����������
	do {
		cout << "������� ���" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_FIO(str) == false);
	strcpy_s(new_info.FIO, str);

	do {
		cout << "������� ����� ��������" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_phone(str) == false);
	strcpy_s(new_info.phone, str);

	do {
		cout << "������� �������� ������" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_city(str) == false);
	strcpy_s(new_info.city, str);

	do {
		cout << "������� �������� �����" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_street(str) == false);
	strcpy_s(new_info.street, str);

	do {
		cout << "������� ����� ����" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_house(str) == false);
	new_info.house = atoi(str);

	do {
		cout << "������� ����� ��������" << endl;
		cin.getline(str, 100);
		system("cls");
	} while (check_flat(str) == false);
	new_info.flat = atoi(str);

	// ����������� ��������� �� ��������� �����
	endPtr(L);
	// ������� � ����� ������
	prevPut(L, &new_info);
}