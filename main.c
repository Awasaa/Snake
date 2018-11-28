/* 
 * File:   main.c
 * Author: Awasa
 * Created on 28 de noviembre de 2018, 17:13
 */

#include "init_game.h"
#include "finish_game.h"



int main(int argc, char** argv) 
{
    ALLEGRO_DISPLAY *snake_game =  NULL;   //declaro el display
    ALLEGRO_FONT *font = NULL;  //declaro la fuente
    
    if(!init_allegro())
    {
        if (!create_display(snake_game))
        {
            if (!create_logo(snake_game,font))
            {
                printf ("se ejecuto la presentacion\n");
            }
        }
    }
    close_allegro (snake_game,font);
    return (EXIT_SUCCESS);
}

