#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pair.h"

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y) {
    pair_t p = malloc(sizeof(struct s_pair_t));
    p->fst = x;
    p->snd = y;
    assert(p->fst == x && p->snd == y);
    return p;
}

elem pair_first(pair_t p) {
    assert(sizeof(p) == sizeof(pair_t));
    return p->fst;
}

elem pair_second(pair_t p) {
    assert(sizeof(p) == sizeof(pair_t));
    return p->snd;
}

pair_t pair_swapped(pair_t p) {
    assert(sizeof(p) == sizeof(pair_t));
    pair_t q = pair_new(p->snd, p->fst);
    assert(pair_first(q) == pair_second(p) && pair_second(q) == pair_first(p));
    return q;
}

pair_t pair_destroy(pair_t p) {
    free(p);
    return NULL;
}