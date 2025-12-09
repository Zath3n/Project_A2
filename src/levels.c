//ID: 3143692 Name: Kye Rich
//ID: 3132175 Name: Gabriel


#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#define WIDTH 80
#define HEIGHT 30

typedef struct {
    char tiles[HEIGHT][WIDTH];
} Level;


//-------------------Level 1-----------------------

>>>>>>> Stashed changes:src/levels.c
/*
*makes a box of '#' to start maze
*/
static void make_border(Level *lvl) {
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++){
            lvl->tiles[y][x] = '#';
        }
}
/*
*creates space for maze
*/

static void lvl1_top_path(Level *lvl) {
    int y = 2;
    int x = 1;

    while (x < WIDTH - 3){
        lvl->tiles[y][x++] = ' ';
    }

    while (y < HEIGHT - 2){
        lvl->tiles[y++][x] = ' ';
    }
}

static void lvl1_bottom_path(Level *lvl) {
    int x = 1;
    int y = 1;

    while (y < HEIGHT - 3){
        lvl->tiles[y++][x] = ' ';
    }

    while (x < WIDTH - 2){
        lvl->tiles[y][x++] = ' ';
    }
}

static void lvl1_middle_path(Level *lvl) {
    int y = HEIGHT/2;
    for (int x = 1; x < WIDTH - 2; x++){
        lvl->tiles[y][x] = ' ';
    }
}

void load_level1(Level *lvl) {
    make_border(lvl);
    lvl1_top_path(lvl);
    lvl1_bottom_path(lvl);
    lvl1_middle_path(lvl);
    lvl->tiles[HEIGHT-3][WIDTH-3] = 'F';
}

//----------------------Level two Stuff-------------------------

/*
*makes a 3 space wide path
*/
static void wide3(Level *lvl, int y, int x) {
    lvl->tiles[y][x] = ' ';
    lvl->tiles[y][x+1] = ' ';
    lvl->tiles[y+1][x] = ' ';
}

static void lvl2_start_area(Level *lvl) {
    for (int y = 1; y <= 3; y++)
        for (int x = 1; x <= 5; x++){
            lvl->tiles[y][x] = ' ';
        }
}

static void lvl2_exit_area(Level *lvl) {
    for (int y = 26; y <= 28; y++)
        for (int x = 74; x <= 78; x++){
            lvl->tiles[y][x] = ' ';
        }
}


static void lvl2_npc_area(Level *lvl) {
    for (int y = 4; y <= 10; y++)
        for (int x = 65; x <= 75; x++){
            lvl->tiles[y][x] = ' ';
        }
}


static void lvl2_npc_connect(Level *lvl){

	int x = 14; 
	int y = 7;

	while (x < 65){
		lvl->tiles[y][x++] = ' ';
	}
}

static void lvl2_random_box(Level *lvl) {
    for (int y = 25; y <= 28; y++)
        for (int x = 3; x <= 9; x++){
            lvl->tiles[y][x] = ' ';
        }
}

static void lvl2_random_box_line(Level *lvl) {
    int x = 9, y = 26;

    while (x < 65){
        wide3(lvl, y, x++);
    }

    while (y > 15){
        lvl->tiles[y--][x] = ' ';
    } 
}

static void lvl2_correct_path(Level *lvl) {
    int x = 3;
    int y = 3;

    while (x < WIDTH/2 - 2 && y < HEIGHT/2 - 2){
        wide3(lvl, y++, x++);
    }

    int down_start = HEIGHT/4;
    int down_end = HEIGHT*3/4;
    y = down_start;

    while (y < down_end){
        lvl->tiles[y++][x] = ' ';
    }

    while (x < WIDTH-2){
        lvl->tiles[y][x++] = ' ';
    }

    while (y < HEIGHT-4){
        vl->tiles[y++][x] = ' ';
    }
}

static void lvl2_wrong_path1(Level *lvl) {
    int x = 3;
    int y = 3;

    while (x < WIDTH/2){
        lvl->tiles[y][x++] = ' ';
    }

    while (y < HEIGHT-8){
        lvl->tiles[y++][x] = ' ';
    }

}

static void lvl2_wrong_path2(Level *lvl) {
    int x = 3;
    int y = 3;

    while (y < HEIGHT/2){
        lvl->tiles[y++][x] = ' ';
    }

    while (x < (WIDTH*3)/4){
        lvl->tiles[y][x++] = ' ';
    }
}

void load_level2(Level *lvl) {
    make_border(lvl);
    lvl2_start_area(lvl);
    lvl2_exit_area(lvl);
    lvl2_npc_area(lvl);
    lvl2_npc_connect(lvl);
    lvl2_random_box(lvl);
    lvl2_random_box_line(lvl);
    lvl2_correct_path(lvl);
    lvl2_wrong_path1(lvl);
    lvl2_wrong_path2(lvl);
    lvl->tiles[HEIGHT-3][WIDTH-3] = 'F'; //Exit of the Game
}

//-----------------Check Functions -------------

void draw_level(Level *lvl) {
    for (int y = 0; y < HEIGHT; y++) {
        move(y,0);
        for (int x = 0; x < WIDTH; x++){
            addch(lvl->tiles[y][x]);
        }
    }
}

int is_walkable(Level *lvl, int x, int y) {
    
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT){
        return 0;
    }

    return lvl->tiles[y][x] != '#';
}