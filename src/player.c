// ID: 3143692 Name: Kye Rich
// ID: 3132175 Name: Gabriel

#include <ncurses.h>
#include "player.h"


void init_player(Player *p) {
    p->x = 2;
    p->y = 2;
    p->symbol = '@';
}


void draw_player(Player *p) {
    mvaddch(p->y, p->x, p->symbol);
}


void player_move(Player *p, Level *lvl, int key) { //Player movement
    int nx = p->x;
    int ny = p->y;

    if (key == 'w' || key == 'W') ny--; //moves player up (Y-axis)
    if (key == 's' || key == 'S') ny++; //moves player down (Y-axis)
    if (key == 'a' || key == 'A') nx--; //moves player left (X-axis)
    if (key == 'd' || key == 'D') nx++; //moves player right (X-axis)

    if (is_walkable(lvl, nx, ny)) { //Checks if the new postion/coordinate is an empty spot and not a border/wall.
        p->x = nx;
        p->y = ny;
    }
}
