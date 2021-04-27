/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** game_ten
*/

#include "my.h"

void create_pause_buttons(ss_s *ss, char const *fp, int posx, int posy)
{
    ss->s = sfSprite_create();
    ss->t = sfTexture_createFromFile(fp, NULL);
    sfSprite_setTexture(ss->s, ss->t, sfTrue);
    ss->r = make_rect(455, 55);
    ss->pos.x = posx;
    ss->pos.y = posy;
    sfSprite_setPosition(ss->s, ss->pos);
    sfSprite_setTextureRect(ss->s, ss->r);
}

void load_pause_menu(ss_s **pause)
{
    pause[0]->s = sfSprite_create();
    pause[0]->t = sfTexture_createFromFile("./sprites/pause/Paused.png", NULL);
    sfSprite_setTexture(pause[0]->s, pause[0]->t, sfTrue);
    pause[0]->ic = sfClock_create();
    create_pause_buttons(pause[1], "./sprites/pause/resp.png", 324, 353);
    create_pause_buttons(pause[2], "./sprites/pause/mmp.png", 324, 418-1);
    create_pause_buttons(pause[3], "./sprites/pause/exitp.png", 324, 483-2);
}

void add_pause_time(game_s *g, ss_s *p)
{
    p->time = sfClock_getElapsedTime(p->ic);
    for (int i = 0; i < 50; i++)
        if (g->en->st[i]->hp == 0)
            g->en->st[i]->dtlim += p->time.microseconds/1000000.0;
}

void redo_stat(stat_s *st, int dtlim, ss_s *ss, int posy)
{
    st->dtlim = dtlim;
    sfClock_restart(st->dt);
    st->hp = 0;
    st->dc = 0;
    st->dist = 0;
    ss->pos.y = posy;
    ss->pos.x = -127;
}
