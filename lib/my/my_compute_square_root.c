/*
** EPITECH PROJECT, 2020
** my_compute_square_root.c
** File description:
** function to calculate the square root of a number
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int i = 0;

    if (nb <= 0 || nb > 2147483647)
        return (0);
    for (i = 0; nb > (i * i); i++)
        if (i * i == nb)
            return (i);
    return (0);
}
