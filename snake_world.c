/* 
 * File:   snake_world.c
 * Author: Awasa 
 * Created on 29 de noviembre de 2018, 13:09
 */

#include "snake_world.h"

void create_world (uint32_t *world, uint16_t widht, uint16_t high)
{
    uint32_t i = 0;
    while (i < (widht*(high - 100)))
    {
        world[i++] = EMPTY_SPACE;
    }
}
