/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** function to copy string into another up to n characters
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    return (dest);
}