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
    ALLEGRO_DISPLAY *snake_game =  NULL;   //declaro el display
    ALLEGRO_FONT *font0 = NULL, *font1 = NULL, *font2 = NULL;  //declaro la fuente
    ALLEGRO_EVENT_QUEUE *event = NULL;
    
    if(!init_allegro())     //Inicializa los servicios de allegro
    {
        if (!create_display(snake_game))    //Creo el display
        {
            if (!create_intro(snake_game,font0,font1,font2))      //Creo y muestro el logo
            {
                //admin_game(snake_game,font);
                create_menu(snake_game,font0,font1,event);
                //admin_game();
            }
        }
    }
    al_destroy_display (snake_game);
    al_destroy_font (font0);
    al_destroy_font (font1);
    al_destroy_font (font2);
    //al_destroy_event_queue (event);
    // close_allegro (snake_game,font0);    //Finaliza los servicios de allegro al finalizar el programa
    return (EXIT_SUCCESS);
}


void admin_game (void)
{
    uint32_t i = 0,cabeza,j = 3;
    uint16_t world[5000];
    create_world (world,5,5);
    
    while (i < (5*5) )
    {
        printf ("%d",world[i++]);
        if (i == 5 || i == 5*2 || i == 5*3 ||  i == 5*4 || i == 5*5 || i == 6*6 || i == 6*7 || i == 6*8 )
            printf ("\n");
    }
    
    while (j != 0)
    {
        cabeza = get_snake_body_part (world,j);
        refresh_world (world,++cabeza,j);
        j--;
    }
    
    printf ("\n\n\n");
    
    i=0;
    
    while (i < (5*5) )
    {
        printf ("%d",world[i++]);
        if (i == 5 || i == 5*2 || i == 5*3 ||  i == 5*4 || i == 5*5 || i == 6*6 || i == 6*7 || i == 6*8 )
            printf ("\n");
    }
    
    

}
