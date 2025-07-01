#ifndef STRMATH_H
#define STRMATH_H

#include <stdlib.h>
//#include <string.h>

#define NOMEM_ERR -1
#define NULL_ERR -2

typedef struct {
    size_t length;
    char* str;
    size_t MEMSIZE;
} string;

string* string_new(const char* startStr, size_t bufsize);
int string_free(string* str);

int string_append(string* str, const char c);
int string_append_str(string* str, const char* s);

int string_set(string* str, const char* newStr);

#endif