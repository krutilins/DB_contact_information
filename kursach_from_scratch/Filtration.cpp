#include "Filtration.h"

void filtrFIO(doubly_linked_list* L)
{
	char start;
	char end;
	system("cls");
	cout << "Введите начало диапазона: " << endl;
	cin >> start;
	cout << "Введите конец диапазона: " << endl;
	cin >> end;

	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	Contact* tmp;
	tmp = L->start->next_link;

	while (tmp != L->end) {
		if (tmp->FIO[0] >= start && tmp->FIO[0] <= end) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}
		tmp = tmp->next_link;
	}
	if (isEmptyList(tempList)) {
		cout << "Ничего не найдено" << endl;
		_getch();
		system("cls");
	}
	else {
		table(tempList);
	}
	clearList(tempList);
}

void filtrFirstName(doubly_linked_list* L)
{
	char start;
	char end;
	system("cls");
	cout << "Введите начало диапазона: " << endl;
	cin >> start;
	cout << "Введите конец диапазона: " << endl;
	cin >> end;

	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	Contact* tmp;
	tmp = L->start->next_link;

	while (tmp != L->end) {
		char name[40] = "";
		int posName = 0;
		while (tmp->FIO[posName] != ' ') {
			posName++;
		}
		posName++;
		for (int i = 0, k = posName; tmp->FIO[k] != ' '; i++, k++)
		{
			name[i] = tmp->FIO[k];
		}
		if (name[0] >= start && name[0] <= end) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}
		tmp = tmp->next_link;
	}
	if (isEmptyList(tempList)) {
		cout << "Ничего не найдено" << endl;
		_getch();
		system("cls");
	}
	else {
		table(tempList);
	}
	clearList(tempList);
}

void filtrSecondName(doubly_linked_list* L)
{
	char start;
	char end;
	system("cls");
	cout << "Введите начало диапазона: " << endl;
	cin >> start;
	cout << "Введите конец диапазона: " << endl;
	cin >> end;

	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	Contact* tmp;
	tmp = L->start->next_link;

	while (tmp != L->end) {
		char surname[20] = "";
		for (int k = 0, l = 0; tmp->FIO[l] != ' '; k++, l++)
		{
			surname[k] = tmp->FIO[l];
		}
		if (surname[0] >= start && surname[0] <= end) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}
		tmp = tmp->next_link;
	}
	if (isEmptyList(tempList)) {
		cout << "Ничего не найдено" << endl;
		_getch();
		system("cls");
	}
	else {
		table(tempList);
	}
	clearList(tempList);
}

void filtrMiddleName(doubly_linked_list* L)
{
	char start;
	char end;
	system("cls");
	cout << "Введите начало диапазона: " << endl;
	cin >> start;
	cout << "Введите конец диапазона: " << endl;
	cin >> end;

	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	Contact* tmp;
	tmp = L->start->next_link;

	while (tmp != L->end) {
		char middleName[40] = "";
		int posName = 0;
		while (tmp->FIO[posName] != ' ') {
			posName++;
		}
		posName++;
		while (tmp->FIO[posName] != ' ') {
			posName++;
		}
		posName++;
		for (int i = 0, k = posName; tmp->FIO[k] != ' ' && tmp->FIO[k] != '\0'; i++, k++)
		{
			middleName[i] = tmp->FIO[k];
		}
		if (middleName[0] >= start && middleName[0] <= end) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}
		tmp = tmp->next_link;
	}
	if (isEmptyList(tempList)) {
		cout << "Ничего не найдено" << endl;
		_getch();
		system("cls");
	}
	else {
		table(tempList);
	}
	clearList(tempList);
}

void filtrPhone(doubly_linked_list* L)
{
	char start;
	char end;
	system("cls");
	cout << "Введите начало диапазона: " << endl;
	cin >> start;
	cout << "Введите конец диапазона: " << endl;
	cin >> end;

	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	Contact* tmp;
	tmp = L->start->next_link;

	while (tmp != L->end) {
		if (tmp->phone[0] >= start && tmp->phone[0] <= end) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}
		tmp = tmp->next_link;
	}
	if (isEmptyList(tempList)) {
		cout << "Ничего не найдено" << endl;
		_getch();
		system("cls");
	}
	else {
		table(tempList);
	}
	clearList(tempList);
}

void filtrCity(doubly_linked_list* L)
{
	char start;
	char end;
	system("cls");
	cout << "Введите начало диапазона: " << endl;
	cin >> start;
	cout << "Введите конец диапазона: " << endl;
	cin >> end;

	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	Contact* tmp;
	tmp = L->start->next_link;

	while (tmp != L->end) {
		if (tmp->city[0] >= start && tmp->city[0] <= end) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}
		tmp = tmp->next_link;
	}
	if (isEmptyList(tempList)) {
		cout << "Ничего не найдено" << endl;
		_getch();
		system("cls");
	}
	else {
		table(tempList);
	}
	clearList(tempList);
}

void filtrStreet(doubly_linked_list* L)
{
	char start;
	char end;
	system("cls");
	cout << "Введите начало диапазона: " << endl;
	cin >> start;
	cout << "Введите конец диапазона: " << endl;
	cin >> end;

	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	Contact* tmp;
	tmp = L->start->next_link;

	while (tmp != L->end) {
		if (tmp->street[0] >= start && tmp->street[0] <= end) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}
		tmp = tmp->next_link;
	}
	if (isEmptyList(tempList)) {
		cout << "Ничего не найдено" << endl;
		_getch();
		system("cls");
	}
	else {
		table(tempList);
	}
	clearList(tempList);
}

void filtrHouse(doubly_linked_list* L)
{
	int start;
	int end;
	system("cls");
	cout << "Введите начало диапазона: " << endl;
	cin >> start;
	cout << "Введите конец диапазона: " << endl;
	cin >> end;

	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	Contact* tmp;
	tmp = L->start->next_link;

	while (tmp != L->end) {
		if (tmp->house >= start && tmp->house <= end) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}
		tmp = tmp->next_link;
	}
	if (isEmptyList(tempList)) {
		cout << "Ничего не найдено" << endl;
		_getch();
		system("cls");
	}
	else {
		table(tempList);
	}
	clearList(tempList);
}

void filtrFlat(doubly_linked_list* L)
{
	int start;
	int end;
	system("cls");
	cout << "Введите начало диапазона: " << endl;
	cin >> start;
	cout << "Введите конец диапазона: " << endl;
	cin >> end;

	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	Contact* tmp;
	tmp = L->start->next_link;

	while (tmp != L->end) {
		if (tmp->house >= start && tmp->house <= end) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}
		tmp = tmp->next_link;
	}
	if (isEmptyList(tempList)) {
		cout << "Ничего не найдено" << endl;
		_getch();
		system("cls");
	}
	else {
		table(tempList);
	}
	clearList(tempList);
}
