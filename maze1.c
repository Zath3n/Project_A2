//Kye Rich 3143692
/**
*implments init and drawing maze 1
*/

//#include "simpleMazeGame.h"
#include "maze1.h"
#include <string.h>

char level1[HEIGHT][WIDTH + 1];

/**
*make bourder walls with '#'
*/
static void make_border() {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++)
			level1[y][x] = '#';
		level1[y][WIDTH] = '\0';
	}
}

/**
*create the path 1 useing '/' '\' and '|'
*top path
*/
static void top_path() {
	int y = 2;
	int x = 1;
// right along top
	while (x < WIDTH - 3)
		level1[y][x++] = ' ';
// go down to f
	while (y < HEIGHT - 2)
		level1[y++][x] = ' ';
}
/**
*bottom path
*/
static void bottom_path() {
	int x = 1;
	int y = 1;

//move down
	while (y < HEIGHT - 3)
		level1[y++][x] = ' ';

//move right
	while (x < WIDTH-2)
		level1[y][x++] = ' ';

}


/**
*middle path
*/

static void middle_path() {

	int y = HEIGHT/2;
	for (int x = 1; x < WIDTH - 2; x++)
		level1[y][x] = ' ';
}
/**
* make full layout for level 1
* make bourders
*paths and exit
*/

void init_maze1() {
	make_border();

	top_path();
	bottom_path();
	middle_path();

	level1[HEIGHT - 3][WIDTH - 3] = 'F';


}

/**
*add maze to window with ncurses
*/

void draw_maze1(){
	clear();
	for (int y = 0; y < HEIGHT; y++) {
		mvprintw(y, 0, "%s", level1[y]);
	}
	refresh();
}



