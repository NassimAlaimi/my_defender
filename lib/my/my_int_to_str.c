/*
** EPITECH PROJECT, 2020
** my_int_to_str.c
** File description:
** function to convert an integer to a string
*/

#include "my.h"

char *my_int_to_str(int nb)
{
    int i = 0;
    int nb_len = 0;
    int new_nb = nb;
    char *result = 0;

    for (nb_len = 0; (new_nb % 10); nb_len++) {
        new_nb = new_nb / 10;
    }

    result = malloc(sizeof(char) * nb_len + 1);

    for (i = 0; nb >= 10; i++) {
        result[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    result[i] = (nb % 10) + '0';
    result[i + 1] = '\0';
    return (my_revstr(result));
}