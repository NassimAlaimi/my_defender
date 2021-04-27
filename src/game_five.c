/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** game_five
*/

#include "my.h"

void make_button_react(sfRenderWindow *w, ss_s *ss)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(w);

    if (mpos.x >= ss->pos.x && mpos.x <= ss->pos.x+160 && mpos.y >= ss->pos.y
    && mpos.y <= ss->pos.y+160) {
        ss->r.left = 160;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            ss->r.left += 160;
        }
    } else {
        ss->r.left = 0;
    }
    sfSprite_setTextureRect(ss->s, ss->r);
    sfRenderWindow_drawSprite(w, ss->s, NULL);
}

void move_by_one(stat_s *st, ss_s *ss)
{
    if (st->dist <= 384)
        ss->pos.x++;
    if (st->dist > 384 && st->dist <= 896)
        ss->pos.y++;
    if (st->dist > 896 && st->dist <= 1152)
        ss->pos.x++;
    if (st->dist > 1152 && st->dist <= 1408)
        ss->pos.y--;
    if (st->dist > 1408)
        ss->pos.x++;
    st->dist++;
}

void enem_death(stat_s *st, ss_s *ss, game_s *g, int worth)
{
    ss->pos.x = -127;
    if (worth != 30)
        ss->pos.y = 96;
    else
        ss->pos.y = 128;
    st->dtlim = 30;
    st->hp = 0;
    g->coin->var += worth;
    sfClock_restart(st->dt);
    st->dist = 0;
    sfSound_play(g->sfx->die);
}

void change_pos(stat_s *st, ss_s *ss, game_s *g, int worth)
{
    st->time = sfClock_getElapsedTime(st->dt);
    if (st->time.microseconds/1000000.0 > 0.01) {
        for (int i = 0; ss->pos.x<1022 && i<st->speed/g->map[(int)  \
            (ss->pos.x/128)][(int)(ss->pos.y/128)+1].sm; i++)
            move_by_one(st, ss);
        sfClock_restart(st->dt);
    }
    if (ss->pos.x >= 1022) {
        g->life->var -= (worth/10);
        enem_death(st, ss, g, worth);
        return;
    }
    g->map[(int)(ss->pos.x/128)][(int)(ss->pos.y/128)+1].enem = 1;
    sfSprite_setPosition(ss->s, ss->pos);
    ss->time = sfClock_getElapsedTime(ss->ic);
    if ((ss->time.microseconds/1000000.0) > (0.20/(worth/10))*g->map[(int)(ss->\
    pos.x/128)][(int)(ss->pos.y/128)+1].sm) {
        move_rect(ss);
        sfClock_restart(ss->ic);
    }
}

void clear_enemies(tile_s **map)
{
    map[0][1].enem = 0;
    map[1][1].enem = 0;
    map[2][1].enem = 0;
    map[2][2].enem = 0;
    map[2][3].enem = 0;
    map[2][4].enem = 0;
    map[2][5].enem = 0;
    map[3][5].enem = 0;
    map[4][5].enem = 0;
    map[4][4].enem = 0;
    map[4][3].enem = 0;
    map[5][3].enem = 0;
    map[6][3].enem = 0;
    map[7][3].enem = 0;
}
