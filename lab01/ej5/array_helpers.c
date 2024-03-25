#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"
#include "mybool.h"

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {

    unsigned int size;

    FILE *file = fopen(filepath, "r");
    
    fscanf(file, "%u", &size);

    if (size > max_size) {
        printf("ERROR! El Tamaño es Superior al Permitido (100000).\n");
        fclose(file);
        return 0u;
    }

    for (unsigned int i = 0; i < size; i++) {
        fscanf(file, "%d", &array[i]);
    }
    
    printf("Datos Recolectados con Exito.\n");

    fclose(file);
    
    return size;
}

void array_dump(int a[], unsigned int length) {
    printf("[");
    for (unsigned int i = 0; i < length; i++) {
        if (i>0) {
            printf(",");
        }
        printf("%d", a[i]);
    }
    printf("]\n\n");
}

mybool array_is_sorted(int a[], unsigned int length) {

    for (unsigned int i = 0; i < length - 1; i++){
        if (a[i] > a[i + 1]){
            return false;
        }
    }
    return true;
}