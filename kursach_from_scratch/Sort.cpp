#include "Sort.h"

void Sort_Ascending(int field, struct Clients* array, int size) {
	Clients* temp = new Clients[1];
	int step, i, j;
	for (step = size / 2; step > 0; step /= 2) {
		for (i = step; i < size; i++) {
			for (j = 0; j < i; j++) {
				if (field == 1) {
					if (strcmp(array[j].FIO, array[i].FIO) > 0) {
						temp[0] = array[j];
						array[j] = array[i];
						array[i] = temp[0];
					}
				}
				if (field == 2) {
					if (strcmp(array[j].city, array[i].city) > 0) {
						temp[0] = array[j];
						array[j] = array[i];
						array[i] = temp[0];
					}
				}
				if (field == 3) {
					if (strcmp(array[j].street, array[i].street) > 0) {
						temp[0] = array[j];
						array[j] = array[i];
						array[i] = temp[0];
					}
				}
				if (field == 4) {
					if (array[j].house > array[i].house) {
						temp[0] = array[j];
						array[j] = array[i];
						array[i] = temp[0];
					}
				}
				if (field == 5) {
					if (array[j].flat > array[i].flat) {
						temp[0] = array[j];
						array[j] = array[i];
						array[i] = temp[0];
					}
				}
				if (field == 6) {
					if (array[j].index > array[i].index) {
						temp[0] = array[j];
						array[j] = array[i];
						array[i] = temp[0];
					}
				}
			}
		}
	}
}

void Sort_Descending(int field, struct Clients* array, int size) {
	Clients* temp = new Clients[1];
	int step, i, j;
	for (step = size / 2; step > 0; step /= 2) {
		for (i = step; i < size; i++) {
			for (j = 0; j < i; j++) {
				if (field == 1) {
					if (strcmp(array[j].FIO, array[i].FIO) < 0) {
						temp[0] = array[j];
						array[j] = array[i];
						array[i] = temp[0];
					}
				}
				if (field == 2) {
					if (strcmp(array[j].city, array[i].city) < 0) {
						temp[0] = array[j];
						array[j] = array[i];
						array[i] = temp[0];
					}
				}
				if (field == 3) {
					if (strcmp(array[j].street, array[i].street) < 0) {
						temp[0] = array[j];
						array[j] = array[i];
						array[i] = temp[0];
					}
				}
				if (field == 4) {
					if (array[j].house < array[i].house) {
						temp[0] = array[j];
						array[j] = array[i];
						array[i] = temp[0];
					}
				}
				if (field == 5) {
					if (array[j].flat < array[i].flat) {
						temp[0] = array[j];
						array[j] = array[i];
						array[i] = temp[0];
					}
				}
				if (field == 6) {
					if (array[j].index < array[i].index) {
						temp[0] = array[j];
						array[j] = array[i];
						array[i] = temp[0];
					}
				}
			}
		}
	}
}

void menu_sort() {
	system("cls");
	cout << "1-Сортировка по ФИО клиента" << endl;
	cout << "2-Сортировка по городу проживания клиента" << endl;
	cout << "3-Сортировка по улице проживания клиента" << endl;
	cout << "4-Сортировка по номер дома проживания клиента" << endl;
	cout << "5-Сортировка по номер квартиры проживания клиента" << endl;
	cout << "6-Сортировка по индексу" << endl;
	cout << "7-Выход в меню" << endl;
}

void celect_sort(int field) {
	system("cls");
	cout << "1-Сортировка по возрастанию" << endl;
	cout << "2-Сортировка по убыванию" << endl;
	cout << "3-Выход в меню" << endl;
	Clients* array = new Clients[kol];
	Loading(array);
	char ch;
	while (1) {
		ch = _getch();
		if (ch == 49) {
			Sort_Ascending(field, array, kol);
			Loading_Queue(array);
			system("cls");
			Tablitsa();
			system("pause");
			menu();
		}
		if (ch == 50) {
			Sort_Descending(field, array, kol);
			Loading_Queue(array);
			system("cls");
			Tablitsa();
			system("pause");
			menu();
		}
		if (ch == 51) {
			menu();
		}
	}
}

void sort() {
	menu_sort();
	char ch;
	while (1) {
		ch = _getch();
		if (ch == 49) {
			celect_sort(1);
		}
		if (ch == 50) {
			celect_sort(2);
		}
		if (ch == 51) {
			celect_sort(3);
		}
		if (ch == 52) {
			celect_sort(4);
		}
		if (ch == 53) {
			celect_sort(5);
		}
		if (ch == 54) {
			celect_sort(6);
		}
		if (ch == 55) {
			menu();
		}

	}
}


