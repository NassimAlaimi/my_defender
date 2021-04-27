/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** menu.c
*/

#include "my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

void load_menu_background(ss_s *ss)
{
    ss->t = sfTexture_createFromFile("./sprites/menu/mm.png", NULL);
    ss->s = sfSprite_create();
    sfSprite_setTexture(ss->s, ss->t, sfTrue);
}

void make_b_sheet(ss_s *ss, int x, int y, char const *fp)
{
    ss->r = make_rect(455, 55);
    ss->t = sfTexture_createFromFile(fp, NULL);
    ss->s = sfSprite_create();
    sfSprite_setTexture(ss->s, ss->t, sfTrue);
    sfSprite_setTextureRect(ss->s, ss->r);
    ss->pos.x = x;
    ss->pos.y = y;
    sfSprite_setPosition(ss->s, ss->pos);
}

void load_sprite_menu(my_defender_s *md)
{
    make_b_sheet(md->sprite->menu->playb, 444, \
    351, "./sprites/menu/playmm.png");
    make_b_sheet(md->sprite->menu->optionb, 444, \
    415, "./sprites/menu/optmm.png");
    make_b_sheet(md->sprite->menu->exitb, 444, \
    479, "./sprites/menu/quitmm.png");
    load_music_option(md->option);
    load_music_game(md->game);
    load_music_menu(md->menu);
    load_menu_background(md->sprite->menu->bg);
}

void make_bm_react(sfRenderWindow *w, ss_s *ss)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(w);

    if (mpos.x >= ss->pos.x && mpos.x <= ss->pos.x+455 && mpos.y >= ss->pos.y
    && mpos.y <= ss->pos.y+55) {
        ss->r.left = 455;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            ss->r.left += 455;
        }
    } else {
        ss->r.left = 0;
    }
    sfSprite_setTextureRect(ss->s, ss->r);
    sfRenderWindow_drawSprite(w, ss->s, NULL);
}

void menu(my_defender_s *my_defender)
{
    sfRenderWindow_drawSprite(my_defender->window->window,  \
    my_defender->sprite->menu->bg->s, NULL);
    make_bm_react(my_defender->window->window,  \
    my_defender->sprite->menu->playb);
    make_bm_react(my_defender->window->window,  \
    my_defender->sprite->menu->optionb);
    make_bm_react(my_defender->window->window,  \
    my_defender->sprite->menu->exitb);
}
