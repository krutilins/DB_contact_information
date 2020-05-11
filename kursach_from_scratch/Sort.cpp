#include "Sort.h"

/*

1 - фио
2 - фамилия
3 - имя
4 - отчество
5 - телефон
6 - город
7 - улица
8 - дом
9 - квартира

*/
void fioAscending(doubly_linked_list* L)
{
	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	Contact* tempElement = NULL;
	resize_z(&tempElement, 1);
	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (strcmp(tempArray[j].FIO, tempArray[i].FIO) > 0) {
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
void fioDescending(doubly_linked_list* L)
{
	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	Contact* tempElement = NULL;
	resize_z(&tempElement, 1);
	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (strcmp(tempArray[j].FIO, tempArray[i].FIO) < 0) {
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

void phoneAscending(doubly_linked_list* L)
{
	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	Contact* tempElement = NULL;
	resize_z(&tempElement, 1);
	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (strcmp(tempArray[j].phone, tempArray[i].phone) > 0) {
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
void phoneDescending(doubly_linked_list* L)
{
	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	Contact* tempElement = NULL;
	resize_z(&tempElement, 1);
	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (strcmp(tempArray[j].phone, tempArray[i].phone) < 0) {
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

void cityAscending(doubly_linked_list* L)
{
	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	Contact* tempElement = NULL;
	resize_z(&tempElement, 1);
	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (strcmp(tempArray[j].city, tempArray[i].city) > 0) {
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
void cityDescending(doubly_linked_list* L)
{
	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	Contact* tempElement = NULL;
	resize_z(&tempElement, 1);
	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (strcmp(tempArray[j].city, tempArray[i].city) < 0) {
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

void streetAscending(doubly_linked_list* L)
{
	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	Contact* tempElement = NULL;
	resize_z(&tempElement, 1);
	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (strcmp(tempArray[j].street, tempArray[i].street) > 0) {
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
void streetDescending(doubly_linked_list* L)
{
	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	Contact* tempElement = NULL;
	resize_z(&tempElement, 1);
	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (strcmp(tempArray[j].street, tempArray[i].street) < 0) {
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

void houseAscending(doubly_linked_list* L)
{
	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	Contact* tempElement = NULL;
	resize_z(&tempElement, 1);
	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (tempArray[j].house > tempArray[i].house) {
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
void houseDescending(doubly_linked_list* L)
{
	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	Contact* tempElement = NULL;
	resize_z(&tempElement, 1);
	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (tempArray[j].house < tempArray[i].house) {
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

void flatAscending(doubly_linked_list* L)
{
	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	Contact* tempElement = NULL;
	resize_z(&tempElement, 1);
	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (tempArray[j].flat > tempArray[i].flat) {
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
void flatDescending(doubly_linked_list* L)
{
	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	Contact* tempElement = NULL;
	resize_z(&tempElement, 1);
	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (tempArray[j].flat < tempArray[i].flat) {
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