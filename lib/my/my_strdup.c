/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** function that reproduces the behaviour of strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    int srclen = 0;
    char *str = NULL;

    for (srclen = 0; src[srclen] != '\0'; srclen++);

    str = malloc(sizeof(char) * srclen);

    for (i = 0; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}