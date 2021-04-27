/*
** EPITECH PROJECT, 2020
** my_strstr.c
** File description:
** function to find a word in a string
*/

#include "my.h"

int word_check(char *str, char const *to_find, int i, char **sub_ptr)
{
    int x = 0;
    int ptr_begin = i;
    int to_find_len = 0;

    for (to_find_len = 0; to_find[to_find_len] != '\0'; to_find_len++);

    while (str[i] == to_find[x]) {
        x++;
        i++;
        if (x == to_find_len) {
            *sub_ptr = &str[ptr_begin];
            return (0);
        }
    }
    ptr_begin = i;
    x = 0;
    i++;
    return (1);
}

char *my_strstr(char *str, char const *to_find)
{
    char *sub_ptr;

    for (int i = 0; str[i] != '\0'; i++) {
        if (word_check(str, to_find, i, &sub_ptr) == 0) {
            return (sub_ptr);
        }
    }
    return (NULL);
}