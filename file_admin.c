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

uint8_t* get_string (uint8_t *file_name,FILE *best_scores, uint8_t array_to_copy[], uint8_t file_line)
{
    uint8_t *score,i;
    
    best_scores = fopen (file_name,"r");
    if (best_scores == NULL)
    {
        fprintf (stderr, "El archivo no existe");
    }
    else 
    {
        for (i = 0; i < file_line; i++)
        {
            score = (fgets(array_to_copy,100,best_scores));
        }
    }
    fclose (best_scores);
    return score;
}
