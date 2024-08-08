#include "simon/tui.h"
#include <ncurses.h>

void init_color_pairs(void){
    init_pair(ON, COLOR_WHITE, COLOR_RED);
    init_pair(OFF, COLOR_WHITE, COLOR_BLACK);
}