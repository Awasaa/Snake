/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   file_admin.c
 * Author: gonzalo
 * 
 * Created on 13 de diciembre de 2018, 17:14
 */

#include "file_admin.h"

uint8_t* get_string (FILE *best_scores, uint8_t text[], uint8_t line)
{
    uint8_t *score,i;
    best_scores = fopen ("best_scores.txt","r");
    if (best_scores == NULL)
    {
        fprintf (stderr, "El archivo no existe");
    }
    else 
    {
        for (i = 0; i< line; i++)
        {
            score = (fgets(text,100,best_scores));
        }
    }
    fclose (best_scores);
    return score;
}
