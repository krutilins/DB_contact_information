#include "Header.h"

/* Инициализация списка */
void initialize(doubly_linked_list* L) {
	L->start = (Contact*)malloc(sizeof(Contact));
	if (!L->start) {
		cout << "Не хватает памяти для инициализации двусвязного списка.";
		cout << "\a";
		cout << endl;
		system("pause");
		return;
	}
	L->end = (Contact*)malloc(sizeof(Contact));
	if (!L->end) {
		cout << "Не хватает памяти для инициализации двусвязного списка.";
		cout << "\a";
		cout << endl;
		free((void*)L->start);
		L->start = NULL;
		system("pause");
		return;
	}
	L->start->next_link = L->end;
	L->start->prev_link = NULL;
	L->end->next_link = NULL;
	L->end->prev_link = L->start;
	L->ptr = L->start;
}

/* включение элемента до рабочего указателя */
void prevPut(doubly_linked_list* L, Contact* elem) {
	if (L->ptr == L->start) {
		cout << "Ошибка. Невозможна вставка до рабочего указателя." << endl;
		cout << "Рабочий указатель на фиктивном начале." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	Contact* pntr = (Contact*)malloc(sizeof(Contact));
	if (!pntr) {
		cout << "Невозможно добавить элемент. Не достаточно памяти." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	strcpy_s(pntr->FIO, elem->FIO);
	strcpy_s(pntr->phone, elem->phone);
	strcpy_s(pntr->city, elem->city);
	strcpy_s(pntr->street, elem->street);
	pntr->house = elem->house;
	pntr->flat = elem->flat;
	pntr->prev_link = L->ptr->prev_link;
	pntr->next_link = L->ptr;
	L->ptr->prev_link->next_link = pntr;
	L->ptr->prev_link = pntr;
}

/* включение элемента после рабочего указателя */
void postPut(doubly_linked_list* L, Contact* elem) {
	if (L->ptr == L->end) {
		cout << "Ошибка. Невозможна вставка после рабочего указателя." << endl;
		cout << "Рабочий указатель на фиктивном конце." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	Contact* pntr = (Contact*)malloc(sizeof(Contact));
	if (!pntr) {
		cout << "Невозможно добавить элемент. Не достаточно памяти." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	strcpy_s(pntr->FIO, elem->FIO);
	strcpy_s(pntr->phone, elem->phone);
	strcpy_s(pntr->city, elem->city);
	strcpy_s(pntr->street, elem->street);
	pntr->house = elem->house;
	pntr->flat = elem->flat;
	pntr->next_link = L->ptr->next_link;
	pntr->prev_link = L->ptr;
	L->ptr->next_link->prev_link = pntr;
	L->ptr->next_link = pntr;
}

/* Исключение элемента до рабочего указателя */
void prevGet(doubly_linked_list* L, Contact* elem) 
{
	if (isEmptyList(L)) return;
	if (L->ptr == L->start) {
		cout << "Ошибка. Невозможна удаление до рабочего указателя." << endl;
		cout << "Рабочий указатель на фиктивном начале." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	strcpy_s(elem->FIO, L->ptr->prev_link->FIO);
	strcpy_s(elem->phone, L->ptr->prev_link->phone);
	strcpy_s(elem->city, L->ptr->prev_link->city);
	strcpy_s(elem->street, L->ptr->prev_link->street);
	elem->house = L->ptr->prev_link->house;
	elem->flat = L->ptr->prev_link->flat;
	Contact* pntr = L->ptr->prev_link;
	L->ptr->prev_link = pntr->prev_link;
	pntr->prev_link->next_link = L->ptr;
	free((void*)pntr);
}

/* Исключение элемента после рабочего указателя */
void postGet(doubly_linked_list* L, Contact* elem) {
	// если список пуст
	if (isEmptyList(L)) return;
	if (L->ptr == L->end) {
		cout << "Ошибка. Невозможна удаление после рабочего указателя." << endl;
		cout << "Рабочий указатель на фиктивном конце." << endl;
		cout << "\a";
		system("pause");
		return;
	}
	strcpy_s(elem->FIO, L->ptr->next_link->FIO);
	strcpy_s(elem->phone, L->ptr->next_link->phone);
	strcpy_s(elem->city, L->ptr->next_link->city);
	strcpy_s(elem->street, L->ptr->next_link->street);
	elem->house = L->ptr->next_link->house;
	elem->flat = L->ptr->next_link->flat;
	Contact* pntr = L->ptr->next_link;
	L->ptr->next_link = pntr->next_link;
	pntr->next_link->prev_link = L->ptr;
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
	if (L->ptr == L->start) {
		return;
	}
	L->ptr = L->ptr->prev_link;
}

/* Сдвиг рабочего указателя вперед */
void movePtrRight(doubly_linked_list* L) {
	if (L->ptr == L->end) {
		return;
	}
	L->ptr = L->ptr->next_link; 
}

/* Удаление списка */
void clearList(doubly_linked_list* L) {
	beginPtr(L); 
	Contact temp;
	while (!isEmptyList(L)) {
		postGet(L, &temp);
	}
	free((void*)L->end);
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

/* Печать всех элементов списка с начала до конца */
void printList(doubly_linked_list* L) {
	Contact* tmp;

	tmp = L->start->next_link;

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
	Contact* tmp;
	tmp = L->start->next_link;
	int itr = 0;
	while (tmp != L->end) {
		itr++;
		tmp = tmp->next_link;
	}
	return itr;
}

/* удалить рабочий элемент */
void deleteItem(doubly_linked_list* L)
{
	if (L->ptr == L->start || L->ptr == L->end) {
		cout << "Удаление фиктивного элемента невозможно." << endl;
		return;
	}
	Contact* pntr = L->ptr;
	if (L->end->prev_link == L->ptr) {
		L->ptr = L->ptr->prev_link;
	}
	else {
		L->ptr = L->ptr->next_link;
	}
	pntr->prev_link->next_link = pntr->next_link;
	pntr->next_link->prev_link = pntr->prev_link;
	free((void*)pntr);
	pntr = NULL;
}

/* заполнение массива */
void fillArray(Contact** tempArray, doubly_linked_list* L)
{
	Contact* tmp;
	tmp = L->start->next_link;

	for (int i = 0; tmp != L->end; i++) {
		resizeArray(tempArray, i + 1);
		strcpy_s((*tempArray)[i].FIO, tmp->FIO);
		strcpy_s((*tempArray)[i].phone, tmp->phone);
		strcpy_s((*tempArray)[i].city, tmp->city);
		strcpy_s((*tempArray)[i].street, tmp->street);
		(*tempArray)[i].house = tmp->house;
		(*tempArray)[i].flat = tmp->flat;
		tmp = tmp->next_link;
	}
}

/* заполнение списка из массива */
void fillListFromArray(doubly_linked_list* L, Contact* tempArray, int sizeArray)
{
	Contact tempElement;
	for (int i = 0; i < sizeArray; i++) {
		strcpy_s(tempElement.FIO, tempArray[i].FIO);
		strcpy_s(tempElement.phone, tempArray[i].phone);
		strcpy_s(tempElement.city, tempArray[i].city);
		strcpy_s(tempElement.street, tempArray[i].street);
		tempElement.house = tempArray[i].house;
		tempElement.flat = tempArray[i].flat;

		endPtr(L);
		prevPut(L, &tempElement);
	}
}

/* выделение памяти под массив */
void resizeArray(Contact** pointer, int newsize) {
	Contact* buff = (Contact*)realloc(*pointer, sizeof(Contact) * newsize);
	if (buff == NULL) {
		cout << "Не удалось выделить память!" << endl;
		exit(-1);
	}
	*pointer = buff;
}

/* очищение памяти выделенного массива*/
void clearArray(Contact** pointer) {
	Contact* buff = (Contact*)realloc(*pointer, 0);
	if (buff != NULL) {
		cout << "Не получилось очистить массив." << endl;
		exit(-1);
	}
	*pointer = buff;
}

/* обмен элементов массива */
void swapArrayElement(Contact& first, Contact& second)
{
	Contact tempElement = first;
	first = second;
	second = tempElement;
}

