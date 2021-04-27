/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** game_eight
*/

#include "my.h"

void drawtiles(my_defender_s *md, game_s *g, tile_s **map)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (map[i][j].tt != 0) {
                sfRenderWindow_drawSprite(md->window->window,
                map[i][j].tower[map[i][j].tt-1]->s, NULL);
                make_tower_think(map, i, j);
            }
        }
    }
    clear_enemies(map);
    (void)(g);
}

void draw_tower(my_defender_s *md, sfRenderWindow *w)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(w);

    md->g->gt->r.left = md->g->selected*128;
    md->g->selector->r.left = md->g->selected*288;
    md->g->gt->pos.x = mpos.x-128/2;
    md->g->gt->pos.y = mpos.y-128/2;
    sfSprite_setPosition(md->g->gt->s, md->g->gt->pos);
    sfSprite_setTextureRect(md->g->gt->s, md->g->gt->r);
    sfSprite_setTextureRect(md->g->selector->s, md->g->selector->r);
    sfRenderWindow_drawSprite(md->window->window, md->g->gt->s, NULL);
}

void clear_sm(tile_s **map)
{
    map[0][1].sm = 1;
    map[1][1].sm = 1;
    map[2][1].sm = 1;
    map[2][2].sm = 1;
    map[2][3].sm = 1;
    map[2][4].sm = 1;
    map[2][5].sm = 1;
    map[3][5].sm = 1;
    map[4][5].sm = 1;
    map[4][4].sm = 1;
    map[4][3].sm = 1;
    map[5][3].sm = 1;
    map[6][3].sm = 1;
    map[7][3].sm = 1;
}

void draw_hammer(sfRenderWindow *w, game_s *g)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(w);

    if (mpos.x < 1024 && g->selected == 5) {
        g->mhmr->pos.x = mpos.x - 40;
        g->mhmr->pos.y = mpos.y - 40;
        sfSprite_setPosition(g->mhmr->s, g->mhmr->pos);
        sfRenderWindow_drawSprite(w, g->mhmr->s, NULL);
    } else
        sfRenderWindow_setMouseCursorVisible(w, sfTrue);
}

void draw_mouse(sfRenderWindow *w, game_s *g)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(w);

    if (g->selected != 0 && mpos.x < 1024)
        sfRenderWindow_setMouseCursorVisible(w, sfFalse);
    else
        sfRenderWindow_setMouseCursorVisible(w, sfTrue);
}
