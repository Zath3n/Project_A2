#ifndef NPC_H
#define NPC_H

#include "levels.h"
#include "player.h"


/**
 * 
 * Creates a struc for an NPC in the maze for the user to talk too. NPC's can move, aswell as
 * talk to the player if prompted by the player
 * 
 */
typedef struct{
	int x;
	int y;
	int move_counter;    //Counter To slow down pace of movement of the NPC based user movement.
} NPC;


/**
 * 
 *Initalizes the NPC at a specific location 
 * 
 */
void init_npc(NPC *n, int x, int y);

/**
 * 
 *Draws the NPC onto the screen.
 * 
 */
void draw_npc(NPC *n);

/**
 * 
 *Moves the NPC based on the movement of the player in a random coordinate/positon. Uses similar 
 *is_walkable() function to check if the new spot is viable or not.
 * 
 */
void npc_move(NPC *n,Level *lvl, Player *p);

/**
 * 
 * Triggers NPC dialog with the playyer interacts with the NPC by pressing the key "T" or "t".
 * Dialog only works if the player is beside the NPC, otherwise, a different pop-up will appear to
 * notify player that talking to the NPC is only possible if they are beside them.
 * 
 */
void npc_dialog(Player *p, NPC *n);

#endif
