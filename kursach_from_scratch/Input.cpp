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
	cout << "������� ���" << endl;
	do {
		cin.getline(str, 100);
	} while (check_FIO(str) == false);
	system("cls");
}

void fillPartFIO(char(&str)[100])
{
	cout << "������� ����� ���" << endl;
	do {
		cin.getline(str, 100);
	} while (checkPartFIO(str) == false);
	system("cls");
}

void fillPhone(char(&str)[100])
{
	cout << "������� ����� ��������" << endl;
	do {
		cin.getline(str, 100);
	} while (check_phone(str) == false);
	system("cls");
}

void fillCity(char(&str)[100])
{
	cout << "������� �������� ������" << endl;
	do {
		cin.getline(str, 100);
	} while (check_city(str) == false);
	system("cls");
}

void fillStreet(char(&str)[100])
{
	cout << "������� �������� �����" << endl;
	do {
		cin.getline(str, 100);
	} while (check_street(str) == false);
	system("cls");
}

void fillHouse(char(&str)[100])
{
	cout << "������� ����� ����" << endl;
	do {
		cin.getline(str, 100);
	} while (check_house(str) == false);
	system("cls");
}

void fillFlat(char(&str)[100])
{
	cout << "������� ����� ��������" << endl;
	do {
		cin.getline(str, 100);
	} while (check_flat(str) == false);
	system("cls");
}

int getInt()
{
	while (true)
	{
		cout << "������� ������������� ��������: ";
		int a;
		cin >> a;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������ �� ����� ���-�� �� ��. ���������� �����." << endl;
		}
		else
		{
			cin.ignore(32767, '\n'); // ������� ������ ��������

			return a;
		}
	}
}

char getLetter()
{
	while (true)
	{
		cout << "������� ������ (� - �, � - �, a - z, A - Z): ";
		char symbol;
		cin >> symbol;

		cin.ignore(32767, '\n');

		if ((symbol >= '�' && symbol <= '�') || (symbol >= '�' && symbol <= '�')
			|| symbol == '�' || symbol == '�'
			|| (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z'))
			return symbol;
		else
			cout << "������ �� ����� ���-�� �� ��. ���������� �����." << endl;
	}
}

char getNumeral()
{
	while (true)
	{
		cout << "������� ������ (0 - 9): ";
		char symbol;
		cin >> symbol;

		cin.ignore(32767, '\n');

		if (symbol >= '0' && symbol <= '9')
			return symbol;
		else
			cout << "������ �� ����� ���-�� �� ��. ���������� �����." << endl;
	}
}