#include "Filtration.h"

void filtration(doubly_linked_list* L, int structField)
{
	char startChar = NULL;
	char endChar = NULL;

	int startInt = NULL;
	int endInt = NULL;
	
	if (structField == 8 || structField == 9) {
		do {
			cout << "Введите начало диапазона." << endl << endl;
			startInt = getInt();

			cout << endl;
			cout << "Введите конец диапзаона." << endl << endl;
			endInt = getInt();
			system("cls");
		} while (startInt >= endInt);
	}
	else if (structField == 5) {
		do {
			cout << "Введите начало диапазона." << endl << endl;
			startChar = getNumeral();

			cout << endl;
			cout << "Введите конец диапзаона." << endl << endl;
			endChar = getNumeral();
			system("cls");
		} while (startChar >= endChar);
	}
	else {
		do {
			cout << "Введите начало диапазона." << endl << endl;
			startChar = getLetter();

			cout << endl;
			cout << "Введите конец диапзаона." << endl << endl;
			endChar = getLetter();
			system("cls");
		} while (startChar >= endChar);
	}

	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	Contact* tmp;
	tmp = L->start->next_link;

	while (tmp != L->end) {
		if (structField == 1 && tmp->FIO[0] >= startChar && tmp->FIO[0] <= endChar) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		if (structField == 2) {
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

		if (structField == 3) {
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

		if (structField == 4) {
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

		if (structField == 5 && tmp->phone[0] >= startChar && tmp->phone[0] <= endChar) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		if (structField == 6 && tmp->city[0] >= startChar && tmp->city[0] <= endChar) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		if (structField == 7 && tmp->street[0] >= startChar && tmp->street[0] <= endChar) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		if (structField == 8 && tmp->house >= startInt && tmp->house <= endInt) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		if (structField == 9 && tmp->flat >= startInt && tmp->flat <= endInt) {
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
		selectionTable(tempList);
	}
	clearList(tempList);
}