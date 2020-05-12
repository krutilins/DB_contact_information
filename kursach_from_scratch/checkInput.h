#pragma once
#ifndef _CHECKINPUT_H_
#define _CHECKINPUT_H_
#include "Header.h"

bool check_FIO(char(&str)[100]);
bool checkPartFIO(char(&str)[100]);
bool check_phone(char(&str)[100]);
bool check_city(char(&str)[100]);
bool check_street(char(&str)[100]);
bool check_house(char(&str)[100]);
bool check_flat(char(&str)[100]);

#endif //!_CHECKINPUT_H_