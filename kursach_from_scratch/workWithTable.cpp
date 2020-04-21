#include "workWithTable.h"

void table(doubly_linked_list* L)
{
	// ���������� ������� ��������� �� ������
	L->ptr = L->start->next_link;

	// �������������� ������� ��� ������� �� ������ �� ����� ������
	Contact* tmp = L->start->next_link; // ������ �� ������ �������
	

	// �������������� ��������� �� ���� �������
	Contact* head = L->start->next_link;

	int functionKey = 0;
	int cntElement = 0;
	int currentPage = 1;
	int maxPage = ceil((double)numElements(L) / TABLE_ELEMENT);
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
		
		cntElement = 0;
		while (tmp != L->end && cntElement != TABLE_ELEMENT) {
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
			if (tmp == L->ptr) {
				cout << "<=";
			}
			else {
				cout << "  ";
			}
			cout << endl;
			cout << "  +----------------------------------------+--------------+--------------------+--------------------+----------+--------------+" << endl;
			tmp = tmp->next_link;
			cntElement++;
		}

		cout << "  |";
		cout << setw(61) << currentPage;
		cout << "/";
		cout << setw(3) << maxPage;
		cout << setw(59) << "|" << endl;
		cout << "  +----------------------------------------+--------------+--------------------+--------------------+----------+--------------+" << endl;

		do {
			functionKey = _getch();
			if (functionKey == 224) {
				functionKey = _getch();
				if (functionKey == 72 && L->ptr != head) { // �����
					L->ptr = L->ptr->prev_link;
					tmp = head;
					break;
				}
				else if (functionKey == 80 && L->ptr != tmp->prev_link) { // ����
					L->ptr = L->ptr->next_link;
					tmp = head;
					break;
				}
				else if (functionKey == 75 && head->prev_link != L->start) { // ����
					// ���������� ��������
					for (int i = 0; i < TABLE_ELEMENT; i++) {
						head = head->prev_link;
					}
					tmp = head;
					L->ptr = head;
					currentPage--;
					break;
				}
				else if (functionKey == 77 && tmp != L->end) { // ������
					head = tmp;
					tmp = head;
					L->ptr = head;
					currentPage++;
					break;
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