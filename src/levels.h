#ifndef LEVELS_H
#define LEVELS_H

/**
*levels.h
* Header file for maze level 2
* this creates a 30x80 maze
*/

#define WIDTH 80
#define HEIGHT 30

typedef struct{
	char tiles[HEIGHT][WIDTH];
} Level;

void load_level1(Level *lvl);
void load_level2(Level *lvl);

void draw_level(Level *lvl);
int is_walkable(Level *lvl, int x, int y);

#endif
