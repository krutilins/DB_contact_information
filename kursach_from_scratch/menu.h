#pragma once
#ifndef _MENU_H_
#define _MENU_H_
#include "Header.h"
#include "Input.h"
#include "File.h"
#include "workWithTable.h"
#include "Search.h"
#include "Sort.h"
#include "Filtration.h"

int choiceMenu(int currentMenu);

void mainMenu(doubly_linked_list* database);
void showMainMenu(int pos);

void sortMenu(doubly_linked_list* database);
void showSortMenu(int pos);

void showOderMenu(int pos);

void searchMenu(doubly_linked_list* database);
void showSearchMenu(int pos);

void showPartFIOMenu(int pos);

void filtrationMenu(doubly_linked_list* database);
void showFiltrationMenu(int pos);


#endif // !_MENU_H_
