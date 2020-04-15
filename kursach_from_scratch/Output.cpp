#include "Output.h"

void display_table(doubly_linked_list* L)
{
	// �������������� ������� ��� ������� �� ������ �� ����� ������
	Contact* tmp;
	tmp = L->start->next_link; // ������ �� ������ �������
	
	cout << "+----------------------------------------+--------------+--------------------+--------------------+------------+----------------+" << endl;
	cout << "|         ������� ��� ��������           |����� ��������|       �����        |       �����        | ����� ���� | ����� �������� |" << endl;
	cout << "+----------------------------------------+--------------+--------------------+--------------------+------------+----------------+" << endl;
	while (tmp != L->end) {
		cout << "|";
		cout << setw(40) << tmp->FIO << "|";
		cout << setw(14) << tmp->phone << "|";
		cout << setw(20) << tmp->city << "|";
		cout << setw(20) << tmp->street << "|";
		cout << setw(12) << tmp->house << "|";
		cout << setw(16) << tmp->flat << "|";
		cout << endl;
		cout << "+----------------------------------------+--------------+--------------------+--------------------+------------+----------------+" << endl;
		tmp = tmp->next_link;
	}
	cout << endl;
}


void display_list(doubly_linked_list* L)
{
	// �������������� ������� ��� ������� �� ������ �� ����� ������
	Contact* tmp;
	tmp = L->start->next_link; // ������ �� ������ �������

	while (tmp != L->end) {
		cout << "���: " << tmp->FIO << endl;
		cout << "�������: " << tmp->phone << endl;
		cout << "�����: " << tmp->city << endl;
		cout << "�����: " << tmp->street << endl;
		cout << "���: " << tmp->house << endl;
		cout << "��������: " << tmp->flat << endl;
		tmp = tmp->next_link;
	}
}