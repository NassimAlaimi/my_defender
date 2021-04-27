/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** function to concatenate src at the end of dest
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int dest_len = 0;

    for (dest_len = 0; dest[dest_len] != '\0'; dest_len++);

    for (; src[i] != '\0' && i < nb; i++) {
        dest[dest_len] = src[i];
        dest_len++;
    }
    dest[dest_len] = '\0';
    return (dest);
}