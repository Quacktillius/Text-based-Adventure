#include "newGame.h"
#include "menu.h"

game::game() {
    win_y = 0;
    win_x = 0;
    hud_y = 5;
    hud_x = 0;
    getmaxyx(stdscr, win_y, win_x);
    win_y -= 6;
    hud_x = win_x;
    player_x = win_x / 2;
    player_y = (win_y / 6) * 5;
    player_health=3;
    player_speed=2;
    player_countdown=0;
    level = 0;
    bfb_used = false;
    for(int i = 0; i < max_projectiles; i++) {
        projectiles[i][0] = -1;
	    projectiles[i][1] = -1;
    }
    for(int i = 0; i < max_number_of_enemies; i++) {
        enemies[i][0] = -1;
	    enemies[i][1] = -1;
    }
}

game::game(WINDOW * win, WINDOW * hud, int lvl, int px, int py, int ps, int ph, int pe[5][5], int pu[1][3]) {
    getmaxyx(win, win_y, win_x);
    getmaxyx(hud, hud_y, hud_x);
    level = lvl;
    player_x = px;
    player_y = py;
    player_health = ph;
    player_speed = ps;
    player_countdown = 0;
    bfb_used = false;
    for(int i = 0; i < max_projectiles; i++) {
        projectiles[i][0] = -1;
	    projectiles[i][1] = -1;
    }
    for(int i = 0; i < max_number_of_enemies; i++) {
        for(int stat = 0; stat < 5; stat++)
	        enemies[i][stat] = pe[i][stat];
    }
    for(int i = 0; i < max_number_of_powerups; i++) {
        for(int stat = 0; stat < 3; stat++)
	        powerups[i][stat] = pu[i][stat];
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
	    for(int a = player_x; a < player_x + 7; a++)
            for(int b = player_y; b < player_y + 3; b++)
                if(enemy_y == b && enemy_x == a) 
                    overlap = true;

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

	    //display powerup
	    for(int j = 0; j < max_number_of_powerups; j++) {

	        //if powerup overlaps with enemy
	        if((powerups[j][0] == -1) || (powerups[j][0] == enemy_y && powerups[j][1] >= enemy_x && powerups[j][1] <= enemy_x + 3)) {
	            powerups[j][0] = -1;
	        }

            //if powerup overlaps with player
            if((powerups[j][0] == player_y) && (powerups[j][1] >= player_x) && (powerups[j][1] <= player_x + 7))    {
                powerups[j][0] = -1;
                switch(powerups[j][2])  {
                    case 0: //extra life powerup
                            player_health++;
                            break;
                    case 1: //BFB powerup
                            for (int k = 0; k < max_number_of_enemies; k++) {
                                enemies[k][0] = -1;
                            }
                            player_countdown = 150;
                            bfb_used = true;
                            break;
                    case 2: // fast movement powerup
                            player_countdown = 1500;
                            player_speed += 2;
                            break;
                }
            }

	        //to make sure powerup y,x are within WINDOW * win. Stops powerup from "sticking" to enemies
	        else if(powerups[j][0] >= 0 && powerups[j][1] >= 0 && powerups[j][0] <= win_y - 1 && powerups[j][1] <= win_x - 1) {
	            wmove(win, powerups[j][0], powerups[j][1]);
	            waddch(win, powerup_appearance[powerups[0][2]]);
	        }
	    }
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
        if(projectiles[i][0] == -1) continue;
	    projectiles[i][0] = (projectiles[i][0] == 0) ? -1 : projectiles[i][0] - 1;
    }

    //only update enemies every 15 ticks
    if(tick % 15 == 0) {
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
    }

    //if enemy gets hit by player projectile
    for(int i = 0; i < max_number_of_enemies; i++) {
        for(int j = 0; j < max_projectiles; j++) {
            if((enemies[i][1] == projectiles[j][1] || enemies[i][1] + 1 == projectiles[j][1] || enemies[i][1] + 2 == projectiles[j][1]) && enemies[i][0] >= projectiles[j][0]) {
		    enemies[i][2]--;
		    projectiles[j][0] = -1;
		    projectiles[j][1] = -1;
	        }
	    }
    }
    //powerups
    if(tick % 15 == 0)  {
        for(int i = 0; i < max_number_of_powerups; i++) {
	        if(powerups[i][0] == -1)
	            continue;
            powerups[i][0] = (powerups[i][0] == win_y - 1) ? -1 : powerups[i][0] + 1;
        }
    }

    if(player_countdown <= 0 && player_speed > 2)    {
        player_countdown = 0;
        player_speed = 2;
    }

    else if (player_countdown <= 0 && bfb_used == true) {
        player_countdown = 0;
        bfb_used = false;
    }

    if (player_countdown > 0)   {
        player_countdown--;
    }
}

bool game::isOver() {
    if(player_health <= 0) 
        return true;
    return false;
}

int game::getLevel()    {
    return level;
}

int game::getDimensions(int i) {
    int a[4];
    a[0] = win_y;
    a[1] = win_x;
    a[2] = hud_y;
    a[3] = hud_x;
    return a[i];
}

int game::getPlayer(int i) {
    int a[5];
    a[0] = player_x;
    a[1] = player_y;
    a[2] = player_health;
    a[3] = player_speed;
    a[4] = player_countdown;
    return a[i];
}

bool game::getFlag()    {
    return bfb_used;
}

int game::getPlayerX()  {
    return player_x;
}

int game::getPlayerY()  {
    return player_y;
}

int game::getPlayerSpeed()  {
    return player_speed;
}

int game::getPlayerHealth() {
    return player_health;
}

void game::setPos(int x, int y)   {
    player_x = x;
    player_y = y;
}

game& game::operator=(game &g)  {

    level = g.getLevel();
    win_y = g.getDimensions(0);
    win_x = g.getDimensions(1);
    hud_y = g.getDimensions(2);
    hud_x = g.getDimensions(3);
    player_x = g.getPlayer(0);
    player_y = g.getPlayer(1);
    player_health = g.getPlayer(2);
    player_speed = g.getPlayer(3);
    player_countdown = g.getPlayer(4);
    bfb_used = g.getFlag();
    return *this;
}

char game::playerMove(char move) {
    switch(move) {
	    //left
        case 'a':
            //Left world boundary is 0+1, as a border may be drawn
            player_x = (player_x == 0) ? player_x : player_x - player_speed;
	    break;

	    //right
	    case 'd':
	        //Right world boundary is 80-1-3, accounting for player model dimensions
	        player_x = (player_x == win_x - 1 - 3) ? player_x : player_x + player_speed;
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

        //pause
        case 'p':
        break;
    }
    return move;
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

void game::generate_enemies(int no_of_enemies) {
    srand(time(NULL));
    for(int i = 0; i < no_of_enemies; i++) {
        enemy E;
	    E.y = 1;
	    E.x = rand() % (win_x-3);
	    E.health = 0;
	    E.projectile_y = -1;
	    E.projectile_x = -1;
        
        all_enemies.push(E);	
    }
}

void game::add_enemies() {
    int i = 0;
    while(!all_enemies.empty() && i < max_number_of_enemies) {
        enemies[i][0] = all_enemies.front().y;
	    enemies[i][1] = all_enemies.front().x;
	    enemies[i][2] = all_enemies.front().health;
	    enemies[i][3] = all_enemies.front().projectile_y;
	    enemies[i][4] = all_enemies.front().projectile_x;

	    all_enemies.pop();
	    i++;
    }
}

bool game::powerups_empty() {
    bool empty = true;
    for(int i = 0; i < max_number_of_powerups; i++) {
        if(powerups[i][0] != -1)
	        empty = false;
    }
    return empty;
}

void game::generate_powerups(int no_of_powerups) {
    srand(time(NULL) + no_of_powerups + 10000);
    for(int i = 0; i < no_of_powerups; i++) {
        powerup P;
	    P.y = rand() % (3);
	    P.x = rand() % (win_x - 3);
	    P.type = rand() % (3);
	    all_powerups.push(P);
    }
}

void game::add_powerups() {
    int i = 0;
    while(!all_powerups.empty() && i < max_number_of_powerups) {
        powerups[i][0] = all_powerups.front().y;
	    powerups[i][1] = all_powerups.front().x;
	    powerups[i][2] = all_powerups.front().type;
	    i++;
    }
    all_powerups.pop();
}

int game::get_player_countdown()    {
    return player_countdown;
}

bool game::get_bfb_used()   {
    return bfb_used;
}

void game::reduce_player_countdown()    {
    player_countdown--;
}
