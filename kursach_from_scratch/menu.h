#pragma once
#ifndef _MENU_H_
#define _MENU_H_
#include "Header.h"
#include "Input.h"
#include "File.h"
#include "workWithTable.h"
#include "Search.h"
#include "Sort.h"

void mainMenu(doubly_linked_list* database);
void showMainMenu(int pos);
int choiceMainMenu();

void sortMenu(doubly_linked_list* database);
void showSortMenu(int pos);
int choiceSortMenu();

void showOderMenu(int pos);
int choiceOderMenu();

void searchMenu(doubly_linked_list* database);
void showSearchMenu(int pos);
int choiceSearchMenu();

void showPartFIOMenu(int pos);
int choicePartFIOMenu();

#endif // !_MENU_H_
