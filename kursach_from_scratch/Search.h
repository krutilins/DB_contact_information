#pragma once
#ifndef _SEARCH_H_
#define _SEARCH_H_
#include "Header.h"
#include "workWithTable.h"
#include "checkInput.h"

/*
�����
1 - ���
2 - �������
3 - ���
4 - ��������
5 - �������
6 - �����
7 - �����
8 - ���
9 - ��������
*/
void search(doubly_linked_list* L, int field);

void makeRequest(char(&str)[100], int field);

#endif // !_SEARCH_H_