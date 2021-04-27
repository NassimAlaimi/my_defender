/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** event.c
*/

#include "my.h"
#include <SFML/System/Clock.h>
#include <SFML/Window/Mouse.h>

void mouse_click_pause(my_defender_s *md, sfVector2i mpos)
{
    if (mpos.x >= 325 && mpos.x <= 780 && mpos.y >= 355 && mpos.y <= 410) {
        add_pause_time(md->g, md->pause[0]);
        md->scene = 1;
    }
    if (mpos.x >= 325 && mpos.x <= 780 && mpos.y >= 420 && mpos.y <= 475) {
        md->scene = 0;
        sfMusic_stop(md->game->m);
        sfMusic_play(md->menu->m);
    }
    if (mpos.x >= 325 && mpos.x <= 780 && mpos.y >= 485 && mpos.y <= 540) {
        md->scene = -1;
    }
}

void mouse_click_go(ss_s **go, sfVector2i mpos, my_defender_s *md)
{
    if (mpos.x >= go[1]->pos.x && mpos.x <= go[1]->pos.x+go[1]->r.width &&
    mpos.y >= go[1]->pos.y && mpos.y <= go[1]->pos.y+go[1]->r.height) {
        md->scene = 0;
        sfMusic_play(md->menu->m);
    }
    if (mpos.x >= go[2]->pos.x && mpos.x <= go[2]->pos.x+go[2]->r.width &&
        mpos.y >= go[2]->pos.y && mpos.y <= go[2]->pos.y+go[2]->r.height)
        md->scene = -1;
}

void mouse_click(my_defender_s *md)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(md->window->window);

    if (md->scene == 0)
        mouse_click_menu(md, mpos);
    if (md->scene == 1)
        mouse_click_game(md, md->g, mpos);
    if (md->scene == 2)
        mouse_click_option(md, mpos);
    if (md->scene == 3)
        mouse_click_pause(md, mpos);
    if (md->scene == 4)
        mouse_click_go(md->go, mpos, md);
    if (md->scene == 5)
        mouse_click_htp(md);
}

void check_pause(my_defender_s *md)
{
    if (md->window->event.key.code == sfKeyEscape) {
        md->scene = 3;
        sfClock_restart(md->pause[0]->ic);
    }
}

void event(my_defender_s *md)
{
    while (sfRenderWindow_pollEvent(md->window->window, &md->window->event)) {
        if (md->window->event.type == sfEvtMouseButtonPressed)
            mouse_click(md);
        if (md->window->event.type == sfEvtKeyPressed && md->scene == 1)
            check_pause(md);
        if (md->window->event.type == sfEvtClosed || md->scene == -1)
            sfRenderWindow_close(md->window->window);
    }
}
