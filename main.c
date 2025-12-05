

#include <ncurses.h>
#include "maze1.h"


int main(void) {
	initscr();
	noecho();
	cbreak();

	init_maze1();
	draw_maze1();

	getch();
	endwin();
	return 0;
}

