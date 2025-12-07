//Kye Rich 3143692

/**
*a funtion to pause the game
*prints infomation on the screen and waits for user to press p again
*/

void pause_game() {
	clear();
	mvprintw(HEIGHT/2 - 1, (WIDTH/2) - 6, "===== PAUSED ====");
	mvprintw(HEIGHT/2 + 1, (WIDTH/2) - 12, "press 'p' to continue");
	refresh();

	int ch;
	//press p again

	do {
		ch = getch();
	} while (ch != 'p' && ch != 'P');
}


// while game running

//if (ch == 'p' || ch == 'P') {
//	pause_game();
//redraw maze
//	init_maze1();
//	draw_maze1();
//	mvaddch(p.y, p.x, p.symbol);
//add char
//	refresh();
//}
