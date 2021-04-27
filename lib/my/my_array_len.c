/*
** EPITECH PROJECT, 2020
** my_array_len.c
** File description:
** function to get the length of an array
*/

#include "my.h"

int my_array_len(char **array)
{
    int res = 0;

    for (res = 0; array[res] != NULL; res++);
    return (res);
}