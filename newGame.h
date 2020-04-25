#ifndef NEW_GAME_H
#define NEW_GAME_H

#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>

class game {
    int player_x, player_y;
    const int max_projectiles=5;
    int projectiles[5][2]; //x, y
    const int max_number_of_enemies=5;
    int enemies[5][3]; //x, y, hit
public:
    game();
    game(int,int,int[5][3]);
    void display(WINDOW * win);
    void update(int);
    bool isOver();
    void playerMove(char);
};

#endif
