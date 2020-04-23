#ifndef NEW_GAME_H
#define NEW_GAME_H

#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>

class game {
    int player_x, player_y;
    const int max_number_of_enemies=5;
    int enemies[max_number_of_enemies][2];
public:
    game();
    game(int,int,int[max_number_of_enemies][2]);
    void display(WINDOW * win);
    bool isover();
    void playerMove(char);
};

#endif
