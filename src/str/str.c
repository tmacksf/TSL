#include "str.h"

string new_string(char *input) {
  /* get string length */
  unsigned long i = 0;
  while (input[i] != NULLCHAR) {
    i++;
  }
  string str;
  str.str = malloc(i);
  str.size = i;
  char *temp = str.str;
  while (i--) {
    *temp++ = *input++;
  }

  return str;
}

int destroy(string *base_str) {
  free(base_str->str);
  return 0;
}

string concat(string *s1, string *s2) {
  string str;
  str.size = s1->size + s2->size;

  /* char is size of 1 so no need to multiply by sizeof(char) */
  str.str = malloc(str.size);
  char *temp = str.str;
  int i;
  for (i = s1->size; i > 0; i--) {
    *temp++ = *s1->str++;
  }
  for (i = s2->size; i > 0; i--) {
    *temp++ = *s2->str++;
  }
  return str;
}

string cut(string *base_str, int index) {
  string str;
  str.size = index + 1;
  str.str = malloc(str.size);

  char *strptr = str.str;
  for (int i = 0; i < index; i++) {
    *strptr++ = *base_str->str++;
  }

  return str;
}

int find(char *str, string base_str) {
  for (int i = 0; i < base_str.size; i++) {
    int not_found = 0;
    char *temp = str;
    int temp_iterator = i;
    while (*temp != '\0') {
      if (temp_iterator >= base_str.size) {
        not_found++;
        break;
      }
      if (base_str.str[temp_iterator] != *temp) {
        not_found++;
        break;
      }
      temp++;
      temp_iterator++;
    }
    if (!not_found)
      return i;
  }
  return -1;
}

int isletter(char c) {
  if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
    return 1;
  else
    return 0;
}

int lower(string *base_str) {
  for (int i = 0; i < base_str->size; i++) {
    if (isupper(base_str->str[i])) {
      base_str->str[i] = base_str->str[i] + 32;
    }
  }

  return 0;
}

int upper(string *base_str) {
  for (int i = 0; i < base_str->size; i++) {
    if (islower(base_str->str[i])) {
      base_str->str[i] = base_str->str[i] - 32;
    }
  }
  return 0;
}
