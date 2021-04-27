/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** option_one
*/

#include "my.h"

void make_htp_react(sfRenderWindow *w, ss_s *ss)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(w);

    if (mpos.x >= ss->pos.x && mpos.x <= ss->pos.x+160 && mpos.y >= ss->pos.y
    && mpos.y <= ss->pos.y+104) {
        ss->r.left = 160;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            ss->r.left += 160;
        }
    } else {
        ss->r.left = 0;
    }
    sfSprite_setTextureRect(ss->s, ss->r);
    sfRenderWindow_drawSprite(w, ss->s, NULL);
}

void make_htp_sheet(ss_s *ss, int x, int y, char const *fp)
{
    ss->r = make_rect(160, 104);
    ss->t = sfTexture_createFromFile(fp, NULL);
    ss->s = sfSprite_create();
    sfSprite_setTexture(ss->s, ss->t, sfTrue);
    sfSprite_setTextureRect(ss->s, ss->r);
    ss->pos.x = x;
    ss->pos.y = y;
    sfSprite_setPosition(ss->s, ss->pos);
}