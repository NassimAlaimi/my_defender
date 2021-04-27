/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** function to concatenate src at the end of dest
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_len = 0;

    for (dest_len = 0; dest[dest_len] != '\0'; dest_len++);

    for (; src[i] != '\0'; i++) {
        dest[dest_len] = src[i];
        dest_len++;
    }
    dest[dest_len] = '\0';
    return (dest);
}