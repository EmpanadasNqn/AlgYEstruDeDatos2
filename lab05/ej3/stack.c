#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty(void) {
    return NULL;
}

stack stack_push(stack s, stack_elem e) {
    if (!stack_is_empty(s)) {
        if (s->size >= s->capacity) {
            s->elems = realloc(s->elems, sizeof(s->capacity) * 2);
        }
        s->elems[s->size] = e;
        s->size = s->size + 1;
    } else {
        s->elems = malloc(sizeof(s->capacity)); //COrregir
        s->elems[s->size] = e;
        s->size = 0;
    }
    return s;    
}

stack stack_pop(stack s) {
    assert(!stack_is_empty(s));
    s->size = s->size - 1;
    return s;
}

unsigned int stack_size(stack s) {
    if (stack_is_empty(s)) {
        return 0u;
    }
    return s->size;
}

stack_elem stack_top(stack s) {
    assert(!stack_is_empty(s));
    return s->elems[s->size];
}

bool stack_is_empty(stack s) {
    return (s == NULL);
}

stack_elem *stack_to_array(stack s) {
    return s->elems;
}

stack stack_destroy(stack s) {
    free(s->elems);
    free(s);
    s = NULL;
    return s;
}