/*
** EPITECH PROJECT, 2020
** my_strupcase.c
** File description:
** function to put every letter of every word in it in uppercase
*/

#include "my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    return (str);
}