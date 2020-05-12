#pragma once
#ifndef _SEARCH_H_
#define _SEARCH_H_
#include "Header.h"
#include "workWithTable.h"
#include "checkInput.h"

/*
Поиск
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
void search(doubly_linked_list* L, int field);

void makeRequest(char(&str)[100], int field);

#endif // !_SEARCH_H_