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

/**
1 - главное меню
2 - меню работы с файлом
3 - меню полей
4 - порядок сортировки
5 - выбор вставки
*/
int choiceMenu(int currentMenu);

void mainMenu(doubly_linked_list* database);
void sortMenu(doubly_linked_list* database);
void searchMenu(doubly_linked_list* database);
void filtrationMenu(doubly_linked_list* database);

void showMainMenu(int position);
void showFileMenu(int position);
void showFieldMenu(int position);
void showOderMenu(int position);
void showInserMenu(int currentPosition);

#endif // !_MENU_H_