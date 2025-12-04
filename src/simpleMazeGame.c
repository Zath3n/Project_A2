#include <stdio.h>
#include <curses.h>
#include <unistd.h>



void MainMenuScreen(){

		clear(); //remove any previous text.

		mvprintw(5, 20, "===============================");
		mvprintw(6, 20, "       TERMINAL MAZE GAME      ");
		mvprintw(7, 20, "===============================");

		
}