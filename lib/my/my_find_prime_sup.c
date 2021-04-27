/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** function to check the first smallest prime number starting from nb
*/

#include "my.h"

int prime(int nb)
{
    for (int i = 2; i < (nb - 1); i++)
        if ((nb % i) == 0)
            return (0);
    return (nb);
}

int my_find_prime_sup(int nb)
{
    while (nb <= 200) {
        if (prime(nb) != 0)
            return (prime(nb));
        nb++;
    }
    return (nb);
}