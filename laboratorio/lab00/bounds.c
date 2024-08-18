#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4


struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    
    res.is_upperbound = 0;
    res.is_lowerbound = 0;
    res.exists = 0;
    res.where = 0;
    
    for (unsigned int i = 0; i < length; i++){
        if (value >= arr[i] && !res.is_lowerbound){
            res.is_upperbound = 1;
        } else {
            res.is_upperbound = 0;
        }
        if (value <= arr[i] && !res.is_upperbound){
            res.is_lowerbound = 1;
        } else {
            res.is_lowerbound = 0;
        }
        if (value == arr[i]){
            res.exists = 1;
            res.where = i;
        }
    }

    return res;
}

int main(void) {
    int a[ARRAY_SIZE];
    int value;
    
    for (int i = 0; i < ARRAY_SIZE; i++){
        printf("Ingrese a[%d]=", i);
        scanf("%d", &a[i]);
    }

    printf("Ingrese el valor a evaluar =");
    scanf("%d", &value);
    
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    if (result.is_upperbound && result.exists){
        printf("El valor ingresado es cota Superior y Maximo.\n");
        printf("Y se encuentra en a[%d].\n", result.where);
    } else if (result.is_upperbound){
        printf("El valor ingresado es cota Superior.\n");
    } else if (result.is_lowerbound && result.exists){
        printf("El valor ingresado es cota Inferior y Minimo.\n");
        printf("Y se encuentra en a[%d].\n", result.where);
    } else if (result.is_lowerbound){
        printf("El valor ingresado es cota Inferior.\n");
    }
    
    return EXIT_SUCCESS;
}
