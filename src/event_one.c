/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** event_one
*/

#include "my.h"
#include <SFML/Audio/Sound.h>

int check_money(game_s *g)
{
    if (g->selected == 1)
        if (g->coin->var >= 100 && g->tn < 8) {
            g->coin->var -= 100;
            return (1);
        }
    if (g->selected == 2)
        if (g->coin->var >= 50 && g->tn < 8) {
            g->coin->var -= 50;
            return (1);
        }
    if (g->selected == 3)
        if (g->coin->var >= 70 && g->tn < 8) {
            g->coin->var -= 70;
            return (1);
        }
    if (g->coin->var >= 90 && g->selected == 4 && g->tn < 8) {
        g->coin->var -= 90;
        return (1);
    }
    return (0);
}

void sell_tower(game_s *g, sfVector2i mpos)
{
    if (g->map[(mpos.x/128)][(mpos.y/128)].tt == 1) {
        g->coin->var+=70;
        g->tn--;
    }
    if (g->map[(mpos.x/128)][(mpos.y/128)].tt == 2) {
        g->coin->var+=35;
        g->tn--;
    }
    if (g->map[(mpos.x/128)][(mpos.y/128)].tt == 3) {
        g->coin->var+=49;
        g->tn--;
    }
    if (g->map[(mpos.x/128)][(mpos.y/128)].tt == 4) {
        g->coin->var+=63;
        g->tn--;
    }
    g->map[mpos.x/128][mpos.y/128].tt = 0;
}

void change_m_vol(my_defender_s *md)
{
    if (md->sprite->o->ms == 0) {
        md->option->vol = 0;
        md->game->vol = 0;
        md->menu->vol = 0;
    } else {
        md->option->vol = 50;
        md->game->vol = 50;
        md->menu->vol = 50;
    }
    sfMusic_setVolume(md->game->m, md->game->vol);
    sfMusic_setVolume(md->menu->m, md->menu->vol);
    sfMusic_setVolume(md->option->m, md->option->vol);
}

void change_s_status(option_s *o, my_defender_s *md)
{
    if (o->ss == 0)
        o->ss = 1;
    else
        o->ss = 0;
    sfSound_setVolume(md->g->sfx->build, o->ss*100);
    sfSound_setVolume(md->g->sfx->die, o->ss*100);
}

void change_m_status(option_s *o)
{
    if (o->ms == 0) {
        o->ms = 1;
    }
    else
        o->ms = 0;
}
