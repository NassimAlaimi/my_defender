/*
** EPITECH PROJECT, 2020
** my_str_isupper.c
** File description:
** function to check if the string only contains lowercase alpha characters
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0';) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            i++;
        else
            return (0);
    }
    return (1);
}