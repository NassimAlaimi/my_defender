/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-emile.ettel
** File description:
** option
*/

#include "my.h"

void make_back_sheet(ss_s *ss, int x, int y, char const *fp)
{
    ss->r = make_rect(160, 80);
    ss->t = sfTexture_createFromFile(fp, NULL);
    ss->s = sfSprite_create();
    sfSprite_setTexture(ss->s, ss->t, sfTrue);
    sfSprite_setTextureRect(ss->s, ss->r);
    ss->pos.x = x;
    ss->pos.y = y;
    sfSprite_setPosition(ss->s, ss->pos);
}

void make_ba_react(sfRenderWindow *w, ss_s *ss)
{
    sfVector2i mpos = sfMouse_getPositionRenderWindow(w);

    if (mpos.x >= ss->pos.x && mpos.x <= ss->pos.x+160 && mpos.y >= ss->pos.y
    && mpos.y <= ss->pos.y+80) {
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

void make_text(text_s *text, int x, int y, char *str)
{
    sfVector2f scale = {2, 2};
    sfFont *font = sfFont_createFromFile("Gameplay.ttf");
    text->text = sfText_create();
    text->pos = (sfVector2f) {x, y};
    sfText_setScale(text->text, scale);
    sfText_setPosition(text->text, text->pos);
    sfText_setString(text->text, str);
    sfText_setFont(text->text, font);
    sfText_setColor(text->text, sfWhite);
}

void load_option_sprites(my_defender_s *md)
{
    make_htp_sheet(md->sprite->o->htpb, 592, 834, "./sprites/option/htpb.png");
    make_text(md->sprite->o->music, 300, 460, "Music :");
    make_text(md->sprite->o->sound, 300, 660, "Sound :");
    make_text(md->sprite->o->setting, md->window->mode.width/2 - 150, 150, \
    "Settings");
    make_bg(md->sprite->o->bg, 0, 0, "./sprites/option/bg_option.png");
    make_tb_sheet(md->sprite->o->mon, 1000, 400, "./sprites/option/music.png");
    make_tb_sheet(md->sprite->o->moff, 1000, 400,   \
    "./sprites/option/musicoff.png");
    make_tb_sheet(md->sprite->o->son, 1000, 600, "./sprites/option/sound.png");
    make_tb_sheet(md->sprite->o->soff, 1000, 600,   \
    "./sprites/option/soundoff.png");
    make_back_sheet(md->sprite->o->ba, 10, 10, "./sprites/option/back.png");
}

void option(my_defender_s *md)
{
    sfRenderWindow_drawSprite(md->window->window, md->sprite->o->bg->s, NULL);
    make_ba_react(md->window->window, md->sprite->o->ba);
    sfRenderWindow_drawText(md->window->window, md->sprite->o->music->text, \
    NULL);
    sfRenderWindow_drawText(md->window->window, md->sprite->o->sound->text, \
    NULL);
    sfRenderWindow_drawText(md->window->window, md->sprite->o->setting->text, \
    NULL);
    make_htp_react(md->window->window, md->sprite->o->htpb);
    if (md->sprite->o->ms == 1)
        make_button_react(md->window->window, md->sprite->o->mon);
    else
        make_button_react(md->window->window, md->sprite->o->moff);
    if (md->sprite->o->ss == 1)
        make_button_react(md->window->window, md->sprite->o->son);
    else
        make_button_react(md->window->window, md->sprite->o->soff);
}
