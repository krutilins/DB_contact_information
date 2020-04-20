#include "Search.h"

/*
	������� ������
		
		� �������� ���������� ������� ����� ��������� ������ ��������� �� ������

		����� ������� ������� ���� �� �������� ����� �������������� �����
			(������������� ����� �������� �����, �� ��������� ���� ������ ������ ��������)

		�������� � ������ ����. ��� ������?

		������ ����� ������� ��������������� �������

		�������� ������ ������ � �������, ������� � ���� �����������: 
		1) ������ ������� ��������
		2) � ������� ����� ��������� ������ ������� ������ ������ � ���� ������� �������, �� �������� � ����� ������
		3) ��� ��� � ������� �������� ��������� �������� � ������� ����� ������, �� ����� ����������� ������� �������� ���������� ��������
		4) ����� ������� ������ � ����������� �� ��������� � ������� ������
		5)


		����
		������� ����
		������ � ��������
		�����
		��������� ����
		�����


*/

void searchFIO(doubly_linked_list* L)
{
	char request[100];
	do {
		cout << "������� ���: " << endl;
		cin.getline(request, 100);
		system("cls");
	} while (s_check_FIO(request) == false);

	int sizeList = numElements(L);

	// �������� � ������������� ������
	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	// �������������� ������� ��� ������� �� ������ �� ����� ������
	Contact* tmp;
	tmp = L->start->next_link; // ������ �� ������ �������

	// ��������� �������
	Contact tempElement;
	// ���� �� ����� ������
	while (tmp != L->end) {
		if (strcmp(request, tmp->FIO) == 0) {
			strcpy_s(tempElement.FIO, tmp->FIO);
			strcpy_s(tempElement.phone, tmp->phone);
			strcpy_s(tempElement.city, tmp->city);
			strcpy_s(tempElement.street, tmp->street);
			tempElement.house = tmp->house;
			tempElement.flat = tmp->flat;
			tempElement.next_link = NULL;
			tempElement.prev_link = NULL;

			// ����������� ��������� �� ��������� �����
			endPtr(tempList);
			// ������� � ����� ������
			prevPut(tempList, &tempElement);
		}
		tmp = tmp->next_link;
	}
	table(tempList);
	clearList(tempList);
}

void searchFirstName(doubly_linked_list* L)
{

}

void searchSecondName(doubly_linked_list* L)
{

}

void searchMiddleName(doubly_linked_list* L)
{
}

void searchPhone(doubly_linked_list* L)
{
	char request[100];
	do {
		cout << "������� ����� ��������: " << endl;
		cin.getline(request, 100);
		system("cls");
	} while (s_check_phone(request) == false);

	int sizeList = numElements(L);

	// �������� � ������������� ������
	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	// �������������� ������� ��� ������� �� ������ �� ����� ������
	Contact* tmp;
	tmp = L->start->next_link; // ������ �� ������ �������

	// ��������� �������
	Contact tempElement;
	// ���� �� ����� ������
	while (tmp != L->end) {
		if (strcmp(request, tmp->phone) == 0) {
			strcpy_s(tempElement.FIO, tmp->FIO);
			strcpy_s(tempElement.phone, tmp->phone);
			strcpy_s(tempElement.city, tmp->city);
			strcpy_s(tempElement.street, tmp->street);
			tempElement.house = tmp->house;
			tempElement.flat = tmp->flat;
			tempElement.next_link = NULL;
			tempElement.prev_link = NULL;

			// ����������� ��������� �� ��������� �����
			endPtr(tempList);
			// ������� � ����� ������
			prevPut(tempList, &tempElement);
		}
		tmp = tmp->next_link;
	}
	table(tempList);
	clearList(tempList);
}

void searchCity(doubly_linked_list* L)
{
	char request[100];
	do {
		cout << "������� ����� ����������: " << endl;
		cin.getline(request, 100);
		system("cls");
	} while (s_check_city(request) == false);

	int sizeList = numElements(L);

	// �������� � ������������� ������
	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	// �������������� ������� ��� ������� �� ������ �� ����� ������
	Contact* tmp;
	tmp = L->start->next_link; // ������ �� ������ �������

	// ��������� �������
	Contact tempElement;
	// ���� �� ����� ������
	while (tmp != L->end) {
		if (strcmp(request, tmp->city) == 0) {
			strcpy_s(tempElement.FIO, tmp->FIO);
			strcpy_s(tempElement.phone, tmp->phone);
			strcpy_s(tempElement.city, tmp->city);
			strcpy_s(tempElement.street, tmp->street);
			tempElement.house = tmp->house;
			tempElement.flat = tmp->flat;
			tempElement.next_link = NULL;
			tempElement.prev_link = NULL;

			// ����������� ��������� �� ��������� �����
			endPtr(tempList);
			// ������� � ����� ������
			prevPut(tempList, &tempElement);
		}
		tmp = tmp->next_link;
	}
	table(tempList);
	clearList(tempList);
}

void searchStreet(doubly_linked_list* L)
{
	char request[100];
	do {
		cout << "������� ����� ����������: " << endl;
		cin.getline(request, 100);
		system("cls");
	} while (s_check_street(request) == false);

	int sizeList = numElements(L);

	// �������� � ������������� ������
	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	// �������������� ������� ��� ������� �� ������ �� ����� ������
	Contact* tmp;
	tmp = L->start->next_link; // ������ �� ������ �������

	// ��������� �������
	Contact tempElement;
	// ���� �� ����� ������
	while (tmp != L->end) {
		if (strcmp(request, tmp->street) == 0) {
			strcpy_s(tempElement.FIO, tmp->FIO);
			strcpy_s(tempElement.phone, tmp->phone);
			strcpy_s(tempElement.city, tmp->city);
			strcpy_s(tempElement.street, tmp->street);
			tempElement.house = tmp->house;
			tempElement.flat = tmp->flat;
			tempElement.next_link = NULL;
			tempElement.prev_link = NULL;

			// ����������� ��������� �� ��������� �����
			endPtr(tempList);
			// ������� � ����� ������
			prevPut(tempList, &tempElement);
		}
		tmp = tmp->next_link;
	}
	table(tempList);
	clearList(tempList);
}

void searchHouse(doubly_linked_list* L)
{
	char request[100];
	do {
		cout << "������� ����� ����" << endl;
		cin.getline(request, 100);
		system("cls");
	} while (s_check_house(request) == false);
	int numRequest = atoi(request);

	int sizeList = numElements(L);

	// �������� � ������������� ������
	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	// �������������� ������� ��� ������� �� ������ �� ����� ������
	Contact* tmp;
	tmp = L->start->next_link; // ������ �� ������ �������

	// ��������� �������
	Contact tempElement;
	// ���� �� ����� ������
	while (tmp != L->end) {
		if (numRequest == tmp->house) {
			strcpy_s(tempElement.FIO, tmp->FIO);
			strcpy_s(tempElement.phone, tmp->phone);
			strcpy_s(tempElement.city, tmp->city);
			strcpy_s(tempElement.street, tmp->street);
			tempElement.house = tmp->house;
			tempElement.flat = tmp->flat;
			tempElement.next_link = NULL;
			tempElement.prev_link = NULL;

			// ����������� ��������� �� ��������� �����
			endPtr(tempList);
			// ������� � ����� ������
			prevPut(tempList, &tempElement);
		}
		tmp = tmp->next_link;
	}
	table(tempList);
	clearList(tempList);
}

void searchFlat(doubly_linked_list* L)
{
	char request[100];
	do {
		cout << "������� ����� ��������" << endl;
		cin.getline(request, 100);
		system("cls");
	} while (s_check_flat(request) == false);
	int numRequest = atoi(request);

	int sizeList = numElements(L);

	// �������� � ������������� ������
	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	// �������������� ������� ��� ������� �� ������ �� ����� ������
	Contact* tmp;
	tmp = L->start->next_link; // ������ �� ������ �������

	// ��������� �������
	Contact tempElement;
	// ���� �� ����� ������
	while (tmp != L->end) {
		if (numRequest == tmp->flat) {
			strcpy_s(tempElement.FIO, tmp->FIO);
			strcpy_s(tempElement.phone, tmp->phone);
			strcpy_s(tempElement.city, tmp->city);
			strcpy_s(tempElement.street, tmp->street);
			tempElement.house = tmp->house;
			tempElement.flat = tmp->flat;
			tempElement.next_link = NULL;
			tempElement.prev_link = NULL;

			// ����������� ��������� �� ��������� �����
			endPtr(tempList);
			// ������� � ����� ������
			prevPut(tempList, &tempElement);
		}
		tmp = tmp->next_link;
	}
	table(tempList);
	clearList(tempList);
}

bool s_check_FIO(char(&str)[100]) {
	size_t length_str = strlen(str);
	int num_of_spaces = 0;
	for (unsigned i = 0; i < length_str; i++) {
		if (str[i] == ' ') num_of_spaces++;
	}
	if (num_of_spaces == length_str) {
		return false;
	}
	if (str[0] == ' ' || length_str > 40) {
		return false;
	}
	else return true;
}
bool s_check_phone(char(&str)[100])
{
	size_t length_str = strlen(str);
	if (length_str != 12) {
		return false;
	}
	for (unsigned i = 0; i < length_str; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}
bool s_check_city(char(&str)[100])
{
	size_t length_str = strlen(str);
	int num_of_spaces = 0;
	for (unsigned i = 0; i < length_str; i++) {
		if (str[i] == ' ') num_of_spaces++;
	}
	if (num_of_spaces == length_str) {
		return false;
	}
	if (str[0] == ' ' || length_str > 20) {
		return false;
	}
	else return true;
}
bool s_check_street(char(&str)[100])
{
	size_t length_str = strlen(str);
	int num_of_spaces = 0;
	for (unsigned i = 0; i < length_str; i++) {
		if (str[i] == ' ') num_of_spaces++;
	}
	if (num_of_spaces == length_str) {
		return false;
	}
	if (str[0] == ' ' || length_str > 20) {
		return false;
	}
	else return true;
}
bool s_check_house(char(&str)[100])
{
	if (strlen(str) > 3 || str[0] == ' ' || str[0] == '0') {
		return false;
	}
	for (unsigned i = 0; i < strlen(str); i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}
bool s_check_flat(char(&str)[100])
{
	if (strlen(str) > 3 || str[0] == ' ' || str[0] == '0') {
		return false;
	}
	for (unsigned i = 0; i < strlen(str); i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}