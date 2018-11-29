/* 
 * File:   init_game.h
 * Author: Awasa
 * Created on 28 de noviembre de 2018, 19:02
 */

#ifndef INIT_GAME_H
#define INIT_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h> 
#include <allegro5/allegro_ttf.h>

#define DISPLAY_W   800
#define DISPLAY_H   600

uint8_t init_allegro    (void);
uint8_t create_display  (ALLEGRO_DISPLAY *);
uint8_t create_logo     (ALLEGRO_DISPLAY *,ALLEGRO_FONT *);
void    display_logo    (ALLEGRO_BITMAP *,ALLEGRO_FONT *);


#endif /* INIT_GAME_H */

