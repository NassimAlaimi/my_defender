/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** pause
*/

#include "my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Mouse.h>

void redo_map(tile_s **map)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            map[i][j].tt = 0;
            for (int x = 0; x < 4; x++) {
                map[i][j].tower[x]->r.left = 0;
                sfSprite_setTextureRect(map[i][j].tower[x]->s,
                map[i][j].tower[x]->r);
            }
        }
}

void reposition_enem(enemies_s *en)
{
    for (int i = 0; i < 20; i++)
        redo_stat(en->st[i], (5*i)+5, en->ss[i], 96);
    for (int i = 20; i < 40; i++)
        redo_stat(en->st[i], (5*(i-20))+40, en->ss[i], 96);
    for (int i = 40; i < 50; i++)
        redo_stat(en->st[i], (10*(i-40))+60, en->ss[i], 127);
}

void redo_game(game_s *g)
{
    g->coin->var = 200;
    g->life->var = 10;
    g->score->var = 0;
    reposition_enem(g->en);
    redo_map(g->map);
}

void make_pbut_react(sfRenderWindow *w, ss_s *ss)
{
    sfVector2i mpos =sfMouse_getPositionRenderWindow(w);

    if (mpos.x>=ss->pos.x && mpos.x<=ss->pos.x+ss->r.width && mpos.y>=ss->pos.y
    && mpos.y <= ss->pos.y+ss->r.height) {
        ss->r.left = ss->r.width*1;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            ss->r.left = ss->r.width*2;
        }
    } else {
        ss->r.left = 0;
    }
    sfSprite_setTextureRect(ss->s, ss->r);
    sfRenderWindow_drawSprite(w, ss->s, NULL);
}

void in_pause(my_defender_s *md, ss_s **pause)
{
    sfRenderWindow_drawSprite(md->window->window, pause[0]->s, NULL);
    make_pbut_react(md->window->window, pause[1]);
    make_pbut_react(md->window->window, pause[2]);
    make_pbut_react(md->window->window, pause[3]);
}
