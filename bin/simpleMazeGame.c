#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define HEIGHT 30
#define WIDTH 80

char level1[HEIGHT][WIDTH + 1];
char level2[HEIGHT][WIDTH + 1];

typedef struct {
    int x, y;
    char symbol;
} Player;


int SplashArt(){


	mvprintw(5, 25, "/$$      /$$  /$$$$$$                             /$$$$$$");
	mvprintw(6, 25, "| $$$    /$$$ /$$__  $$                           /$$__  $$");
	mvprintw(7, 25, "| $$$$  /$$$$| $$  \\ $$ /$$$$$$$$  /$$$$$$       | $$  \\__/  /$$$$$$  /$$$$$$/$$$$   /$$$$$$");
	mvprintw(8, 25, "| $$  $$$| $$| $$__  $$   /$$$$/ | $$$$$$$$      | $$|_  $$  /$$$$$$$| $$ \\$$ \\$$| $$$$$$$$");


}



int MainMenuScreen(){

	clear(); //remove any previous text.

	mvprintw(5, 25, "===============================");
	mvprintw(6, 25, "       TERMINAL MAZE GAME      ");
	mvprintw(7, 25, "===============================");

	mvprintw(9, 21, "Welcome to the HARDEST Maze Adventure!");
	mvprintw(10, 21, "Your Goal is to get to the Exit(F)...!");
	mvprintw(12, 20, "Your represented as: @");
	mvprintw(12, 55, "NPC is: N");

	mvprintw(14, 5, "CONTROLS:");
	mvprintw(16, 5, "Move Your Character using: W A S D");
	mvprintw(17, 5, "Talk to NPC: T");
	mvprintw(18, 5, "Pause: P");
	mvprintw(19, 5, "Quit This Awesome Game: Q");

	mvprintw(14, 50, "Choose Option Here Please:");
	mvprintw(16, 50, "Level 1 (Easy): 1");
	mvprintw(17, 50, "Level 2 (Medium): 2");
	mvprintw(18, 50, "Exit The Games: Q");

	mvprintw(25, 25, "Enter selection: ");
	refresh();

	int ch = getch();
	return ch;
}

void init_level1() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1)
                level1[y][x] = '#';
            else
                level1[y][x] = ' ';
        }
    }

}

void display_level(int level) {
    clear();

    char (*maze)[WIDTH + 1] = (level == 1 ? level1 : level2);

    for (int y = 0; y < HEIGHT; y++) {
        move(y, 0);
        for (int x = 0; x < WIDTH; x++) {
            addch(maze[y][x]);
        }
    }

    refresh();
}

void play_level(int level) {
	char (*maze)[WIDTH + 1] = (level == 1 ? level1 : level2);

	Player p = {1, 1, '@'};


	//Game States
	int paused = 0;
	int running = 1;
	int ch;

	display_level(level);


	mvaddch(p.y, p.x, p.symbol);
	refresh();

	while (running){

		ch = getch();

		//Player Movement ---------------------------------
	
		int nx = p.x;
		int ny = p.y;

		if (ch == 'w') ny--;
		if (ch == 's') ny++;
		if (ch == 'a') nx--;
		if (ch == 'd') nx++;

		if (maze[ny][nx] != '#') {
			mvaddch(p.y, p.x, ' ');
			p.x = nx;
			p.y = ny;
			mvaddch(p.y, p.x, p.symbol);
		}

		//-------------------------------------------------


	}

	


}


int main() {

	srand(time(NULL));

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);	


	while (1){

		
		int choice = SplashArt();
		int choice = MainMenuScreen();

		if (choice == '1') {
			init_level1();
			play_level(1);
		}
			
		if (choice == "2"){
			printf("WIP");
		}

		if (choice == "3"){
			printf("WIP");
		}
	}

	return 0;
}