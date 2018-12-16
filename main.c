/* 
 * File:   main.c
 * Author: Awasa
 * Created on 28 de noviembre de 2018, 17:13
 */

#include "init_game.h"
#include "menus.h"
#include "admin_game.h"



int main(int argc, char** argv) 
{
    FILE *options_files;
    FILE *best_scores;
    
    ALLEGRO_DISPLAY *snake_game =  NULL;   //declaro el display
    ALLEGRO_FONT *font0 = NULL, *font1 = NULL, *font2 = NULL;  //declaro la fuente
    ALLEGRO_EVENT_QUEUE *event = NULL;
    
    
    if(!init_allegro() && !create_intro(snake_game,font0,font1,font2))      //Inicializa los servicios de allegro
    {                                                                       //Crea el display, el logo y la presentacion
        if(!(create_menu(snake_game,font0,font1,font2,event,options_files,best_scores) == GAME_EXIT))
        {   
            admin_game(options_files,best_scores,event);
        }
    }
    al_destroy_display (snake_game);
    al_destroy_font (font0);
    al_destroy_font (font1);
    al_destroy_font (font2);
    //al_destroy_event_queue (event);
    return (EXIT_SUCCESS);
}

