//Kye Rich 3142692

/**
*maze1.h
* Header file for maze level 1
* this creates a 30x80 maze with 3 paths
*one for top bottom and middle
*/

#ifndef MAZE1_H
#define MAZE1_H

#include <ncurses.h>

/** maze height */
#define HEIGHT 30
/** maze width */
#define WIDTH 80


/** array with maze layout
*ends in NULL
*/
extern char level1[HEIGHT][WIDTH + 1];


/** 
* makes maze 1 layout
*makes bourders paths
*/

void init_maze1();

/**
*draws maze 1 with ncurses
*clears screen and adds rows
*/
void draw_maze1();

#endif
