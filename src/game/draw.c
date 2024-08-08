#include "simon/tui.h"
#include "simon/game.h"
#include <ncurses.h>
#include <unistd.h>


void draw_commands(stack_t* stack, WINDOW* top, WINDOW* bottom, WINDOW* left, WINDOW* right){
    WINDOW* base = stdscr;

    for (int i = 0; i < stack->pointer; i++){
        if (i != 0){
            napms(1000);
        }
        byte_t current_command = stack->commands[i];

        switch(current_command){
            case UP:{
                window_blink(top, 1000);
            }
            break;
            case DOWN:{
                window_blink(bottom, 1000);
            }
            break;
            case LEFT:{
                window_blink(left, 1000);
            }
            break;
            case RIGHT:{
                window_blink(right, 1000);
            }
            break;
        }   
    }
}