#include "edit.h"

void edit(Contact* item)
{
	char str[100];
	// ввод информации
	fillFIO(str);
	strcpy_s(item->FIO, str);

	fillPhone(str);
	strcpy_s(item->phone, str);

	fillCity(str);
	strcpy_s(item->city, str);

	fillStreet(str);
	strcpy_s(item->street, str);

	fillHouse(str);
	item->house = atoi(str);

	fillFlat(str);
	item->flat = atoi(str);
}
