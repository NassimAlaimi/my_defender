/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** loop.c
*/

#include "my.h"

void loop(my_defender_s *md)
{
    while (sfRenderWindow_isOpen(md->window->window)) {
        event(md);
        sfRenderWindow_clear(md->window->window, sfBlack);
        if (md->scene == 0)
            menu(md);
        if (md->scene == 1)
            game(md);
        if (md->scene == 2)
            option(md);
        if (md->scene == 3)
            in_pause(md, md->pause);
        if (md->scene == 4)
            game_over_screen(md->go, md);
        if (md->scene == 5)
            htp(md);
        sfRenderWindow_display(md->window->window);
    }
}
