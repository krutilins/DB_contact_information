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
		fcnPtrShowCurrentMenu = showFieldMenu;
		lastMenuItem = 8;
	}
	else if (currentMenu == 3) {
		fcnPtrShowCurrentMenu = showOderMenu;
		lastMenuItem = 3;
	}
	else if (currentMenu == 4) {
		fcnPtrShowCurrentMenu = showFieldMenu;
		lastMenuItem = 8;
	}
	else if (currentMenu == 5) {
		fcnPtrShowCurrentMenu = showPartFIOMenu;
		lastMenuItem = 4;
	}
	else if (currentMenu == 6) {
		fcnPtrShowCurrentMenu = showFieldMenu;
		lastMenuItem = 8;
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

	while (true) {
		switch (choiceMenu(mainMenu))
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
		case 8: // ����������
			filtrationMenu(database);
			break;
		case 9:
			return;
		}
	}
}

void sortMenu(doubly_linked_list* database) {
	const int sortMenu = 2;
	const int oderMenu = 3;
	const int partFIOMenu = 5;

	while (true) {
		switch (choiceMenu(sortMenu))
		{
		case 1: // ���
			switch (choiceMenu(oderMenu))
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
		case 2: // ����� ���
			cout << "���������� �� ����� ��� �� �����������" << endl;
			system("pause");
			//switch (choiceMenu(partFIOMenu))
			//{
			//case 1: // ���
			//	switch (choiceMenu(oderMenu))
			//	{
			//	case 1: // �����������
			//		fioAscending(database);
			//		break;
			//	case 2: // ��������
			//		fioDescending(database);
			//		break;
			//	case 3:
			//		break;
			//	}
			//	break;
			//case 2: // ���
			//	switch (choiceMenu(oderMenu))
			//	{
			//	case 1: // �����������
			//		fioAscending(database);
			//		break;
			//	case 2: // ��������
			//		fioDescending(database);
			//		break;
			//	case 3:
			//		break;
			//	}
			//	break;
			//case 3: // ��������
			//	switch (choiceMenu(oderMenu))
			//	{
			//	case 1: // �����������
			//		fioAscending(database);
			//		break;
			//	case 2: // ��������
			//		fioDescending(database);
			//		break;
			//	case 3:
			//		break;
			//	}
			//	break;
			//case 4: // ���� ����������
			//	break;
			//}
			break;
		case 3: // ����� ��������
			switch (choiceMenu(oderMenu))
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
		case 4: // �����
			switch (choiceMenu(oderMenu))
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
		case 5: // �����
			switch (choiceMenu(oderMenu))
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
		case 6: // ���
			switch (choiceMenu(oderMenu))
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
		case 7: // ��������
			switch (choiceMenu(oderMenu))
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
		case 8: // ������� ����
			return;
		}
	}
}
void searchMenu(doubly_linked_list* database) {
	const int searchMenu = 4;
	const int partFIOMenu = 5;

	while (true) {
		switch (choiceMenu(searchMenu))
		{
		case 1: // ���
			searchFIO(database);
			break;
		case 2: // ����� ���
			switch (choiceMenu(partFIOMenu))
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
void filtrationMenu(doubly_linked_list* database) {
	const int filtrationMenu = 6;
	const int partFIOMenu = 5;

	while (true) {
		switch (choiceMenu(filtrationMenu))
		{
		case 1: // ���
			filtrFIO(database);
			break;
		case 2: // ����� ���
			switch (choiceMenu(partFIOMenu))
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
void showFieldMenu(int currentPosition) {
	int i = 1;
	cout << "���� ����������:" << endl;

	if (currentPosition == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "���" << endl;

	if (currentPosition == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�� ����� ���" << endl;

	if (currentPosition == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "����� ��������" << endl;

	if (currentPosition == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;

	if (currentPosition == 5) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�����" << endl;

	if (currentPosition == 6) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "���" << endl;

	if (currentPosition == 7) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������" << endl;

	if (currentPosition == 8) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������� � ������� ����" << endl;
}
void showPartFIOMenu(int currentPosition) {
	int i = 1;
	cout << "�������� ����� ���:" << endl;

	if (currentPosition == 1) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "�������" << endl;

	if (currentPosition == 2) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "���" << endl;

	if (currentPosition == 3) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������" << endl;

	if (currentPosition == 4) { cout << ">"; }
	else { cout << " "; i++; }
	cout << "��������� � ���� ������" << endl;
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
	cout << "��������� � ���� ����������" << endl;
}