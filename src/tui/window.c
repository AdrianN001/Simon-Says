#include "simon/tui.h"
#include "simon/assert.h"
#include <ncurses.h>
#include <unistd.h>

WINDOW* top_window_init(WINDOW* base_window){

    const int x_top = 70;
    const int y_top = 10;
    int top_window_height = (int)(LINES*0.2);
    int top_window_width  = (int)(COLS*0.4);
    
    WINDOW* top_window = subwin(base_window, top_window_height, top_window_width, y_top, x_top);
    assert(top_window != NULL);
    box(top_window, 0, 0);
    wrefresh(base_window);
    wrefresh(top_window);
    return top_window;
}
WINDOW* bottom_window_init(WINDOW* base_window){
    const int x_top = 70;
    const int y_top = 40;
    int bottom_window_height = (int)(LINES*0.2);
    int bottom_window_width  = (int)(COLS*0.4);
    
    WINDOW* bottom_window = subwin(base_window, bottom_window_height, bottom_window_width, y_top, x_top);
    assert(bottom_window != NULL);
    box(bottom_window, 0, 0);
    wrefresh(base_window);
    wrefresh(bottom_window);
    return bottom_window;
}
WINDOW* left_window_init(WINDOW* base_window){
    const int x_top = 40;
    const int y_top = 21;
    int left_window_heigth = (int)(LINES*0.34);
    int left_window_width  = (int)(COLS*0.2);
    
    WINDOW* left_window = subwin(base_window, left_window_heigth, left_window_width, y_top, x_top);
    assert(left_window != NULL);
    box(left_window, 0, 0);
    wrefresh(base_window);
    wrefresh(left_window);
    return left_window;
}
WINDOW* right_window_init(WINDOW* base_window){
    const int x_top = 145;
    const int y_top = 21;
    int right_window_heigth = (int)(LINES*0.34);
    int right_window_width  = (int)(COLS*0.2);
    
    WINDOW* right_window = subwin(base_window, right_window_heigth, right_window_width, y_top, x_top);
    assert(right_window != NULL);
    box(right_window, 0, 0);
    wrefresh(base_window);
    wrefresh(right_window);
    return right_window;
}


void window_fill(WINDOW* window){
    wbkgd(window, COLOR_PAIR(ON));
    wrefresh(window);
}
void window_unfill(WINDOW* window){
    wbkgd(window, COLOR_PAIR(OFF));
    wrefresh(window);
}

void window_blink(WINDOW* window, int duration_ms){
    window_fill(window);
    napms(duration_ms);
    window_unfill(window);
}

void window_free(WINDOW* window){}