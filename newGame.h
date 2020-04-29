#ifndef NEW_GAME_H
#define NEW_GAME_H

#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <queue>

class game {
    int level;

    //max y and x values for win and hud
    int win_y, win_x, hud_y, hud_x;

    int player_x, player_y, player_health;
    const int max_projectiles=5;
    //y, x
    int projectiles[5][2];

    struct enemy {
        int y, x, health, projectile_y, projectile_x;
    };
    std::queue<enemy> all_enemies;

    const int max_number_of_enemies=5;
    //y, x, health, projectile_y, projectile_x
    int enemies[5][5];
public:
    game();
    game(WINDOW * win, WINDOW * hud,int,int,int,int,int[5][5]);
    void display(WINDOW * win, WINDOW * hud);
    void update(int);
    bool isOver();
    void playerMove(char);
    bool enemies_empty();
    //adds enemies to buffer queue
    void generate_enemies(int);
    //adds enemies to enemies[][] array
    void add_enemies();
};

#endif
