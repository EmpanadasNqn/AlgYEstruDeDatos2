#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size) {
    
    unsigned int length = 0u;
    FILE *file = fopen(path, "r");

    //Problema con Bordes && Problema con Indices muy grande en archivos
    while (length < max_size && feof(file) == 0){
        fscanf(file, "%u -> ", &indexes[length]);
        fscanf(file, "*%c*", &letters[length]);
        length++;

        if (ferror(file) != 0){
            printf("Error de Lectura.\n");
            clearerr(file);
            return 0u;
        }
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
    FILE *file = fopen(filePath, "r");

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];

    unsigned int length = data_from_file(filePath, indexes, letters, MAX_SIZE); 
    
    sort_letters(indexes, letters, sorted, length);

    dump(sorted, length);

    fclose(file);
    return EXIT_SUCCESS;
}

