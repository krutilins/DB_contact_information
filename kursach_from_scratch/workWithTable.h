#pragma once
#ifndef _WORKWITHTABLE_H_
#define _WORKWITHTABLE_H_
#include "Header.h"
#include "Input.h"
#include "edit.h"

void table(doubly_linked_list* L);
void printTable();
void showHeader();
void showBorder();
void showFooter(int currentPage, int maxPage);

#endif // !_WORKWITHTABLE_H_
