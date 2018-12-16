/* 
 * File:   snake_world.c
 * Author: Awasa 
 * Created on 29 de noviembre de 2018, 13:09
 */

#include "snake_world.h"

static uint16_t* get_snake_body_part (uint16_t [MAX_SIZE_X][MAX_SIZE_Y], uint16_t);
static void      move_snake_head     (uint16_t* , uint16_t);
static void      move_snake_body     (uint16_t [MAX_SIZE_X][MAX_SIZE_Y], uint16_t);


void game_logic (uint16_t snake_world[MAX_SIZE_X][MAX_SIZE_Y], uint32_t direction)
{
    uint16_t *body_part_ubication = NULL;
    uint16_t  body_part = SNAKE_HEAD ;
    
    while   (body_part != (END_OF_SNAKE+1))
    {
            if (body_part_ubication = get_snake_body_part(snake_world,body_part))
            {
                move_snake_head (body_part_ubication,32);
            }
           // else 
           // {
              // move_snake_body (snake_world,body_part);
            //}
            body_part++;
    }
    
    *body_part_ubication = EMPTY_SPACE;
    body_part = SNAKE_HEAD;
    //body_part_ubication = get_snake_body_part(snake_world,body_part);
}

void create_world (uint16_t snake_world [MAX_SIZE_X][MAX_SIZE_Y])
{
    uint16_t i,j;
    for (i=0; i < MAX_SIZE_X; i++)
    {
        for(j=0; j < MAX_SIZE_Y; j++)
        {
            if ((i == LEFT_WALL_SPACE) || (i == RIGHT_WALL_SPACE) || (j== TOP_WALL_SPACE)  || (j == BOTTOM_WALL_SPACE ))
            {
             	 snake_world [i][j] = WALL;  // pone una pared en los extremos del mundo
	    }
            else
            {
                snake_world [i][j] = EMPTY_SPACE; //pone en 0 los espacios libre del mundo
            }
        }
        
    }
    snake_world [MAX_WORLD_HIGH/2][MAX_WORLD_WIDTH/2]     = SNAKE_HEAD;
    snake_world [MAX_WORLD_HIGH/2][(MAX_WORLD_WIDTH/2)-1] = SNAKE_HEAD+1;
    snake_world [MAX_WORLD_HIGH/2][(MAX_WORLD_WIDTH/2)-2] = SNAKE_HEAD+2;
    snake_world [MAX_WORLD_HIGH/2][(MAX_WORLD_WIDTH/2)-3] = END_OF_SNAKE;
}

static uint16_t* get_snake_body_part (uint16_t snake_world [MAX_SIZE_X][MAX_SIZE_Y], uint16_t body_part)
{
    uint16_t i,j;
    uint16_t* part_pos = NULL;
    
    for(i = MIN_WORLD_WIDTH; i <= MAX_WORLD_WIDTH; i++)			
    {
        for(j = MIN_WORLD_HIGH; j <= MAX_WORLD_HIGH; j++)
        {
            if(snake_world[i][j] == body_part)
            {
                part_pos= &(snake_world [i][j]);     //devuelve puntero con la posicion en la que se encuentra la body
            }
        }
    }
    
    return part_pos;
}


static void move_snake_head ( uint16_t* body_part,uint16_t direction )
{
    uint16_t* copy_of_body_part = body_part;
    //switch (direction)
    //{
       // case (ALLEGRO_KEY_RIGHT):
            copy_of_body_part[1] = *body_part;
          //  break;
        //case (ALLEGRO_KEY_LEFT):
          //  *(copy_of_body_part-1) = *body_part;
          //  break; 
        //case (ALLEGRO_KEY_DOWN):
          //  copy_of_body_part[MAX_SIZE_X] = *body_part;
           // break;
        //case (ALLEGRO_KEY_UP):
          //  *(copy_of_body_part-MAX_SIZE_X) = *body_part; 
          //  break;
        //default:
          // *(copy_of_body_part+1) = *body_part;
          //  break;
     //}             
}

static void move_snake_body (uint16_t snake_world[MAX_SIZE_X][MAX_SIZE_Y], uint16_t body_part)
{
    uint16_t *body_part_ubication = get_snake_body_part (snake_world,body_part-1);
    *body_part_ubication = body_part;
}
    
