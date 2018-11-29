/* 
 * File:   finish_game.c
 * Author: Awasa
 * Created on 28 de noviembre de 2018, 18:47
 */

#include "finish_game.h"

void close_allegro (ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font)
{
    al_shutdown_image_addon();      //"Apaga" el sistema de imagen
    al_destroy_display(display);    //Destruye el display
    al_destroy_font(font);          //Destruye la fuente
    al_shutdown_font_addon();       //"Apaga" el sistema de fuente
    al_shutdown_ttf_addon();        //"Apaga" el "true type font"
    al_uninstall_system();          //"Apaga" el sistema de allegro
}
