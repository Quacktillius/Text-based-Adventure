#ifndef NEW_GAME_H
#define NEW_GAME_H

#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <string>

class game {
    int level;

    int win_y, win_x, hud_y, hud_x;

    int player_x, player_y, player_health;
    const int max_projectiles=5;
    int projectiles[5][2]; //x, y

    const int max_number_of_enemies=5;
    int enemies[5][5]; //x, y, health, projectile_x, projectile_y
public:
    game();
    game(WINDOW * win, WINDOW * hud,int,int,int,int,int[5][5]);
    void display(WINDOW * win, WINDOW * hud);
    void update(int);
    bool isOver();
    void playerMove(char);
};

#endif
