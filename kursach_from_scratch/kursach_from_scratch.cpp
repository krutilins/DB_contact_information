///������� ����

//����������� ����������
#include "Header.h"
#include "Input.h"
#include "Output.h"
#include "File.h"
#include "workWithTable.h"
#include "Search.h"
#include "Sort.h"

void showMainMenu(int pos) {
	int i = 1;
	cout << "����:" << endl;
	
	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������� ������ �� �����" << endl;
	
	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "����� �������" << endl;
	
	if (pos == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�������� �������" << endl;
	
	if (pos == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������� ������ � ����" << endl;
	
	if (pos == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "������� ������" << endl;
	
	if (pos == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "������ � ��������" << endl;
	
	if (pos == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "����������" << endl;

	if (pos == 8) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;
}
int mainMenu() {
	int functionKey;
	int pos = 1;
	do {
		showMainMenu(pos);
		functionKey = _getch();
		if (functionKey == 224) {
			functionKey = _getch();
			if (functionKey == 72) { // �����
				if (pos != 1) {
					pos--;
				}
			}
			else if (functionKey == 80) { // ����
				if (pos != 8) {
					pos++;
				}
			}
		}
		if (functionKey == 13) { //enter
			system("cls");
			return pos;
		}
		if (functionKey == 27) { //esc
			system("cls");
			return 7;
		}
		system("cls");
	} while (true);
}

void showSortMenu(int pos) {
	int i = 1;
	cout << "������������� ����:" << endl;

	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "���" << endl;

	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "����� ��������" << endl;

	if (pos == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;

	if (pos == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;

	if (pos == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "���" << endl;

	if (pos == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������" << endl;

	if (pos == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������� � ������� ����" << endl;
}
int sortMenu() {
	int functionKey;
	int pos = 1;
	do {
		showSortMenu(pos);
		functionKey = _getch();
		if (functionKey == 224) {
			functionKey = _getch();
			if (functionKey == 72) { // �����
				if (pos != 1) {
					pos--;
				}
			}
			else if (functionKey == 80) { // ����
				if (pos != 7) {
					pos++;
				}
			}
		}
		if (functionKey == 13) { //enter
			system("cls");
			return pos;
		}
		if (functionKey == 27) { //esc
			system("cls");
			return 7;
		}
		system("cls");
	} while (true);
}

void showOderMenu(int pos) {
	int i = 1;
	cout << "������������� ����:" << endl;

	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�� �����������" << endl;

	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�� ��������" << endl;

	if (pos == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������� � ������� ����" << endl;
}
int oderMenu() {
	int functionKey;
	int pos = 1;
	do {
		showOderMenu(pos);
		functionKey = _getch();
		if (functionKey == 224) {
			functionKey = _getch();
			if (functionKey == 72) { // �����
				if (pos != 1) {
					pos--;
				}
			}
			else if (functionKey == 80) { // ����
				if (pos != 3) {
					pos++;
				}
			}
		}
		if (functionKey == 13) { //enter
			system("cls");
			return pos;
		}
		if (functionKey == 27) { //esc
			system("cls");
			return 7;
		}
		system("cls");
	} while (true);
}

int main()
{
	// ����������� ������� ���������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ��������� �������� �������
	system("mode con cols=133 lines=35");
	
	// �������� � ������������� ������
	doubly_linked_list* database = (doubly_linked_list*)malloc(0);
	initialize(database);
	
	// ������� ����
	char choice;
	char file[51];
	while (true) {
		switch (mainMenu())
		{
		case 1: // ��������� �� �����
			cout << "������� �������� �����(� ��������� �������): ";
			cin.getline(file, 50);
			system("cls");
			load_DB(database, file);
			cout << "������ ������� ����������." << endl;
			_getch();
			system("cls");
			break;
		case 2: // ������� �������
			if (!isEmptyList(database)) {
				display_table(database);
			}
			else {
				cout << "������ ����.";
			}
			_getch();
			system("cls");
			break;
		case 3: // �������� �������
			add_information(database);
			break;
		case 4: // ��������� � ����
			cout << "������� �������� �����(� ��������� �������): ";
			cin.getline(file, 50);
			system("cls");
			upload_file(database, file);
			cout << "���� ��� ��������." << endl;
			_getch();
			system("cls");
			break;
		case 5: // �������� ������
			clearList(database);
			initialize(database);
			cout << "������ ��� ������." << endl;
			_getch();
			system("cls");
			break;
		case 6: // ����������� � ��������
			table(database);
			system("cls");
			break;
		case 7: // ����������
			switch (sortMenu())
			{
			case 1: // ���
				switch (oderMenu())
				{
				case 1: // �����������
					fioAscending(database);
					break;
				case 2: // ��������
					fioDescending(database);
					break;
				case 3:
					break;
				}
				break;
			case 2: // ����� ��������
				switch (oderMenu())
				{
				case 1: // �����������
					phoneAscending(database);
					break;
				case 2: // ��������
					phoneDescending(database);
					break;
				case 3:
					break;
				}
				break;
			case 3: // �����
				switch (oderMenu())
				{
				case 1: // �����������
					cityAscending(database);
					break;
				case 2: // ��������
					cityDescending(database);
					break;
				case 3:
					break;
				}
				break;
			case 4: // �����
				switch (oderMenu())
				{
				case 1: // �����������
					streetAscending(database);
					break;
				case 2: // ��������
					streetDescending(database);
					break;
				case 3:
					break;
				}
				break;
			case 5: // ���
				switch (oderMenu())
				{
				case 1: // �����������
					houseAscending(database);
					break;
				case 2: // ��������
					houseDescending(database);
					break;
				case 3:
					break;
				}
				break;
			case 6: // ��������
				switch (oderMenu())
				{
				case 1: // �����������
					flatAscending(database);
					break;
				case 2: // ��������
					flatDescending(database);
					break;
				case 3:
					break;
				}
				break;
			case 7: // ������� ����
				break;
			default:
				break;
			}
			break;
		case 8: // ����� c ������������� ������
			clearList(database);
			free(file);
			cout << "�� ����� �� ���������" << endl;
			exit(0);
			break;
		default:
			break;
		}
	}
}