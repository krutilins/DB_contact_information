#pragma once
#ifndef _SORT_H_
#define _SORT_H_
#include "Header.h"

void sort();
void Sort_Ascending(int field, struct Clients* array, int size);
void Sort_Descending(int field, struct Clients* array, int size);

#endif // !_SORT_H_