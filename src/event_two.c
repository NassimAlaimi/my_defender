/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** event_two
*/

#include "my.h"

void mouse_click_option(my_defender_s *md, sfVector2i mpos)
{
    if (md->window->event.mouseButton.button == sfMouseLeft) {
        if (mpos.x >= 1000 && mpos.x <= 1000+160 && mpos.y >= 400
        && mpos.y <= 400+160) {
            change_m_status(md->sprite->o);
            change_m_vol(md);
        }
        if (mpos.x >= 1000 && mpos.x <= 1000+160 && mpos.y >= 600
            && mpos.y <= 600+160)
            change_s_status(md->sprite->o, md);
        if (mpos.x >= 10 && mpos.x <= 10+160 && mpos.y >= 10
        && mpos.y <= 10+80) {
            md->scene = 0;
            sfMusic_pause(md->option->m);
            sfMusic_play(md->menu->m);
        }
        if (mpos.x >= 592 && mpos.x <= 592+160 && mpos.y >= 834
            && mpos.y <= 834+104)
            md->scene = 5;
    }
}

void restart_clocks(game_s *g)
{
    for (int i = 0; i < 20; i++) {
        sfClock_restart(g->en->st[i]->dt);
    }
}

void mouse_button_click(sfVector2i mpos, game_s *g)
{
    if (mpos.x >= 1196 && mpos.x <= 1196+160 && mpos.y >= 905
        && mpos.y <= 905+160)
        g->selected = 0;
    if (mpos.x >= 1032 && mpos.x <= 1032+160 && mpos.y >= 180
        && mpos.y <= 180+160)
        g->selected = 1;
    if (mpos.x >= 1196 && mpos.x <= 1196+160 && mpos.y >= 180
        && mpos.y <= 180+160)
        g->selected = 2;
    if (mpos.x >= 1032 && mpos.x <= 1032+160 && mpos.y >= 348
        && mpos.y <= 348+160)
        g->selected = 3;
    if (mpos.x >= 1196 && mpos.x <= 1196+160 && mpos.y >= 348
        && mpos.y <= 348+160)
        g->selected = 4;
    if (mpos.x >= 1032 && mpos.x <= 1032+160 && mpos.y >= 905
        && mpos.y <= 905+160)
        g->selected = 5;
}

void mouse_click_game(my_defender_s *md, game_s *g, sfVector2i mpos)
{
    if (mpos.x > 1024 && md->window->event.mouseButton.button == sfMouseLeft) {
        mouse_button_click(mpos, g);
    }
    if (mpos.x < 1024 && md->window->event.mouseButton.button == sfMouseLeft) {
        if ((g->selected != 0 && g->selected != 5) && g->map[(mpos.x/128)] \
        [(mpos.y/128)].ir == 0 && g->map[(mpos.x/128)][(mpos.y/128)].tt == 0 \
        && check_money(g) == 1) {
            g->map[mpos.x/128][mpos.y/128].tt = g->selected;
            g->tn++;
            sfSound_play(g->sfx->build);
        }
        if (g->selected == 5) {
            sell_tower(g, mpos);
        }
        g->selected = 0;
    }
}

void mouse_click_menu(my_defender_s *md, sfVector2i mpos)
{
    if (md->window->event.mouseButton.button == sfMouseLeft) {
        if (mpos.x >= 444 && mpos.x <= 900 &&
        mpos.y >= 351 && mpos.y <= 351+55) {
            md->scene = 1;
            restart_clocks(md->g);
            sfMusic_pause(md->menu->m);
            sfMusic_play(md->game->m);
            redo_game(md->g);
        }
        if (mpos.x >= 444 && mpos.x <= 900 &&
        mpos.y >= 415 && mpos.y <= 415+55) {
            md->scene = 2;
            sfMusic_pause(md->menu->m);
            sfMusic_play(md->option->m);
        }
        if (mpos.x >= 444 && mpos.x <= 900 &&
            mpos.y >= 479 && mpos.y <= 479+55)
            md->scene = -1;
    }
}
