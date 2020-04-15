#pragma once
#ifndef _FILE_H_
#define _FILE_H_
#include "Header.h"

void upload_file(doubly_linked_list* L, char* file);
int load_DB(doubly_linked_list* L, char* file);
bool f_check_FIO(char str[]);
bool f_check_phone(char str[]);
bool f_check_city(char str[]);
bool f_check_street(char str[]);
bool f_check_house(char str[]);
bool f_check_flat(char str[]);

#endif // !_FILE_H_
