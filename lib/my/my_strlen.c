/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** function to calculate the length of a string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}