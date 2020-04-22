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
