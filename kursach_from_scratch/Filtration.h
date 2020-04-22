#pragma once
#ifndef _FILTRATION_H_
#define _FILTRATION_H_
#include "Header.h"
#include "workWithTable.h"

/* фильтрация по фио */
void filtrFIO(doubly_linked_list* L);

/* фильтрация по имени*/
void filtrFirstName(doubly_linked_list* L); 

/* фильтрация по фамилии */
void filtrSecondName(doubly_linked_list* L);

/* фильтрация по отчеству */
void filtrMiddleName(doubly_linked_list* L);

/* фильтрация по телефону */
void filtrPhone(doubly_linked_list* L);

/* фильтрация по городу */
void filtrCity(doubly_linked_list* L);

/* фильтрация по улице */
void filtrStreet(doubly_linked_list* L);

/* фильтрация по дому */
void filtrHouse(doubly_linked_list* L);

/* фильтрация по квартире */
void filtrFlat(doubly_linked_list* L); // квартира

#endif // !_FILTRATION_H_
