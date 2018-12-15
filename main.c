/* 
 * File:   main.c
 * Author: Awasa
 * Created on 28 de noviembre de 2018, 17:13
 */

#include "init_game.h"
#include "finish_game.h"
#include "snake_world.h"

static void admin_game ();


int main(int argc, char** argv) 
{
    FILE *options_files;
    FILE *best_scores;
    
    ALLEGRO_DISPLAY *snake_game =  NULL;   //declaro el display
    ALLEGRO_FONT *font0 = NULL, *font1 = NULL, *font2 = NULL;  //declaro la fuente
    ALLEGRO_EVENT_QUEUE *event = NULL;
    
    if(!init_allegro()   &&   !create_display(snake_game)   && \
       !create_intro(snake_game,font0,font1,font2))      //Inicializa los servicios de allegro
    {                                                    //Crea el display, el logo y la presentacion
        if(!(create_menu(snake_game,font0,font1,font2,event,options_files,best_scores) == GAME_EXIT))
        {
        //admin_game();
        }
    }
    al_destroy_display (snake_game);
    al_destroy_font (font0);
    al_destroy_font (font1);
    al_destroy_font (font2);
    //al_destroy_event_queue (event);
    //close_allegro (snake_game,font0);    //Finaliza los servicios de allegro al finalizar el programa
    return (EXIT_SUCCESS);
}


void admin_game (void)
{
    uint32_t i = 0,cabeza,j = 3;
    uint16_t world[5000];
   
    

}
