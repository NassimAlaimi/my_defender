/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** game_nine
*/

#include "my.h"

void load_music_option(music_s *option)
{
    option->vol = 50;
    option->m = sfMusic_createFromFile("music/option.ogg");
    sfMusic_setVolume(option->m, option->vol);
    sfMusic_setLoop(option->m, 1);
}

void load_music_game(music_s *game)
{
    game->vol = 50;
    game->m = sfMusic_createFromFile("music/game.ogg");
    sfMusic_setVolume(game->m, game->vol);
    sfMusic_setLoop(game->m, 1);
}

void load_music_menu(music_s *menu)
{
    menu->vol = 50;
    menu->m = sfMusic_createFromFile("music/menu.ogg");
    sfMusic_setVolume(menu->m, menu->vol);
    sfMusic_play(menu->m);
    sfMusic_setLoop(menu->m, 1);
}

tile_s **malloc_map(void)
{
    tile_s **map = malloc(sizeof(tile_s*)*9);
    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(tile_s)*9);
        for (int j = 0; j < 8; j++) {
            map[i][j].tower[0] = malloc(sizeof(ss_s));
            map[i][j].tower[1] = malloc(sizeof(ss_s));
            map[i][j].tower[2] = malloc(sizeof(ss_s));
            map[i][j].tower[3] = malloc(sizeof(ss_s));
        }
    }
    return (map);
}

game_s *malloc_texts(game_s *g)
{
    g->coin = malloc(sizeof(text_s));
    g->life = malloc(sizeof(text_s));
    g->score = malloc(sizeof(text_s));
    return (g);
}
