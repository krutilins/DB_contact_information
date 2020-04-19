#include "File.h"

using namespace std;

void upload_file(doubly_linked_list* L)
{
	char file[50];
	cout << "Введите название файла(с указанием формата): ";
	cin.getline(file, 50);
	system("cls");
	ofstream fout(file, ios_base::trunc);
	// дополнительный элемент для рпохода от начала до конца списка
	Contact* tmp;
	tmp = L->start->next_link; // ссылка на первый элемент
	// пока не конец списка 
	while (tmp != L->end) {
		fout << tmp->FIO << endl;
		fout << tmp->phone << endl;
		fout << tmp->city << endl;
		fout << tmp->street << endl;
		fout << tmp->house << endl;
		fout << tmp->flat << endl;
		tmp = tmp->next_link;
	}
	fout.close();
}

int load_DB(doubly_linked_list* L)
{
	char file[50] = "";
	cout << "Введите название файла(с указанием формата): " << endl;
	cin.getline(file, 50);
	system("cls");
	// открытие файла
	ifstream fin(file);
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла!\n";
		return 0;
	}

	//подсчет строк и поиск повреждений
	int lineCount = 0;
	while (!fin.eof()) {
		if (fin.get() == '\n') {
			lineCount++;
		}
	}
	if (lineCount == 0 || lineCount % 6 > 0) {
		fin.close();
		cout << "Данные повреждены!\n";
		return 0;
	}
	lineCount = lineCount / 6;
	fin.clear();
	fin.seekg(0, ios::beg);

	// считывание данных с проверкой
	Contact new_info;
	char str[100] = "";
	int lineNumber = 0;
	for (int i = 0; i < lineCount; i++) {
		// ФИО
		lineNumber++;
		fin.getline(str, 40);
		if (f_check_FIO(str) == false) {
			cout << "Данные повреждены в строке №: " << lineNumber << " - ";
			cout << "\"" << str << "\"." << endl;
			fin.close();
			return 0;
		}
		strcpy_s(new_info.FIO, str);

		// номер телефона
		lineNumber++;
		fin.getline(str, 13);
		if (f_check_phone(str) == false) {
			cout << "Данные повреждены в строке №: " << lineNumber << " - ";
			cout << "\"" << str << "\"." << endl;
			fin.close();
			return 0;
		}
		strcpy_s(new_info.phone, str);

		// город
		lineNumber++;
		fin.getline(str, 20);
		if (f_check_city(str) == false) {
			cout << "Данные повреждены в строке №: " << lineNumber << " - ";
			cout << "\"" << str << "\"." << endl;
			fin.close();
			return 0;
		}
		strcpy_s(new_info.city, str);

		// улица
		lineNumber++;
		fin.getline(str, 20);
		if (f_check_street(str) == false) {
			cout << "Данные повреждены в строке №: " << lineNumber << " - ";
			cout << "\"" << str << "\"." << endl;
			fin.close();
			return 0;
		}
		strcpy_s(new_info.street, str);
		
		// дом
		lineNumber++;
		fin.getline(str, 10);
		if (f_check_house(str) == false) {
			cout << "Данные повреждены в строке №: " << lineNumber << " - ";
			cout << "\"" << str << "\"." << endl;
			fin.close();
			return 0;
		}
		new_info.house = atoi(str);

		// квартира
		lineNumber++;
		fin.getline(str, 10);
		if (f_check_flat(str) == false) {
			cout << "Данные повреждены в строке №: " << lineNumber << " - ";
			cout << "\"" << str << "\"." << endl;
			fin.close();
			return 0;
		}
		new_info.flat = atoi(str);
		

		// перемещение указателя на фиктивный конец
		endPtr(L);
		// вставка в конец списка
		prevPut(L, &new_info);
	}
	fin.close();
	return 1;
}

bool f_check_FIO(char(&str)[100]) {
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

bool f_check_phone(char(&str)[100])
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

bool f_check_city(char(&str)[100])
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

bool f_check_street(char(&str)[100])
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

bool f_check_house(char(&str)[100])
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

bool f_check_flat(char(&str)[100])
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