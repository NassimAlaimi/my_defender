/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** game
*/

#include "my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Mouse.h>


void react_enems(enemies_s *en, tile_s **map, game_s *g)
{
    for (int i = 0; i < 50; i++) {
        if (en->st[i]->hp > 0 && en->st[i]->dist != 0) {
            en->st[i]->hp -= map[(int)(en->ss[i]->pos.x/128)]   \
            [(int)(en->ss[i]->pos.y/128)+1].dm;
            if (en->st[i]->hp <= 0) {
                enem_death(en->st[i], en->ss[i], g, 10*(1+i/20));
                g->score->var += 10*(1+i/20);
            }
        }
    }
    clear_sm(map);
    clear_roads(map);
}

void game(my_defender_s *md)
{
    sfRenderWindow_drawSprite(md->window->window, md->g->bg->s, NULL);
    move_enemies(md, md->g->en, md->g);
    react_enems(md->g->en, md->g->map, md->g);
    drawtiles(md, md->g, md->g->map);
    draw_tower(md, md->window->window);
    sfRenderWindow_drawSprite(md->window->window, md->g->sb->s, NULL);
    sfRenderWindow_drawSprite(md->window->window, md->g->selector->s, NULL);
    make_button_react(md->window->window, md->g->ftb);
    make_button_react(md->window->window, md->g->itb);
    make_button_react(md->window->window, md->g->gtb);
    make_button_react(md->window->window, md->g->ltb);
    make_button_react(md->window->window, md->g->ds);
    make_button_react(md->window->window, md->g->hmr);
    text_loop(md->window->window, md->g->coin, md->g->life);
    draw_hammer(md->window->window, md->g);
    draw_mouse(md->window->window, md->g);
    if (md->g->life->var <= 0) {
        md->scene = 4;
        sfMusic_stop(md->game->m);
    }
}
