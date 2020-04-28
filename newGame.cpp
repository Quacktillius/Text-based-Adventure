#include "newGame.h"

game::game() {
    win_y=0;
    win_x=0;
    hud_y=0;
    hud_x=0;
    player_x=0;
    player_y=0;
    player_health=3;
    for(int i=0; i<max_projectiles; i++) {
        projectiles[i][0]=-1;
	projectiles[i][1]=-1;
    }
    for(int i=0; i<max_number_of_enemies; i++) {
        enemies[i][0]=-1;
	enemies[i][1]=-1;
    }
}

game::game(WINDOW * win, WINDOW * hud, int lvl, int px, int py, int ph, int pe[5][5]) {
    getmaxyx(win, win_y, win_x);
    getmaxyx(hud, hud_y, hud_x);
    level=lvl;
    player_x=px;
    player_y=py;
    player_health=ph;
    for(int i=0; i<max_projectiles; i++) {
        projectiles[i][0]=-1;
	projectiles[i][1]=-1;
    }
    for(int i=0; i<max_number_of_enemies; i++) {
        enemies[i][0]=pe[i][0];
	enemies[i][1]=pe[i][1];
	enemies[i][2]=pe[i][2];
	enemies[i][3]=pe[i][3];
	enemies[i][4]=pe[i][4];
    }
}

void game::display(WINDOW * win, WINDOW * hud) {

    wmove(win, player_y, player_x);
    waddstr(win, " ^ ");
    wmove(win, player_y+1, player_x);
    waddstr(win, "/#\\");
    wmove(win, player_y+2, player_x);
    waddstr(win, "H#H");

    for(int i=0; i<max_projectiles; i++) {
        if(projectiles[i][0]==-1) continue;
	wmove(win, projectiles[i][0], projectiles[i][1]);
	waddch(win, '!');
    }

    for(int i=0; i<max_number_of_enemies; i++) {
        if(enemies[i][0]==-1 || enemies[i][2]==-1) continue;
        int enemy_y=enemies[i][0], enemy_x=enemies[i][1];
	bool overlap=false;
	for(int a=player_x; a<player_x+7; a++)
            for(int b=player_y; b<player_y+3; b++)
                if(enemy_y==b && enemy_x==a) 
                    overlap=true;
	for(int a=0; a<max_projectiles; a++) {
            if(enemy_y==projectiles[i][0] && (enemy_x==projectiles[i][1] || enemy_x+1==projectiles[i][1] || enemy_x+2==projectiles[i][1]))
                overlap=true;
	}
        if(overlap) {
	    continue;
	    enemies[i][2]==-1;
	}
	wmove(win, enemy_y, enemy_x);
	waddstr(win, "X-X");
    } 

    for(int i = 0; i < hud_x; i++) {
        waddch(hud, '_');
    }
    wmove(hud, hud_y/2, hud_x/5);
    std::string lvl = "Level: " + std::to_string(level);
    waddstr(hud, lvl.c_str());
    wmove(hud, hud_y/2, hud_x/5*3);
    for(int i = 0; i < player_health; i++) {
        waddstr(hud,"O ");
    }
}

void game::update(int tick) {
    for(int i=0; i<max_projectiles; i++) {
        if(projectiles[i][0]==-1) continue;
	projectiles[i][0] = (projectiles[i][0] == 0) ? -1 : projectiles[i][0]-1;
    }
    if(tick%5==0) {
        for(int i=0; i<max_number_of_enemies; i++) {
            if(enemies[i][0]==-1) continue;
	    enemies[i][0] = (enemies[i][0] == win_y - 1) ? enemies[i][0] : enemies[i][0]+1;
	    if(enemies[i][0] == win_y - 1) player_health--;
        }
    }
    for(int i=0; i<max_number_of_enemies; i++) {
        for(int j=0; j< max_projectiles; j++) {
            if((enemies[i][1] == projectiles[j][1] || enemies[i][1]+1==projectiles[j][1] || enemies[i][1]+2==projectiles[j][1]) && enemies[i][0] >= projectiles[j][0]) {
                enemies[i][0]=-1;
		enemies[i][1]=-1;
		projectiles[j][0]=-1;
		projectiles[j][1]=-1;
	    }
	}
    }
}

bool game::isOver() {
    if(player_health<=0) return true;
    return false;
}

void game::playerMove(char move) {
    switch(move) {
        case 'a':
            player_x = (player_x == 1) ? player_x : player_x-1; //Left world boundary is 0+1, as a border may be drawn
	    break;
	case 'd':
	    player_x = (player_x == win_x - 1 - 3) ? player_x : player_x+1; //Right world boundary is 80-1-3, accounting for playermodel dimensions
	    break;
	case 'w': //temporary case to test shooting capabilities
	    for(int i=0; i<max_projectiles; i++) {
                if(projectiles[i][0]!=-1)continue;
		projectiles[i][0]=player_y-1;
		projectiles[i][1]=player_x;
		break;
	    }
	    break;
    }
}
