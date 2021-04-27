/*
** EPITECH PROJECT, 2020
** my_strncmp.c
** File description:
** function to compare strings up to n characters
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, size_t n)
{
    size_t i = 0;

    for (i = 0; (s1[i] != '\0' && s2[i] != '\0') && i < n; i++) {
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] > s2[i])
            return (1);
    }
    if (s1[i] == s2[i])
        return (0);
    return (0);
}