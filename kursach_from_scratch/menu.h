#pragma once
#ifndef _MENU_H_
#define _MENU_H_
#include "Header.h"
#include "Input.h"
#include "Output.h"
#include "File.h"
#include "workWithTable.h"
#include "Search.h"
#include "Sort.h"

void menu(doubly_linked_list* database);

void showMainMenu(int pos);
int mainMenu();

void showSortMenu(int pos);
int sortMenu();

void showOderMenu(int pos);
int oderMenu();

void showSearchtMenu(int pos);
int searchMenu();

void showPartFIOMenu(int pos);
int partFIOMenu();

#endif // !_MENU_H_
