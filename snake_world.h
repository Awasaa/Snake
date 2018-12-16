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

#define EMPTY_SPACE             (0)
#define SNAKE_HEAD              (1)
#define SNAKE_BODY              (2)
#define END_OF_SNAKE            (MAX_WORLD_WIDTH*MAX_WORLD_HIGH)
#define WALL                    (END_OF_SNAKE+1)
#define SNAKE_FOOD              (WALL+1)
#define MAX_WORLD_WIDTH         (20)
#define MAX_WORLD_HIGH          (20)
#define MIN_WORLD_WIDTH         (1)
#define MIN_WORLD_HIGH          (1)
#define WORLD_WIDTH_WITH_WALLS  (MAX_WORLD_WIDTH+2)
#define WORLD_HIGH_WITH_WALLS   (MAX_WORLD_HIGH+2)
#define MAX_SIZE_X              (WORLD_WIDTH_WITH_WALLS)
#define MAX_SIZE_Y              (WORLD_HIGH_WITH_WALLS)
#define MIN_SIZE_X              (0)
#define MIN_SIZE_Y              (0)
#define LEFT_WALL_SPACE         (MIN_WORLD_WIDTH-1)
#define RIGHT_WALL_SPACE        (MAX_WORLD_WIDTH+1)
#define TOP_WALL_SPACE          (MIN_WORLD_HIGH-1)          
#define BOTTOM_WALL_SPACE       (MAX_WORLD_HIGH+1)

void game_logic   (uint16_t [MAX_SIZE_X][MAX_SIZE_Y], uint32_t);
void create_world (uint16_t snake_world [MAX_SIZE_X][MAX_SIZE_Y]);


#endif /* SNAKE_WORLD_H */
