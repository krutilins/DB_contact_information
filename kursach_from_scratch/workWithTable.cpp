#include "workWithTable.h"

void table(doubly_linked_list* L)
{
    // ��������� �� ������������ ������� � �������
	Contact* pointer = L->start->next_link; // ������ �� ������ ������� � �������
	// �������������� ������� ��� ������� �� ������ �� ����� ������
	Contact* tmp =L->start->next_link; // ������ �� ������ �������
    int functionKey = 0;
    do {

        cout << "  +----------------------------------------+--------------+--------------------+--------------------+------------+----------------+" << endl;
        cout << "  |         ������� ��� ��������           |����� ��������|       �����        |       �����        | ����� ���� | ����� �������� |" << endl;
        cout << "  +----------------------------------------+--------------+--------------------+--------------------+------------+----------------+" << endl;
        while (tmp != L->end) {
            if (tmp == pointer) {
                cout << "=>";
            }
            else {
                cout << "  ";
            }
            cout << "|";
            cout << setw(40) << tmp->FIO << "|";
            cout << setw(14) << tmp->phone << "|";
            cout << setw(20) << tmp->city << "|";
            cout << setw(20) << tmp->street << "|";
            cout << setw(12) << tmp->house << "|";
            cout << setw(16) << tmp->flat << "|";
            cout << endl;
            cout << "  +----------------------------------------+--------------+--------------------+--------------------+------------+----------------+" << endl;
            tmp = tmp->next_link;
        }

        functionKey = _getch();
        if (functionKey == 224) {
            functionKey = _getch();
            if (functionKey == 80) { // ����
                pointer = pointer->next_link;
                tmp = L->start->next_link;
            }
            else if (functionKey == 75) { // ����
                cout << "����" << endl;
            }
            else if (functionKey == 72) { // �����
                pointer = pointer->prev_link;
                tmp = L->start->next_link;
            }
            else if (functionKey == 77) { // ������
                cout << "������" << endl;
            }
        }
        if (functionKey == 8) {
            cout << "Backspace" << endl;
        }
        if (functionKey == 27) {
            cout << "Esc" << endl;
        }
        system("cls");
    } while (true);
}
