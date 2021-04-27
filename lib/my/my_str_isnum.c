/*
** EPITECH PROJECT, 2020
** my_str_isnum.c
** File description:
** function that returns if the string only contains digits
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0';) {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}