/* 
 * File:   snake_world.h
 * Author: Awasa
 * Created on 29 de noviembre de 2018, 13:09
 */

#ifndef SNAKE_WORLD_H
#define SNAKE_WORLD_H

#include <stdio.h>
#include <stdint.h>

#define EMPTY_SPACE   (0)
#define SNAKE_HEAD    (1)
#define SNAKE_BODY    (2)
#define END_OF_SNAKE  (360)
#define WALL          (END_OF_SNAKE+1)
#define SNAKE_FOOD    (WALL+1)
#define MAX_SIZE_X    (100)
#define MAX_SIZE_Y    (100)


void        create_world         (uint16_t [MAX_SIZE_X][MAX_SIZE_Y]);    //En esta funcion se crea el diseño del mundo
uint16_t*    get_snake_body_part  (uint16_t [MAX_SIZE_X][MAX_SIZE_Y], uint16_t );
void        move_snake           (uint16_t *);


#endif /* SNAKE_WORLD_H */
