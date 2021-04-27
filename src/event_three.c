/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** event_three
*/

#include "my.h"

void mouse_click_htp(my_defender_s *md)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(md->window->window);

    if (md->window->event.mouseButton.button == sfMouseLeft) {
        if (mpos.x >= 10 && mpos.x <= 10+160 && mpos.y >= 10
            && mpos.y <= 10+80)
            md->scene = 2;
    }
}