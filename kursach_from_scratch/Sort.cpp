#include "Sort.h"

void fillArray(Contact** tempArray, doubly_linked_list* L)
{
	// дополнительный элемент дл€ прохода от начала до конца списка
	Contact* tmp;
	tmp = L->start->next_link; // ссылка на первый элемент

	// пока не конец списка
	for (int i = 0; tmp != L->end; i++) {
		resize_z(tempArray, i + 1);
		strcpy((*tempArray)[i].FIO, tmp->FIO);
		strcpy((*tempArray)[i].phone, tmp->phone);
		strcpy((*tempArray)[i].city, tmp->city);
		strcpy((*tempArray)[i].street, tmp->street);
		(*tempArray)[i].house = tmp->house;
		(*tempArray)[i].flat = tmp->flat;
		tmp = tmp->next_link;
	}
}
void fillList(doubly_linked_list* L, Contact* tempArray, int sizeArray)
{
	// временный элемент
	Contact tempElement;
	// пока не конец списка
	for (int i = 0; i < sizeArray; i++) {
		strcpy(tempElement.FIO, tempArray[i].FIO);
		strcpy(tempElement.phone, tempArray[i].phone);
		strcpy(tempElement.city, tempArray[i].city);
		strcpy(tempElement.street, tempArray[i].street);
		tempElement.house = tempArray[i].house;
		tempElement.flat = tempArray[i].flat;

		// перемещение указател€ на фиктивный конец
		endPtr(L);
		// вставка в конец списка
		prevPut(L, &tempElement);
	}
}
void resize_z(Contact** pointer, int newsize) {
	Contact* buff = (Contact*)realloc(*pointer, sizeof(Contact) * newsize);
	if (buff == NULL) {
		cout << "Ќе удалось выделить пам€ть!" << endl;
		exit(-1);
	}

	*pointer = buff;
}
void clear_z(Contact** pointer) {
	Contact* buff = (Contact*)realloc(*pointer, 0);
	if (buff != NULL) {
		cout << "Ќе получилось очистить массив." << endl;
		exit(-1);
	}
	*pointer = buff;

}

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
