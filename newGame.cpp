#include "newGame.h"

game::game() {
    win_y = 0;
    win_x = 0;
    hud_y = 0;
    hud_x = 0;
    player_x = 0;
    player_y = 0;
    player_health = 3;
    player_speed = 2;
    
    for(int i = 0; i < max_projectiles; i++) {
        projectiles[i][0] = -1;
	    projectiles[i][1] = -1;
    }
    for(int i = 0; i < max_number_of_enemies; i++) {
        enemies[i][0] = -1;
	    enemies[i][1] = -1;
    }
    for (int i = 0; i < max_number_of_powerups; i++)    {
        powerups[i][0] = -1;
        powerups[i][1] = -1;
    }
}

game::game(WINDOW * win, WINDOW * hud, int lvl, int px, int py, int ph, int ps, int pe[5][5]) {
    getmaxyx(win, win_y, win_x);
    getmaxyx(hud, hud_y, hud_x);
    level = lvl;
    player_x = px;
    player_y = py;
    player_health = ph;
    player_speed = ps;
    for(int i = 0; i < max_projectiles; i++) {
        projectiles[i][0] = -1;
	    projectiles[i][1] = -1;
    }
    for(int i = 0; i < max_number_of_enemies; i++) {
        for(int stat=0; stat<5; stat++)
	        enemies[i][stat] = pe[i][stat];
    }
}

void game::display(WINDOW * win, WINDOW * hud) {

    //display player
    wmove(win, player_y, player_x);
    waddstr(win, " ^ ");
    wmove(win, player_y+1, player_x);
    waddstr(win, "/#\\");
    wmove(win, player_y+2, player_x);
    waddstr(win, "H#H");

    //display player projectiles
    for(int i = 0; i < max_projectiles; i++) {
        if(projectiles[i][0] == -1)
            continue;
        wmove(win, projectiles[i][0], projectiles[i][1]);
        waddch(win, '!');
    }

    //display enemies
    for(int i = 0; i < max_number_of_enemies; i++) {

        if(enemies[i][0] == -1 || enemies[i][2] == -1)
            continue;

        int enemy_y = enemies[i][0], enemy_x = enemies[i][1];
        bool overlap = false;

        //check overlapping between player and enemy (enemies[i])
        if (enemy_y >= player_y && enemy_y <= player_y + 3) {
            if (enemy_x >= player_x - 3 && enemy_x <= player_x + 3) {
                overlap = true;
            }
        }

        //check if enemy hit by projectile
        for(int a = 0; a < max_projectiles; a++) {
                if(enemy_y == projectiles[i][0] && (enemy_x == projectiles[i][1] || enemy_x + 1 == projectiles[i][1] || enemy_x + 2 == projectiles[i][1]))
                    overlap = true;
        }

        //if overlapping or hit - set enemy health to -1, and skip display
        if(overlap) {
            enemies[i][2] = -1;
            continue;
        }

        //display enemy. only 1 kind so far
        wmove(win, enemy_y, enemy_x);
        waddstr(win, "X-X");
    } 

    //display the power-ups
    for (int i = 0; i < max_number_of_powerups; i++)    {
        if (powerups[i][0] == -1 || powerups[i][2] == 1)
            continue;
        
        int powerup_y = powerups[i][0];
        int powerup_x = powerups[i][1];
        bool overlap = false;

        //check whether the player overlaps with a power-up
        if (powerup_y >= player_y && powerup_y <= player_y + 2) {
            if (powerup_x >= player_x - 2 && powerup_x <= player_x + 2) {
                overlap = true;
            }
        }

        //if overlapping - set used flag to 1, and skip display
        if (overlap)    {
            powerups[i][2] = 1;
            switch(powerups[i][3])  {
                case 1:
                case 2: player_health++;
                case 3:
                case 0: player_speed += 2;
            }
            continue;
        }

        //display powerup
        wmove(win, powerup_y, powerup_x);
        waddstr(win, "*");
    }

    //displaying the HUD

    //line separating win and hud
    for(int i = 0; i < hud_x; i++) {
        waddch(hud, '_');
    }

    //display Level
    wmove(hud, hud_y/2, hud_x/5);
    std::string lvl = "Level: " + std::to_string(level);
    waddstr(hud, lvl.c_str());

    //display player_health
    wmove(hud, hud_y/2, hud_x/5*3);
    for(int i = 0; i < player_health; i++) {
        waddstr(hud,"O ");
    }
}

void game::update(int tick) {

    //update player projectiles
    for(int i = 0; i < max_projectiles; i++) {
        if(projectiles[i][0] == -1) 
            continue;
	    projectiles[i][0] = (projectiles[i][0] == 0) ? -1 : projectiles[i][0] - 1;
    }

    //every TICK_COUNT * 100 ticks, check if a speed powerup is active. If so, disable its effects
    if (tick % 1500 == 0)   {
        if (player_speed > 2)
            player_speed = 2;
    }

    //only update enemies every TICK_COUNT ticks, same for power-ups
    if (tick % 15 == 0) {
        for(int i = 0; i < max_number_of_enemies; i++) {
            if(enemies[i][0] == -1 || enemies[i][2] == -1) 
                continue;

            enemies[i][0] = (enemies[i][0] == win_y - 1) ? enemies[i][0] : enemies[i][0] + 1;

            //enemy reaches end of map
            if(enemies[i][0] == win_y - 1) {
                    player_health--;

                //reset enemy to default
                for(int reset = 0; reset < 5; reset++) {
                    enemies[i][reset] = -1;
                }

            }
        }
        for (int i = 0; i < max_number_of_powerups; i++)    {
            if (powerups[i][0] == -1 || powerups[i][2] == 1)
                continue;

            powerups[i][0] = (powerups[i][0] == win_y - 1) ? powerups[i][0] : powerups[i][0] + 1;

            //powerup reaches end of map
            if (powerups[i][0] == win_y - 1)    {

                //reset powerup to default
                for (int reset = 0; reset < 5; reset++) {
                    powerups[i][reset] = -1;
                }
                for (int j = 0; j < 5; j++) {
                    powerups[j][2] = 1;
                }
            }
        }
    }

    //if enemy gets hit by player projectile
    for(int i = 0; i < max_number_of_enemies; i++) {
        for(int j = 0; j < max_projectiles; j++) {
            if((enemies[i][1] == projectiles[j][1] || enemies[i][1] + 1 == projectiles[j][1] || enemies[i][1] + 2 == projectiles[j][1]) && enemies[i][0] >= projectiles[j][0]) {

            //enemies[i][2]--;
	    //resets enemies. TEMPORARY CODE. SHOULD FIX ENEMIES NOT DYING
	    for(int reset = 0; reset < 5; reset++) {
                enemies[i][reset] = -1;
	    }
            projectiles[j][0] = -1;
            projectiles[j][1] = -1;
	        }
	    }
    }
}

bool game::isOver() {
    if(player_health <= 0) 
        return true;
    return false;
}

void game::playerMove(char move) {
    switch(move) {
	//left
        case 'a':
            //Left world boundary is 0+1, as a border may be drawn
            player_x = (player_x == 1) ? player_x : player_x - 2;
	    break;

        //right
        case 'd':
            //Right world boundary is 80-1-3, accounting for player model dimensions
            player_x = (player_x == win_x - 1 - 3) ? player_x : player_x + 2;
            break;

        //shoot
        case 'w':
            for(int i=0; i<max_projectiles; i++) {
                if(projectiles[i][0] != -1)
                    continue;
                projectiles[i][0] = player_y - 1;
                projectiles[i][1] = player_x;
                break;
            }
            break;
        }
}

bool game::enemies_empty() {
    bool empty = true;
    for(int i = 0; i < max_number_of_enemies; i++) {
        if(!(enemies[i][0] == -1 || enemies[i][2] == -1)) {
            empty = false;
	    }
    }
    return empty;
}

bool game::powerups_empty() {
    bool empty = true;
    for (int i = 0; i < max_number_of_powerups; i++)    {
        if (!(powerups[i][0] == -1 || powerups[i][2] == 1))    {
            empty = false;
        }
    }
    return empty;
}

void game::generate_enemies(int no_of_enemies) {
    srand(time(NULL));
    for(int i = 0; i < no_of_enemies; i++) {
        enemy E;
        E.y = 1;
        E.x = rand() % (win_x - 3);
        E.health = 0;
        E.projectile_y = -1;
        E.projectile_x = -1;
        
        all_enemies.push(E);	
    }
}

void game::generate_powerups(int no_of_powerups)    {
    srand(time(NULL));
    for (int i = 0; i < no_of_powerups; i++) {
        powerup P;
        P.y = 1;
        P.x = rand() % (win_x - 3);
        P.used = 0;
        //P.duration = rand() % 20;
        P.effect = rand() % 4;
        P.appearance = (char) appearances[P.effect];
        power_ups.push(P);
    }
}

void game::add_enemies() {
    int i = 0;
    while(!all_enemies.empty() && i++ < max_number_of_enemies) {
        enemies[i][0] = all_enemies.front().y;
        enemies[i][1] = all_enemies.front().x;
        enemies[i][2] = all_enemies.front().health;
        enemies[i][3] = all_enemies.front().projectile_y;
        enemies[i][4] = all_enemies.front().projectile_x;

        all_enemies.pop();
    }
}

void game::add_powerups()   {
    int i = 0; 
    while ((!power_ups.empty()) && (i++ < max_number_of_powerups))  {
        powerups[i][0] = power_ups.front().y;
        powerups[i][1] = power_ups.front().x;
        //powerups[i][2] = power_ups.front().duration;
        powerups[i][2] = power_ups.front().used;
        powerups[i][3] = power_ups.front().effect;
        powerups[i][4] = power_ups.front().appearance;
        //powerups[i][5] = power_ups.front().used;
        power_ups.pop();
    }
}
