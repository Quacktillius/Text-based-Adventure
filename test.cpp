#include "newGame.h"
#include <ncurses.h>
#include <unistd.h>

int main() {
	// initialise ncurses stuff
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	WINDOW * win = newwin(48, 80, 0, 0);
	//parameters for the game
	int count = 100;
	char c;
	int px = 35, py = 35;
	int pe[5][2] = { {1, 5}, {1, 20}, {1, 35}, {1, 40}, {1, 70}};
	game game1(px,py,pe);
	
	while(count-- >= 0)	{
		if((c = getch()) != ERR)
			game1.playerMove(c);
		game1.display(win);
		wrefresh(win);
		sleep(1);
		werase(win);
		game1.update();
		if(game1.isOver())	{
			break;
		}
	}

	// wrapping up ncurses output
	wrefresh(win);
	waddstr(win, "You Lost! Game over...");
	sleep(2);
	delwin(win);
	endwin();
	
	return 0;
}
