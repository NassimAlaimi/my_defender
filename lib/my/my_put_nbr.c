/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** function to print integers
*/

#include "my.h"

void print_maxint(void)
{
    my_putchar('-');
    my_putchar(2 + '0');
    my_putchar(1 + '0');
    my_putchar(4 + '0');
    my_putchar(7 + '0');
    my_putchar(4 + '0');
    my_putchar(8 + '0');
    my_putchar(3 + '0');
    my_putchar(6 + '0');
    my_putchar(4 + '0');
    my_putchar(8 + '0');
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        print_maxint();
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9)
        my_put_nbr(nb / 10);

    my_putchar(nb % 10 + '0');
    return (0);
}