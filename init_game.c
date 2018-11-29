/* 
 * File:   init_game.c
 * Author: Awasa
 * Created on 28 de noviembre de 2018, 17:28
 */

#include "init_game.h"


uint8_t init_allegro (void)
{
    //Declaro todos los servicios de allegro que utilizare en el juego
    //como la fuente,la musica, el sistema de imagen e inicializo allegro
    
    if(!al_init()) //Inicializo allegro 
    {
        fprintf(stderr, "Fallo el inicio de allegro \n"); //Mensaje de error al usuario
        al_uninstall_system();  //"apaga allegro"
        return 1;   //Condicion de salida con error
    }
    if(!al_init_image_addon()) //inicializo el sistema de imagen
    {
        fprintf(stderr,"Creacion de sistema de imagen erronea \n");  ///Mensaje de error al usuario
        al_uninstall_system();  //"apaga" allegro
        al_shutdown_image_addon;    //Destruye el sistema de imagen
        return 1;  //Condicion de salida con error
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



uint8_t create_logo (ALLEGRO_DISPLAY *display,ALLEGRO_FONT *font )
{
    ALLEGRO_BITMAP  *logo = NULL;       //declaro el bitmap logo
    
    //Creo el diseño del logo del juego
      
    if(!(logo = al_load_bitmap ("itba_logo.png")))
    {
        fprintf(stderr,"Creacion de logo erronea \n");  ///Mensaje de error al usuario
        al_destroy_bitmap(logo);    //destruye el bitmap del logo
        al_destroy_display(display);    //Destruye el display
        return 1;  //Condicion de salida con error
    }
    else if(!(font = al_load_ttf_font("Minecrafter.Reg.ttf",30,0 )))  //Elijo la fuente deseada
    {
        fprintf(stderr,"Creacion de fuente erronea \n");
        al_destroy_bitmap(logo);    //destruye el bitmap del logo
        al_destroy_display(display);    //Destruye el display
        al_destroy_font(font);
        return 1;
    }
        
    display_logo (logo,font); //Llamo a la funcion que muestra un bitmap y texto en el display
    
    return 0;   //Ejecucion exitosa de la funcion  
}
