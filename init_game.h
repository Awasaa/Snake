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
#include <allegro5/allegro_primitives.h>

#define DISPLAY_W       (800)         //Ancho del display
#define DISPLAY_H       (600)         //Alto del display
#define TRIAN_POINT_X1           (DISPLAY_W *0.22)
#define TRIAN_POINT_Y1           (DISPLAY_H *0.5)
#define TRIAN_POINT_X2           (DISPLAY_W *0.22)
#define TRIAN_POINT_Y2           (DISPLAY_H *0.5 + DISPLAY_H*0.05)
#define TRIAN_POINT_X3           (DISPLAY_W *0.22 + DISPLAY_W *0.05)
#define TRIAN_POINT_Y3           (DISPLAY_H *0.5 + (DISPLAY_H*0.05)/2)
#define TRIAN_POINT_Y1_ONE_STEP  (TRIAN_POINT_Y1+60)
#define TRIAN_POINT_Y1_TWO_STEP  (TRIAN_POINT_Y1+60*2)
#define TRIAN_POINT_Y1_EXT_DOWN  (TRIAN_POINT_Y1+60*3)
#define LINE_DISTANCE (60)
#define LOOP_EXIT   (2)
#define GAME_EXIT   (1)

uint8_t init_allegro    (void);     //Funcion que inicializa todas los sistemas de allegro que se utilizaran
uint8_t create_display  (ALLEGRO_DISPLAY *);    //Esta funcion inicia exclusivamente el display
uint8_t create_intro     (ALLEGRO_DISPLAY *, ALLEGRO_FONT *, ALLEGRO_FONT *, ALLEGRO_FONT *); //Diseño del logo. Fuente y bitmap
uint8_t create_menu     (ALLEGRO_DISPLAY *, ALLEGRO_FONT *, ALLEGRO_FONT *, ALLEGRO_FONT *, ALLEGRO_EVENT_QUEUE *,FILE *,FILE *);


#endif /* INIT_GAME_H */

