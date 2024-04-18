#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "array_helpers.h"


/**
 * @brief Calcula la menor temperatura minima historica registrada
 * @details Analiza el array, especificamente a[y][m][j]._min_temp buscando la menor temperatura minima y guardandola en la variable min
 * @param a es un array del tipo abstracto WeatherTable
 * @return La variable min con la menor temperatura minima del arreglo a
*/
int temp_min(WeatherTable a);


/**
 * @brief Guarda todas las mayores temperaturas maximas del arreglo en otro arreglo
 * @details Del arreglo a compara todas las mayores temperaturas maximas de cada anio y guardandolas en el arreglo maxs
 * @param a Arreglo del tipo abstracto WeatherTable
 * @param maxs Arreglo de enteros
 * @return El arreglo maxs con todas las mayores temperaturas maximas de cada anio
*/
void temps_maxs_totales(WeatherTable a, int maxs[YEARS]);

#endif