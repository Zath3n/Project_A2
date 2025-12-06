//Kye Rich 3142692

/**
*maze1.h
* Header file for maze level 2
* this creates a 30x80 maze
*
*/

#ifndef MAZE2_H
#define MAZE2_H

#include <ncurses.h>

/** maze height */
#define HEIGHT 30
/** maze width */
#define WIDTH 80


/** array with maze layout
*ends in NULL
*/
extern char level2[HEIGHT][WIDTH + 1];


/** 
* makes maze 2 layout
*makes paths
*/

void init_maze2();

/**
*draws maze 2 with ncurses
*clears screen and adds rows
*/
void draw_maze2();

#endif
