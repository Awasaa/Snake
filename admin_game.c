/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   admin_game.c
 * Author: gonza
 * 
 * Created on 15 de diciembre de 2018, 13:44
 */

#include "admin_game.h"
#include "snake_world.h"
#include "output.h"
#include "file_admin.h"
#include "input.h"

static uint8_t  create_display           (ALLEGRO_DISPLAY *, uint16_t, uint16_t);
static void     get_resolution           (FILE *, uint16_t *,uint16_t *);
static void     delay                    (FILE *);
static void     admin_display_world      (uint16_t [MAX_SIZE_X][MAX_SIZE_Y], uint16_t, uint16_t);
static uint32_t check_key                (uint32_t, uint32_t);
static uint32_t pause_menu               (ALLEGRO_EVENT_QUEUE *);
static void     move_pause_menu_pointer  (uint16_t *, uint16_t *, uint16_t *, uint32_t);
static uint32_t admin_pause_menu         (uint16_t *);

uint32_t admin_game (FILE *options_files, FILE *best_scores,ALLEGRO_EVENT_QUEUE *event_queue)
{
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP  *background = NULL;
  
    uint32_t last_pressed_valid_key = RIGHT;
    uint32_t key;
    uint16_t snake_world [MAX_SIZE_X][MAX_SIZE_Y];
    uint16_t width, high;
    
    get_resolution (options_files,&width,&high);
    create_display (display,width,high);
     if (!(event_queue = al_create_event_queue()))
    {
        fprintf(stderr, "Creacion de fila de eventos fallida \n");
        al_destroy_event_queue(event_queue);
        return 1;
    }
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    
    srand(time(NULL));
    create_world (snake_world);
    do
    {
        key = get_keyboard(event_queue);
        //if ((key = check_key (key,last_pressed_valid_key)) == ANY_KEY)
        //{
         //   al_flush_event_queue(event_queue);
        //}
        switch (key)
        {
            case (ALLEGRO_KEY_RIGHT) :
                game_logic (snake_world,RIGHT,&last_pressed_valid_key);
                last_pressed_valid_key = RIGHT;
                break;
            case (ALLEGRO_KEY_LEFT) :
                game_logic (snake_world,LEFT,&last_pressed_valid_key);
                last_pressed_valid_key = LEFT;
                break;
            case (ALLEGRO_KEY_DOWN) :
                game_logic (snake_world,DOWN,&last_pressed_valid_key);
                last_pressed_valid_key = DOWN;
                break;
            case (ALLEGRO_KEY_UP) :
                game_logic (snake_world,UP,&last_pressed_valid_key);
                last_pressed_valid_key = UP;
                break;  
            case (ALLEGRO_KEY_ESCAPE):
                key = pause_menu(event_queue);
                break;
            default:
                game_logic (snake_world,last_pressed_valid_key,&last_pressed_valid_key);
        }
        admin_display_world (snake_world,width,high);
        delay(options_files);
    }	
    while (key != BACK_TO_MENU && key != QUIT_GAME);
    
    return key; 
}

static uint8_t create_display (ALLEGRO_DISPLAY *display,uint16_t width, uint16_t high)
{
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    if (!(display = al_create_display (width,high))) //Creo el display con medidas "DISPLAY_W" y "DISPLAY_H"
    {
        fprintf (stderr, "Creacion de display erronea \n");    //Mensaje de error al usuario
        al_destroy_display(display);  //destruye el display
        return 1;      //Condicion de salida con error
    }
    return 0;   //Ejecucion exitosa de la funcion
}


static void get_resolution (FILE *options_files, uint16_t *width, uint16_t *high)
{
    uint8_t resolution[MAX_LENGHT];
    
    read_config (FILE_RESOLUTION,options_files,resolution);
    if (strcmp (resolution,RESOLUTION_1) == 0)
    {
        *width = 800;
        *high  = 600;
    }
    else if (strcmp (resolution,RESOLUTION_2) == 0)  
    {
       *width = 1024;
       *high  = 720; 
    }
    else if (strcmp (resolution,RESOLUTION_3) == 0)  
    { 
       *width = 1366;
       *high  = 768; 
    }   
}

static void delay (FILE *options_files)
{
    usleep (U_DELAY);
}


static void    admin_display_world  ( uint16_t snake_world [MAX_SIZE_X][MAX_SIZE_Y], uint16_t width, uint16_t high)
{
    uint16_t i,j;
    ALLEGRO_BITMAP  *background = NULL;
    ALLEGRO_COLOR color = al_map_rgb (0,0,0);
    ALLEGRO_COLOR color1 = al_map_rgb (255,0,0);
    ALLEGRO_COLOR color2 = al_map_rgb (0,0,255);
    
    if(!(background = al_load_bitmap ("grass.jpg")))
    {
        fprintf(stderr,"Creacion de fondo fallida \n");  ///Mensaje de error al usuario
        al_destroy_bitmap(background);    //destruye el bitmap del logo
        //return 1;  //Condicion de salida con error
    }
    display_world (background,width,high);
    for(i = MIN_WORLD_WIDTH; i <= MAX_WORLD_WIDTH; i++)			
    {
        for(j = MIN_WORLD_HIGH; j <= MAX_WORLD_HIGH; j++)
        {
            if(snake_world[i][j] >= SNAKE_HEAD && snake_world[i][j] <= END_OF_SNAKE)
            {
                display_snake (background,snake_world [i][j],width,high,SNAKE_HEAD,i,j,MAX_WORLD_WIDTH,MAX_WORLD_HIGH,color);
            }
            else if (snake_world[i][j] == SNAKE_FOOD)
            {
                display_snake (background,snake_world [i][j],width,high,SNAKE_HEAD,i,j,MAX_WORLD_WIDTH,MAX_WORLD_HIGH,color1);
            }
            else if (snake_world[i][j] == WALL)
            {
                display_snake (background,snake_world [i][j],width,high,SNAKE_HEAD,i,j,MAX_WORLD_WIDTH,MAX_WORLD_HIGH,color2);
            }
        }
    }
  
	/*for (i=1; i<20;i++)
    	{
       		for(j=1; j<20; j++)
       		 {
		 	printf (" %d ",snake_world [i][j]);   
      		 }
	printf ("\n");
	}*/
    al_destroy_bitmap(background);

}
  

static uint32_t check_key (uint32_t key, uint32_t last_pressed_valid_key)
{
    if ((key == ALLEGRO_KEY_RIGHT || key == ALLEGRO_KEY_LEFT) && (last_pressed_valid_key == RIGHT || last_pressed_valid_key == LEFT))
    {
        return ANY_KEY;
    }
    else if ((key == ALLEGRO_KEY_DOWN || key == ALLEGRO_KEY_UP) && (last_pressed_valid_key == UP || last_pressed_valid_key == DOWN))
    {
        return ANY_KEY;
    }
}

static uint32_t pause_menu (ALLEGRO_EVENT_QUEUE *event_queue)
{
    ALLEGRO_FONT *opciones = NULL;
    ALLEGRO_BITMAP *pause = NULL;
    
    uint32_t key;
    uint16_t x1 = TRIAN_POINT_X1, y1 = TRIAN_POINT_Y1; 
    uint16_t x2 = TRIAN_POINT_X2, y2 = TRIAN_POINT_Y2;
    uint16_t x3 = TRIAN_POINT_X3, y3 = TRIAN_POINT_Y3;
  
    if(!(opciones = al_load_ttf_font("SuperMario256.ttf",20,0)))  //Elijo la fuente deseada
    {
        fprintf(stderr,"Creacion de fuente erronea \n");
        al_destroy_font(opciones);
        return 1;
    }
    else if(!(pause = al_load_bitmap ("grass.jpg")))
    {
        fprintf(stderr,"Creacion de fondo fallida \n");  ///Mensaje de error al usuario
        al_destroy_bitmap(pause);    //destruye el bitmap del logo
        al_destroy_font(opciones);
        return 1;  //Condicion de salida con error
    }
    do
    {
        key = get_keyboard (event_queue);
        switch (key)
        {
            case (ALLEGRO_KEY_DOWN):
                move_pause_menu_pointer (&y1,&y2,&y3,key);
                display_pause_menu (pause,opciones,x1,y1,x2,y2,x3,y3);
                break;
            case (ALLEGRO_KEY_UP):
                move_pause_menu_pointer (&y1,&y2,&y3,key);
                display_pause_menu (pause,opciones,x1,y1,x2,y2,x3,y3);
                break; 
            case (ALLEGRO_KEY_ENTER):
                key = admin_pause_menu (&y1);
                break;
            default:
                display_pause_menu (pause,opciones,x1,y1,x2,y2,x3,y3);
                break;    
        }
    }
    while (key != RESUME && key != QUIT_GAME && key != BACK_TO_MENU);
    
    return key;   
}

static void move_pause_menu_pointer (uint16_t *y1, uint16_t *y2, uint16_t *y3, uint32_t key)
{
    if (key == ALLEGRO_KEY_UP && *y1 != TRIAN_POINT_Y1)
    {
        *y1 -= LINE_DISTANCE;
        *y2 -= LINE_DISTANCE;
        *y3 -= LINE_DISTANCE;
    }
    else if (key == ALLEGRO_KEY_DOWN && *y1 != TRIAN_POINT_Y1_EXT_DOWN)
    {
        *y1 += LINE_DISTANCE;
        *y2 += LINE_DISTANCE;
        *y3 += LINE_DISTANCE;
    }   
}

static uint32_t admin_pause_menu (uint16_t *y_pos)
{
    if (*y_pos == TRIAN_POINT_Y1)
    {
        return (RESUME);
    }
    else if (*y_pos == TRIAN_POINT_Y1_ONE_STEP)
    {
        return (BACK_TO_MENU) ;
    }
    else if (*y_pos == TRIAN_POINT_Y1_TWO_STEP)
    {
        return (QUIT_GAME);
    }
}