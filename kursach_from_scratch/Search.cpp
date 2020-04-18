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
	cout << "������� ���: " << endl;
	char request[40];
	cin.getline(request, 40);
	system("cls");

	int sizeList = numElements(L);

	// �������� � ������������� ������
	doubly_linked_list* tempList = (doubly_linked_list*)malloc(0);
	initialize(tempList);

	// �������������� ������� ��� ������� �� ������ �� ����� ������
	Contact* tmp;
	tmp = L->start->next_link; // ������ �� ������ �������

	// ��������� �������
	Contact tempElement;
	// ���� �� ����� ������
	while (tmp != L->end) {
		if (strcmp(request, tmp->FIO) == 0) {
			strcpy(tempElement.FIO, tmp->FIO);
			strcpy(tempElement.phone, tmp->phone);
			strcpy(tempElement.city, tmp->city);
			strcpy(tempElement.street, tmp->street);
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
}

void searchCity(doubly_linked_list* L)
{
}

void searchStreet(doubly_linked_list* L)
{
}

void searchHouse(doubly_linked_list* L)
{
}

void searchFlat(doubly_linked_list* L)
{
}
