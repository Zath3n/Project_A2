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

    if (key == 'w' || key == 'W') ny--;
    if (key == 's' || key == 'S') ny++;
    if (key == 'a' || key == 'A') nx--;
    if (key == 'd' || key == 'D') nx++;

    if (is_walkable(lvl, nx, ny)) {
        p->x = nx;
        p->y = ny;
    }
}

