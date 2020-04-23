#include "newGame.h"

void game::display(WINDOW * win) {
    wmove(win, player_y, player_x);
    waddstr(win, "###");
    wmove(win player_y+1, player_x+2);
    waddstr(win,"####>");
    wmove(win, player_y+2, player_x);
    waddstr(win, "###");

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
