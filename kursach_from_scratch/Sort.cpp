#include "Sort.h"

void Ascending(doubly_linked_list* L, int field)
{
	if (field == 2 || field == 3 || field == 4) {
		cout << "Данная сортировка на данный момент не поддерживаеться." << endl;
		cout << "Ожиданийте следующих версий приложения." << endl;
		_getch();
		system("cls");
		return;
	}

	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	Contact* tempElement = NULL;
	resize_z(&tempElement, 1);
	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (field == 1 && strcmp(tempArray[j].FIO, tempArray[i].FIO) > 0) {
					tempElement[0] = tempArray[j];
					tempArray[j] = tempArray[i];
					tempArray[i] = tempElement[0];
				}

				if (field == 5 && strcmp(tempArray[j].phone, tempArray[i].phone) > 0) {
					tempElement[0] = tempArray[j];
					tempArray[j] = tempArray[i];
					tempArray[i] = tempElement[0];
				}

				if (field == 6 && strcmp(tempArray[j].city, tempArray[i].city) > 0) {
					tempElement[0] = tempArray[j];
					tempArray[j] = tempArray[i];
					tempArray[i] = tempElement[0];
				}

				if (field == 7 && strcmp(tempArray[j].street, tempArray[i].street) > 0) {
					tempElement[0] = tempArray[j];
					tempArray[j] = tempArray[i];
					tempArray[i] = tempElement[0];
				}

				if (field == 8 && tempArray[j].house > tempArray[i].house) {
					tempElement[0] = tempArray[j];
					tempArray[j] = tempArray[i];
					tempArray[i] = tempElement[0];
				}

				if (field == 9 && tempArray[j].flat > tempArray[i].flat) {
					tempElement[0] = tempArray[j];
					tempArray[j] = tempArray[i];
					tempArray[i] = tempElement[0];
				}
			}
		}
	}

	clearList(L);
	initialize(L);
	fillList(L, tempArray, arraySize);
	clear_z(&tempArray);
	clear_z(&tempElement);
}

void Descending(doubly_linked_list* L, int field)
{
	if (field == 2 || field == 3 || field == 4) {
		cout << "Данная сортировка на данный момент не поддерживаеться." << endl;
		cout << "Ожиданийте следующих версий приложения." << endl;
		_getch();
		system("cls");
		return;
	}

	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	Contact* tempElement = NULL;
	resize_z(&tempElement, 1);
	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (field == 1 && strcmp(tempArray[j].FIO, tempArray[i].FIO) < 0) {
					tempElement[0] = tempArray[j];
					tempArray[j] = tempArray[i];
					tempArray[i] = tempElement[0];
				}

				if (field == 5 && strcmp(tempArray[j].phone, tempArray[i].phone) < 0) {
					tempElement[0] = tempArray[j];
					tempArray[j] = tempArray[i];
					tempArray[i] = tempElement[0];
				}

				if (field == 6 && strcmp(tempArray[j].city, tempArray[i].city) < 0) {
					tempElement[0] = tempArray[j];
					tempArray[j] = tempArray[i];
					tempArray[i] = tempElement[0];
				}

				if (field == 7 && strcmp(tempArray[j].street, tempArray[i].street) < 0) {
					tempElement[0] = tempArray[j];
					tempArray[j] = tempArray[i];
					tempArray[i] = tempElement[0];
				}

				if (field == 8 && tempArray[j].house < tempArray[i].house) {
					tempElement[0] = tempArray[j];
					tempArray[j] = tempArray[i];
					tempArray[i] = tempElement[0];
				}

				if (field == 9 && tempArray[j].flat < tempArray[i].flat) {
					tempElement[0] = tempArray[j];
					tempArray[j] = tempArray[i];
					tempArray[i] = tempElement[0];
				}
			}
		}
	}

	clearList(L);
	initialize(L);
	fillList(L, tempArray, arraySize);
	clear_z(&tempArray);
	clear_z(&tempElement);
}