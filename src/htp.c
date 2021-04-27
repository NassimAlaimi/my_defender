/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** htp
*/

#include "my.h"

void load_htp(option_s *o)
{
    make_bg(o->htp, 0, 0, "./sprites/option/htp.png");
    make_back_sheet(o->ba, 10, 10, "./sprites/option/back.png");
}

void htp(my_defender_s *md)
{
    sfRenderWindow_drawSprite(md->window->window, md->sprite->o->htp->s, NULL);
    make_ba_react(md->window->window, md->sprite->o->ba);
}