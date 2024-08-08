#pragma once

#include <ncurses.h>
#include "stack.h"
#include "simon/tui/windows.h"

#define COMMANND_UPTIME_S 0.5
#define SLEEP_BETWEEN_COMMANDS_S 0.5

void draw_commands(stack_t* stack, WINDOW* top, WINDOW* bottom, WINDOW* left, WINDOW* right);