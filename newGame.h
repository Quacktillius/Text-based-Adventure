#ifndef NEW_GAME_H
#define NEW_GAME_H

#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>

class game {
    int player_x, player_y;
    const int max_projectiles=5;
    int projectiles[5][2];
    const int max_number_of_enemies=5;
    int enemies[5][2];
public:
    game();
    game(int,int,int[5][2]);
    void display(WINDOW * win);
    void update();
    bool isOver();
    void playerMove(char);
};

#endif
