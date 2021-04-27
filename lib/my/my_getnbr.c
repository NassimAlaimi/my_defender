/*
** EPITECH PROJECT, 2020
** my_get_nbr.c
** File description:
** function to retrieve a number in a string
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    int final_num = 0;

    while ((str[i] == '-' || str[i] == '+') && str[i] != '\0') {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        final_num = final_num * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '\0')
        return (84);
    return (final_num * neg);
}