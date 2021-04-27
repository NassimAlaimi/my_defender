/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** function to print a string given in argument
*/

#include "my.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}