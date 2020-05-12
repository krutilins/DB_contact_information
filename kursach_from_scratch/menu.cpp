#include "menu.h"

int choiceMenu(int currentMenu) {
	int functionKey;
	int position = 1;

	void (*fcnPtrShowCurrentMenu)(int);
	int lastMenuItem;
	if (currentMenu == 1) {
		fcnPtrShowCurrentMenu = showMainMenu;
		lastMenuItem = 9;
	}
	else if (currentMenu == 2) {
		fcnPtrShowCurrentMenu = showFileMenu;
		lastMenuItem = 2;
	}
	else if (currentMenu == 3) {
		fcnPtrShowCurrentMenu = showFieldMenu;
		lastMenuItem = 10;
	}
	else if (currentMenu == 4) {
		fcnPtrShowCurrentMenu = showOderMenu;
		lastMenuItem = 3;
	}
	else {
		exit(0);
	}

	
	do {
		(*fcnPtrShowCurrentMenu)(position);
	
		functionKey = _getch();
		if (functionKey == 224) {
			functionKey = _getch();
			if (functionKey == 72) { // �����
				if (position != 1) {
					position--;
				}
			}
			else if (functionKey == 80) { // ����
				if (position != lastMenuItem) {
					position++;
				}
			}
		}
		if (functionKey == 13) { //enter
			system("cls");
			return position;
		}
		if (functionKey == 27) { //esc
			system("cls");
			return lastMenuItem;
		}
		
		system("cls");
	} while (true);
}

void mainMenu(doubly_linked_list* database) {
	const int mainMenu = 1;
	const int fileMenu = 2;

	while (true) {
		switch (choiceMenu(mainMenu))
		{
		case 1: // ��������� �� �����
			if (!isEmptyList(database)) {
				switch (choiceMenu(fileMenu)) {
				case 1:
					clearList(database);
					initialize(database);
					break;
				}
			}
			load_DB(database);
			break;
		case 2: // ������� �������
			table(database);
			break;
		case 3: // �������� �������
			add_end(database);
			break;
		case 4: // ��������� � ����
			if (isEmptyList(database)) {
				cout << "������ ����." << endl;
				_getch();
				system("cls");
				break;
			}
			upload_file(database);
			break;
		case 5: // �������� ������
			if (isEmptyList(database)) {
				cout << "������ ����." << endl;
				_getch();
				system("cls");
				break;
			}
			clearList(database);
			initialize(database);
			cout << "������ ��� ������." << endl;
			_getch();
			system("cls");
			break;
		case 6: // ����������
			if (isEmptyList(database) || numElements(database) == 1) {
				cout << "������������ ��������� ��� ����������." << endl;
				_getch();
				system("cls");
				break;
			}
			sortMenu(database);
			break;
		case 7: // �����
			if (isEmptyList(database) || numElements(database) == 1) {
				cout << "������������ ��������� ��� ������." << endl;
				_getch();
				system("cls");
				break;
			}
			searchMenu(database);
			break;
		case 8: // ����������
			if (isEmptyList(database) || numElements(database) == 1) {
				cout << "������������ ��������� ��� ����������." << endl;
				_getch();
				system("cls");
				break;
			}
			filtrationMenu(database);
			break;
		case 9:
			return;
		}
	}
}

void sortMenu(doubly_linked_list* database) {
	const int fieldMenu = 3;
	const int oderMenu = 4;

	while(true) {
		switch (choiceMenu(oderMenu))
		{
		case 1:
			switch (choiceMenu(fieldMenu))
			{
			case 1:
				Ascending(database, 1);
				break;
			case 2:
				Ascending(database, 2);
				break;
			case 3:
				Ascending(database, 3);
				break;
			case 4:
				Ascending(database, 4);
				break;
			case 5:
				Ascending(database, 5);
				break;
			case 6:
				Ascending(database, 6);
				break;
			case 7:
				Ascending(database, 7);
				break;
			case 8:
				Ascending(database, 8);
				break;
			case 9:
				Ascending(database, 9);
				break;
			case 10:
				break;
			}
			break;
		case 2:
			switch (choiceMenu(fieldMenu))
			{
			case 1:
				Descending(database, 1);
				break;
			case 2:
				Descending(database, 2);
				break;
			case 3:
				Descending(database, 3);
				break;
			case 4:
				Descending(database, 4);
				break;
			case 5:
				Descending(database, 5);
				break;
			case 6:
				Descending(database, 6);
				break;
			case 7:
				Descending(database, 7);
				break;
			case 8:
				Descending(database, 8);
				break;
			case 9:
				Descending(database, 9);
				break;
			case 10:
				break;
			}
			break;
		case 3:
			return;
		}
	}
}
void searchMenu(doubly_linked_list* database) {
	const int fieldMenu = 3;

	while (true) {
		switch (choiceMenu(fieldMenu))
		{
		case 1: // ���
			search(database, 1);
			break;
		case 2: // �������
			search(database, 2);
			break;
		case 3: // ���
			search(database, 3);
			break;
		case 4: // ��������
			search(database, 4);
			break;
		case 5: // �������
			search(database, 5);
			break;
		case 6: // �����
			search(database, 6);
			break;
		case 7: // �����
			search(database, 7);
			break;
		case 8: // ���
			search(database, 8);
			break;
		case 9: // ��������
			search(database, 9);
			break;
		case 10: // ������� ����
			return;
		}
	}
}
void filtrationMenu(doubly_linked_list* database) {
	const int fieldMenu = 3;

	while (true) {
		switch (choiceMenu(fieldMenu))
		{
		case 1: // ���
			filtrFIO(database);
			break;
		case 2: // �������
			filtrSecondName(database);
			break;
		case 3: // ���
			filtrFirstName(database);
			break;
		case 4: // ��������
			filtrMiddleName(database);
			break;
		case 5: // �������
			filtrPhone(database);
			break;
		case 6: // �����
			filtrCity(database);
			break;
		case 7: // �����
			filtrStreet(database);
			break;
		case 8: // ���
			filtrHouse(database);
			break;
		case 9: // ��������
			filtrFlat(database);
			break;
		case 10: // ������� ����
			return;
		}
	}
}

void showMainMenu(int currentPosition) {
	int i = 1;
	cout << "����:" << endl;

	if (currentPosition == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������� ������ �� �����" << endl;

	if (currentPosition == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "������ � ��������" << endl;

	if (currentPosition == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�������� �������" << endl;

	if (currentPosition == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������� ������ � ����" << endl;

	if (currentPosition == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "������� ������" << endl;

	if (currentPosition == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "����������" << endl;

	if (currentPosition == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;

	if (currentPosition == 8) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "����������" << endl;

	if (currentPosition == 9) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;
}
void showFileMenu(int currentPosition) {
	int i = 1;
	cout << "�� ������ ������ �� ��� ��������� � ����� ����� ������." << endl;
	cout << "�������� �������� ���� ����� ��������� ����� ������? (1 - �� / 0 - ���)" << endl;

	if (currentPosition == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��" << endl;

	if (currentPosition == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "���" << endl;
}
void showFieldMenu(int currentPosition) {
	int i = 1;
	cout << "�������� ����:" << endl;

	if (currentPosition == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "���" << endl;

	if (currentPosition == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�������" << endl;

	if (currentPosition == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "���" << endl;

	if (currentPosition == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������" << endl;

	if (currentPosition == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "����� ��������" << endl;

	if (currentPosition == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;

	if (currentPosition == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;

	if (currentPosition == 8) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "���" << endl;

	if (currentPosition == 9) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������" << endl;

	if (currentPosition == 10) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;
}
void showOderMenu(int currentPosition) {
	int i = 1;
	cout << "�������� ������������ ����������:" << endl;

	if (currentPosition == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�� �����������" << endl;

	if (currentPosition == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�� ��������" << endl;

	if (currentPosition == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;
}