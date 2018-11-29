/* 
 * File:   output.c
 * Author: Awasa
 * Created on 29 de noviembre de 2018, 13:47
 */

#include "output.h"

void display_intro (ALLEGRO_BITMAP *logo,ALLEGRO_FONT *font)
{
    al_draw_scaled_bitmap(logo,0,0,al_get_bitmap_width(logo),al_get_bitmap_height(logo),0,0,DISPLAY_W,DISPLAY_H,0); //coloca el logo
    al_flip_display();  //Envia al display lo acumulado en el buffer (logo)
    al_rest(1.0);   //Lo deja durante 1 seg
    al_destroy_bitmap(logo); //Destruye el bitmap logo
    al_clear_to_color(al_map_rgb(130,130,130)); //Pone el fondo gris
    al_draw_text (font, al_map_rgb(0,0,0), 84, 65,0, "lalalala");   //Crea el texto formateado
    al_flip_display();    //Envia al display lo acumulado en el buffer (texto)
    al_rest (3.0);      //Lo deja durante 3 seg 
    al_destroy_font(font);  //Elimina la fuente
}
