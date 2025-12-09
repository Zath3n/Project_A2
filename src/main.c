/********************************************************
 * @file npc.c                  
 * @Brief Definition of the functions in npc.h       
 * @author Kye R. ID:3143692 & Gabriel N. ID: 3132176                   
 * @date Dec. 9, 2025                  
 ********************************************************/

#include <curses.h>
#include <unistd.h>
#include "player.h"
#include "npc.h"
#include "levels.h"

#define WIDTH 80
#define HEIGHT 30

/**
 * 
 *Shows a splashArt to the user before showing the main menu
 * 
 */
int SplashArt(){


	clear(); 

	mvprintw(2, 16, "  /$$      /$$  /$$$$$$  /$$$$$$$$ /$$$$$$$$  ");
	mvprintw(3, 16, " | $$$    /$$$ /$$__  $$|_____ $$ | $$_____/  ");
	mvprintw(4, 16, " | $$$$  /$$$$| $$  \\ $$     /$$/ | $$        ");
	mvprintw(5, 16, " | $$ $$/$$ $$| $$$$$$$$    /$$/  | $$$$$     ");
	mvprintw(6, 16, " | $$  $$$| $$| $$__  $$   /$$/   | $$__/     ");
	mvprintw(7, 16, " | $$\\  $ | $$| $$  | $$  /$$/    | $	      ");
	mvprintw(8, 16, " | $$ \\/  | $$| $$  | $$ /$$$$$$$$| $$$$$$$$  ");
	mvprintw(9, 16, " |__/     |__/|__/  |__/|________/ \\_______/  ");

			
	mvprintw(11, 16, "   /$$$$$$                                    ");
	mvprintw(12, 16, "  /$$__  $$                                   ");
	mvprintw(13, 16, " | $$  \\__/  /$$$$$$  /$$$$$$/$$$$   /$$$$$$  ");
	mvprintw(14, 16, " | $$ /$$$$ |____  $$| $$_  $$_  $$ /$$__  $$ ");
	mvprintw(15, 16, " | $$|_  $$  /$$$$$$$| $$ \\ $$ \\ $$| $$$$$$$$ ");
	mvprintw(16, 16, " | $$  \\ $$ /$$__  $$| $$ | $$ | $$| $$_____/ ");
	mvprintw(17, 16, " |  $$$$$$/|  $$$$$$$| $$ | $$ | $$|  $$$$$$$ ");
	mvprintw(18, 16, "  \\______/  \\_______/|__/ |__/ |__/ \\_______/ ");
	

	mvprintw(28, 25, "Press Any Key To Continue... ");


	int ch = getch();
	return ch;

}

/**
 * 
 *Main Menu showing controls to the user and generally how to play the game.
 * 
 */
int MainMenuScreen(){

	clear();

	mvprintw(5, 25, "===============================");
	mvprintw(6, 25, "       TERMINAL MAZE GAME      ");
	mvprintw(7, 25, "===============================");

	mvprintw(9, 21, "Welcome to the HARDEST Maze Adventure!");
	mvprintw(10, 21, "Your Goal is to get to the Exit(F)...!");
	mvprintw(12, 20, "Your represented as: @");
	mvprintw(12, 55, "NPC is: N");

	mvprintw(14, 5, "CONTROLS:");
	mvprintw(16, 5, "Move Your Character using: W A S D");
	mvprintw(17, 5, "To interact with a Lever: X");
	mvprintw(18, 5, "Talk to NPC: T");
	mvprintw(19, 5, "Pause: P");
	mvprintw(20, 5, "Quit This Awesome Game: Q");

	mvprintw(14, 50, "Choose Option Here Please:");
	mvprintw(16, 50, "Level 1 (Easy): 1");
	mvprintw(17, 50, "Level 2 (Medium): 2");
	mvprintw(18, 50, "Exit The Games: Q");

	mvprintw(25, 25, "Enter selection: ");
	refresh();

	int ch = getch();
	return ch;
}

/**
 * 
 * Pauses the game if the player presses P by switching the screen to the pause menu, until the
 * user presses "p" or "P" to continue the game again.
 * 
 */
void pause_game() {
    clear();
    mvprintw(15, 32, "===== PAUSED =====");
    mvprintw(17, 30, "Press 'P' to continue");
    refresh();

    int ch;
    do {
        ch = getch();
    } while (ch != 'p' && ch != 'P');
}

/**
 * 
 *Switches the screen to the win menu, telling the user they reached the end, until the user presses
 *any key to go back to the menu.
 * 
 */
void win_screen() {
    clear();
    mvprintw(HEIGHT / 2 - 1, WIDTH / 2 - 4, "YOU WIN!");
    mvprintw(HEIGHT / 2 + 1, WIDTH / 2 - 14, "Press any key to continue...");
    refresh();
    getch();
}

/**
 * 
 *Function to check if the player reached the exit or "F" in to scren with "@" If so, return 1(True).
 * 
 */
int player_reached_exit(Player *player, Level *lvl) {

    // Check the level map at the users position
    if (lvl->tiles[player->y][player->x] == 'F') {
        return 1;
    }
    return 0;
}


/**
 * 
 *Function that handles running the game. NPC spawn location is changed depending on the level loaded.
 *Initalizes playerand NPC, and uses a while loop to process input/movement to redraw the screen, with
 * additional functions such as to pause, exit, talking to NPC, and if the player reaches the end.
 * 
 */
void run_level(void (*load_fn)(Level*)) {

	Player player;
	NPC npc;
	Level lvl;

	load_fn(&lvl); 
	init_player(&player);

	//initialize NPC location to 0,0.
	int npc_x = 0;
	int npc_y = 0;  

	//NPC Coordinates/Position based on level loaded.
	if (load_fn == load_level1){ 
		npc_x = 2;
		npc_y = 26;
	} 

	else if (load_fn == load_level2){
		npc_x = 5;
		npc_y = 26;
	}

	init_npc(&npc, npc_x, npc_y);

	int running = 1;
	while (running){

		erase();

		//updates level, npc, & player status by calling helper function to re-draw new npc & player location
		//if they moved.
		draw_level(&lvl);         
		draw_player(&player);
 		draw_npc(&npc);

		int ch = getch();

		if (ch == 'q' || ch == 'Q')
			break;

		else if (ch == 't' || ch == 'T')
			npc_dialog(&player, &npc);

		else if (ch == 'p' || ch == 'P')
			pause_game();

		else if (ch == 'x' || ch == 'X') {

			//If the player is standing on the lever 
			if (lvl.tiles[player.y][player.x] == 'L') {

    				lvl.tiles[player.y][player.x] = 'l';

    				lvl.tiles[HEIGHT-4][WIDTH-3] = ' ';


				// Give player a message
				clear();
				mvprintw(15, 28, "You pulled the lever!");
				mvprintw(17, 25, "The barricade has opened...");
				refresh();
				sleep(1);
			}
		}


		else
			player_move(&player, &lvl, ch);


		if (player_reached_exit(&player, &lvl)) { //if player reaches exit, show win screen and exit loop.
			win_screen();
			running = 0;
			continue;
		}


		npc_move(&npc, &lvl, &player); //update npc movement.
		refresh(); //refreshes the console to apply all the movement done before the re-loop.
	}
}


/**
 * 
 *Initalize curses, show splash screeen, and loop to create a menu for user input.
 *Loads and run different level or exit program based on said user input.
 * 
 */
int main(){

    clear();
    initscr();
    noecho();


    SplashArt();

    while (1) {
        int choice = MainMenuScreen();

        if (choice == '1'){
		run_level(load_level1);
	}
            
        else if (choice == '2'){
		run_level(load_level2);
	}
 
        else if (choice == 'q' || choice == 'Q'){
		break;
	}

    }
    endwin();
    return 0;
}