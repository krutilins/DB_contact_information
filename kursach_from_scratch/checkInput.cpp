#include "checkInput.h"

bool check_FIO(char(&str)[100]) {
	size_t length_str = strlen(str);
	if (str[0] == ' ' && length_str > 40) {
		return false;
	}
	
	int countWords = 1;
	int num_of_spaces = 0;
	for (unsigned i = 0; i < length_str; i++) {
		if (!((str[i] >= 'à' && str[i] <= 'ÿ') || (str[i] >= 'À' && str[i] <= 'ß')
			|| str[i] == '¸' || str[i] == '¨' || str[i] == ' '
			|| (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
			return false;
		}
		if (str[i] == ' ') {
			if ((str[i + 1] >= 'à' && str[i + 1] <= 'ÿ') || (str[i + 1] >= 'À' && str[i + 1] <= 'ß')
				|| str[i + 1] == '¸' || str[i + 1] == '¨' || str[i + 1] == ' '
				|| (str[i + 1] >= 'a' && str[i + 1] <= 'z') || (str[i + 1] >= 'A' && str[i + 1] <= 'Z')) {
				countWords++;
			}
			num_of_spaces++;
			if (num_of_spaces > 2) {
				return false;
			}
		}
	}
	if (countWords != 3) {
		return false;
	}
	return true;
}

bool checkPartFIO(char(&str)[100])
{
	size_t length_str = strlen(str);
	for (unsigned i = 0; i < length_str; i++) {
		if (!((str[i] >= 'à' && str[i] <= 'ÿ') || (str[i] >= 'À' && str[i] <= 'ß')
			|| str[i] == '¸' || str[i] == '¨'
			|| (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
			return false;
		}
	}
	if (length_str > 40) {
		return false;
	}
	else return true;
}

bool check_phone(char(&str)[100])
{
	size_t length_str = strlen(str);
	if (length_str != 12) {
		return false;
	}
	for (unsigned i = 0; i < length_str; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

bool check_city(char(&str)[100])
{
	size_t length_str = strlen(str);
	for (unsigned i = 0; i < length_str; i++) {
		if (!((str[i] >= 'à' && str[i] <= 'ÿ') || (str[i] >= 'À' && str[i] <= 'ß')
			|| str[i] == '¸' || str[i] == '¨'
			|| (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
			return false;
		}
	}
	if (length_str > 20) {
		return false;
	}
	else return true;
}

bool check_street(char(&str)[100])
{
	size_t length_str = strlen(str);
	for (unsigned i = 0; i < length_str; i++) {
		if (!((str[i] >= 'à' && str[i] <= 'ÿ') || (str[i] >= 'À' && str[i] <= 'ß')
			|| str[i] == '¸' || str[i] == '¨'
			|| (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
			return false;
		}
	}
	if (length_str > 20) {
		return false;
	}
	else return true;
}

bool check_house(char(&str)[100])
{
	if (strlen(str) > 3 || str[0] == ' ' || str[0] == '0') {
		return false;
	}
	for (unsigned i = 0; i < strlen(str); i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

bool check_flat(char(&str)[100])
{
	if (strlen(str) > 3 || str[0] == ' ' || str[0] == '0') {
		return false;
	}
	for (unsigned i = 0; i < strlen(str); i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}
	