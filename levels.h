// ID: 3143692 Name: Kye Rich
// ID: 3132175 Name: Gabriel

#ifndef LEVELS_H
#define LEVELS_H

/**
*levels.h
* Header file for maze level 1 and 2
* this creates a 30x80 maze
*with many paths useing ' '
*/

#define WIDTH 80
#define HEIGHT 30

/**
* struct of arrays that tracks maze layout
*/

typedef struct{
	char tiles[HEIGHT][WIDTH];
} Level;

//*
*creates layout for given maze
*makes paths
*/
void load_level1(Level *lvl);
void load_level2(Level *lvl);


/**
*draws the maze useing ncurses
*clears screen and adds maze
*by removeing '#' to ' ' to make maze
*/

void draw_level(Level *lvl);

/*
*checks that maze is walkable to character
*by makeing sure their are ' ' gaps 
*/

int is_walkable(Level *lvl, int x, int y);

#endif
