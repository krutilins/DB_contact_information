#include "workWithTable.h"

void table(doubly_linked_list* L)
{
    // ���������� ������� ��������� �� ������
    L->ptr = L->start->next_link;

	// �������������� ������� ��� ������� �� ������ �� ����� ������
	Contact* tmp =L->start->next_link; // ������ �� ������ �������
    
    int functionKey = 0;
    do {
        if (isEmptyList(L)) {
            cout << "������ ����." << endl;
            _getch();
            return;
        }

        cout << "  +----------------------------------------+--------------+--------------------+--------------------+------------+----------------+" << endl;
        cout << "  |         ������� ��� ��������           |����� ��������|       �����        |       �����        | ����� ���� | ����� �������� |" << endl;
        cout << "  +----------------------------------------+--------------+--------------------+--------------------+------------+----------------+" << endl;
        
        while (tmp != L->end) {
            if (tmp == L->ptr) {
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
        
        do {
            functionKey = _getch();
            if (functionKey == 224) {
                functionKey = _getch();
                if (functionKey == 72 && L->ptr != L->start->next_link) { // �����
                    L->ptr = L->ptr->prev_link;
                    tmp = L->start->next_link;
                    break;
                }
                else if (functionKey == 80 && L->ptr != L->end->prev_link) { // ����
                    L->ptr = L->ptr->next_link;
                    tmp = L->start->next_link;
                    break;
                }
                else if (functionKey == 75) { // ����
                    // ���������� ��������
                }
                else if (functionKey == 77) { // ������
                    // ��������� ��������
                }
            }
            if (functionKey == 8) { // backspace
                deleteItem(L);
                tmp = L->start->next_link;
                break;
            }
            if (functionKey == 13) { // enter
                functionKey = _getch();
                if (functionKey == 224) {
                    functionKey = _getch();
                    if (functionKey == 72) { // �����
                        
                        break;
                    }
                    else if (functionKey == 80) { // ����

                        break;
                    }
                    else if (functionKey == 75) { // ����

                        break;
                    }
                    else if (functionKey == 77) { // ������

                    }
                }
            }
            if (functionKey == 27) { //esc
                system("cls");
                return;
            }
        } while (true);
       
        system("cls");
    } while (true);
}