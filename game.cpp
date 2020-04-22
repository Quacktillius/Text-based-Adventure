#include<ncurses.h>
#include<string>
#include"menu.h"

void drawMap(WINDOW * win, int px, int py){
	wmove(win, py, px);
	waddstr(win, "###");
	wmove(win, py+1, px+2);
	waddstr(win, "##>");
	wmove(win, py+2, px);
	waddstr(win, "###");
}

int main() {
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	WINDOW * win = newwin(48, 80, 0, 0);
	int player_x=0, player_y=0;
	/*int enemies[5][2];
	char inp;
	while(1){
		drawMap(&win, player_x, player_y, enemies);
		if((ch = getch()) != ERR){
			playermove(ch);
		}
		for (int i=0; i<5; i++) enemies[i][1]--;
	}*/
	drawMap(win, player_x, player_y);
	wrefresh(win);
	sleep(5);
	endwin();
	return 0;
}
