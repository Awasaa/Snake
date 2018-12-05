/* 
 * File:   input.c
 * Author: Awasa 
 * Created on 29 de noviembre de 2018, 13:48
 */

#include "input.h"

void wait_for_key (int32_t key)
{
    ALLEGRO_KEYBOARD_STATE state;
    
    al_get_keyboard_state (&state);
    
    while (!al_key_down(&state, key))
    {
        al_get_keyboard_state (&state);
    }
    usleep(300000);
}


