#pragma once
#ifndef _SEARCH_H_
#define _SEARCH_H_
#include "Header.h"
#include "workWithTable.h"

void searchFIO(doubly_linked_list* L); // фио

void searchFirstName(doubly_linked_list* L); // имя

void searchSecondName(doubly_linked_list* L); // фамилия

void searchMiddleName(doubly_linked_list* L); // отчество

void searchPhone(doubly_linked_list* L); // телефон

void searchCity(doubly_linked_list* L); // город

void searchStreet(doubly_linked_list* L); // улица

void searchHouse(doubly_linked_list* L); // дом

void searchFlat(doubly_linked_list* L); // квартира

bool s_check_FIO(char(&str)[100]);
bool s_check_phone(char(&str)[100]);
bool s_check_city(char(&str)[100]);
bool s_check_street(char(&str)[100]);
bool s_check_house(char(&str)[100]);
bool s_check_flat(char(&str)[100]);

#endif // !_SEARCH_H_