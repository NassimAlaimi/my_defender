/*
** EPITECH PROJECT, 2020
** my_atoi.c
** File description:
** function to convert a string to an int
*/

#include "my.h"

int my_atoi(const char *nptr)
{
    int res = 0;
    int i = 0;
    int x = 0;

    if (nptr[i] == '-'){
        i++;
        x++;
    }
    for (; nptr[i] != '\0' && my_is_number(nptr[i]) == 1; i++) {
        res = (res * 10) + (nptr[i] - '0');
    }
    if (x == 1) {
        res *= -1;
    }
    return (res);
}