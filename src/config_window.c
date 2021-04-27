/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** config_window
*/

#include "my.h"

void config_window(my_defender_s *md)
{
    md->window->mode = (sfVideoMode) {1364, 1024, 32};
    md->window->window = sfRenderWindow_create(md->window->mode,    \
    "My_Defender", sfClose, NULL);
    // sfRenderWindow_setFramerateLimit(md->window->window, 30);
    md->scene = 0;
    md->sprite->o->ms = 1;
    md->sprite->o->ss = 1;
}
