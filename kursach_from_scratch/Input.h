#pragma once
#ifndef _INPUT_H
#define _INPUT_H
#include "Header.h"

void add_information(doubly_linked_list* database);

char* get_FIO();
bool check_FIO(char str[]);

char* get_phone();
bool check_phone(char str[]);

char* get_city();
bool check_city(char str[]);

char* get_street();
bool check_street(char str[]);

int get_house();
bool check_house(char str[]);

int get_flat();
bool check_flat(char str[]);

#endif // !_INPUT_H_
