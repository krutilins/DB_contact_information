#include "Filtration.h"

void filtration(doubly_linked_list* L, int field)
{
	char startChar;
	char endChar;

	int startInt;
	int endInt;
	
	if (field == 8 || field == 9) {
		cout << "Введите начало диапазона." << endl;
		cin >> startInt;
		cout << "Введите конец диапзаона." << endl;
		cin >> endInt;
	}
	else {
		cout << "Введите начало диапазона." << endl;
		cin >> startChar;
		cout << "Введите конец диапзаона." << endl;
		cin >> endChar;
	}

	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	Contact* tmp;
	tmp = L->start->next_link;

	while (tmp != L->end) {
		if (field == 1 && tmp->FIO[0] >= startChar && tmp->FIO[0] <= endChar) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		if (field == 2) {
			char surname[20] = "";
			for (int k = 0, l = 0; tmp->FIO[l] != ' '; k++, l++)
			{
				surname[k] = tmp->FIO[l];
			}
			if (surname[0] >= startChar && surname[0] <= endChar) {
				endPtr(tempList);
				prevPut(tempList, tmp);
			}
		}

		if (field == 3) {
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
			if (name[0] >= startChar && name[0] <= endChar) {
				endPtr(tempList);
				prevPut(tempList, tmp);
			}
		}

		if (field == 4) {
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
			if (middleName[0] >= startChar && middleName[0] <= endChar) {
				endPtr(tempList);
				prevPut(tempList, tmp);
			}
		}

		if (field == 5 && tmp->phone[0] >= startChar && tmp->phone[0] <= endChar) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		if (field == 6 && tmp->city[0] >= startChar && tmp->city[0] <= endChar) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		if (field == 7 && tmp->street[0] >= startChar && tmp->street[0] <= endChar) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		if (field == 8 && tmp->house >= startChar && tmp->house <= endChar) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		if (field == 9 && tmp->house >= startChar && tmp->house <= endChar) {
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