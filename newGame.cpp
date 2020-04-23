#include "newGame.h"

void game::display(WINDOW * win) {
    wmove(win, player_y, player_x);
    waddstr(win, " ^ ");
    wmove(win player_y+1, player_x);
    waddstr(win, "/#\\");
    wmove(win, player_y+2, player_x);
    waddstr(win, "H#H");

    for(int i=0; i<max_number_of_enemies; i++) {
        if(enemies[i][1]==-1) continue;
        int enemy_y=enemies[i][0], enemy_x=enemies[i][1];
	bool overlap=false;
	for(int a=player_x; a<player_x+7; a++)
            for(int b=player_y; b<player_y+3; b++)
                if(enemy_y==b || enemy_x==a) 
                    overlap=true;
        if(overlap) continue;
	wmove(win, enemy_y, enemy_x);
	waddstr(win, "X");
    } 
}

void game::playerMove(char move) {
    switch(move) {
        case 'a':
            player_x = (player_x == 1) ? player_x : player_x-1; //Left world boundary is 0+1, as a border may be drawn
	    break;
	case 'd':
	    player_x = (player_x == 76) ? player_x : player_x+1; //Right world boundary is 80-1-3, accounting for playermodel dimensions
	    break;
    }
}
