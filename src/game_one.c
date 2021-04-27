/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** game_one
*/

#include "my.h"

sfIntRect make_rect(int x, int y)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = x;
    rect.height = y;
    return (rect);
}

void make_life(text_s *life)
{
    sfFont *font = sfFont_createFromFile("Gameplay.ttf");
    life->text = sfText_create();
    life->pos = (sfVector2f) {1185, 118};
    life->var = 10;
    char *score = my_int_to_str(life->var);
    sfText_setPosition(life->text, life->pos);
    sfText_setString(life->text, score);
    sfText_setFont(life->text, font);
    sfText_setColor(life->text, sfWhite);
}

void make_coin(text_s *coin)
{
    sfFont *font = sfFont_createFromFile("Gameplay.ttf");
    coin->text = sfText_create();
    coin->pos = (sfVector2f) {1160, 32};
    coin->var = 200;
    char *money = my_int_to_str(coin->var);
    sfText_setPosition(coin->text, coin->pos);
    sfText_setString(coin->text, money);
    sfText_setFont(coin->text, font);
    sfText_setColor(coin->text, sfWhite);
}

void make_scores(text_s *t)
{
    sfFont *font = sfFont_createFromFile("Gameplay.ttf");
    t->text = sfText_create();
    t->pos = (sfVector2f) {682, 400};
    sfText_setPosition(t->text, t->pos);
    sfText_setFont(t->text, font);
    sfText_setColor(t->text, sfWhite);
}

void text_loop(sfRenderWindow *w, text_s *coin, text_s *life)
{
    char *money = my_int_to_str(coin->var);
    char *heart = my_int_to_str(life->var);
    sfText_setString(coin->text, money);
    sfText_setString(life->text, heart);
    sfRenderWindow_drawText(w, coin->text, NULL);
    sfRenderWindow_drawText(w, life->text, NULL);
}
