#pragma once
#include"ALL.h"

#ifndef __FUNC_H__
#define __FUNC_H__

/*BASIC_STACK*/
Stack* Add_new_stack();
void Push_stack(int item);
int Pop_stack();
int IsEmpty();

/*BRACKET_CHECK_GETCHAR*/
int Bracket_check_getchar_stack(int ch);
/*BRACKET_CHECK_GETS*/
int Count_stack();
Bracket_check_gets_stack(char *string);
/*NOTATION_CHANGER*/
int Level_tester(int op);
char* Notation_changer(const char *string);
/*Simple Function*/
char* get_string_return_ptr();
void clear_buf();
#endif

