#ifndef PLAYER_H
#define PLAYER_H

#include "levels.h"

typedef struct {
    int x, y;
    char symbol;
} Player;

void init_player(Player *p);
void draw_player(Player *p);
void player_move(Player *p, Level *lvl, int key);
int player_reached_exit(Player *p, Level *lvl);

#endif
