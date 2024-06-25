#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int x, y;
    x = 6;
    y = 4;
    printf("x = %d\ny = %d\n\n",x, y);
    swap(&x, &y);
    printf("x = %d\ny = %d\n",x, y);
    return EXIT_SUCCESS;
}