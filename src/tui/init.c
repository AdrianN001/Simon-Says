#include "simon/tui.h"
#include <stddef.h>
#include <stdlib.h>

WINDOW* init_screen(void){
    initscr();

    if(!has_colors()){
        exit(0);
    }
    start_color();
    init_color_pairs();

    WINDOW* main_window;
    if ( (main_window = initscr()) == NULL ) {
	    fprintf(stderr, "Error initialising ncurses.\n");
	    exit(1);
    }
    curs_set(0); /* Hide the cursor */
    cbreak();
    noecho();
    return main_window;
}