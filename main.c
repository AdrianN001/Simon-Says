#include <stdio.h>
#include <ncurses.h>
#include "simon/game.h"
#include "simon/tui.h"
#include "simon/assert.h"

int main(void){
    stack_t stack = stack_init();
    WINDOW* base = init_screen();

    WINDOW* top_window = top_window_init(base);
    WINDOW* bottom_window = bottom_window_init(base);
    WINDOW* left_window = left_window_init(base);
    WINDOW* right_window = right_window_init(base);
    mvwprintw(base, 30, 104, "Press [Enter] to start ");
    wrefresh(base);
    
    for (;;){
        int character = wgetch(base);
        if (character == 10){break;}
    }
    mvwprintw(base, 30, 104, "                       ");
    refresh();
    for(;;){
        for (int i = 0; i < stack.pointer; ){
            int character = wgetch(base);
            if (character != (int)'w' && character != (int)'s' && character != (int)'a' && character != (int)'d'){
                continue;
            }
            refresh();
            byte_t current_command = stack.commands[i];

            /*
                top = 65;
                bottom = 66
                right = 67
                left = 68
            */
           switch(character){
            case (int)'w':{ 
                if (current_command != UP ) {return 0;}
                window_blink(top_window, 500);
            }
            break;
            case (int)'s':{
                if (current_command != DOWN ) {return 0;}
                window_blink(bottom_window, 500);
            }
            break;
            case (int)'d':{
                if (current_command != RIGHT ) {return 0;}
                window_blink(right_window, 500);
            }
            break;
            case (int)'a':{
                if (current_command != LEFT ) {return 0;}
                window_blink(left_window, 500);
            }
            break;
            i++;
           }
        }
        napms(1000);
        mvwprintw(base, 30, 104, "       ");
        mvwprintw(base, 1, 0, "You have %d points.", stack.pointer);
        refresh();

        mvwprintw(base, 30, 104, "Wait...");
        refresh();
        stack_push(&stack);
        draw_commands(&stack, top_window, bottom_window, left_window, right_window);

        mvwprintw(base, 30, 104, "You go ");
        refresh();

    }
    return 0;
}