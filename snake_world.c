/* 
 * File:   snake_world.c
 * Author: Awasa 
 * Created on 29 de noviembre de 2018, 13:09
 */

#include "snake_world.h"

void create_world (uint16_t world[5000], uint16_t widht, uint16_t high)
{
    uint32_t i = 0;
    while (i < (widht*high))
    {
        world[i] = EMPTY_SPACE;
        if (i == ((widht*high)/2))
        {
            world[i] = SNAKE_HEAD;
            world[i-1] = SNAKE_BODY;
            world[i-2] = SNAKE_TAIL;         
        }
        i++;
    }
}

uint16_t get_snake_body_part (uint16_t world[5000], uint16_t body_part)
{
    uint32_t i = 0;
    while (world[i] != body_part)
    {
        i++;
    }
    return i;
}

void refresh_world (uint16_t world[5000], uint32_t new_position, uint16_t body_part)
{
        world [new_position] = body_part;
}
    
