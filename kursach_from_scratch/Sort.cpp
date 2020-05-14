#include "Sort.h"

void Ascending(doubly_linked_list* L, int field)
{
	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (field == 1 && strcmp(tempArray[j].FIO, tempArray[i].FIO) > 0) {
					swapArrayElement(tempArray[j], tempArray[i]);
				}

				if (field == 2) {
					char surnameFirst[40] = "";
					for (int k = 0, l = 0; tempArray[j].FIO[l] != ' '; k++, l++)
					{
						surnameFirst[k] = tempArray[j].FIO[l];
					}

					char surnameSecond[40] = "";
					for (int k = 0, l = 0; tempArray[i].FIO[l] != ' '; k++, l++)
					{
						surnameSecond[k] = tempArray[i].FIO[l];
					}

					if (strcmp(surnameFirst, surnameSecond) > 0) {
						swapArrayElement(tempArray[j], tempArray[i]);
					}
				}

				if (field == 3) {
					char firstName[40] = "";
					int posFirstName = 0;
					while (tempArray[j].FIO[posFirstName] != ' ') {
						posFirstName++;
					}
					posFirstName++;
					for (int l = 0, k = posFirstName; tempArray[j].FIO[k] != ' '; l++, k++)
					{
						firstName[l] = tempArray[j].FIO[k];
					}

					char secondtName[40] = "";
					int posSecondName = 0;
					while (tempArray[i].FIO[posSecondName] != ' ') {
						posSecondName++;
					}
					posSecondName++;
					for (int l = 0, k = posSecondName; tempArray[i].FIO[k] != ' '; l++, k++)
					{
						secondtName[l] = tempArray[i].FIO[k];
					}

					if (strcmp(firstName, secondtName) > 0) {
						swapArrayElement(tempArray[j], tempArray[i]);
					}
				}

				if (field == 4) {
					char firstMiddleName[40] = "";
					int posFirstName = 0;
					while (tempArray[j].FIO[posFirstName] != ' ') {
						posFirstName++;
					}
					posFirstName++;
					while (tempArray[j].FIO[posFirstName] != ' ') {
						posFirstName++;
					}
					posFirstName++;

					for (int l = 0, k = posFirstName; tempArray[j].FIO[k] != ' ' && tempArray[j].FIO[k] != '\0'; l++, k++)
					{
						firstMiddleName[l] = tempArray[j].FIO[k];
					}

					char secondMiddleName[40] = "";
					int posSecondName = 0;
					while (tempArray[i].FIO[posSecondName] != ' ') {
						posSecondName++;
					}
					posSecondName++;
					while (tempArray[i].FIO[posSecondName] != ' ') {
						posSecondName++;
					}
					posSecondName++;

					for (int l = 0, k = posSecondName; tempArray[i].FIO[k] != ' ' && tempArray[j].FIO[k] != '\0'; l++, k++)
					{
						secondMiddleName[l] = tempArray[i].FIO[k];
					}

					if (strcmp(firstMiddleName, secondMiddleName) > 0) {
						swapArrayElement(tempArray[j], tempArray[i]);
					}
				}

				if (field == 5 && strcmp(tempArray[j].phone, tempArray[i].phone) > 0) {
					swapArrayElement(tempArray[j], tempArray[i]);
				}

				if (field == 6 && strcmp(tempArray[j].city, tempArray[i].city) > 0) {
					swapArrayElement(tempArray[j], tempArray[i]);
				}

				if (field == 7 && strcmp(tempArray[j].street, tempArray[i].street) > 0) {
					swapArrayElement(tempArray[j], tempArray[i]);
				}

				if (field == 8 && tempArray[j].house > tempArray[i].house) {
					swapArrayElement(tempArray[j], tempArray[i]);
				}

				if (field == 9 && tempArray[j].flat > tempArray[i].flat) {
					swapArrayElement(tempArray[j], tempArray[i]);
				}
			}
		}
	}

	clearList(L);
	initialize(L);
	fillListFromArray(L, tempArray, arraySize);
	clearArray(&tempArray);
}

void Descending(doubly_linked_list* L, int field)
{
	Contact* tempArray = NULL;
	fillArray(&tempArray, L);

	int arraySize = numElements(L);
	for (int step = arraySize / 2; step > 0; step /= 2) {
		for (int i = step; i < arraySize; i++) {
			for (int j = 0; j < i; j++) {
				if (field == 1 && strcmp(tempArray[j].FIO, tempArray[i].FIO) < 0) {
					swapArrayElement(tempArray[j], tempArray[i]);
				}

				if (field == 2) {
					char surnameFirst[40] = "";
					for (int k = 0, l = 0; tempArray[j].FIO[l] != ' '; k++, l++)
					{
						surnameFirst[k] = tempArray[j].FIO[l];
					}

					char surnameSecond[40] = "";
					for (int k = 0, l = 0; tempArray[i].FIO[l] != ' '; k++, l++)
					{
						surnameSecond[k] = tempArray[i].FIO[l];
					}

					if (strcmp(surnameFirst, surnameSecond) < 0) {
						swapArrayElement(tempArray[j], tempArray[i]);
					}
				}

				if (field == 3) {
					char firstName[40] = "";
					int posFirstName = 0;
					while (tempArray[j].FIO[posFirstName] != ' ') {
						posFirstName++;
					}
					posFirstName++;
					for (int l = 0, k = posFirstName; tempArray[j].FIO[k] != ' '; l++, k++)
					{
						firstName[l] = tempArray[j].FIO[k];
					}

					char secondtName[40] = "";
					int posSecondName = 0;
					while (tempArray[i].FIO[posSecondName] != ' ') {
						posSecondName++;
					}
					posSecondName++;
					for (int l = 0, k = posSecondName; tempArray[i].FIO[k] != ' '; l++, k++)
					{
						secondtName[l] = tempArray[i].FIO[k];
					}

					if (strcmp(firstName, secondtName) < 0) {
						swapArrayElement(tempArray[j], tempArray[i]);
					}
				}

				if (field == 4) {
					char firstMiddleName[40] = "";
					int posFirstName = 0;
					while (tempArray[j].FIO[posFirstName] != ' ') {
						posFirstName++;
					}
					posFirstName++;
					while (tempArray[j].FIO[posFirstName] != ' ') {
						posFirstName++;
					}
					posFirstName++;

					for (int l = 0, k = posFirstName; tempArray[j].FIO[k] != ' '; l++, k++)
					{
						firstMiddleName[l] = tempArray[j].FIO[k];
					}

					char secondMiddleName[40] = "";
					int posSecondName = 0;
					while (tempArray[i].FIO[posSecondName] != ' ') {
						posSecondName++;
					}
					posSecondName++;
					while (tempArray[i].FIO[posSecondName] != ' ') {
						posSecondName++;
					}
					posSecondName++;

					for (int l = 0, k = posSecondName; tempArray[i].FIO[k] != ' '; l++, k++)
					{
						secondMiddleName[l] = tempArray[i].FIO[k];
					}

					if (strcmp(firstMiddleName, secondMiddleName) > 0) {
						swapArrayElement(tempArray[j], tempArray[i]);
					}
				}

				if (field == 4) {
					char firstMiddleName[40] = "";
					int posFirstName = 0;
					while (tempArray[j].FIO[posFirstName] != ' ') {
						posFirstName++;
					}
					posFirstName++;
					while (tempArray[j].FIO[posFirstName] != ' ') {
						posFirstName++;
					}
					posFirstName++;

					for (int l = 0, k = posFirstName; tempArray[j].FIO[k] != ' ' && tempArray[j].FIO[k] != '\0'; l++, k++)
					{
						firstMiddleName[l] = tempArray[j].FIO[k];
					}

					char secondMiddleName[40] = "";
					int posSecondName = 0;
					while (tempArray[i].FIO[posSecondName] != ' ') {
						posSecondName++;
					}
					posSecondName++;
					while (tempArray[i].FIO[posSecondName] != ' ') {
						posSecondName++;
					}
					posSecondName++;

					for (int l = 0, k = posSecondName; tempArray[i].FIO[k] != ' ' && tempArray[j].FIO[k] != '\0'; l++, k++)
					{
						secondMiddleName[l] = tempArray[i].FIO[k];
					}

					if (strcmp(firstMiddleName, secondMiddleName) < 0) {
						swapArrayElement(tempArray[j], tempArray[i]);
					}
				}

				if (field == 5 && strcmp(tempArray[j].phone, tempArray[i].phone) < 0) {
					swapArrayElement(tempArray[j], tempArray[i]);

				}

				if (field == 6 && strcmp(tempArray[j].city, tempArray[i].city) < 0) {
					swapArrayElement(tempArray[j], tempArray[i]);

				}

				if (field == 7 && strcmp(tempArray[j].street, tempArray[i].street) < 0) {
					swapArrayElement(tempArray[j], tempArray[i]);

				}

				if (field == 8 && tempArray[j].house < tempArray[i].house) {
					swapArrayElement(tempArray[j], tempArray[i]);

				}

				if (field == 9 && tempArray[j].flat < tempArray[i].flat) {
					swapArrayElement(tempArray[j], tempArray[i]);
				}
			}
		}
	}

	clearList(L);
	initialize(L);
	fillListFromArray(L, tempArray, arraySize);
	clearArray(&tempArray);
}