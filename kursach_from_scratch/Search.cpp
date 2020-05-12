#include "Search.h"

void search(doubly_linked_list* L, int field)
{
	char request[100];
	int numRequest = 0;
	if (field == 1) {
		do {
			cout << "Введите ФИО: " << endl;
			cin.getline(request, 100);
			system("cls");
		} while (check_FIO(request) == false);
	}

	if (field == 2 || field == 3 || field == 4) {
		cout << "Введите искомый элемент: ";
		cin >> request;
		system("cls");
	}

	if (field == 5) {
		do {
			cout << "Введите номер телефона: " << endl;
			cin.getline(request, 100);
			system("cls");
		} while (check_phone(request) == false);
	}

	if (field == 6) {
		do {
			cout << "Введите город проживания: " << endl;
			cin.getline(request, 100);
			system("cls");
		} while (check_city(request) == false);
	}

	if (field == 7) {
		do {
			cout << "Введите улицу проживания: " << endl;
			cin.getline(request, 100);
			system("cls");
		} while (check_street(request) == false);
	}

	if (field == 8) {
		do {
			cout << "Введите номер дома" << endl;
			cin.getline(request, 100);
			system("cls");
		} while (check_house(request) == false);
		numRequest = atoi(request);
	}

	if (field == 9) {
		do {
			cout << "Введите номер квартиры" << endl;
			cin.getline(request, 100);
			system("cls");
		} while (check_flat(request) == false);
		numRequest = atoi(request);
	}

	int sizeList = numElements(L);

	doubly_linked_list* tempList = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(tempList);

	Contact* tmp;
	tmp = L->start->next_link;

	while (tmp != L->end) {
		if (field == 1 && strcmp(request, tmp->FIO) == 0) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		if (field == 2) {
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
			if ((strcmp(request, name) == 0)) {
				endPtr(tempList);
				prevPut(tempList, tmp);
			}
		}

		if (field == 3) {
			char surname[20] = "";
			for (int k = 0, l = 0; tmp->FIO[l] != ' '; k++, l++)
			{
				surname[k] = tmp->FIO[l];
			}
			if ((strcmp(request, surname) == 0)) {
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
			if ((strcmp(request, middleName) == 0)) {
				endPtr(tempList);
				prevPut(tempList, tmp);
			}
		}

		if (field == 5 && strcmp(request, tmp->phone) == 0) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		if (field == 6 && strcmp(request, tmp->city) == 0) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		if (field == 7 && strcmp(request, tmp->street) == 0) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		if (field == 8 && numRequest == tmp->house) {
			endPtr(tempList);
			// вставка в конец списка
			prevPut(tempList, tmp);
		}

		if (field == 9 && numRequest == tmp->flat) {
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