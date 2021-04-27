/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** game_four
*/

#include "my.h"

void clear_roads(tile_s **map)
{
    map[0][1].dm = 0;
    map[1][1].dm = 0;
    map[2][1].dm = 0;
    map[2][2].dm = 0;
    map[2][3].dm = 0;
    map[2][4].dm = 0;
    map[2][5].dm = 0;
    map[3][5].dm = 0;
    map[4][5].dm = 0;
    map[4][4].dm = 0;
    map[4][3].dm = 0;
    map[5][3].dm = 0;
    map[6][3].dm = 0;
    map[7][3].dm = 0;
}

void prep_map(tile_s **map)
{
    mark_road(map);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            map[i][j].tt = 0;
            make_tower_sheet(map[i][j].tower[0], "./sprites/g/FT1.png", \
            896, i*10+j);
            make_tower_sheet(map[i][j].tower[1], "./sprites/g/IT3.png", 1536, \
            i*10+j);
            make_tower_sheet(map[i][j].tower[2], "./sprites/g/ET.png", 2688, \
            i*10+j);
            make_tower_sheet(map[i][j].tower[3], "./sprites/g/LT.png", 1152, \
            i*10+j);
        }
}

void load_sounds(sfx_s *sfx)
{
    sfx->df = sfSoundBuffer_createFromFile("./sprites/g/die.wav");
    sfx->bf = sfSoundBuffer_createFromFile("./sprites/g/build.wav");
    sfx->build = sfSound_create();
    sfx->die = sfSound_create();
    sfSound_setBuffer(sfx->die, sfx->df);
    sfSound_setBuffer(sfx->build, sfx->bf);
}

void load_game_sprites(game_s *g)
{
    prep_map(g->map);
    make_t_sheet(g->gt, "./sprites/g/Ghosttowers.png");
    make_s_sheet(g->selector, 1050, 550, "./sprites/g/Select.png");
    make_tb_sheet(g->ds, 1196, 905, "./sprites/g/Deselect.png");
    make_tb_sheet(g->hmr, 1032, 905, "./sprites/g/Delete.png");
    make_tb_sheet(g->ftb, 1032, 180, "./sprites/g/FTB.png");
    make_tb_sheet(g->itb, 1196, 180, "./sprites/g/ITB.png");
    make_tb_sheet(g->gtb, 1032, 348, "./sprites/g/ETB.png");
    make_tb_sheet(g->ltb, 1196, 348, "./sprites/g/LTB.png");
    load_sounds(g->sfx);
    make_enemies(g->en);
    make_bg(g->bg, 0, 0, "./sprites/g/Map.png");
    make_bg(g->sb, 1024, 0, "./sprites/g/SB.png");
    make_coin(g->coin);
    make_life(g->life);
    make_scores(g->score);
    make_hammer(g->mhmr, "./sprites/g/hammer.png");
}

void move_rect(ss_s *ss)
{
    ss->r.left += ss->r.width;
    if (ss->r.left >= ss->leftmax)
        ss->r.left = 0;
    sfSprite_setTextureRect(ss->s, ss->r);
}
