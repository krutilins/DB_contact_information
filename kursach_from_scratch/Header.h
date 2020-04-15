#pragma once
#ifndef _HEADER_H_
#define _HEADER_H_

#define _CRT_SECURE_NO_WARNINGS

// ����������

#include <iostream>
#include <cstdlib>
#include <clocale>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <fstream>

using namespace std;

struct Contact {
	char FIO[40];
	char phone[13];
	char city[20];
	char street[20];
	int house;
	int flat;
	struct Contact* next_link;
	struct Contact* prev_link;
};

struct doubly_linked_list {
	Contact* start;
	Contact* end;
	Contact* ptr;
};

/* ������������� ������ */
void initialize(doubly_linked_list* L);
/* ��������� �������� �� �������� ��������� */
void prevPut(doubly_linked_list* L, Contact* elem);
/* ��������� �������� ����� �������� ��������� */
void postPut(doubly_linked_list* L, Contact* elem);
/* ���������� �������� �� �������� ��������� */
void prevGet(doubly_linked_list* L, Contact* elem);
/* ���������� �������� ����� �������� ��������� */
void postGet(doubly_linked_list* L, Contact* elem);
/* ��������� �������� ��������� � ������ ������ */
void beginPtr(doubly_linked_list* L);
/* ��������� �������� ��������� � ����� ������ */
void endPtr(doubly_linked_list* L);
/* ����� �������� ��������� ����� */
void movePtrLeft(doubly_linked_list* L);
/* ����� �������� ��������� ������ */
void movePtrRight(doubly_linked_list* L);
/* ������� ������ */
void clearList(doubly_linked_list* L);
/* ��������: �������� �� ������ ������ */
int isEmptyList(doubly_linked_list* L);
/* ������ ��� ��������� ������ � ������ �� ����� */
void printList(doubly_linked_list* L);

#endif // _HEADER_H_