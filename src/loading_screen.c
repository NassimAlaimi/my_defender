/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** loading_sceen
*/

#include "my.h"

void loading_screen(my_defender_s *md)
{
    sfRenderWindow_clear(md->window->window, sfBlack);
    sfTexture *loading_texture = sfTexture_createFromFile(\
    "./sprites/loading.png", NULL);
    sfSprite *loading_sprite = sfSprite_create();
    sfSprite_setTexture(loading_sprite, loading_texture, sfTrue);
    sfRenderWindow_drawSprite(md->window->window, loading_sprite, NULL);
    sfRenderWindow_display(md->window->window);
}