///������� ����

//����������� ����������
#include "Header.h"
#include "menu.h"

int main()
{
	// ����������� ������� ���������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ��������� �������� �������
	system("mode con cols=133 lines=35");
	
	// �������� � ������������� ������
	doubly_linked_list* database = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
	initialize(database);
	
	// ������� ����
	menu(database);

	// ������� ������
	clearList(database);
}