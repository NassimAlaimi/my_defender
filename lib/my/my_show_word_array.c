/*
** EPITECH PROJECT, 2020
** my_show_word_array.c
** File description:
** function to print a word array with \n's in between
*/

#include "my.h"

int my_show_word_array(char **tab)
{
    int y = 0;

    for (int x = 0; tab[y] != NULL; x++) {
        my_putchar(tab[y][x]);
        if (tab[y][x] == '\0') {
            my_putchar('\n');
            x = 0;
            y++;
        }
    }
    return (0);
}