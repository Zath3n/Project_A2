/********************************************************
 * @file npc.c                  
 * @Brief Definition of the functions in npc.h       
 * @author Kye R. ID:3143692 & Gabriel N. ID: 3132176                   
 * @date Dec. 9, 2025                  
 ********************************************************/

#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

#include "npc.h"
#include "levels.h"
#include "player.h"

#define NPC_MOVE_INTERVAL 2 //Interval of player movement before NPC moves

void init_npc(NPC *n, int x, int y){
	n->x = x;
    n->y = y;
    n->move_counter = 0;
}

void draw_npc(NPC *n){
	mvaddch(n->y, n->x, 'N');
}


void npc_move(NPC *n, Level *lvl, Player *p) {

    n->move_counter++;

    if (n->move_counter < NPC_MOVE_INTERVAL){
    	return;
    }

    n->move_counter = 0;

    int directions[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

    int idx = rand() % 4; //chose a random direction to move in.

    int nx = n->x + directions[idx][0];
    int ny = n->y + directions[idx][1];

    if (is_walkable(lvl, nx, ny) && !(nx == p->x && ny == p->y)) {
        n->x = nx;
        n->y = ny;
    }

}
void npc_dialog(Player *p, NPC *n){	//talking interactions

	int dx = (p->x - n->x);
	int dy = (p->y - n->y);

	if (dx + dy != 1) {	//Player not beside NPC, notify user they need to be.
		clear();
		mvprintw(15, 23, "You must stand next to the NPC!");
		refresh();
		sleep(1);
		return;
	}

	clear();
	mvprintw(15 , 30, "You need Help? IM LOST TOO!");
	refresh();
	sleep(2);
}
