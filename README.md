# strmath
A lightweight string library for [C](https://en.wikipedia.org/wiki/C_(programming_language))

*Currently only tested on linux and windows*

## Usage
Add the header file and the c file to your project and include it using

**Make sure you have `strmath.h` and `strmath.c` in the same directory or it won't work**

```c
#include <strmath.h>
```

## Functionality
Here are the functions in this library:
```c
/*
The string type
*/
string

/*
Creates a string
    startStr - the starting string (can be NULL)
    bufsize - the size to allocate (must be higher than 0)
*/
string* string_new(const char* startStr, size_t bufsize)

/*
Appends a character to the end of the string
    str - the string to append to
    c - the character to append
*/
int string_append(string* str, const char c)

/*
Appends another string to the end of the string
    str - the string to append to
    s - the string to append
*/
int string_append_str(string* str, const char* s)

/*
Sets the string to a new value
    str - the string pointer
    newStr - the new string
*/
int string_set(string* str, const char* newStr)

/*
Frees a string object from the memory
    str - the string pointer
*/
int string_free(string* str)
```