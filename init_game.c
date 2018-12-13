/* 
 * File:   init_game.c
 * Author: Awasa
 * Created on 28 de noviembre de 2018, 17:28
 */

#include "init_game.h"
#include "output.h"
#include "input.h"
#include "file_admin.h"


static uint32_t  admin_menu        (ALLEGRO_BITMAP *,ALLEGRO_FONT *,ALLEGRO_FONT*, ALLEGRO_FONT *,ALLEGRO_EVENT_QUEUE *, FILE *, FILE *);
static void      move_menu_pointer (uint16_t *, uint16_t *, uint16_t *, uint32_t);
static uint32_t  admin_submenu     (ALLEGRO_FONT *, ALLEGRO_FONT *, ALLEGRO_FONT *,ALLEGRO_EVENT_QUEUE *, FILE *, FILE *,uint16_t *);
static uint8_t   create_best_score (ALLEGRO_FONT *, ALLEGRO_FONT *, ALLEGRO_FONT *, FILE *);
static uint8_t   create_options    (ALLEGRO_FONT *, ALLEGRO_FONT *, ALLEGRO_FONT *, ALLEGRO_EVENT_QUEUE *, FILE *);

uint8_t init_allegro (void)
{
    //Declaro todos los servicios de allegro que utilizare en el juego como la fuente,
    //el sistema de imagen,sonido y primitivas,teclado, e inicializo allegro
    
    if(!al_init()) //Inicializo allegro 
    {
        fprintf(stderr, "Fallo el inicio de allegro \n"); //Mensaje de error al usuario
        al_uninstall_system();  //"apaga allegro"
        return 1;   //Condicion de salida con error
    }
    else if(!al_init_image_addon()) //inicializo el sistema de imagen
    {
        fprintf(stderr,"Creacion de sistema de imagen erronea \n");  ///Mensaje de error al usuario
        al_uninstall_system();  //"apaga" allegro
        al_shutdown_image_addon;    //Destruye el sistema de imagen
        return 1;  //Condicion de salida con error
    }
    else if(!al_install_keyboard()) 
    {
        fprintf(stderr, "Fallo el inicio del teclado \n");
        al_uninstall_system();  //"apaga" allegro
        al_shutdown_image_addon;    //Destruye el sistema de imagen
        return 1;
    }
    else if (!al_init_primitives_addon())
    {
        fprintf(stderr, "Fallo el inicio de las primitivas \n");
        al_uninstall_system();  //"apaga" allegro
        al_shutdown_image_addon;    //Destruye el sistema de imagen
        return 1;
    }
    
    al_init_font_addon();   //Inicializo el sistema para la fuente
    al_init_ttf_addon();    //Inicializo el "true type font" 
    return 0;    //Ejecucion exitosa de la funcion
}


uint8_t create_display (ALLEGRO_DISPLAY *display)
{
    if (!(display = al_create_display (DISPLAY_W,DISPLAY_H))) //Creo el display con medidas "DISPLAY_W" y "DISPLAY_H"
    {
        fprintf (stderr, "Creacion de display erronea \n");    //Mensaje de error al usuario
        al_destroy_display(display);  //destruye el display
        return 1;      //Condicion de salida con error
    }
    return 0;   //Ejecucion exitosa de la funcion
}



uint8_t create_intro (ALLEGRO_DISPLAY *display, ALLEGRO_FONT *titulo, ALLEGRO_FONT *subtitulo, ALLEGRO_FONT *mensaje)
{
    ALLEGRO_BITMAP  *logo = NULL;       //declaro el bitmap logo
    
    //Creo el diseño del logo del juego
      
    if(!(logo = al_load_bitmap ("itba_logo2.jpg")))
    {
        fprintf(stderr,"Creacion de logo erronea \n");  ///Mensaje de error al usuario
        al_destroy_bitmap(logo);    //destruye el bitmap del logo
        al_destroy_display(display);    //Destruye el display
        return 1;  //Condicion de salida con error
    }
    else if((!(titulo = al_load_ttf_font("ComfortaaBold.ttf",60,0 ))) || \
            (!(subtitulo = al_load_ttf_font("CCKeni.ttf",30,0))) || \
            (!(mensaje = al_load_ttf_font("Spongeboy.ttf",10,0))))  //Elijo la fuente deseada
    {
        fprintf(stderr,"Creacion de fuente erronea \n");
        al_destroy_bitmap(logo);    //destruye el bitmap del logo
        al_destroy_display(display);    //Destruye el display
        al_destroy_font(titulo);
        return 1;
    }
        
    display_logo (logo,mensaje,DISPLAY_W,DISPLAY_H); //Llamo a la funcion que muestra un bitmap y texto en el display
    wait_for_key(ALLEGRO_KEY_SPACE);
    display_info (logo,titulo,subtitulo,mensaje,DISPLAY_W,DISPLAY_H);
    wait_for_key(ALLEGRO_KEY_SPACE);
    
    al_destroy_bitmap (logo);
    return 0;   //Ejecucion exitosa de la funcion  
}

uint8_t create_menu (ALLEGRO_DISPLAY *display, ALLEGRO_FONT *titulo, \
                     ALLEGRO_FONT *opciones, ALLEGRO_FONT *mensaje, ALLEGRO_EVENT_QUEUE *event_queue, \
                     FILE *options_file, FILE *best_scores)
{
    ALLEGRO_BITMAP *menu = NULL;
    uint32_t exit_type;
    
    if(!(menu = al_load_bitmap ("menu3.png")))
    {
        fprintf(stderr,"Creacion de logo erronea \n");  ///Mensaje de error al usuario
        al_destroy_bitmap(menu);    //destruye el bitmap del logo
        al_destroy_display(display);    //Destruye el display
        al_destroy_font(titulo);
        al_destroy_font(opciones);
        al_destroy_event_queue(event_queue);
        return 1;  //Condicion de salida con error
    }
    else if((!(titulo = al_load_ttf_font("Turtles.otf",60,0 ))) || \
            (!(opciones = al_load_ttf_font("SuperMario256.ttf",30,0))))  //Elijo la fuente deseada
    {
        fprintf(stderr,"Creacion de fuente erronea \n");
        al_destroy_bitmap(menu);    //destruye el bitmap del logo
        al_destroy_display(display);    //Destruye el display
        al_destroy_font(titulo);
        al_destroy_font(opciones);
        al_destroy_event_queue(event_queue);
        return 1;
    }                 

    display_menu (menu, titulo, opciones, DISPLAY_W, DISPLAY_H,TRIAN_POINT_X1,TRIAN_POINT_Y1,TRIAN_POINT_X2,TRIAN_POINT_Y2,TRIAN_POINT_X3,TRIAN_POINT_Y3);
    exit_type = admin_menu(menu, titulo, opciones, mensaje, event_queue, options_file, best_scores);
    
    al_destroy_bitmap (menu);
    return (exit_type);
}

static uint32_t admin_menu (ALLEGRO_BITMAP *menu, ALLEGRO_FONT *titulo,ALLEGRO_FONT *opciones, ALLEGRO_FONT *mensaje, ALLEGRO_EVENT_QUEUE *event_queue, FILE *options_file, FILE *best_scores)
{
    uint32_t key;
    uint16_t x1 = TRIAN_POINT_X1, y1 = TRIAN_POINT_Y1; 
    uint16_t x2 = TRIAN_POINT_X2, y2 = TRIAN_POINT_Y2;
    uint16_t x3 = TRIAN_POINT_X3, y3 = TRIAN_POINT_Y3;
    
    if (!(event_queue = al_create_event_queue()))
    {
        fprintf(stderr, "Creacion de fila de eventos fallida \n");
        al_destroy_event_queue(event_queue);
        return -1;
    }  
    
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    display_menu(menu, titulo, opciones, DISPLAY_W, DISPLAY_H,x1,y1,x2,y2,x3,y3);
    
    do
    {
        key = get_keyboard (event_queue);
        switch (key)
        {
            case (ALLEGRO_KEY_DOWN):
                move_menu_pointer (&y1,&y2,&y3,key);
                display_menu(menu, titulo, opciones, DISPLAY_W, DISPLAY_H,x1,y1,x2,y2,x3,y3);
                break;
            case (ALLEGRO_KEY_UP):
                move_menu_pointer (&y1,&y2,&y3,key);
                display_menu(menu, titulo, opciones, DISPLAY_W, DISPLAY_H,x1,y1,x2,y2,x3,y3);
                break; 
            case (ALLEGRO_KEY_ENTER):
                key = admin_submenu (titulo,opciones,mensaje,event_queue,options_file,best_scores,&y1);
                break;
            default:
                display_menu(menu, titulo, opciones, DISPLAY_W, DISPLAY_H,x1,y1,x2,y2,x3,y3);
                break;    
        }
    }
    while (key != LOOP_EXIT && key != GAME_EXIT); 
    
    return key;
}

static void move_menu_pointer (uint16_t *y1, uint16_t *y2, uint16_t *y3, uint32_t key)
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

static uint32_t admin_submenu (ALLEGRO_FONT *titulo, ALLEGRO_FONT *opciones, ALLEGRO_FONT *mensaje, ALLEGRO_EVENT_QUEUE *event, FILE *options_file, FILE *best_scores, uint16_t *y_pos)
{
        if (*y_pos == TRIAN_POINT_Y1)
        {
            return (LOOP_EXIT);
        }
        else if (*y_pos == TRIAN_POINT_Y1_ONE_STEP)
        {
            if(create_best_score(titulo,opciones,mensaje,best_scores))
            {
                return(GAME_EXIT);
            }     
        }
        else if (*y_pos == TRIAN_POINT_Y1_TWO_STEP)
        {
            if(create_options(titulo,opciones,mensaje,event,options_file))
            {
                return(GAME_EXIT);
            }
        }
        else if (*y_pos == TRIAN_POINT_Y1_EXT_DOWN)
        {
            return (GAME_EXIT);
        }   
}

static uint8_t create_best_score(ALLEGRO_FONT *titulo, ALLEGRO_FONT *opciones, ALLEGRO_FONT *mensaje, FILE *best_scores)
{ 
    ALLEGRO_BITMAP *scores = NULL;
    uint8_t *score1,*score2,*score3;
    uint8_t text1[100],text2[100],text3[100];
    
    if(!(scores = al_load_bitmap ("trofeo.jpg")))
    {
        fprintf(stderr,"Creacion de logo erronea \n");  ///Mensaje de error al usuario
        al_destroy_bitmap(scores);    //destruye el bitmap del logo
        return 1;  //Condicion de salida con error
    }
    else if((!(titulo = al_load_ttf_font("Turtles.otf",60,0 ))) || \
            (!(opciones = al_load_ttf_font("SuperMario256.ttf",30,0))) || \
            (!(mensaje = al_load_ttf_font("Spongeboy.ttf",10,0))))  //Elijo la fuente deseada
    {
        fprintf(stderr,"Creacion de fuente erronea \n");
        al_destroy_bitmap(scores);    //destruye el bitmap del logo
        return 1;
    }
    
    score1 = get_string (best_scores,text1,1);
    score2 = get_string (best_scores,text2,2);
    score3 = get_string (best_scores,text3,3);
    
    display_best_score (scores, titulo, opciones, mensaje, DISPLAY_W, DISPLAY_H, score1, score2, score3);
    wait_for_key(ALLEGRO_KEY_ESCAPE);
    
    al_destroy_bitmap(scores);
    return 0;
}

static uint8_t create_options(ALLEGRO_FONT *titulo, ALLEGRO_FONT *opciones, ALLEGRO_FONT *mensaje, ALLEGRO_EVENT_QUEUE *event_queue, FILE *options_file)
{ 
    ALLEGRO_BITMAP *options = NULL;
    
    if(!(options = al_load_bitmap ("menu3.png")))
    {
        fprintf(stderr,"Creacion de logo erronea \n");  ///Mensaje de error al usuario
        al_destroy_bitmap(options);    //destruye el bitmap del logo
        al_destroy_font(titulo);
        al_destroy_font(opciones);
        al_destroy_event_queue(event_queue);
        return 1;  //Condicion de salida con error
    }
    else if((!(titulo = al_load_ttf_font("Turtles.otf",60,0 ))) || \
            (!(opciones = al_load_ttf_font("SuperMario256.ttf",30,0))))  //Elijo la fuente deseada
    {
        fprintf(stderr,"Creacion de fuente erronea \n");
        al_destroy_bitmap(options);    //destruye el bitmap del logo
        al_destroy_font(titulo);
        al_destroy_font(opciones);
        al_destroy_event_queue(event_queue);
        return 1;
    }
}