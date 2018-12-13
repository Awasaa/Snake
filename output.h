/* 
 * File:   output.h
 * Author: Awasa
 * Created on 29 de noviembre de 2018, 13:47
 */

#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include <stdint.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>




void    display_logo        (ALLEGRO_BITMAP *, ALLEGRO_FONT *, uint16_t, uint16_t);  //Pone en pantalla el diseño del logo
void    display_info        (ALLEGRO_BITMAP *, ALLEGRO_FONT *, ALLEGRO_FONT *, ALLEGRO_FONT *, uint16_t, uint16_t);
void    display_menu        (ALLEGRO_BITMAP *, ALLEGRO_FONT *, ALLEGRO_FONT *, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
void    display_best_score  (ALLEGRO_BITMAP *, ALLEGRO_FONT *, ALLEGRO_FONT *, ALLEGRO_FONT *, uint16_t, uint16_t, uint8_t*, uint8_t*, uint8_t*);
uint8_t display_world       (ALLEGRO_DISPLAY *);    //Se muestra el mundo en el display
uint8_t display_snake       (ALLEGRO_DISPLAY *);    //Se muestra la serpiente en el display


#endif /* OUTPUT_H */
