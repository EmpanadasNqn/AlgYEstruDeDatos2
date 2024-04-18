#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n");
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size) {
    
    unsigned int length = 0u;
    char format[4];
    FILE *file = NULL;
    file = fopen(path, "r");

    if (file == NULL) {
        printf("Error! Archivo No Existe.\n");
        exit(EXIT_FAILURE);
    }
    
    while (length < max_size && feof(file) == 0){
        
        fscanf(file, "%u %c%c %c%c%c", &indexes[length], &format[0], &format[1], &format[2], &letters[length], &format[3]);
        
        if(format[0] != '-' || format[1] != '>' || format[2] != '*' || format[3] != '*'){
            printf("Error! Formato del Archivo No Valido.\n");
            exit(EXIT_FAILURE);
        }

        if (indexes[length] >= max_size){
            printf("Error! Indice del Archivo Supera Max Size=%u.\n",max_size);
            exit(EXIT_FAILURE);
        }
        
        if (ferror(file) != 0){
            printf("Error! de Lectura.\n");
            clearerr(file);
            exit(EXIT_FAILURE);
        }
        
        length++;
    }
 
    fclose(file);
    return length - 1;
}

void sort_letters(unsigned int indexes[], char letters[], char sorted[], unsigned int length) {
    for (unsigned int i = 0; i < length; i++){
        sorted[indexes[i]] = letters[i];
    }
}

char *parce_filepath(int argc, char *argv[]) {
    char *result = NULL;

    if (argc < 2){
        exit(EXIT_FAILURE);
    }
    
    result = argv[1];
    
    return result;
}

int main(int argc, char *argv[]) {
    const char *filePath = parce_filepath(argc, argv);
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];

    unsigned int length = data_from_file(filePath, indexes, letters, MAX_SIZE); 
    
    if (length == 0u){
        return EXIT_FAILURE;
    }
    
    sort_letters(indexes, letters, sorted, length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

