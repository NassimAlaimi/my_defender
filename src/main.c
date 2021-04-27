/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** main.c
*/

#include "my.h"
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>

void free_map(tile_s **map, game_s *g)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            free(map[i][j].tower[0]);
            free(map[i][j].tower[1]);
            free(map[i][j].tower[2]);
            free(map[i][j].tower[3]);
        }
        free(map[i]);
    }
    free(map);
    sfSound_destroy(g->sfx->build);
    sfSound_destroy(g->sfx->die);
    sfSoundBuffer_destroy(g->sfx->bf);
    sfSoundBuffer_destroy(g->sfx->df);
    free(g->sfx);
    for (int i = 0; i < 50; i++) {
        free(g->en->st[i]);
        free(g->en->ss[i]);
    }
    free(g->en);
}

void free_game(game_s *g)
{
    free(g->coin);
    free(g->life);
    free(g->score);
    free(g->selector);
    free(g->hmr);
    free(g->ds);
    free(g->gt);
    free(g->bg);
    free(g->sb);
    free(g->ftb);
    free(g->itb);
    free(g->gtb);
    free(g->ltb);
    free(g->mhmr);
    free_map(g->map, g);
    free(g);
}

void free_option(option_s *op)
{
    free(op->setting);
    free(op->music);
    free(op->sound);
    free(op->bg);
    free(op->mon);
    free(op->moff);
    free(op->son);
    free(op->soff);
    free(op->ba);
    free(op->htpb);
    free(op->htp);
    free(op);
}

void free_defender(my_defender_s *md)
{
    free_game(md->g);
    sfMusic_destroy(md->game->m);
    sfMusic_destroy(md->menu->m);
    sfMusic_destroy(md->option->m);
    free(md->menu);
    free(md->option);
    free(md->game);
    free(md->sprite->o);
    for (int i = 0; i < 3; i++) {
        free(md->pause[i]);
        free(md->go[i]);
    }
    free(md->pause[3]);
    free(md->sprite->menu->playb);
    free(md->sprite->menu->bg);
    free(md->sprite->menu->exitb);
    free(md->sprite->menu->optionb);
    free(md->sprite->menu);
    free(md->sprite);
    free(md);
}

int main(int ac, char **av)
{
    my_defender_s *my_defender = malloc_my_defender();
    (void)ac;
    (void)av;
    config_window(my_defender);
    loading_screen(my_defender);
    load_sprite_menu(my_defender);
    load_htp(my_defender->sprite->o);
    load_game_sprites(my_defender->g);
    load_option_sprites(my_defender);
    load_pause_menu(my_defender->pause);
    load_game_over(my_defender->go);
    loop(my_defender);
    free_defender(my_defender);
    return (0);
}
