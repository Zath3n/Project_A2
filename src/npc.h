#ifndef NPC_H
#define NPC_H

#include "levels.h"
#include "player.h"

typedef struct{
	int x, y;
	const char *dialog;
	int move_counter;
}NPC;

void init_npc(NPC *n, int x, int y);
void draw_npc(NPC *n);
void npc_move(NPC *n,Level *lvl, Player *p);
void npc_dialog(Player *p, NPC *n);

#endif
