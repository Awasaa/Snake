/* 
 * File:   main.c
 * Author: Awasa
 * Created on 28 de noviembre de 2018, 17:13
 */

#include "init_game.h"
#include "finish_game.h"
#include "snake_world.h"

static void admin_game (ALLEGRO_DISPLAY *, ALLEGRO_FONT *);


int main(int argc, char** argv) 
{
    ALLEGRO_DISPLAY *snake_game =  NULL;   //declaro el display
    ALLEGRO_FONT *font = NULL;  //declaro la fuente
    
    if(!init_allegro())     //Inicializa los servicios de allegro
    {
        if (!create_display(snake_game))    //Creo el display
        {
            if (!create_logo(snake_game,font))      //Creo y muestro el logo
            {
                //admin_game(snake_game,font);
                create_menu(snake_game,font);
            }
        }
    }
    close_allegro (snake_game,font);    //Finaliza los servicios de allegro al finalizar el programa
    return (EXIT_SUCCESS);
}


void admin_game (ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font)
{
        
/*    if(!create_world())
    {
        if(!create_snake(display))
        {
            
        }
    }*/

}
