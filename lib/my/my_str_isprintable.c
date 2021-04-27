/*
** EPITECH PROJECT, 2020
** my_str_isprintable.c
** File description:
** function to print all printable characters
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0';) {
        if (str[i] >= 32)
            i++;
        else
            return (0);
    }
    return (1);
}