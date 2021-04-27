/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** game_seven
*/

#include "my.h"

void do_aoe_damage(tile_s **map, int i, int j)
{
    for (int x = -1; x < 2; x++)
        for (int y = -1; y < 2; y++)
            (i+x<8 && i+x>=0 && y+j<8 && y+j>=0)?(map[i+x][y+j].dm+=5):(0);
}

void attack_furthest_thunder(tile_s **map)
{
    int x = 0;

    (map[0][1].enem == 1) ? (x=1) : (0);
    (map[1][1].enem == 1) ? (x=11) : (0);
    (map[2][1].enem == 1) ? (x=21) : (0);
    (map[2][2].enem == 1) ? (x=22) : (0);
    (map[2][3].enem == 1) ? (x=23) : (0);
    (map[2][4].enem == 1) ? (x=24) : (0);
    (map[2][5].enem == 1) ? (x=25) : (0);
    (map[3][5].enem == 1) ? (x=35) : (0);
    (map[4][5].enem == 1) ? (x=45) : (0);
    (map[4][4].enem == 1) ? (x=44) : (0);
    (map[4][3].enem == 1) ? (x=43) : (0);
    (map[5][3].enem == 1) ? (x=53) : (0);
    (map[6][3].enem == 1) ? (x=63) : (0);
    (map[7][3].enem == 1) ? (x=73) : (0);
    map[x/10][x%10].dm += 50;
}

int check_roads(tile_s **map)
{
    if (map[0][1].enem == 1 || map[1][1].enem == 1 || map[2][1].enem == 1 ||
    map[2][2].enem == 1 || map[2][3].enem == 1 || map[2][4].enem == 1 ||
    map[2][5].enem == 1 || map[3][5].enem == 1 || map[4][5].enem == 1 ||
    map[4][4].enem == 1 || map[4][3].enem == 1 || map[5][3].enem == 1 ||
    map[6][3].enem == 1 || map[7][3].enem == 1) {
        return (1);
    }
    return (0);
}

void thunder_tower_do(tile_s **map, ss_s *ss)
{
    ss->time = sfClock_getElapsedTime(ss->ic);
    if (ss->r.left == 0 && ss->time.microseconds/1000000.0 >= 6
    && check_roads(map) == 1) {
        attack_furthest_thunder(map);
        move_rect(ss);
        sfClock_restart(ss->ic);
    }
    if (ss->r.left != 0)
        animate_tow(ss);
}

void make_tower_think(tile_s **map, int i, int j)
{
    if (map[i][j].tt == 1)
        fire_tower_do(map, i, j, map[i][j].tower[0]);
    if (map[i][j].tt == 2) {
        for (int x = -1; x < 2; x++)
            for (int y = -1; y < 2; y++)
                (i+x<8 && i+x>=0 && y+j<8 && y+j>=0) ? (map[i+x][y+j].sm=2):(0);
        animate_tow(map[i][j].tower[1]);
        (map[i][j].tower[1]->r.left == 0) ? (move_rect(map[i][j].tower[1])):(0);
    }
    if (map[i][j].tt == 3) {
        if (map[i][j].tower[2]->r.left == 15*128)
            do_aoe_damage(map, i, j);
        animate_tow(map[i][j].tower[2]);
    }
    if (map[i][j].tt == 4)
        thunder_tower_do(map, map[i][j].tower[3]);
}
