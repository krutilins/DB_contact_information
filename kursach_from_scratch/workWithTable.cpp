#include "workWithTable.h"

void table(doubly_linked_list* L)
{
    // указатель на определенный элемент в таблице
	Contact* pointer = L->start->next_link; // ссылка на первый элемент в таблице
	// дополнительный элемент для прохода от начала до конца списка
	Contact* tmp =L->start->next_link; // ссылка на первый элемент
    int functionKey = 0;
    do {

        cout << "  +----------------------------------------+--------------+--------------------+--------------------+------------+----------------+" << endl;
        cout << "  |         Фамииля Имя Отчество           |Номер телефона|       Город        |       Улица        | Номер дома | Номер квартиры |" << endl;
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
            if (functionKey == 80) { // Вниз
                pointer = pointer->next_link;
                tmp = L->start->next_link;
            }
            else if (functionKey == 75) { // Лево
                cout << "Лево" << endl;
            }
            else if (functionKey == 72) { // вверх
                pointer = pointer->prev_link;
                tmp = L->start->next_link;
            }
            else if (functionKey == 77) { // вправо
                cout << "Вправо" << endl;
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
