/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

/* Include */
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>
#include <SFML/Window.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Mouse.h>
#include <unistd.h>
#include <stdlib.h>
/* Struct */

typedef struct text_t {
    int var;
    sfText *text;
    sfVector2f pos;
} text_s;

typedef struct sfx_t {
    sfSound *build;
    sfSoundBuffer *bf;
    sfSound *die;
    sfSoundBuffer *df;
} sfx_s;

typedef struct ss_t {
    int price;
    sfSprite *s;
    sfTexture *t;
    sfIntRect r;
    sfVector2f pos;
    sfClock *ic;
    int leftmax;
    sfTime time;
    int status;
} ss_s;

typedef struct tile_t {
    char ir;
    _Bool enem;
    int sm;
    ss_s *tower[4];
    int tt;
    int dm;
} tile_s;

typedef struct option_t {
    ss_s *bg;
    ss_s *mon;
    ss_s *moff;
    ss_s *son;
    ss_s *soff;
    ss_s *ba;
    ss_s *htpb;
    ss_s *htp;
    int ms;
    int ss;
    text_s *setting;
    text_s *music;
    text_s *sound;
} option_s;

typedef struct menu_t {
    ss_s *bg;
    ss_s *playb;
    ss_s *exitb;
    ss_s *optionb;
} menu_s;

typedef struct sprite_t {
    /* Struct */
    menu_s *menu;
    option_s *o;
} sprite_s;

typedef struct stats_t {
    int hp_base;
    int hp;
    int speed;
    int dist;
    int dc;
    sfClock *dt;
    sfTime time;
    int dtlim;
} stat_s;

typedef struct enemies_t {
    stat_s *st[50];
    ss_s *ss[50];
} enemies_s;

typedef struct game_t {
    text_s *coin;
    text_s *life;
    text_s *score;
    ss_s *selector;
    int selected;
    ss_s *hmr;
    ss_s *ds;
    ss_s *gt;
    ss_s *bg;
    ss_s *sb;
    ss_s *ftb;
    ss_s *itb;
    ss_s *gtb;
    ss_s *ltb;
    ss_s *mhmr;
    int tn;
    sfx_s *sfx;
    enemies_s *en;
    tile_s **map;
    int mouseclick;
} game_s;

typedef struct window_t {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
} window_s;

typedef struct music_t {
    sfMusic *m;
    float vol;
} music_s;

typedef struct my_defender_t
{
    /* Strcut */
    sprite_s *sprite;
    game_s *g;
    window_s *window;
    ss_s *pause[4];
    ss_s *go[3];
    /* Scène */
    int scene;
    /* Music */
    music_s *menu;
    music_s *game;
    music_s *option;
} my_defender_s;

/* Lib Fonction */
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
void my_swap(int a, int b);
char *my_strupcase(char *str);
int word_check(char *str, char const *to_find, int i, char **sub_ptr);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, size_t n);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *my_strcapitalize(char *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *array, int size);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_atoi(const char *nptr);
int my_show_word_array(char **tab);
int my_array_len(char **array);
char *my_int_to_str(int nb);
int my_is_number(char c);
char *my_strdup(char const *src);
int my_is_char_in_str(char c, char *str);

/* Project Fonction */
void in_pause(my_defender_s *md, ss_s **pause);
void make_pbut_react(sfRenderWindow *w, ss_s *ss);
void redo_game(game_s *g);
void reposition_enem(enemies_s *en);
void redo_map(tile_s **map);
void redo_stat(stat_s *st, int dtlim, ss_s *ss, int posy);
void add_pause_time(game_s *g, ss_s *p);
void load_pause_menu(ss_s **pause);
void create_pause_buttons(ss_s *ss, char const *fp, int posx, int posy);
void config_window(my_defender_s *my_defender);
void config_struct(my_defender_s *my_defender);
void react_enems(enemies_s *en, tile_s **map, game_s *g);
void load_game_sprites(game_s *g);
void loop(my_defender_s *my_defender);
void event(my_defender_s *my_defender);
void text_loop(sfRenderWindow *w, text_s *coin, text_s *life);
void make_scores(text_s *t);
void make_coin(text_s *coin);
void make_life(text_s *life);
void make_t_sheet(ss_s *ss, char const *fp);
void make_s_sheet(ss_s *ss, int x, int y, char const *fp);
void make_hammer(ss_s *ss, char const *fp);
void mark_road(tile_s **map);
void make_tower_sheet(ss_s *ss, char const *fp, int leftmax, int ij);
void make_enemies(enemies_s *en);
void make_stat(stat_s *st, int dtlim, int speed, int hp);
void make_en(ss_s *ss, char const *fp, int leftmax, int posy);
void game(my_defender_s *md);
void menu(my_defender_s *my_defender);
void option(my_defender_s *md);
void load_sprite_menu(my_defender_s *my_defender);
void load_option_sprites(my_defender_s *md);
void move_rect(ss_s *ss);
void load_game_sprites(game_s *g);
void load_sounds(sfx_s *sfx);
void prep_map(tile_s **map);
void clear_roads(tile_s **map);
void make_bg(ss_s *ss, int x, int y, char const *fp);
void loading_screen(my_defender_s *md);
void make_tb_sheet(ss_s *ss, int x, int y, char const *fp);
void make_button_react(sfRenderWindow *w, ss_s *ss);
sfIntRect make_rect(int x, int y);
void make_button_react(sfRenderWindow *w, ss_s *ss);
void move_by_one(stat_s *st, ss_s *ss);
void enem_death(stat_s *st, ss_s *ss, game_s *g, int worth);
void change_pos(stat_s *st, ss_s *ss, game_s *g, int worth);
void clear_enemies(tile_s **map);
void fire_tower_do(tile_s **map, int i, int j, ss_s *ss);
void attack_furthest(tile_s **map, int i, int j);
int enem_in_prox(tile_s **map, int i, int j);
void animate_tow(ss_s *ss);
void move_enemies(my_defender_s *md, enemies_s *en, game_s *g);
void make_tower_think(tile_s **map, int i, int j);
void thunder_tower_do(tile_s **map, ss_s *ss);
int check_roads(tile_s **map);
void attack_furthest_thunder(tile_s **map);
void do_aoe_damage(tile_s **map, int i, int j);
void draw_mouse(sfRenderWindow *w, game_s *g);
void draw_hammer(sfRenderWindow *w, game_s *g);
void clear_sm(tile_s **map);
void draw_tower(my_defender_s *md, sfRenderWindow *w);
void drawtiles(my_defender_s *md, game_s *g, tile_s **map);
void change_m_status(option_s *o);
void change_s_status(option_s *o, my_defender_s *md);
void change_m_vol(my_defender_s *md);
void sell_tower(game_s *g, sfVector2i mpos);
int check_money(game_s *g);
void mouse_click_menu(my_defender_s *md, sfVector2i mpos);
void mouse_click_game(my_defender_s *md, game_s *g, sfVector2i mpos);
void mouse_button_click(sfVector2i mpos, game_s *g);
void restart_clocks(game_s *g);
void mouse_click_option(my_defender_s *md, sfVector2i mpos);
tile_s **malloc_map(void);
game_s *malloc_texts(game_s *g);
void load_music_option(music_s *option);
void load_music_game(music_s *game);
void load_music_menu(music_s *menu);
void game_over_screen(ss_s **go, my_defender_s *md);
void load_game_over(ss_s **go);
void load_htp(option_s *o);
void make_back_sheet(ss_s *ss, int x, int y, char const *fp);
void make_ba_react(sfRenderWindow *w, ss_s *ss);
void htp(my_defender_s *md);
void make_htp_sheet(ss_s *ss, int x, int y, char const *fp);
void make_htp_react(sfRenderWindow *w, ss_s *ss);
void mouse_click_htp(my_defender_s *md);

/* Malloc Struct */
my_defender_s *malloc_my_defender(void);
menu_s *malloc_menu(void);
window_s *malloc_window(void);
sprite_s *malloc_sprite(void);
game_s *malloc_game(void);
option_s *malloc_option(void);




#endif /* !MY_H_ */
