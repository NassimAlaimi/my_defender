/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** malloc_struct.c
*/

#include "my.h"

game_s *malloc_game_part(game_s *g)
{
    g->bg = malloc(sizeof(ss_s));
    g->sb = malloc(sizeof(ss_s));
    g->ftb = malloc(sizeof(ss_s));
    g->itb = malloc(sizeof(ss_s));
    g->hmr = malloc(sizeof(ss_s));
    g->mhmr = malloc(sizeof(ss_s));
    g->gtb = malloc(sizeof(ss_s));
    g->ltb = malloc(sizeof(ss_s));
    g->gt = malloc(sizeof(ss_s));
    g->ds = malloc(sizeof(ss_s));
    g->selector = malloc(sizeof(ss_s));
    return (g);
}

game_s *malloc_game(void)
{
    game_s *g = malloc(sizeof(game_s));
    g = malloc_game_part(g);
    g->sfx = malloc(sizeof(sfx_s));
    g->en = malloc(sizeof(enemies_s));
    g = malloc_texts(g);
    g->map = malloc_map();
    for (int i = 0; i < 50; i++) {
        g->en->ss[i] = malloc(sizeof(ss_s));
        g->en->st[i] = malloc(sizeof(stat_s));
    }
    return (g);
}

menu_s *malloc_menu(void)
{
    menu_s *m = malloc(sizeof(menu_s));
    m->bg = malloc(sizeof(ss_s));
    m->playb = malloc(sizeof(ss_s));
    m->optionb = malloc(sizeof(ss_s));
    m->exitb = malloc(sizeof(ss_s));
    return (m);
}

option_s *malloc_option(void)
{
    option_s *o = malloc(sizeof(option_s));
    o->bg = malloc(sizeof(ss_s));
    o->ba = malloc(sizeof(ss_s));
    o->htpb = malloc(sizeof(ss_s));
    o->htp = malloc(sizeof(ss_s));
    o->mon = malloc(sizeof(ss_s));
    o->moff = malloc(sizeof(ss_s));
    o->son = malloc(sizeof(ss_s));
    o->soff = malloc(sizeof(ss_s));
    o->music = malloc(sizeof(text_s));
    o->setting = malloc(sizeof(text_s));
    o->sound = malloc(sizeof(text_s));
    return (o);
}

my_defender_s *malloc_my_defender(void)
{
    my_defender_s *md = malloc(sizeof(my_defender_s));
    md->sprite = malloc(sizeof(sprite_s));
    md->g = malloc_game();
    md->window = malloc(sizeof(window_s));
    md->sprite->menu = malloc_menu();
    md->sprite->o = malloc_option();
    md->menu = malloc(sizeof(music_s));
    md->game = malloc(sizeof(music_s));
    md->option = malloc(sizeof(music_s));
    for (int i = 0; i < 4; i++)
        md->pause[i] = malloc(sizeof(ss_s));
    for (int i = 0; i < 3; i++)
        md->go[i] = malloc(sizeof(ss_s));
    return (md);
}
