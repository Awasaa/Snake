/* 
 * File:   snake_world.h
 * Author: Awasa
 * Created on 29 de noviembre de 2018, 13:09
 */

#ifndef SNAKE_WORLD_H
#define SNAKE_WORLD_H

#include <stdio.h>
#include <stdint.h>

#define EMPTY_SPACE 0
#define SNAKE_HEAD  3
#define SNAKE_BODY  2
#define SNAKE_TAIL  1
#define SNAKE_FOOD  4


void        create_world    (uint16_t *, uint16_t, uint16_t);    //En esta funcion se crea el diseño del mundo
uint16_t    get_snake_body_part (uint16_t *, uint16_t);
void        refresh_world     (uint16_t *, uint32_t, uint16_t);


#endif /* SNAKE_WORLD_H */
