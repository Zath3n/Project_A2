//Kye Rich 3143692
/**
*implments init and drawing maze 1
*/

//#include "simpleMazeGame.h"
#include "maze2.h"
#include <string.h>

char level2[HEIGHT][WIDTH + 1];

/**
*make bourder walls with '#'
*/
static void make_border() {

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++)
			level2[y][x] = '#';
		level2[y][WIDTH] = '\0';
	}
}

/**
*3 wide path when needed
*/
static void wide3(int y, int x) {
	level2[y][x] = ' ';
	level2[y][x + 1]= ' ';
	level2[y + 1][x] = ' ';
}

/**
*make start area 3x5
*/

static void start_area(){
	for (int y = 1; y <= 3; y++) {
		for (int x = 1; x <= 5; x++){
			level2[y][x] = ' ';
		}
	}

}
/**
*make exit area 3x5
*/

static void exit_area() {
	for (int y = 26; y <= 28; y++) {
		for (int x = 74; x <= 78; x++) {
			level2[y][x]= ' ';
		}
	}
}

/**
*make npc area
*/

static void npc_area() {
	for (int y =4; y <= 10; y++) {
		for (int x = 65; x <= 75; x ++) {
			level2[y][x] = ' ';
		}
	}
}

static void npc_connect() {
	int x = 14;
	int y = 7;

	while (x < 65) {
		level2[y][x] = ' ';
		x++;
	}

}
//bottom right
static void random_box(){
	for (int y = 25; y <= 28; y++) {
		for (int x = 3; x <= 9; x++) {
			level2[y][x] = ' ';
		}
	}
}

//random box line
static void random_box_line() {

	int x = 9;
	int y = 26;
//right
	while (x < 65) {
		wide3(y,x);
		x++;
	}

// up
	while (y > 15) {
		level2[y][x] = ' ';
		y--;
	}
}

/**
*make correct path
*goes diagnoal to middle. down, right, then down to f
*/

static void correct_path() {
	int x = 3;
	int y = 3;

//diagonal
	while (x < WIDTH/2 - 2 && y < HEIGHT/2 - 2) {
		wide3(y,x);
		x++;
		y++;
	}


//move down
	int down_start = HEIGHT /4;
	int down_end= (HEIGHT *3) / 4;

	y = down_start;

	while (y < down_end) {
		level2[y][x] = ' ';
		y++;
	}
//move right
	while (x < WIDTH - 2) {
		level2[y][x] = ' ';
		x++;
	}

//move to finish

	while ( y < HEIGHT - 4) {
		level2[y][x] = ' ';
		y++;
	}
}

/**
*wrong path that goes right and  then down
*/

static void wrong_path1() {
	int x = 3;
	int y = 3;

	int mid_x = WIDTH/2;
// right
	while (x < mid_x) {
		level2[y][x] = ' ';
		x++;
	}

//down
	int bottom = HEIGHT - 8;
	while (y < bottom) {
		level2[y][x] = ' ';
		y++;
	}
}

/**
*wrong path that goes down and right
*/

static void wrong_path2() {
	int x = 3;
	int y = 3;

	int mid_y = HEIGHT/2;
	while ( y < mid_y) {
		level2[y][x]= ' ';
		y++;
	}

	int tar_x = (WIDTH * 3) /4;
	while (x < tar_x) {
		level2[y][x]= ' ';
		x++;
	}
}
/**
*make full layout for maze 2
* makeing border paths and exir
*/

void init_maze2() {
	make_border();

	npc_area();
	start_area();
	exit_area();
	random_box(); //bottom right

	npc_connect();
	random_box_line();

	correct_path();
	wrong_path1();
	wrong_path2();
//exit
	level2[HEIGHT - 3][WIDTH - 3] = 'F';
}
/**
*add maze 2 to window with ncurses
*/
void draw_maze2() {
	clear();
	for (int y = 0; y < HEIGHT; y++) {
		mvprintw(y,0,"%s",level2[y]);
	}
	refresh();
}
