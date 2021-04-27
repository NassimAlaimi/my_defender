/*
** EPITECH PROJECT, 2020
** my_swap.c
** File description:
** function to swap two integers
*/

#include "my.h"

void my_swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}