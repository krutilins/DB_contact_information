#include "menu.h"

void mainMenu(doubly_linked_list* database)
{
	while (true) {
		switch (choiceMainMenu())
		{
		case 1: // ��������� �� �����
			load_DB(database);
			break;
		case 2: // ������� �������
			table(database);
			break;
		case 3: // �������� �������
			add_end(database);
			break;
		case 4: // ��������� � ����
			upload_file(database);
			break;
		case 5: // �������� ������
			clearList(database);
			initialize(database);
			cout << "������ ��� ������." << endl;
			_getch();
			system("cls");
			break;
		case 6: // ����������
			sortMenu(database);
			break;
		case 7: // �����
			searchMenu(database);
			break;
		case 8:
			filtrationMenu(database);
			break;
		case 9:
			return;
		}
	}
}
void showMainMenu(int pos) {
	int i = 1;
	cout << "����:" << endl;

	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������� ������ �� �����" << endl;

	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "������ � ��������" << endl;

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
	cout << "����������" << endl;

	if (pos == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;

	if (pos == 8) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "����������" << endl;

	if (pos == 9) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;
}
int choiceMainMenu() {
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
				if (pos != 9) {
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
			return 9;
		}
		system("cls");
	} while (true);
}

void sortMenu(doubly_linked_list* database) {
	while (true) {
		switch (choiceSortMenu())
		{
		case 1: // ���
			switch (choiceOderMenu())
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
			switch (choiceOderMenu())
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
			switch (choiceOderMenu())
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
			switch (choiceOderMenu())
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
			switch (choiceOderMenu())
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
			switch (choiceOderMenu())
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
			return;
		}
	}
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
int choiceSortMenu() {
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
	cout << "�������� ������������ ����������:" << endl;

	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�� �����������" << endl;

	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�� ��������" << endl;

	if (pos == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������� � ���� ����������" << endl;
}
int choiceOderMenu() {
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
			return 3;
		}
		system("cls");
	} while (true);
}

void searchMenu(doubly_linked_list* database) {
	while (true) {
		switch (choiceSearchMenu())
		{
		case 1: // ���
			searchFIO(database);
			break;
		case 2: // ����� ���
			switch (choicePartFIOMenu())
			{
			case 1: // �������
				searchSecondName(database);
				break;
			case 2: // ���
				searchFirstName(database);
				break;
			case 3: // ��������
				searchMiddleName(database);
				break;
			case 4: // ���� ������
				break;
			default:
				break;
			}
			break;
		case 3: // �������
			searchPhone(database);
			break;
		case 4: // �����
			searchCity(database);
			break;
		case 5: // �����
			searchStreet(database);
			break;
		case 6: // ���
			searchHouse(database);
			break;
		case 7: // ��������
			searchFlat(database);
			break;
		case 8: // ������� ����
			return;
		}
	}
}
void showSearchMenu(int pos) {
	int i = 1;
	cout << "���� ������:" << endl;

	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "���" << endl;

	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�� ����� ���" << endl;

	if (pos == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "����� ��������" << endl;

	if (pos == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;

	if (pos == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;

	if (pos == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "���" << endl;

	if (pos == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������" << endl;

	if (pos == 8) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������� � ������� ����" << endl;
}
int choiceSearchMenu() {
	int functionKey;
	int pos = 1;
	do {
		showSearchMenu(pos);
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
			return 8;
		}
		system("cls");
	} while (true);
}

void showPartFIOMenu(int pos) {
	int i = 1;
	cout << "�������� ����� ���:" << endl;

	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�������" << endl;

	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "���" << endl;

	if (pos == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������" << endl;

	if (pos == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������� � ���� ������" << endl;
}
int choicePartFIOMenu() {
	int functionKey;
	int pos = 1;
	do {
		showPartFIOMenu(pos);
		functionKey = _getch();
		if (functionKey == 224) {
			functionKey = _getch();
			if (functionKey == 72) { // �����
				if (pos != 1) {
					pos--;
				}
			}
			else if (functionKey == 80) { // ����
				if (pos != 4) {
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
			return 4;
		}
		system("cls");
	} while (true);
}

void filtrationMenu(doubly_linked_list* database) {
	while (true) {
		switch (choiceSearchMenu())
		{
		case 1: // ���
			filtrFIO(database);
			break;
		case 2: // ����� ���
			switch (choicePartFIOMenu())
			{
			case 1: // �������
				filtrSecondName(database);
				break;
			case 2: // ���
				filtrFirstName(database);
				break;
			case 3: // ��������
				filtrMiddleName(database);
				break;
			case 4: // ���� ������
				break;
			default:
				break;
			}
			break;
		case 3: // �������
			filtrPhone(database);
			break;
		case 4: // �����
			filtrCity(database);
			break;
		case 5: // �����
			filtrStreet(database);
			break;
		case 6: // ���
			filtrHouse(database);
			break;
		case 7: // ��������
			filtrFlat(database);
			break;
		case 8: // ������� ����
			return;
		}
	}
}
void showFiltrationMenu(int pos) {
	int i = 1;
	cout << "���� ������:" << endl;

	if (pos == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "���" << endl;

	if (pos == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�� ����� ���" << endl;

	if (pos == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "����� ��������" << endl;

	if (pos == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;

	if (pos == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;

	if (pos == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "���" << endl;

	if (pos == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������" << endl;

	if (pos == 8) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������� � ������� ����" << endl;
}
int choiceFiltrationMenu() {
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
			return 8;
		}
		system("cls");
	} while (true);
}
