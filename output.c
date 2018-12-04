/* 
 * File:   output.c
 * Author: Awasa
 * Created on 29 de noviembre de 2018, 13:47
 */

#include "output.h"

void display_intro (ALLEGRO_BITMAP *logo,ALLEGRO_FONT *font, uint16_t width, uint16_t high)
{
    al_draw_scaled_bitmap(logo,0,0,al_get_bitmap_width(logo),al_get_bitmap_height(logo),0,0,width,high,0); //coloca el logo
    al_flip_display();  //Envia al display lo acumulado en el buffer (logo)
    al_rest(1.0);   //Lo deja durante 1 seg
    al_destroy_bitmap(logo); //Destruye el bitmap logo
    al_clear_to_color(al_map_rgb(130,130,130)); //Pone el fondo gris
    al_draw_text (font, al_map_rgb(0,0,0), width/10, high/2,0, "Alumnos");   //Crea el texto formateado
    al_flip_display();    //Envia al display lo acumulado en el buffer (texto)
    al_rest (3.0);      //Lo deja durante 3 seg 
    al_destroy_font(font);  //Elimina la fuente
}

void display_menu (ALLEGRO_BITMAP *menu, ALLEGRO_FONT *font, uint16_t width, uint16_t high)
{
    al_draw_scaled_bitmap (menu,0,0,al_get_bitmap_width(menu),al_get_bitmap_height(menu),0,0,width,high,0);
    al_draw_text (font, al_map_rgb(0,0,0), width/2, high/10,ALLEGRO_ALIGN_CENTRE, "SNAKE");
    al_draw_text (font, al_map_rgb(0,0,0), width/2, high/2,ALLEGRO_ALIGN_CENTRE, "Jugar");
    al_draw_text (font, al_map_rgb(0,0,0), width/2, high*6/10,ALLEGRO_ALIGN_CENTRE, "Mejores puntajes");
    al_draw_text (font, al_map_rgb(0,0,0), width/2, high*7/10,ALLEGRO_ALIGN_CENTRE, "Opciones");
    al_draw_text (font, al_map_rgb(0,0,0), width/2, high*8/10,ALLEGRO_ALIGN_CENTRE, "Creditos");
    al_flip_display();
    al_rest(3.0);
    al_destroy_bitmap(menu);
    al_destroy_font (font);
}
