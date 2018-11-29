/* 
 * File:   output.h
 * Author: Awasa
 * Created on 29 de noviembre de 2018, 13:47
 */

#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdint.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>



void    display_intro    (ALLEGRO_BITMAP *,ALLEGRO_FONT *);  //Pone en pantalla el diseño del logo
uint8_t display_world   (ALLEGRO_DISPLAY *);    //Se muestra el mundo en el display
uint8_t display_snake   (ALLEGRO_DISPLAY *);    //Se muestra la serpiente en el display


#endif /* OUTPUT_H */
