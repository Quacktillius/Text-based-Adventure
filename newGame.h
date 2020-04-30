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

    struct powerup  {
        int y, x, duration, effect;
        char appearance;
    };

    std::queue<powerup> power_ups;
    const int max_number_of_powerups = 2;
    //y, x, duration, effect, appearance
    int powerups[5][5];
    int appearances[4] = {0xd1aa, 0xd1ae, 0xd1b0, 0xd296};

public:
    game();
    game(WINDOW * win, WINDOW * hud,int,int,int,int,int[5][5]);
    void display(WINDOW * win, WINDOW * hud);
    void update(int);
    bool isOver();
    void playerMove(char);
    bool enemies_empty();
    bool powerups_empty();
    //adds enemies to buffer queue
    void generate_enemies(int);
    //adds power-ups to buffer queue
    void generate_powerups(int);
    //adds enemies to enemies[][] array
    void add_enemies();
    //adds power-ups to the screen
    void add_powerups();
};

#endif
