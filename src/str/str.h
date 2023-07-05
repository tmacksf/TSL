
// String

#ifndef STRING_H
#define STRING_H

#include "../base/base.h"
#include <ctype.h>

#define NULLCHAR '\0'

typedef struct string {
  int size;
  char *str;
} string;

// memorycopy
// TODO:
// #define memorycopy(c, c, c)

// Creates a new string taking a char * input
string new_string(char *input);
// concatenates two strings creating a new string
string concat(string *s1, string *s2);
// pops character at an index
string pop(string *base_str, int intex);
// cuts the string at a given index
string cut(string *base_str, int index);
// finds a char * within the string if exists
int find(char *str, string base_str);
// destroys a given string
int destroy(string *base_str);
// counts number of occurences of given input
int count(char *str, string *base_str);
// makes the string lower case
int lower(string *base_str);
// makes the string upper case
int upper(string *base_str);
// checks if char is a letter
int isletter(char c);

#endif
