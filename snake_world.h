/* 
 * File:   snake_world.h
 * Author: Awasa
 * Created on 29 de noviembre de 2018, 13:09
 */

#ifndef SNAKE_WORLD_H
#define SNAKE_WORLD_H

#include <stdio.h>
#include <stdint.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define EMPTY_SPACE 0
#define SNAKE_BODY  1
#define SNAKE_FOOD  2


uint8_t create_world    (uint8_t *);    //En esta funcion se crea el diseño del mundo
uint8_t create_snake    (ALLEGRO_DISPLAY *);    //En esta funcion se crea el diseño de la serpiente


#endif /* SNAKE_WORLD_H */
