#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n\n", sizeof(messi.name), sizeof(messi.age), sizeof(messi.height), sizeof(messi));
    /**
     * La suma de los miembros no coincide con el total (38 != 40).
     * El tamaño del campo name depende del tamaño fijo del arreglo (En este caso NAME_MAXSIZE = 30).
    */

    printf("name-mem-dir  : %lu decimal\n"
           "age-mem-dir   : %lu decimal\n"
           "height-mem-dir: %lu decimal\n"
           "data_t-mem-dir: %lu decimal\n\n", (uintptr_t) &messi.name, (uintptr_t) &messi.age, (uintptr_t) &messi.height, (uintptr_t) &messi);
    
    printf("name-mem-dir  : %p hex\n"
           "age-mem-dir   : %p hex\n"
           "height-mem-dir: %p hex\n"
           "data_t-mem-dir: %p hex\n\n", (void *) &messi.name, (void *) &messi.age, (void *) &messi.height, (void *) &messi);
    /* Lo raro que encuentro en las direcciones de memoria son que la direccion de la estructura data_t (&messi) es la misma que la direccion que name (&messi.name). */
    
    return EXIT_SUCCESS;
}

