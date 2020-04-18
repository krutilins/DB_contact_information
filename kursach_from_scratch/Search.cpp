#include "Search.h"

/*
	ФУНКЦИЯ ПОИСКА
		
		В КАЧЕСТВЕ АРГУМЕНТОВ ФУНКЦИЯ БУДЕТ ПРИНИМАТЬ ТОЛЬКО УКАЗАТЕЛЬ НА СПИСОК

		ДАЛЕЕ СЛЕДУЕТ ВЫБРАТЬ ПОЛЕ ПО КОТОРОМУ БУДЕТ ОСУЩЕСТВЛЯТЬСЯ ПОИСК
			(КАСТОМИЗАЦИЕЙ МОЖНО ЗАНЯТЬСЯ ПОЗЖЕ, НО ВЫГЛЯДИТЬ МЕНЮ ПОИСКА ДОЛЖНО БАЛДЕЗНО)

		ДОПУСТИМ Я ВЫБРАЛ ПОЛЕ. ЧТО ДАЛЬШЕ?

		ДАЛЬШЕ НУЖНО ВЫЗВАТЬ СООТВЕТСТВУЮЩУЮ ФУНКЦИЮ

		ПРИНЦИПЫ РАБОТЫ ПОИСКА И ФУНКЦИИ, КОТОРЫЕ Я ХОЧУ РЕАЛИЗОВАТЬ: 
		1) ВВЕСТИ ИСКОМОЕ ЗНАЧЕНИЕ
		2) С ПОМОЩЬЮ ЦИКЛА ПЕРЕБРАТЬ КАЖДЫЙ ЭЛЕМЕНТ НАШЕГО СПИСКА И ЕСЛИ НАШЕЛСЯ ПОХОЖИЙ, ТО ЗАПИСАТЬ В НОВЫЙ СПИСОК
		3) ТАК КАК В БУДУЩЕМ ВОЗМОЖНО ПРИДЕТЬСЯ РАБОТАТЬ С БОЛЬШОЙ БАЗОЙ ДАННЫХ, ТО НУЖНО РЕАЛИЗОВАТЬ СИСТЕМУ УДАЛЕНИЯ НАЙДЕННОГО ЭЛЕМЕНТА
		4) НУЖНО СОЗДАТЬ МАССИВ С УКАЗАТЕЛЯМИ НА ПОЛОЖЕНИЕ В ИСКОМОМ СПИСКЕ
		5)


		меню
		открыть базу
		работа с таблицей
		поиск
		выгрузить базу
		выход


*/

void searchFIO(doubly_linked_list* L)
{
	cout << "Введите ФИО: " << endl;
	char request[40];
	cin.getline(request, 40);
	system("cls");

	int sizeList = numElements(L);

	// создание и инициализация списка
	doubly_linked_list* tempList = (doubly_linked_list*)malloc(0);
	initialize(tempList);

	// дополнительный элемент для прохода от начала до конца списка
	Contact* tmp;
	tmp = L->start->next_link; // ссылка на первый элемент

	// временный элемент
	Contact tempElement;
	// пока не конец списка
	while (tmp != L->end) {
		if (strcmp(request, tmp->FIO) == 0) {
			strcpy(tempElement.FIO, tmp->FIO);
			strcpy(tempElement.phone, tmp->phone);
			strcpy(tempElement.city, tmp->city);
			strcpy(tempElement.street, tmp->street);
			tempElement.house = tmp->house;
			tempElement.flat = tmp->flat;
			tempElement.next_link = NULL;
			tempElement.prev_link = NULL;

			// перемещение указателя на фиктивный конец
			endPtr(tempList);
			// вставка в конец списка
			prevPut(tempList, &tempElement);
		}
		tmp = tmp->next_link;
	}
	table(tempList);
}

void searchFirstName(doubly_linked_list* L)
{
}

void searchSecondName(doubly_linked_list* L)
{
}

void searchMiddleName(doubly_linked_list* L)
{
}

void searchPhone(doubly_linked_list* L)
{
}

void searchCity(doubly_linked_list* L)
{
}

void searchStreet(doubly_linked_list* L)
{
}

void searchHouse(doubly_linked_list* L)
{
}

void searchFlat(doubly_linked_list* L)
{
}
