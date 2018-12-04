/* 
 * File:   init_game.h
 * Author: Awasa
 * Created on 28 de noviembre de 2018, 19:02
 */

#ifndef INIT_GAME_H
#define INIT_GAME_H

#include <stdio.h>
#include <stdint.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>

#define DISPLAY_W   800         //Ancho del display
#define DISPLAY_H   600         //Alto del display

uint8_t init_allegro    (void);     //Funcion que inicializa todas los sistemas de allegro que se utilizaran
uint8_t create_display  (ALLEGRO_DISPLAY *);    //Esta funcion inicia exclusivamente el display
uint8_t create_logo     (ALLEGRO_DISPLAY *,ALLEGRO_FONT *); //Diseño del logo. Fuente y bitmap
uint8_t create_menu     (ALLEGRO_DISPLAY *,ALLEGRO_FONT *);

#endif /* INIT_GAME_H */

