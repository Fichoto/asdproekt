#ifndef MENU_FUNCTIONS_H
#define MENU_FUNCTIONS_H

#include "maze_generator/maze_generator.h"

void print_maze();
void save_maze_to_file(const char* filename);
void load_maze_from_file(const char* filename);
void user_move();

#endif