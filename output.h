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


#define DISPLAY_W                (800)         //Ancho del display
#define DISPLAY_H                (600)         //Alto del display
#define TRIAN_POINT_X1           (DISPLAY_W *0.21)
#define TRIAN_POINT_X1B          (DISPLAY_W *0.13)
#define TRIAN_POINT_Y1           (DISPLAY_H *0.5)
#define TRIAN_POINT_X2           (TRIAN_POINT_X1)
#define TRIAN_POINT_X2B          (TRIAN_POINT_X1B)
#define TRIAN_POINT_Y2           (DISPLAY_H *0.5 + DISPLAY_H*0.05)
#define TRIAN_POINT_X3           (TRIAN_POINT_X1 + DISPLAY_W *0.05)
#define TRIAN_POINT_X3B          (TRIAN_POINT_X1B + DISPLAY_W *0.05)
#define TRIAN_POINT_Y3           (DISPLAY_H *0.5 + (DISPLAY_H*0.05)/2)
#define TRIAN_POINT_Y1_ONE_STEP  (TRIAN_POINT_Y1+LINE_DISTANCE)
#define TRIAN_POINT_Y1_TWO_STEP  (TRIAN_POINT_Y1+LINE_DISTANCE*2)
#define TRIAN_POINT_Y1_EXT_DOWN  (TRIAN_POINT_Y1+LINE_DISTANCE*3)
#define LINE_DISTANCE            (DISPLAY_H/10)



void    display_logo        (ALLEGRO_BITMAP *, ALLEGRO_FONT *, uint16_t, uint16_t);  //Pone en pantalla el diseño del logo
void    display_info        (ALLEGRO_BITMAP *, ALLEGRO_FONT *, ALLEGRO_FONT *, ALLEGRO_FONT *, uint16_t, uint16_t);
void    display_menu        (ALLEGRO_BITMAP *, ALLEGRO_FONT *, ALLEGRO_FONT *, uint16_t, uint16_t,uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
void    display_best_score  (ALLEGRO_BITMAP *, ALLEGRO_FONT *, ALLEGRO_FONT *, ALLEGRO_FONT *, uint16_t, uint16_t, uint8_t*, uint8_t*, uint8_t*);
void    display_options     (ALLEGRO_BITMAP *, ALLEGRO_FONT *, ALLEGRO_FONT *, ALLEGRO_FONT *, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint8_t*, uint8_t*, uint8_t*, uint8_t*);
void    display_world       (ALLEGRO_BITMAP *, uint16_t, uint16_t);
void    display_snake       (ALLEGRO_BITMAP *, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t); //estra el mundo en el display



#endif /* OUTPUT_H */
