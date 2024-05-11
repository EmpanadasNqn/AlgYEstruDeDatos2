#include <stdio.h>
#include <stdlib.h>

#include "strfuncs.h"

size_t string_length(const char *str) {
    size_t i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *string_filter(const char *str, char c) {
    size_t longitud = string_length(str);
    size_t i = 0, j = 0;
    char *str_ptr = malloc(sizeof(char) * longitud);

    while (i < longitud) {
        if (str[i] != c) {
            str_ptr[j] = str[i];
            j++;
        }
        i++;
    }
    
    return str_ptr;
}

bool string_is_symmetric(const char *str) {
    size_t longitud = string_length(str);
    size_t j = longitud - 1;
    size_t i = 0u;

    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }
        j--;
        i++;
    }

    return true;
}