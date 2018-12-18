/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   admin_game.h
 * Author: gonza
 *
 * Created on 15 de diciembre de 2018, 13:44
 */

#ifndef ADMIN_GAME_H
#define ADMIN_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define U_DELAY      (300000)   //0.3 seg  
#define ANY_KEY      (ALLEGRO_KEY_F)
#define RESUME       (1)
#define QUIT_GAME    (2)
#define BACK_TO_MENU (3)

uint32_t admin_game (FILE *, FILE *,ALLEGRO_EVENT_QUEUE *);

#endif /* ADMIN_GAME_H */
