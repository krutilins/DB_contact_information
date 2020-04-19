#pragma once
#ifndef _FILE_H_
#define _FILE_H_
#include "Header.h"

void upload_file(doubly_linked_list* L);
int load_DB(doubly_linked_list* L);
bool f_check_FIO(char(&str)[100]);
bool f_check_phone(char(&str)[100]);
bool f_check_city(char(&str)[100]);
bool f_check_street(char(&str)[100]);
bool f_check_house(char(&str)[100]);
bool f_check_flat(char(&str)[100]);

#endif // !_FILE_H_
