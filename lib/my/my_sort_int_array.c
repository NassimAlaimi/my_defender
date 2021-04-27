/*
** EPITECH PROJECT, 2020
** my_sort_int_array.c
** File description:
** function to sort an array of integers
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
    int tmp = 0;

    for (int i = 0; i < size - 1;) {
        if (array[i] >= array[i+1]) {
            tmp = array[i];
            array[i] = array[i+1];
            array[i+1] = tmp;
            i = 0;
        } else {
            i++;
        }
    }
}