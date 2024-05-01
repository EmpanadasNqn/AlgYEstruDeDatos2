#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if (x >= 0) {
        *y = x;
    } else {
        *y = -x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---
    a = -10;
    absolute(a,&res);
    printf("%d\n", res);
    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

/**
 * El parametro int *y de absolute() es de tipo OUT ya que solo lo usamos para almacenar
 * el dato de x. No sacamos informacion de esa direccion de memoria.
 * 
 * Los parametros IN serian funcion(int x); Los OUT serian funcion(int *x) si lo unico que
 * hacemos en la funcion es usar esa direccion para guardar algo; Los IN/OUT serian
 * funcion(int *x) Pero con la diferencia que accedemos a la direccion de memoria para
 * sacar algun dato y ademas despues guardamos y devolvemos datos en el puntero x.
*/