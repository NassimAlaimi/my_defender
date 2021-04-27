/*
** EPITECH PROJECT, 2020
** my_str_isalpha.c
** File description:
** function that returns if the string contains alphabetical characters
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0';) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' &&\
str[i] <= 'z') || str[i] == ' ')
            i++;
        else
            return (0);
    }
    return (1);
}