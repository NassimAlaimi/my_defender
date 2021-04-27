/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** game_three
*/

#include "my.h"

void make_en(ss_s *ss, char const *fp, int leftmax, int posy)
{
    ss->r = make_rect(128, 128);
    ss->t = sfTexture_createFromFile(fp, NULL);
    ss->s= sfSprite_create();
    sfSprite_setTexture(ss->s, ss->t, sfTrue);
    sfSprite_setTextureRect(ss->s, ss->r);
    ss->pos.x = -127;
    ss->pos.y = posy;
    sfSprite_setPosition(ss->s, ss->pos);
    ss->ic = sfClock_create();
    ss->leftmax = leftmax;
}

void make_stat(stat_s *st, int dtlim, int speed, int hp)
{
    st->dtlim = dtlim;
    st->dt = sfClock_create();
    st->hp = 0;
    st->dc = 0;
    st->speed = speed;
    st->hp_base = hp;
    st->dist = 0;
}

void make_enemies(enemies_s *en)
{
    for (int i = 0; i < 20; i++) {
        make_en(en->ss[i], "./sprites/g/Zomb.png", 256, 96);
        make_stat(en->st[i], (5*i)+5, 4, 50);
    }
    for (int i = 20; i < 40; i++) {
        make_en(en->ss[i], "./sprites/g/imp.png", 896, 96);
        make_stat(en->st[i], (5*(i-20))+40, 6, 30);
    }
    for (int i = 40; i < 50; i++) {
        make_en(en->ss[i], "./sprites/g/Troll.png", 1024, 128);
        make_stat(en->st[i], (10*(i-40))+60, 2, 150);
    }
}

void make_tower_sheet(ss_s *ss, char const *fp, int leftmax, int ij)
{
    ss->pos.x = (ij/10)*128;
    ss->pos.y = (ij%10)*128;
    ss->r = make_rect(128, 128);
    ss->leftmax = leftmax;
    ss->ic = sfClock_create();
    ss->s = sfSprite_create();
    ss->t = sfTexture_createFromFile(fp, NULL);
    sfSprite_setTexture(ss->s, ss->t, sfTrue);
    sfSprite_setTextureRect(ss->s, ss->r);
    sfSprite_setPosition(ss->s, ss->pos);
}

void mark_road(tile_s **map)
{
    map[0][1].ir = 1;
    map[1][1].ir = 2;
    map[2][1].ir = 3;
    map[2][2].ir = 4;
    map[2][3].ir = 5;
    map[2][4].ir = 6;
    map[2][5].ir = 7;
    map[3][5].ir = 8;
    map[4][5].ir = 9;
    map[4][4].ir = 10;
    map[4][3].ir = 11;
    map[5][3].ir = 12;
    map[6][3].ir = 13;
    map[7][3].ir = 14;
}
