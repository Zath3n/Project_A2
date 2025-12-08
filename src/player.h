#ifndef PLAYER_H
#define PLAYER_H

#include "levels.h"


/**
 * 
 * Stores the users current coordinates/position and display symbol.
 * 
 */
typedef struct {
    int x, y;
    char symbol;
} Player;


/**
 * 
 * Initializes the player with startng values by
 * setting the player's position based on x/y value and symbol represented by @.
 * 
 */
void init_player(Player *p);


/**
 * 
 * Draws the player on the Ncurses screen, using mvaddch() to place @, 
 * at the given location/position
 * 
 */
void draw_player(Player *p);

/**
 * 
 * Moves the user based on user keyboard input by allowing the user to move the character with WASD key. 
 * If one said button is pressed, the current location of @ in the console is moved in the 
 * direction of the key pressed.
 * 
 */
void player_move(Player *p, Level *lvl, int key);

/**
 * 
 * Checks if the player symbol has reached the exit of the level, which is represented by "F".
 * 
 */
int player_reached_exit(Player *p, Level *lvl);

#endif
