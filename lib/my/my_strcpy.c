/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** function to copy string into another variable, already allocated
*/

#include "my.h"

char *my_strcpy(char *dest, char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        dest[i] = str[i];
    dest[i] = '\0';
    return (dest);
}