/* 
 * File:   snake_world.c
 * Author: Awasa 
 * Created on 29 de noviembre de 2018, 13:09
 */

#include "snake_world.h"

void create_world (uint16_t mundo [MAX_SIZE_X][MAX_SIZE_Y])
{
    uint16_t i,j;
    for (i=0; i<12;i++)
    {
        for(j=0; j<12; j++)
        {
            if (((i==0)||(i==11))||((j==0)||(j==11) ))
            {
             	 mundo[i][j] = WALL;  // pone una pared en los extremos del mundo
	    }
            else
            {
                mundo[i][j] = EMPTY_SPACE; //pone en 0 los espacios libre del mundo
            }
        }
        
    }
    mundo[2][5]=SNAKE_HEAD;
    mundo[2][4]=2;
    mundo[2][3]=3;
    mundo[2][2]=END_OF_SNAKE;
}

uint16_t* get_snake_body_part (uint16_t mundo [MAX_SIZE_X][MAX_SIZE_Y], uint16_t body_part)
{
    uint32_t i,j;
    uint16_t* part_pos;
    for(i=1;i<12;i++)			
    {
        for(j=1;j<12;j++)
        {
            if(mundo[i][j]== body_part)
            {
                part_pos= &(mundo[i][j]);
                            //devuelve puntero con la posicion en la que se encuentra la body
            }
        }
    }
    return part_pos;
}


void move_snake ( uint16_t* parte_del_cuerpo)
{
	uint16_t* p = parte_del_cuerpo;
	p[1] = *parte_del_cuerpo;
}
    
