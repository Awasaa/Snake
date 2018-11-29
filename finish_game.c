/* 
 * File:   finish_game.c
 * Author: Awasa
 * Created on 28 de noviembre de 2018, 18:47
 */

#include "finish_game.h"

void close_allegro (ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font)
{
    al_uninstall_system();
    al_shutdown_image_addon();
    al_destroy_display(display);
    al_destroy_font(font);
    al_shutdown_font_addon();
    al_shutdown_ttf_addon();
}
