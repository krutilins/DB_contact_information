#pragma once
#ifndef _FILE_H_
#define _FILE_H_
#include "Header.h"
#include "checkInput.h"

void upload_file(doubly_linked_list* L);
int load_DB(doubly_linked_list* L);
void errorMessage(char(&str)[100], int lineNumber);

#endif // !_FILE_H_
