/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-cyprien.piron
** File description:
** function to check if a character is in a string
*/

#include "my.h"

int my_is_char_in_str(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (1);
    return (0);
}