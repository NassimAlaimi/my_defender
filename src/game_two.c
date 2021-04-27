/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** game_two
*/

#include "my.h"

void make_hammer(ss_s *ss, char const *fp)
{
    ss->t = sfTexture_createFromFile(fp, NULL);
    ss->s = sfSprite_create();
    sfVector2f scale = {0.5, 0.5};
    sfSprite_setScale(ss->s, scale);
    sfSprite_setTexture(ss->s, ss->t, sfTrue);
}

void make_s_sheet(ss_s *ss, int x, int y, char const *fp)
{
    ss->r = make_rect(288, 192);
    ss->t = sfTexture_createFromFile(fp, NULL);
    ss->s = sfSprite_create();
    sfSprite_setTexture(ss->s, ss->t, sfTrue);
    sfSprite_setTextureRect(ss->s, ss->r);
    ss->pos.x = x;
    ss->pos.y = y;
    sfSprite_setPosition(ss->s, ss->pos);
}

void make_t_sheet(ss_s *ss, char const *fp)
{
    ss->r = make_rect(128, 128);
    ss->t = sfTexture_createFromFile(fp, NULL);
    ss->s = sfSprite_create();
    sfSprite_setTexture(ss->s, ss->t, sfTrue);
    sfSprite_setTextureRect(ss->s, ss->r);
}

void make_tb_sheet(ss_s *ss, int x, int y, char const *fp)
{
    ss->r = make_rect(160, 160);
    ss->t = sfTexture_createFromFile(fp, NULL);
    ss->s = sfSprite_create();
    sfSprite_setTexture(ss->s, ss->t, sfTrue);
    sfSprite_setTextureRect(ss->s, ss->r);
    ss->pos.x = x;
    ss->pos.y = y;
    sfSprite_setPosition(ss->s, ss->pos);
}

void make_bg(ss_s *ss, int x, int y, char const *fp)
{
    ss->r = make_rect(1364, 1024);
    ss->t = sfTexture_createFromFile(fp, NULL);
    ss->s= sfSprite_create();
    sfSprite_setTexture(ss->s, ss->t, sfTrue);
    sfSprite_setTextureRect(ss->s, ss->r);
    ss->pos.x = x;
    ss->pos.y = y;
    sfSprite_setPosition(ss->s, ss->pos);
}
