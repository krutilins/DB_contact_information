#include "checkInput.h"

bool check_FIO(char(&str)[100]) {
	size_t length_str = strlen(str);
	if (str[0] == ' ' && length_str > 40) {
		cout << "Введены неверные данные. Попробуйте снова." << endl;
		return false;
	}
	
	int countWords = 1;
	int num_of_spaces = 0;
	for (unsigned i = 0; i < length_str; i++) {
		if (!((str[i] >= 'а' && str[i] <= 'я') || (str[i] >= 'А' && str[i] <= 'Я')
			|| str[i] == 'ё' || str[i] == 'Ё' || str[i] == ' '
			|| (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
			cout << "Введены неверные данные. Попробуйте снова." << endl;
			return false;
		}
		if (str[i] == ' ') {
			if ((str[i + 1] >= 'а' && str[i + 1] <= 'я') || (str[i + 1] >= 'А' && str[i + 1] <= 'Я')
				|| str[i + 1] == 'ё' || str[i + 1] == 'Ё' || str[i + 1] == ' '
				|| (str[i + 1] >= 'a' && str[i + 1] <= 'z') || (str[i + 1] >= 'A' && str[i + 1] <= 'Z')) {
				countWords++;
			}
			num_of_spaces++;
			if (num_of_spaces > 2) {
				cout << "Введены неверные данные. Попробуйте снова." << endl;
				return false;
			}
		}
	}
	if (countWords != 3) {
		cout << "Введены неверные данные. Попробуйте снова." << endl;
		return false;
	}
	return true;
}

bool checkPartFIO(char(&str)[100])
{
	size_t length_str = strlen(str);
	for (unsigned i = 0; i < length_str; i++) {
		if (!((str[i] >= 'а' && str[i] <= 'я') || (str[i] >= 'А' && str[i] <= 'Я')
			|| str[i] == 'ё' || str[i] == 'Ё'
			|| (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
			cout << "Введены неверные данные. Попробуйте снова." << endl;
			return false;
		}
	}
	if (length_str > 20) {
		cout << "Введены неверные данные. Попробуйте снова." << endl;
		return false;
	}
	else return true;
}

bool check_phone(char(&str)[100])
{
	size_t length_str = strlen(str);
	if (length_str != 12) {
		cout << "Введены неверные данные. Попробуйте снова." << endl;
		return false;
	}
	for (unsigned i = 0; i < length_str; i++) {
		if (str[i] < '0' || str[i] > '9') {
			cout << "Введены неверные данные. Попробуйте снова." << endl;
			return false;
		}
	}
	return true;
}

bool check_city(char(&str)[100])
{
	size_t length_str = strlen(str);
	for (unsigned i = 0; i < length_str; i++) {
		if (!((str[i] >= 'а' && str[i] <= 'я') || (str[i] >= 'А' && str[i] <= 'Я')
			|| str[i] == 'ё' || str[i] == 'Ё'
			|| (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
			cout << "Введены неверные данные. Попробуйте снова." << endl;
			return false;
		}
	}
	if (length_str > 20) {
		cout << "Введены неверные данные. Попробуйте снова." << endl;
		return false;
	}
	else return true;
}

bool check_street(char(&str)[100])
{
	size_t length_str = strlen(str);
	for (unsigned i = 0; i < length_str; i++) {
		if (!((str[i] >= 'а' && str[i] <= 'я') || (str[i] >= 'А' && str[i] <= 'Я')
			|| str[i] == 'ё' || str[i] == 'Ё'
			|| (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
			cout << "Введены неверные данные. Попробуйте снова." << endl;
			return false;
		}
	}
	if (length_str > 20) {
		cout << "Введены неверные данные. Попробуйте снова." << endl;
		return false;
	}
	else return true;
}

bool check_house(char(&str)[100])
{
	if (strlen(str) > 3 || str[0] == ' ' || str[0] == '0' || str[0] == 0) {
		cout << "Введены неверные данные. Попробуйте снова." << endl;
		return false;
	}
	for (unsigned i = 0; i < strlen(str); i++) {
		if (str[i] < '0' || str[i] > '9') {
			cout << "Введены неверные данные. Попробуйте снова." << endl;
			return false;
		}
	}
	return true;
}

bool check_flat(char(&str)[100])
{
	if (strlen(str) > 3 || str[0] == ' ' || str[0] == '0' || str[0] == 0) {
		cout << "Введены неверные данные. Попробуйте снова." << endl;
		return false;
	}
	for (unsigned i = 0; i < strlen(str); i++) {
		if (str[i] < '0' || str[i] > '9') {
			cout << "Введены неверные данные. Попробуйте снова." << endl;
			return false;
		}
	}
	return true;
}
	