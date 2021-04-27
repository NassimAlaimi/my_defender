/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** game_six
*/

#include "my.h"

void move_enemies(my_defender_s *md, enemies_s *en, game_s *g)
{
    for (int i = 0; i < 50; i++) {
        if (en->st[i]->hp == 0) {
            en->st[i]->time = sfClock_getElapsedTime(en->st[i]->dt);
            if (en->st[i]->time.microseconds/1000000.0 >= en->st[i]->dtlim) {
                en->st[i]->hp = en->st[i]->hp_base*(1+en->st[i]->dc);
                sfClock_restart(en->ss[i]->ic);
            }
        } else {
            change_pos(en->st[i], en->ss[i], g, 10*(1+i/20));
            sfRenderWindow_drawSprite(md->window->window, en->ss[i]->s, NULL);
        }
    }
}

void animate_tow(ss_s *ss)
{
    ss->time = sfClock_getElapsedTime(ss->ic);
    if ((ss->time.microseconds/1000000.0) > 0.10) {
        move_rect(ss);
        sfClock_restart(ss->ic);
    }
}

int enem_in_prox(tile_s **map, int i, int j)
{
    for (int x = -2; x < 3; x++)
        for (int y = -2; y < 3; y++)
            if (i+x < 8 && i+x >= 0 && j+y < 8 && j+y >= 0 &&
                map[i+x][y+j].enem == 1)
                return (1);
    return (0);
}

void attack_furthest(tile_s **map, int i, int j)
{
    char orn = 0;
    char rn = 0;
    int ij;

    for (int x = -2; x < 3; x++)
        for (int y = -2; y < 3; y++)
            if (i+x < 8 && i+x >= 0 && j+y < 8 && j+y >= 0 &&
            map[i+x][y+j].enem == 1) {
                (rn < map[i+x][y+j].ir) ? (rn = map[i+x][y+j].ir) : (0);
                (orn != rn) ? (ij = (i+x)*10+(y+j)) : (0);
                (orn != rn) ? (orn = rn) : (0);
            }
    map[ij/10][ij%10].dm += 20;
}

void fire_tower_do(tile_s **map, int i, int j, ss_s *ss)
{
    ss->time = sfClock_getElapsedTime(ss->ic);
    if (ss->r.left == 0 && ss->time.microseconds/1000000.0 >= 1
    && enem_in_prox(map, i, j) == 1) {
        attack_furthest(map, i, j);
        move_rect(ss);
        sfClock_restart(ss->ic);
    }
    if (map[i][j].tower[0]->r.left != 0) {
        animate_tow(ss);
    }
}
