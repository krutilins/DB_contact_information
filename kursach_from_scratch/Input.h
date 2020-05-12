#pragma once
#ifndef _INPUT_H
#define _INPUT_H
#include "Header.h"
#include "checkInput.h"

void add_start(doubly_linked_list* L);
void add_end(doubly_linked_list* L);
void add_prev(doubly_linked_list* L);
void add_next(doubly_linked_list* L);

void fillItem(Contact* new_info);

void fillFIO(char(&str)[100]);
void fillPartFIO(char(&str)[100]);
void fillPhone(char(&str)[100]);
void fillCity(char(&str)[100]);
void fillStreet(char(&str)[100]);
void fillHouse(char(&str)[100]);
void fillFlat(char(&str)[100]);

#endif // !_INPUT_H_
