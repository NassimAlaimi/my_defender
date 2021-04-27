/*
** EPITECH PROJECT, 2020
** my is number
** File description:
** checks if char is nmber
*/

#include "my.h"

int my_is_number(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}