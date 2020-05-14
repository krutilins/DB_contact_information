#pragma once
#ifndef _WORKWITHTABLE_H_
#define _WORKWITHTABLE_H_
#include "Header.h"
#include "Input.h"
#include "edit.h"

void table(doubly_linked_list* L);

void tableTitle();
void selectionTitle();

void showTable(doubly_linked_list* L, Contact** tmp, const int TABLE_ELEMENT);
void showHeader();
void showBorder();
void showFooter(int currentPage, int maxPage);
int keyRegister(doubly_linked_list* L, Contact** tmp, Contact** head, int& currentPage, const int TABLE_ELEMENT);

void selectionTable(doubly_linked_list* L);
int simplifiedKeyRegister(doubly_linked_list* L, Contact** tmp, Contact** head, int& currentPage, const int TABLE_ELEMENT);

#endif // !_WORKWITHTABLE_H_
