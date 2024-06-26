/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

static const int EXPECTED_DIM_VALUE = 2;

static const char* CITY_NAMES[CITIES] = {
    "Cordoba", "Rosario", "Posadas", "Tilcara", "Bariloche"};
static const char* SEASON_NAMES[SEASONS] = {"low", "high"};

void array_dump(BakeryProductTable a) {
    for (unsigned int city = 0u; city < CITIES; ++city) {
        for (unsigned int season = 0u; season < SEASONS; ++season) {
            fprintf(stdout, "%s in %s season: flour (%u,%u) Yeast (%u,%u) Butter (%u,%u) Sales value %u",
                    CITY_NAMES[city], SEASON_NAMES[season], a[city][season].flour_cant,
                    a[city][season].flour_price, a[city][season].yeast_cant,
                    a[city][season].yeast_price, a[city][season].butter_cant,
                    a[city][season].butter_price, a[city][season].sale_value);
            fprintf(stdout, "\n");
        }
    }
}

unsigned int best_profit(BakeryProductTable a) {
    unsigned int max_profit = 0u;
    unsigned int profit;

    for (unsigned int city = 0; city < CITIES; city++) {
        for (unsigned int season = 0; season < SEASONS; season++) {
            profit = (a[city][season].flour_cant * a[city][season].flour_price) + (a[city][season].yeast_cant * a[city][season].yeast_price) + (a[city][season].butter_cant * a[city][season].butter_price);

            profit = a[city][season].sale_value - profit;

            if (max_profit < profit) {
                max_profit = profit;
            }
        }
    }
    
    return max_profit;
}

void array_from_file(BakeryProductTable array, const char* filepath) {
    FILE* file = NULL;

    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    int length = 0;
    unsigned int city = 0u;
    unsigned int season = 0u;
    while (!feof(file) && length < CITIES * SEASONS) {

        int res = fscanf(file, "##%u??%u", &city, &season);
        
        if (res != EXPECTED_DIM_VALUE) {
            fprintf(stderr, "Invalid file.\n");
            exit(EXIT_FAILURE);
        }

        if (city >= CITIES) {
            fprintf(stderr, "Invalid City Code.\n");
            exit(EXIT_FAILURE);
        }
        
        if (season >= SEASONS) {
            fprintf(stderr, "Invalid Season.\n");
            exit(EXIT_FAILURE);
        }

        BakeryProduct product = bakery_product_from_file(file);
        array[city][season] = product;

        ++length;
    }
    fclose(file);
}
