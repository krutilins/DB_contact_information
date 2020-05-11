#pragma once
#ifndef _SORT_H_
#define _SORT_H_
#include "Header.h"

/*
Сортировка по возрастанию
1 - фио
2 - фамилия
3 - имя
4 - отчество
5 - телефон
6 - город
7 - улица
8 - дом
9 - квартира

*/
void Ascending(doubly_linked_list* L, int field);

/*
Сортировка по убыванию
1 - фио
2 - фамилия
3 - имя
4 - отчество
5 - телефон
6 - город
7 - улица
8 - дом
9 - квартира

*/
void Descending(doubly_linked_list* L, int field);

#endif // !_SORT_H_