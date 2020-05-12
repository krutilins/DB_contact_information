#include "checkInput.h"

bool check_FIO(char(&str)[100]) {
	size_t length_str = strlen(str);
	int num_of_spaces = 0;
	for (unsigned i = 0; i < length_str; i++) {
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

bool checkPartFIO(char(&str)[100])
{
	size_t length_str = strlen(str);
	int num_of_spaces = 0;
	for (unsigned i = 0; i < length_str; i++) {
		if (str[i] == ' ') return false;
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
	int num_of_spaces = 0;
	for (unsigned i = 0; i < length_str; i++) {
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

bool check_street(char(&str)[100])
{
	size_t length_str = strlen(str);
	int num_of_spaces = 0;
	for (unsigned i = 0; i < length_str; i++) {
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
	