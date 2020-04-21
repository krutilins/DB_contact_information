#include "File.h"

void upload_file(doubly_linked_list* L)
{
	char file[50];
	cout << "Введите название файла(с указанием формата): ";
	cin.getline(file, 50);

	ofstream fout(file, ios_base::trunc);
	ifstream afodsut(file);
	
	Contact* tmp;
	tmp = L->start->next_link;
	
	while (tmp != L->end) 
	{
		fout << tmp->FIO << endl;
		fout << tmp->phone << endl;
		fout << tmp->city << endl;
		fout << tmp->street << endl;
		fout << tmp->house << endl;
		fout << tmp->flat << endl;
		tmp = tmp->next_link;
	}
	fout.close();
	system("cls");
}

int load_DB(doubly_linked_list* L)
{
	char file[50] = "";
	cout << "Введите название файла(с указанием формата): " << endl;
	cin.getline(file, 50);

	ifstream fin(file);
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла!\n";
		return 0;
	}

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

	Contact new_info;
	char str[100] = "";
	int lineNumber = 0;
	for (int i = 0; i < lineCount; i++) {
		lineNumber++;
		fin.getline(str, 40);
		if (check_FIO(str) == false) {
			cout << "Данные повреждены в строке №: " << lineNumber << " - ";
			cout << "\"" << str << "\"." << endl;
			fin.close();
			return 0;
		}
		strcpy_s(new_info.FIO, str);

		lineNumber++;
		fin.getline(str, 13);
		if (check_phone(str) == false) {
			cout << "Данные повреждены в строке №: " << lineNumber << " - ";
			cout << "\"" << str << "\"." << endl;
			fin.close();
			return 0;
		}
		strcpy_s(new_info.phone, str);

		lineNumber++;
		fin.getline(str, 20);
		if (check_city(str) == false) {
			cout << "Данные повреждены в строке №: " << lineNumber << " - ";
			cout << "\"" << str << "\"." << endl;
			fin.close();
			return 0;
		}
		strcpy_s(new_info.city, str);

		lineNumber++;
		fin.getline(str, 20);
		if (check_street(str) == false) {
			cout << "Данные повреждены в строке №: " << lineNumber << " - ";
			cout << "\"" << str << "\"." << endl;
			fin.close();
			return 0;
		}
		strcpy_s(new_info.street, str);
		
		lineNumber++;
		fin.getline(str, 10);
		if (check_house(str) == false) {
			cout << "Данные повреждены в строке №: " << lineNumber << " - ";
			cout << "\"" << str << "\"." << endl;
			fin.close();
			return 0;
		}
		new_info.house = atoi(str);

		lineNumber++;
		fin.getline(str, 10);
		if (check_flat(str) == false) {
			cout << "Данные повреждены в строке №: " << lineNumber << " - ";
			cout << "\"" << str << "\"." << endl;
			fin.close();
			return 0;
		}
		new_info.flat = atoi(str);
		

		endPtr(L);
		prevPut(L, &new_info);
	}
	fin.close();
	system("cls");
	return 1;
}