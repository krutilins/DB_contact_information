#include "workWithTable.h"

void table(doubly_linked_list* L)
{
	L->ptr = L->start->next_link;

	Contact* tmp = L->start->next_link;
	Contact* head = L->start->next_link;

	const int TABLE_ELEMENT = 14;
	int currentPage = 1;
	int maxPage;
	do {
		if (isEmptyList(L)) {
			cout << "Список пуст." << endl;
			_getch();
			system("cls");
			return;
		}

		maxPage = ceil((double)numElements(L) / TABLE_ELEMENT);
		
		tableTitle();
		showHeader();
		showTable(L, &tmp, TABLE_ELEMENT);
		showFooter(currentPage, maxPage);

		if (keyRegister(L, &tmp, &head, currentPage, TABLE_ELEMENT) == 0) {
			return;
		}
	   
		system("cls");
	} while (true);
}

void tableTitle()
{
	cout << "  |         Используйте стрельки для навигации и enter для выбора элемента для дальнейшей работы с ним.                       |" << endl;
}

void selectionTitle()
{
	cout << "  |                                    Используйте стрелки для навигации                                                      |" << endl;
}

void showTable(doubly_linked_list* L, Contact** tmp, const int TABLE_ELEMENT)
{
	int cntElement = 0;
	while ((*tmp) != L->end && cntElement != TABLE_ELEMENT) {
		if ((*tmp) == L->ptr) {
			cout << "=>";
		}
		else {
			cout << "  ";
		}
		cout << "|";
		cout << setw(40) << (*tmp)->FIO << "|";
		cout << setw(14) << (*tmp)->phone << "|";
		cout << setw(20) << (*tmp)->city << "|";
		cout << setw(20) << (*tmp)->street << "|";
		cout << setw(10) << (*tmp)->house << "|";
		cout << setw(14) << (*tmp)->flat << "|";
		if ((*tmp) == L->ptr) {
			cout << "<=";
		}
		else {
			cout << "  ";
		}
		cout << endl;
		cout << "  +----------------------------------------+--------------+--------------------+--------------------+----------+--------------+" << endl;
		(*tmp) = (*tmp)->next_link;
		cntElement++;
	}
}

void showHeader()
{
	showBorder();
	cout << "  |         Фамииля Имя Отчество           |Номер телефона|       Город        |       Улица        |Номер дома|Номер квартиры|" << endl;
	showBorder();
}

void showBorder()
{
	cout << "  +----------------------------------------+--------------+--------------------+--------------------+----------+--------------+" << endl;
}

void showFooter(int currentPage, int maxPage)
{
	cout << "  |";
	cout << setw(61) << currentPage;
	cout << "/";
	cout << setw(3) << maxPage;
	cout << setw(59) << "|" << endl;
	showBorder();
}

int keyRegister(doubly_linked_list* L, Contact** tmp, Contact** head, int& currentPage, const int TABLE_ELEMENT)
{
	int functionKey = 0;

	do {
		functionKey = _getch();
		if (functionKey == 224) { // навигация
			functionKey = _getch();
			if (functionKey == 72 && L->ptr != (*head)) { // вверх
				L->ptr = L->ptr->prev_link;
				(*tmp) = (*head);
				break;
			}
			else if (functionKey == 80 && L->ptr != (*tmp)->prev_link) { // Вниз
				L->ptr = L->ptr->next_link;
				(*tmp) = (*head);
				break;
			}
			else if (functionKey == 75 && (*head)->prev_link != L->start) { // Лево
				// предыдущая страница
				for (int i = 0; i < TABLE_ELEMENT; i++) {
					(*head) = (*head)->prev_link;
				}
				(*tmp) = (*head);
				L->ptr = (*head);
				currentPage--;
				break;
			}
			else if (functionKey == 77 && (*tmp) != L->end) { // вправо
				(*head) = (*tmp);
				(*tmp) = (*head);
				L->ptr = (*head);
				currentPage++;
				break;
			}
		}

		if (functionKey == 8) { // backspace
			if (L->start->next_link == (*head)) {

				if (L->ptr == (*head)) {
					if ((*head)->next_link == L->end) {
						(*head) = L->end;
						deleteItem(L);
					}
					else {
						(*head) = (*head)->next_link;
						deleteItem(L);
					}
				}
				else if (L->ptr->next_link == L->end) {
					deleteItem(L);
				}
				else {
					deleteItem(L);
				}

			}
			else {

				if (L->ptr == (*head)) {
					if ((*head)->next_link == L->end) {
						for (int i = 0; i < TABLE_ELEMENT; i++) {
							(*head) = (*head)->prev_link;
						}
						deleteItem(L);
						L->ptr = (*head);
						currentPage--;
					}
					else {
						(*head) = (*head)->next_link;
						deleteItem(L);
						L->ptr = (*head);
					}
				}
				else if (L->ptr->next_link == L->end) {
					deleteItem(L);
				}
				else {
					deleteItem(L);
				}

			}

			(*tmp) = (*head);
			break;
		}

		if (functionKey == 13) { // enter
			system("cls");
			cout << "Нажмите ВВЕРХ для вставки элемента перед выбранным." << endl;
			cout << "Нажмите ВПРАВО для редактирования выбранного элемента." << endl;
			cout << "Нажмите ВНИЗ для вставки элемента после выбранного." << endl;
			functionKey = _getch();
			if (functionKey == 224) {
				functionKey = _getch();
				if (functionKey == 72) { // вверх
					add_prev(L);
					if (L->ptr == (*head)) {
						(*head) = (*head)->prev_link;
					}
					if (L->ptr->next_link == (*tmp)) {
						(*head) = L->ptr;
					}
					(*tmp) = (*head);
					break;
				}
				else if (functionKey == 80) { // Вниз
					add_next(L);
					(*tmp) = (*head);
					break;
				}
				else if (functionKey == 77) { // вправо
					(*tmp) = (*head);
					edit(L->ptr);
					break;
				}
				else {
					(*tmp) = (*head);

					return 1;
				}
			}
			else {
				(*tmp) = (*head);
				return 1;
			}
		}

		if (functionKey == 27) { //esc
			system("cls");
			return 0;
		}
	} while (true);
	(*tmp) = (*head);
	return 1;
}

void selectionTable(doubly_linked_list* L)
{
	L->ptr = L->start->next_link;

	Contact* tmp = L->start->next_link;
	Contact* head = L->start->next_link;

	const int TABLE_ELEMENT = 14;
	int currentPage = 1;
	int maxPage;
	do {
		if (isEmptyList(L)) {
			cout << "Список пуст." << endl;
			_getch();
			system("cls");
			return;
		}

		maxPage = ceil((double)numElements(L) / TABLE_ELEMENT);

		selectionTitle();
		showHeader();
		showTable(L, &tmp, TABLE_ELEMENT);
		showFooter(currentPage, maxPage);

		if (simplifiedKeyRegister(L, &tmp, &head, currentPage, TABLE_ELEMENT) == 0) {
			return;
		}

		system("cls");
	} while (true);
}

int simplifiedKeyRegister(doubly_linked_list* L, Contact** tmp, Contact** head, int& currentPage, const int TABLE_ELEMENT)
{
	int functionKey = 0;

	do {
		functionKey = _getch();
		if (functionKey == 224) {
			functionKey = _getch();
			if (functionKey == 72 && L->ptr != (*head)) { // вверх
				L->ptr = L->ptr->prev_link;
				(*tmp) = (*head);
				break;
			}
			else if (functionKey == 80 && L->ptr != (*tmp)->prev_link) { // Вниз
				L->ptr = L->ptr->next_link;
				(*tmp) = (*head);
				break;
			}
			else if (functionKey == 75 && (*head)->prev_link != L->start) { // Лево
				// предыдущая страница
				for (int i = 0; i < TABLE_ELEMENT; i++) {
					(*head) = (*head)->prev_link;
				}
				(*tmp) = (*head);
				L->ptr = (*head);
				currentPage--;
				break;
			}
			else if (functionKey == 77 && (*tmp) != L->end) { // вправо
				(*head) = (*tmp);
				(*tmp) = (*head);
				L->ptr = (*head);
				currentPage++;
				break;
			}
		}

		if (functionKey == 27) { //esc
			system("cls");
			return 0;
		}
	} while (true);
	return 1;
}