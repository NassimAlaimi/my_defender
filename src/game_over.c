/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** game_over
*/

#include "my.h"
#include <SFML/Graphics/RenderWindow.h>

void make_mmgo_but(ss_s *ss)
{
    ss->s = sfSprite_create();
    ss->t = sfTexture_createFromFile("./sprites/go/mmgo.png", NULL);
    sfSprite_setTexture(ss->s, ss->t, sfTrue);
    ss->r = make_rect(718, 171);
    ss->pos.x = 331;
    ss->pos.y = 640;
    sfSprite_setPosition(ss->s, ss->pos);
    sfSprite_setTextureRect(ss->s, ss->r);
}

void make_exgo_but(ss_s *ss)
{
    ss->s = sfSprite_create();
    ss->t = sfTexture_createFromFile("./sprites/go/exgo.png", NULL);
    sfSprite_setTexture(ss->s, ss->t, sfTrue);
    ss->r = make_rect(584, 139);
    ss->pos.x = 391-2;
    ss->pos.y = 852-3;
    sfSprite_setPosition(ss->s, ss->pos);
    sfSprite_setTextureRect(ss->s, ss->r);
}

void load_game_over(ss_s **go)
{
    go[0]->s = sfSprite_create();
    go[0]->t = sfTexture_createFromFile("./sprites/go/GO.png", NULL);
    sfSprite_setTexture(go[0]->s, go[0]->t, sfTrue);
    go[0]->ic = sfClock_create();
    make_mmgo_but(go[1]);
    make_exgo_but(go[2]);
}

void game_over_screen(ss_s **go, my_defender_s *md)
{
    char *score = my_int_to_str(md->g->score->var);

    sfRenderWindow_drawSprite(md->window->window, go[0]->s, NULL);
    make_pbut_react(md->window->window, go[1]);
    make_pbut_react(md->window->window, go[2]);
    sfText_setString(md->g->score->text, score);
    sfRenderWindow_drawText(md->window->window, md->g->score->text, NULL);

}
