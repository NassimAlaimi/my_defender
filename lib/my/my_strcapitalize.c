/*
** EPITECH PROJECT, 2020
** my_strcapitalize.c
** File description:
** function that capitalizes the first letter of each word
*/

#include "my.h"

char *lower(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    str = lower(str);

    for (i = 0; i == 0; i++)
        str[i] -= 32;
    for (; str[i] != '\0'; i++) {
        if ((str[i] == '+' || str[i] == '-') &&\
        (str[i+1] >= 'a' && str[i+1] <= 'z')) {
            str[i+1] -= 32;
            i++;
        } else if (str[i] == ' ' && (str[i+1] >= 'a' && str[i+1] <= 'z')) {
            str[i+1] -= 32;
            i++;
        }
    }
    return (str);
}