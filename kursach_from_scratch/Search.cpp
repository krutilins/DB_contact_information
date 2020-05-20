#include "Search.h"

void search(doubly_linked_list* L, int field)
{
	char request[100];
	int numRequest = 0;

	makeRequest(request, field);
	if (field == 8 || field == 9) {
		numRequest = atoi(request);
	}

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
			if ((strcmp(request, name) == 0)) {
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
			prevPut(tempList, tmp);
		}

		if (field == 9 && numRequest == tmp->flat) {
			endPtr(tempList);
			prevPut(tempList, tmp);
		}

		tmp = tmp->next_link;
	}
	if (isEmptyList(tempList)) {
		cout << "Ничего не найдено!" << endl;
		_getch();
		system("cls");
	}
	else {
		selectionTable(tempList);
	}
	clearList(tempList);
}

void makeRequest(char(&request)[100], int field) {
	if (field == 1) {
		fillFIO(request);
	}

	if (field == 2 || field == 3 || field == 4) {
		fillPartFIO(request);
	}

	if (field == 5) {
		fillPhone(request);
	}

	if (field == 6) {
		fillCity(request);
	}

	if (field == 7) {
		fillStreet(request);
	}

	if (field == 8) {
		fillHouse(request);
	}

	if (field == 9) {
		fillFlat(request);
	}
}