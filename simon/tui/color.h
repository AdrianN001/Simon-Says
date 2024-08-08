#pragma once
#include <ncurses.h>


typedef enum {
    ON=16, 
    OFF
} color_e;

void init_color_pairs(void);