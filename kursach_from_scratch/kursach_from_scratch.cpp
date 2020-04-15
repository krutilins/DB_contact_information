///������� ����

//����������� ����������
#include "Header.h"
#include "Input.h"
#include "Output.h"
#include "File.h"
#include "Search.h"
#include "Sort.h"


void showMenu() {
	cout << "����:" << endl;
	cout << "1. ��������� ������ �� �����." << endl;
	cout << "2. ����� �������" << endl;
	cout << "3. �������� �������." << endl;
	cout << "5. ����� ������" << endl;
	cout << "6. ��������� ������ � ����." << endl;
	cout << "7. ������� ������." << endl;
	cout << "0. �����" << endl;
}

int main()
{
	// ����������� ������� ���������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ��������� �������� �������
	system("mode con cols=131 lines=70");
	
	// �������� � ������������� ������
	doubly_linked_list* database = (doubly_linked_list*)malloc(0);
	initialize(database);
	
	// ������� ����
	char choice;
	char* file = (char*)malloc(sizeof(char) * 50);
	while (true) {
		showMenu();
		choice = _getch();
		system("cls");

		if (choice == '1') { // ��������� �� �����
			cout << "������� �������� �����(� ��������� �������): ";
			cin.getline(file,50);
			system("cls");
			load_DB(database, file);
			cout << "������ ������� ����������." << endl;
			_getch();
			system("cls");
		}
		
		if (choice == '2') { // ������� �������
			if (!isEmptyList(database)) {
				display_table(database);
			}
			else {
				cout << "������ ����.";
			}
			_getch();
			system("cls");
		}
		
		if (choice == '3') { // �������� �������
			add_information(database);
		}
		
		if (choice == '5') { // ������� ������
			if (!isEmptyList(database)) {
				display_list(database);
			}
			else {
				cout << "������ ����.";
			}
			_getch();
			system("cls");
		}
		
		if (choice == '6') { // ��������� � ����
			cout << "������� �������� �����(� ��������� �������): ";
			cin.getline(file, 50);
			system("cls");
			upload_file(database, file);
			cout << "���� ��� ��������." << endl;
			_getch();
			system("cls");
		}
		
		if (choice == '7') { // �������� ������
			clearList(database);
			initialize(database);
			cout << "������ ��� ������." << endl;
			_getch();
			system("cls");
		}
		
		if (choice == '0') { // ����� c ������������� ������
			clearList(database);
			free(file);
			cout << "�� ����� �� ���������" << endl;
			exit(0);
		}
	}
}