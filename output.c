/* 
 * File:   output.c
 * Author: Awasa
 * Created on 29 de noviembre de 2018, 13:47
 */

#include "output.h"

void display_logo (ALLEGRO_BITMAP *logo, ALLEGRO_FONT *mensaje, uint16_t width, uint16_t high)
{
    ALLEGRO_COLOR gris_claro = al_map_rgb(150,150,150);
    
    al_draw_scaled_bitmap(logo,0,0,al_get_bitmap_width(logo),al_get_bitmap_height(logo),0,0,width,high,0); //coloca el logo
    al_draw_text (mensaje, gris_claro, width*0.75, high*0.95,0, "Presione espacio para continuar");   //Crea el texto formateado
    al_flip_display();  //Envia al display lo acumulado en el buffer (logo)  
}

void display_info (ALLEGRO_BITMAP *logo, ALLEGRO_FONT *titulo, ALLEGRO_FONT *subtitulo, ALLEGRO_FONT *mensaje,  uint16_t width, uint16_t high)
{
    ALLEGRO_COLOR negro = al_map_rgb(0,0,0);
    ALLEGRO_COLOR gris_claro1 = al_map_rgb(150,150,150);
    ALLEGRO_COLOR gris_claro2 = al_map_rgb(230,230,230);
    
    al_clear_to_color(gris_claro2); //Pone el fondo gris
    al_draw_text (titulo, negro, width*0.5, high*0.1,ALLEGRO_ALIGN_CENTRE, "Trabajo Práctico");
    al_draw_text (titulo, negro, width*0.5, high*0.22,ALLEGRO_ALIGN_CENTRE, "Final");
    al_draw_text (subtitulo, negro, width*0.1, high*0.45,0, "Cátedra : Programación I");   //Crea el texto formateado
    al_draw_text (subtitulo, negro, width*0.1, high*0.55,0, "Alumnos : Pintos, Gonzalo Agustín ");   //Crea el texto formateado
    al_draw_text (subtitulo, negro, width*0.28, high*0.62,0, "Terra Brandes Britos, Ignacio");   //Crea el texto formateado
    al_draw_text (subtitulo, negro, width*0.1, high*0.72,0, "Profesores : Jacoby, Daniel Andres");   //Crea el texto formateado
    al_draw_text (subtitulo, negro, width*0.32, high*0.79,0, "Magliola, Nicolas ");   //Crea el texto formateado
    al_draw_text (subtitulo, negro, width*0.32, high*0.86,0, "Vacatello, Pablo Daniel ");   //Crea el texto formateado
    al_draw_text (mensaje, gris_claro1, width*0.75, high*0.93,0, "Presione espacio para continuar");   //Crea el texto formateado
    al_flip_display();    //Envia al display lo acumulado en el buffer (texto y fondo)                                                                                             al_destroy_font(font);  //Elimina la fuente
}

void display_menu (ALLEGRO_BITMAP *menu, ALLEGRO_FONT *titulo, ALLEGRO_FONT *opciones, uint16_t width, uint16_t high, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3)
{
    ALLEGRO_COLOR negro = al_map_rgb(0,0,0);
    ALLEGRO_COLOR rojo = al_map_rgb(255,0,0);
    
    al_draw_scaled_bitmap (menu,0,0,al_get_bitmap_width(menu),al_get_bitmap_height(menu),0,0,width,high,0);
    al_draw_text (titulo, negro, width/2, high/10,ALLEGRO_ALIGN_CENTRE, "SNAKE");
    al_draw_text (opciones, negro, width/2, high/2,ALLEGRO_ALIGN_CENTRE, "Jugar");
    al_draw_text (opciones, negro, width/2, high*6/10,ALLEGRO_ALIGN_CENTRE, "Mejores puntajes");
    al_draw_text (opciones, negro, width/2, high*7/10,ALLEGRO_ALIGN_CENTRE, "Opciones");
    al_draw_text (opciones, negro, width/2, high*8/10,ALLEGRO_ALIGN_CENTRE, "Salir");
    al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, rojo);
    al_flip_display();
}


