#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int l = 0;
    while (l < FIXSTRING_MAX){
        if (s[l] == '\0'){
            break;
        }
        l = l + 1;
    }
    return l;   
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool igual = true;
    for (int i = 0; i < FIXSTRING_MAX; i++){
        if (s1[i] != s2[i] || fstring_length(s1) != fstring_length(s2)){
            igual = false;
            break;
        }
    }
    return igual;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool menorIgual = false;
    if (fstring_length(s1) <= fstring_length(s2)){
        menorIgual = true;
    }
    return menorIgual;
}

