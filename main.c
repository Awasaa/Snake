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
    
    if(!init_allegro())     //Inicializa los servicios de allegro
    {
        if (!create_display(snake_game))    //Creo el display
        {
            if (!create_logo(snake_game,font))      //Creo y muestro el logo
            {
                printf ("se ejecuto la presentacion\n");
            }
        }
    }
    close_allegro (snake_game,font);    //Finaliza los servicios de allegro al finalizar el programa
    return (EXIT_SUCCESS);
}

