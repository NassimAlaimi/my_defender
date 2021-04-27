/*
** EPITECH PROJECT, 2020
** my_isneg.c
** File description:
** function to print either N or P if integers passed are negative or positive
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar('P');
    else
        my_putchar('N');
    return (0);
}