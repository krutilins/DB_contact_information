#pragma once
#ifndef _FILTRATION_H_
#define _FILTRATION_H_
#include "Header.h"
#include "workWithTable.h"

/* ���������� �� ��� */
void filtrFIO(doubly_linked_list* L);

/* ���������� �� �����*/
void filtrFirstName(doubly_linked_list* L); 

/* ���������� �� ������� */
void filtrSecondName(doubly_linked_list* L);

/* ���������� �� �������� */
void filtrMiddleName(doubly_linked_list* L);

/* ���������� �� �������� */
void filtrPhone(doubly_linked_list* L);

/* ���������� �� ������ */
void filtrCity(doubly_linked_list* L);

/* ���������� �� ����� */
void filtrStreet(doubly_linked_list* L);

/* ���������� �� ���� */
void filtrHouse(doubly_linked_list* L);

/* ���������� �� �������� */
void filtrFlat(doubly_linked_list* L); // ��������

#endif // !_FILTRATION_H_
