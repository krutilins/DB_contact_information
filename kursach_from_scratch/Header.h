#pragma once
#ifndef _HEADER_H_
#define _HEADER_H_

#define _CRT_SECURE_NO_WARNINGS

// встроенные

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

/* Инициализация списка */
void initialize(doubly_linked_list* L);
/* включение элемента до рабочего указателя */
void prevPut(doubly_linked_list* L, Contact* elem);
/* включение элемента после рабочего указателя */
void postPut(doubly_linked_list* L, Contact* elem);
/* Исключение элемента до рабочего указателя */
void prevGet(doubly_linked_list* L, Contact* elem);
/* Исключение элемента после рабочего указателя */
void postGet(doubly_linked_list* L, Contact* elem);
/* Установка рабочего указателя в начало списка */
void beginPtr(doubly_linked_list* L);
/* Установка рабочего указателя в конец списка */
void endPtr(doubly_linked_list* L);
/* Сдвиг рабочего указателя назад */
void movePtrLeft(doubly_linked_list* L);
/* Сдвиг рабочего указателя вперед */
void movePtrRight(doubly_linked_list* L);
/* Очистка списка */
void clearList(doubly_linked_list* L);
/* Предикат: является ли список пустым */
int isEmptyList(doubly_linked_list* L);
/* Печать все элементов списка с начала до конца */
void printList(doubly_linked_list* L);

#endif // _HEADER_H_