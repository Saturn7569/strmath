#pragma once

#ifndef STRMATH_H
#define STRMATH_H

#include <stdlib.h>
#include <string.h>

#define NOMEM_ERR -1
#define NULL_ERR -2

typedef struct {
    int length;
    char* str;
    size_t MEMSIZE;
} string;

string* string_new(const char* startStr, size_t bufsize) {
    if (bufsize == 0) return NULL; // Prevent zero-size allocations

    string* res = (string*)malloc(sizeof(string));
    if (!res) return NULL;

    size_t stringLen = startStr ? strlen(startStr) : 0;
    size_t mallocSize = bufsize;

    while (stringLen + 1 > mallocSize) { // Ensure space for '\0'
        mallocSize *= 2; // More efficient growth strategy
    }

    res->str = (char*)malloc(mallocSize);
    if (!res->str) {
        free(res);
        return NULL;
    }

    if (startStr) {
        memcpy(res->str, startStr, stringLen); // Safer than strcpy
    }

    res->str[stringLen] = '\0'; // Ensure null termination
    res->length = stringLen;
    res->MEMSIZE = mallocSize;
    //res->BUFSIZE = bufsize;

    return res;
}

int string_append(string* str, const char c) {
    if (!str || !c) return NULL_ERR;

    str->length++;
    if (str->length > str->MEMSIZE) {
        str->MEMSIZE *= 2;
        str->str = (char*)realloc(str->str, str->MEMSIZE);
        if (!str->str) {
            free(str);
            return NOMEM_ERR;
        }
    }
}

#endif