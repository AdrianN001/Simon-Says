#pragma once
#include <ncurses.h>


WINDOW* top_window_init(WINDOW* base_window);
WINDOW* bottom_window_init(WINDOW* base_window);
WINDOW* left_window_init(WINDOW* base_window);
WINDOW* right_window_init(WINDOW* base_window);


void window_fill(WINDOW* window);
void window_unfill(WINDOW* window);
void window_blink(WINDOW* window, int duration_ms);


void window_free(WINDOW* window);