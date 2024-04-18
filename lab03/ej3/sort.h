/*
  @file sort.h
  @brief Sort functions declarations
*/
#ifndef _SORT_H
#define _SORT_H
#include <stdbool.h>
#include "player.h"


/**
 * @brief Returns true if player 'x' goes before player 'y' in a sorted array of players.
 *
 * @param[in]  x Player 'x'
 * @param[in]  y Player 'y'
 *
 * @return true if player 'x' goes before player 'y' in a sorted array of players.
 */
bool goes_before(player_t x, player_t y);


/**
 * @brief Intercambia las posiciones de a[i] con a[j]
 * @param[in] a Arreglo de Jugadores
 * @param[in] i Posicion a ser reemplazada por j
 * @param[in] j Posicion a ser reemplazada por i
*/
void swap(player_t a[], unsigned int i, unsigned int j);


/**
 * @brief    Checks if the array 'a' is in ascending order according
 *           to the goes_before function
 *
 * @param[in]  atp     The Player array
 * @param[in]  length  Length of player array
 *
 * @return True if array is sorted in ascendirng order according to goes_before function, false otherwise
 */
bool array_is_sorted(player_t atp[], unsigned int length);


/**
 * @brief Subdivide el Arreglo a en dos, dejando los elementos menores al pivote a su izquierda y los elementos mayores a la derecha. DE esa manera dejando al pivote en su posicion ordenada
 * @param[in] a Arreglo de Jugadores
 * @param[in] izq Posicion Izquierda del Arreglo
 * @param[in] der Posicion Derecha del Arreglo
 * @return La posicion Pivote, Que ya se Encuentra en su Posicion Ordenada
*/
unsigned int partition(player_t a[], unsigned int izq, unsigned int der);


/**
 * @brief Ordena el Arreglo usando la Funcion partition
 * @param[in] a Arreglo de Jugadores
 * @param[in] izq Posicion Izquierda del Arreglo
 * @param[in] der Posicion Derecha del Arreglo
*/
void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der);


/**
 * @brief Sort the array 'a' using quick sort algorithm. The resulting sort
 *        will be ascending according to the goes_before funtion.
 *        The array 'a' must have exactly 'length' elements.
 *
 * @param[in]      a       Players array
 * @param[in]      length  Length of players array
 */
void sort(player_t a[], unsigned int length);


#endif
