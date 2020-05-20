#include "edit.h"

void edit(Contact* item)
{
	char str[100];

	int word = 1;
	char first[40];
	char second[40];
	char third[40];

	switch (choiceMenu(3))
	{
	case 1:
		fillFIO(str);
		strcpy_s(item->FIO, str);
		break;
	case 2:
		fillPartFIO(str);

		for (int i = 0, j = 0; i < strlen(item->FIO); i++) {
			if (word == 1) {
				first[j] = item->FIO[i];
				first[j + 1] = '\0';
				j++;
			}
			if (word == 2) {
				second[j] = item->FIO[i];
				second[j + 1] = '\0';
				j++;
			}
			if (word == 3) {
				third[j] = item->FIO[i];
				third[j + 1] = '\0';
				j++;
			}
			if (item->FIO[i + 1] == ' ') {
				word++;
				i++;
				j = 0;
			}
		}
		
		strcpy_s(item->FIO, str);
		strcat_s(item->FIO, " ");
		strcat_s(item->FIO, second);
		strcat_s(item->FIO, " ");
		strcat_s(item->FIO, third);

		break;
	case 3:
		fillPartFIO(str);

		for (int i = 0, j = 0; i < strlen(item->FIO); i++) {
			if (word == 1) {
				first[j] = item->FIO[i];
				first[j + 1] = '\0';
				j++;
			}
			if (word == 2) {
				second[j] = item->FIO[i];
				second[j + 1] = '\0';
				j++;
			}
			if (word == 3) {
				third[j] = item->FIO[i];
				third[j + 1] = '\0';
				j++;
			}
			if (item->FIO[i + 1] == ' ') {
				word++;
				i++;
				j = 0;
			}
		}

		strcpy_s(item->FIO, first);
		strcat_s(item->FIO, " ");
		strcat_s(item->FIO, str);
		strcat_s(item->FIO, " ");
		strcat_s(item->FIO, third);

		break;
	case 4:
		fillPartFIO(str);

		for (int i = 0, j = 0; i < strlen(item->FIO); i++) {
			if (word == 1) {
				first[j] = item->FIO[i];
				first[j + 1] = '\0';
				j++;
			}
			if (word == 2) {
				second[j] = item->FIO[i];
				second[j + 1] = '\0';
				j++;
			}
			if (word == 3) {
				third[j] = item->FIO[i];
				third[j + 1] = '\0';
				j++;
			}
			if (item->FIO[i + 1] == ' ') {
				word++;
				i++;
				j = 0;
			}
		}

		strcpy_s(item->FIO, first);
		strcat_s(item->FIO, " ");
		strcat_s(item->FIO, second);
		strcat_s(item->FIO, " ");
		strcat_s(item->FIO, str);

		break;
	case 5:
		fillPhone(str);
		strcpy_s(item->phone, str);
		break;
	case 6:
		fillCity(str);
		strcpy_s(item->city, str);
		break;
	case 7:
		fillStreet(str);
		strcpy_s(item->street, str);
		break;
	case 8:
		fillHouse(str);
		item->house = atoi(str);
		break;
	case 9:
		fillFlat(str);
		item->flat = atoi(str);
		break;
	case 10:
		return;
	}
}
