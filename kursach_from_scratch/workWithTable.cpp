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
            system("cls");
            return;
        }

        cout << "  +----------------------------------------+--------------+--------------------+--------------------+----------+--------------+" << endl;
        cout << "  |         ������� ��� ��������           |����� ��������|       �����        |       �����        |����� ����|����� ��������|" << endl;
        cout << "  +----------------------------------------+--------------+--------------------+--------------------+----------+--------------+" << endl;
        
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
            cout << setw(10) << tmp->house << "|";
            cout << setw(14) << tmp->flat << "|";
            cout << endl;
            cout << "  +----------------------------------------+--------------+--------------------+--------------------+----------+--------------+" << endl;
            tmp = tmp->next_link;
        }

        cout << "  |";
        cout << setw(61) << "---";
        cout << "/";
        cout << setw(3) << "---";
        cout << setw(59) << "|" << endl;
        cout << "  +----------------------------------------+--------------+--------------------+--------------------+----------+--------------+" << endl;

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
                        add_prev(L);
                        tmp = L->start->next_link;
                        break;
                    }
                    else if (functionKey == 80) { // ����
                        add_next(L);
                        tmp = L->start->next_link;
                        break;
                    }
                    else if (functionKey == 77) { // ������
                        tmp = L->start->next_link;
                        edit(L->ptr);
                        break;
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