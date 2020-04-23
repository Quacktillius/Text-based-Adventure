#include "newGame.h"

game::game() {
    player_x=0;
    player_y=0;
    for(int i=0; i<max_projectiles; i++) {
        projectiles[i][0]=-1;
	projectiles[i][1]=-1;
    }
    for(int i=0; i<max_number_of_enemies; i++) {
        enemies[i][0]=-1;
	enemies[i][1]=-1;
    }
}

game::game(int px, int py, int pe[5][2]) {
    player_x=px;
    player_y=py;
    for(int i=0; i<max_projectiles; i++) {
        projectiles[i][0]=-1;
	projectiles[i][1]=-1;
    }
    for(int i=0; i<max_number_of_enemies; i++) {
        enemies[i][0]=pe[i][0];
	enemies[i][1]=pe[i][1];
    }
}

void game::display(WINDOW * win) {
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
        if(enemies[i][0]==-1) continue;
        int enemy_y=enemies[i][0], enemy_x=enemies[i][1];
	bool overlap=false;
	for(int a=player_x; a<player_x+7; a++)
            for(int b=player_y; b<player_y+3; b++)
                if(enemy_y==b && enemy_x==a) 
                    overlap=true;
	for(int a=0; a<max_projectiles; a++) {
            if(enemy_y==projectiles[i][0] && enemy_x==projectiles[i][1])
                overlap=true;
	}
        if(overlap) continue;
	wmove(win, enemy_y, enemy_x);
	waddstr(win, "X");
    } 
}

void game::update() {
    for(int i=0; i<max_projectiles; i++) {
        if(projectiles[i][0]==-1) continue;
	projectiles[i][0] = (projectiles[i][0] == 0) ? -1 : projectiles[i][0]-1;
    }
    for(int i=0; i<max_number_of_enemies; i++) {
        if(enemies[i][0]==-1) continue;
	enemies[i][0] = (enemies[i][0] == 47) ? enemies[i][0] : enemies[i][0]+1;
    }
    for(int i=0; i<max_number_of_enemies; i++) {
        for(int j=0; j< max_projectiles; j++) {
            if(enemies[i][1] == projectiles[j][1] && enemies[i][0] >= projectiles[j][0]) {
                enemies[i][0]=-1;
		enemies[i][1]=-1;
		projectiles[j][0]=-1;
		projectiles[j][1]=-1;
	    }
	}
    }
}

bool game::isOver() {
    for(int i=0; i<max_number_of_enemies; i++) {
        if(enemies[i][0]==47) return true;
    }
    return false;
}

void game::playerMove(char move) {
    switch(move) {
        case 'a':
            player_x = (player_x == 1) ? player_x : player_x-1; //Left world boundary is 0+1, as a border may be drawn
	    break;
	case 'd':
	    player_x = (player_x == 76) ? player_x : player_x+1; //Right world boundary is 80-1-3, accounting for playermodel dimensions
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
