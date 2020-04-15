#include "Input.h"

void add_information(doubly_linked_list* L)
{
	Contact new_info;
	// ввод информации
	strcpy(new_info.FIO, get_FIO());
	strcpy(new_info.phone, get_phone());
	strcpy(new_info.city, get_city());
	strcpy(new_info.street, get_street());
	new_info.house = get_house();
	new_info.flat = get_flat();
	// перемещение указател€ на фиктивный конец
	endPtr(L);
	// вставка в конец списка
	prevPut(L, &new_info);
}

char* get_FIO()
{
	char str[40];
	do {
		cout << "¬ведите ‘»ќ" << endl;
		gets_s(str);
		system("cls");
	} while (check_FIO(str) == false);
	return str;
}

bool check_FIO(char str[]) {
	int length_str = strlen(str);
	int num_of_spaces = 0;
	for (int i = 0; i < length_str; i++) {
		if (str[i] == ' ') num_of_spaces++;
	}
	if (num_of_spaces == length_str) {
		return false;
	}
	if (str[0] == ' ' || length_str > 40) {
		return false;
	}
	else return true;
}

char* get_phone()
{
	char str[40];
	do {
		cout << "¬ведите номер телефона" << endl;
		gets_s(str);
		system("cls");
	} while (check_phone(str) == false);
	return str;
}

bool check_phone(char str[])
{
	int length_str = strlen(str);
	if (length_str != 12) {
		return false;
	}
	for (int i = 0; i < length_str; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

char* get_city()
{
	char str[40];
	do {
		cout << "¬ведите название города" << endl;
		gets_s(str);
		system("cls");
	} while (check_city(str) == false);
	return str;
}

bool check_city(char str[])
{
	int length_str = strlen(str);
	int num_of_spaces = 0;
	for (int i = 0; i < length_str; i++) {
		if (str[i] == ' ') num_of_spaces++;
	}
	if (num_of_spaces == length_str) {
		return false;
	}
	if (str[0] == ' ' || length_str > 20) {
		return false;
	}
	else return true;
}

char* get_street()
{
	char str[40];
	do {
		cout << "¬ведите название улицы" << endl;
		gets_s(str);
		system("cls");
	} while (check_street(str) == false);
	return str;
}

bool check_street(char str[])
{
	int length_str = strlen(str);
	int num_of_spaces = 0;
	for (int i = 0; i < length_str; i++) {
		if (str[i] == ' ') num_of_spaces++;
	}
	if (num_of_spaces == length_str) {
		return false;
	}
	if (str[0] == ' ' || length_str > 20) {
		return false;
	}
	else return true;
}

int get_house()
{
	char str[10];
	int number;
	do {
		cout << "¬ведите номер дома" << endl;
		gets_s(str);
		system("cls");
	} while (check_house(str) == false);
	number = atoi(str);
	return number;
}

bool check_house(char str[])
{
	if (strlen(str) > 3 || str[0] == ' ' || str[0] == '0') {
		return false;
	}
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

int get_flat()
{
	char str[10];
	int number;
	do {
		cout << "¬ведите номер квартиры" << endl;
		gets_s(str);
		system("cls");
	} while (check_flat(str) == false);
	number = atoi(str);
	return number;
}

bool check_flat(char str[])
{
	if (strlen(str) > 3 || str[0] == ' ' || str[0] == '0') {
		return false;
	}
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}