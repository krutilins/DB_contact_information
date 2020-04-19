#include "Header.h"

/* Инициализация списка */
void initialize(doubly_linked_list* L) {
	// выделение под левый фиктивный элемент
	L->start = (Contact*)malloc(sizeof(Contact));
	// если памяти не хватило
	if (!L->start) {
		cout << "Не хватает памяти для инициализации двусвязного списка.";
		cout << "\a";
		cout << endl;
		system("pause");
		return;
	}
	// выделение памяти для правого фиктивного элемента
	L->end = (Contact*)malloc(sizeof(Contact));
	// если памяти не хватило
	if (!L->end) {
		cout << "Не хватает памяти для инициализации двусвязного списка.";
		cout << "\a";
		cout << endl;
		free((void*)L->start); // удаление левого фиктивного элемента
		L->start = NULL;
		system("pause");
		return;
	}
	// элемент, следующий за левым фиктивным - правый фиктивный элемент
	L->start->next_link = L->end;
	// элемента, предшествующего левому фиктивному элементу нет
	L->start->prev_link = NULL;
	// элемента, следующего за правым фиктивным элементом нет
	L->end->next_link = NULL;
	// элемент, предшествующий правому фиктивному - левый фиктивный элемент
	L->end->prev_link = L->start;
	L->ptr = L->start;
}

/* включение элемента до рабочего указателя */
void prevPut(doubly_linked_list* L, Contact* elem) {
	// если рабочий указатель установлен на начало
	if (L->ptr == L->start) {
		cout << "Ошибка. Невозможна вставка до рабочего указателя." << endl;
		cout << "Рабочий указатель на фиктивном начале." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	// выделение памяти под новый элемент
	Contact* pntr = (Contact*)malloc(sizeof(Contact));
	// если памяти не достаточно
	if (!pntr) {
		cout << "Невозможно добавить элемент. Не достаточно памяти." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	// Запись информации в новый элемент
	strcpy_s(pntr->FIO, elem->FIO);
	strcpy_s(pntr->phone, elem->phone);
	strcpy_s(pntr->city, elem->city);
	strcpy_s(pntr->street, elem->street);
	pntr->house = elem->house;
	pntr->flat = elem->flat;
	// новый элемент указывает слева на предыдущий
	pntr->prev_link = L->ptr->prev_link;
	// новый элемент указывает справа на текующий
	pntr->next_link = L->ptr;
	// предыдущий элемент указывает справа на новый
	L->ptr->prev_link->next_link = pntr;
	// текущий элемент указывает слева на новый
	L->ptr->prev_link = pntr;
}

/* включение элемента после рабочего указателя */
void postPut(doubly_linked_list* L, Contact* elem) {
	// если рабочий указатель установлен на начало
	if (L->ptr == L->end) {
		cout << "Ошибка. Невозможна вставка после рабочего указателя." << endl;
		cout << "Рабочий указатель на фиктивном конце." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	// выделение памяти под новый элемент
	Contact* pntr = (Contact*)malloc(sizeof(Contact));
	// если памяти не достаточно
	if (!pntr) {
		cout << "Невозможно добавить элемент. Не достаточно памяти." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	// Запись информации в новый элемент
	strcpy_s(pntr->FIO, elem->FIO);
	strcpy_s(pntr->phone, elem->phone);
	strcpy_s(pntr->city, elem->city);
	strcpy_s(pntr->street, elem->street);
	pntr->house = elem->house;
	pntr->flat = elem->flat;
	// новый элемент указывает справа на следующий
	pntr->next_link = L->ptr->next_link;
	// новый элемент указывает слева на текущий
	pntr->prev_link = L->ptr;
	// следующий элемент указывает слева на новый
	L->ptr->next_link->prev_link = pntr;
	// текующий элемент указывает справа на новый
	L->ptr->next_link = pntr;
}

/* Исключение элемента до рабочего указателя */
void prevGet(doubly_linked_list* L, Contact* elem) {
	// если список пуст
	if (isEmptyList(L)) return;
	// если рабочий указатель указывает на начало (левый фиктивный элемент)
	if (L->ptr == L->start) {
		cout << "Ошибка. Невозможна удаление до рабочего указателя." << endl;
		cout << "Рабочий указатель на фиктивном начале." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	// запись информации в переменную 
	strcpy_s(elem->FIO, L->ptr->prev_link->FIO);
	strcpy_s(elem->phone, L->ptr->prev_link->phone);
	strcpy_s(elem->city, L->ptr->prev_link->city);
	strcpy_s(elem->street, L->ptr->prev_link->street);
	elem->house = L->ptr->prev_link->house;
	elem->flat = L->ptr->prev_link->flat;
	// временный элемент, указывающий на удаляемый
	Contact* pntr = L->ptr->prev_link;
	// текущий элемент указывает на предшествующий удаляемому
	L->ptr->prev_link = pntr->prev_link;
	// предшествующий удаляемому элемент указывает на текущий
	pntr->prev_link->next_link = L->ptr;
	// удаление временного элемента
	free((void*)pntr);
}

/* Исключение элемента после рабочего указателя */
void postGet(doubly_linked_list* L, Contact* elem) {
	// если список пуст
	if (isEmptyList(L)) return;
	// если рабочий указатель указывает на конец (правый фиктивный элемент)
	if (L->ptr == L->end) {
		cout << "Ошибка. Невозможна удаление после рабочего указателя." << endl;
		cout << "Рабочий указатель на фиктивном конце." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	// запись информации в переменную 
	strcpy_s(elem->FIO, L->ptr->next_link->FIO);
	strcpy_s(elem->phone, L->ptr->next_link->phone);
	strcpy_s(elem->city, L->ptr->next_link->city);
	strcpy_s(elem->street, L->ptr->next_link->street);
	elem->house = L->ptr->next_link->house;
	elem->flat = L->ptr->next_link->flat;
	// временный элемент, указывающий на удаляемый
	Contact* pntr = L->ptr->next_link;
	// текущий элемент указывает на предшествующий удаляемому
	L->ptr->next_link = pntr->next_link;
	// предшествующий удаляемому элемент указывает на текущий
	pntr->next_link->prev_link = L->ptr;
	// удаление временного элемента
	free((void*)pntr);
}

/* Установка рабочего указателя в начало списка */
void beginPtr(doubly_linked_list* L) {
	while (L->ptr != L->start) movePtrLeft(L);
}

/* Установка рабочего указателя в конец списка */
void endPtr(doubly_linked_list* L) {
	while (L->ptr != L->end) movePtrRight(L);
}

/* Сдвиг рабочего указателя назад */
void movePtrLeft(doubly_linked_list* L) {
	// если рабочий указатель указывает на начало
	if (L->ptr == L->start) {
		return;
	}
	L->ptr = L->ptr->prev_link; // иначе смещение указателя
}

/* Сдвиг рабочего указателя вперед */
void movePtrRight(doubly_linked_list* L) {
	// если рабочий указатель указывает на конец
	if (L->ptr == L->end) {
		return;
	}
	L->ptr = L->ptr->next_link; // иначе смещение указателя
}

/* Удаление списка */
void clearList(doubly_linked_list* L) {
	beginPtr(L); // установка рабочего указателя в начало
	Contact temp; // создание временной переменной
	while (!isEmptyList(L)) {	// пока список не пуст
		postGet(L, &temp);						// извлечь элемент
	}
	free((void*)L->end);  // удалить фиктивный элемент
	// L->ptr ссылается на L->start, поэтому присваиваем ему значение NULL
	L->ptr = NULL;
	free((void*)L->start);
	L->end = NULL;
	L->start = NULL;
}

/* Предикат: является ли список пустым */
int isEmptyList(doubly_linked_list* L) {
	if (L->start->next_link == L->end) {
		return 1;
	}
	return 0;
}

/* Печать все элементов списка с начала до конца */
void printList(doubly_linked_list* L) {
	// дополнительный элемент для прохода от начала до конца списка
	Contact* tmp;

	tmp = L->start->next_link; // ссылка на первый элемент

	// пока не конец списка
	while (tmp != L->end) {
		cout << tmp->FIO << endl;
		cout << tmp->phone << endl;
		cout << tmp->city << endl;
		cout << tmp->street << endl;
		cout << tmp->house << endl;
		cout << tmp->flat << endl;
		cout << endl;
		tmp = tmp->next_link;
	}
}

/* Счетчик длинны списка */
int numElements(doubly_linked_list* L) {
	// дополнительный элемент для прохода от начала до конца списка
	Contact* tmp;
	tmp = L->start->next_link; // ссылка на первый элемент
	int itr = 0;
	// пока не конец списка
	while (tmp != L->end) {
		itr++;
		tmp = tmp->next_link;
	}
	return itr;
}

/* заполнение массива */
void fillArray(Contact** tempArray, doubly_linked_list* L)
{
	// дополнительный элемент для прохода от начала до конца списка
	Contact* tmp;
	tmp = L->start->next_link; // ссылка на первый элемент

	// пока не конец списка
	for (int i = 0; tmp != L->end; i++) {
		resize_z(tempArray, i + 1);
		strcpy_s((*tempArray)[i].FIO, tmp->FIO);
		strcpy_s((*tempArray)[i].phone, tmp->phone);
		strcpy_s((*tempArray)[i].city, tmp->city);
		strcpy_s((*tempArray)[i].street, tmp->street);
		(*tempArray)[i].house = tmp->house;
		(*tempArray)[i].flat = tmp->flat;
		tmp = tmp->next_link;
	}
}

/* заполнение списка */
void fillList(doubly_linked_list* L, Contact* tempArray, int sizeArray)
{
	// временный элемент
	Contact tempElement;
	// пока не конец списка
	for (int i = 0; i < sizeArray; i++) {
		strcpy_s(tempElement.FIO, tempArray[i].FIO);
		strcpy_s(tempElement.phone, tempArray[i].phone);
		strcpy_s(tempElement.city, tempArray[i].city);
		strcpy_s(tempElement.street, tempArray[i].street);
		tempElement.house = tempArray[i].house;
		tempElement.flat = tempArray[i].flat;

		// перемещение указателя на фиктивный конец
		endPtr(L);
		// вставка в конец списка
		prevPut(L, &tempElement);
	}
}

/* выделение памяти под массив */
void resize_z(Contact** pointer, int newsize) {
	Contact* buff = (Contact*)realloc(*pointer, sizeof(Contact) * newsize);
	if (buff == NULL) {
		cout << "Не удалось выделить память!" << endl;
		exit(-1);
	}
	*pointer = buff;
}

/* очищение памяти выделенного массива*/
void clear_z(Contact** pointer) {
	Contact* buff = (Contact*)realloc(*pointer, 0);
	if (buff != NULL) {
		cout << "Не получилось очистить массив." << endl;
		exit(-1);
	}
	*pointer = buff;
}