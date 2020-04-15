#include "Output.h"

void display_table(doubly_linked_list* L)
{
	// дополнительный элемент для прохода от начала до конца списка
	Contact* tmp;
	tmp = L->start->next_link; // ссылка на первый элемент
	
	cout << "+----------------------------------------+--------------+--------------------+--------------------+------------+----------------+" << endl;
	cout << "|         Фамииля Имя Отчество           |Номер телефона|       Город        |       Улица        | Номер дома | Номер квартиры |" << endl;
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
	// дополнительный элемент для рпохода от начала до конца списка
	Contact* tmp;
	tmp = L->start->next_link; // ссылка на первый элемент

	while (tmp != L->end) {
		cout << "ФИО: " << tmp->FIO << endl;
		cout << "Телефон: " << tmp->phone << endl;
		cout << "Город: " << tmp->city << endl;
		cout << "Улица: " << tmp->street << endl;
		cout << "Дом: " << tmp->house << endl;
		cout << "Квартира: " << tmp->flat << endl;
		tmp = tmp->next_link;
	}
}