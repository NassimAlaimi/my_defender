/*
** EPITECH PROJECT, 2020
** my_is_prime.c
** File description:
** function to check if number is prime or not
*/

#include "my.h"

int my_is_prime(int nb)
{
    for (int i = 2; i < (nb - 1); i++)
        if ((nb % i) == 0)
            return (0);
    return (1);
}