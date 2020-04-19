#pragma once
#ifndef _INPUT_H
#define _INPUT_H
#include "Header.h"

void add_information(doubly_linked_list* database);

bool check_FIO(char(&str)[100]);

bool check_phone(char(&str)[100]);

bool check_city(char(&str)[100]);

bool check_street(char(&str)[100]);

bool check_house(char(&str)[100]);

bool check_flat(char(&str)[100]);

#endif // !_INPUT_H_
