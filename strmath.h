#pragma once

#ifndef STRMATH_H
#define STRMATH_H

#include <stdlib.h>
#include <string.h>

#define NOMEM_ERR -1
#define NULL_ERR -2

typedef struct {
    size_t length;
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
        mallocSize *= 2; // More efficient growth
    }

    res->str = (char*)malloc(mallocSize);
    if (!res->str) {
        free(res);
        return NULL;
    }

    if (startStr) {
        memcpy(res->str, startStr, stringLen); // Safer than strcpy because it doesn't need to find the length
    }

    res->str[stringLen] = '\0'; // Ensure null termination
    res->length = stringLen;
    res->MEMSIZE = mallocSize;
    //res->BUFSIZE = bufsize;

    return res;
}

int string_free(string* str) {
    if (!str) return NULL_ERR;
    free(str->str);
    free(str);
    return 0;
}

int string_append(string* str, const char c) {
    if (!str) return NULL_ERR;

    if (str->length + 1 > str->MEMSIZE) {
        str->MEMSIZE *= 2;
        str->str = (char*)realloc(str->str, str->MEMSIZE);
        if (!str->str) {
            free(str);
            return NOMEM_ERR;
        }
    }

    str->str[str->length] = c;
    str->length++;
    str->str[str->length] = '\0';

    return 0;
}

int string_set(string* str, const char* newStr) {
    if (!str || !newStr) return NULL_ERR;

    size_t newLen = strlen(newStr);

    if (newLen + 1 > str->MEMSIZE) {
        size_t newSize = str->MEMSIZE;
        while (newLen + 1 > newSize) {
            newSize *= 2;
        }
        char* newPtr = (char*)realloc(str->str, newSize);
        if (!newPtr) {
            return NOMEM_ERR;
        }
        str->str = newPtr;
        str->MEMSIZE = newSize;
    }

    memcpy(str->str, newStr, newLen);
    str->str[newLen] = '\0';

    str->length = newLen;

    return 0;
}

#endif