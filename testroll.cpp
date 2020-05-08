#include <ncurses.h>
#include "roll.h"
#include <unistd.h>

int main() {
	initscr();
	int y, x;
	getmaxyx(stdscr, y, x);

	WINDOW * up = newwin(y / 2, x, 0, 0);
	WINDOW * mid = NULL;
	WINDOW * low = newwin(y / 2 - 1 , x, y/2, 0);

	rollTheIntro(up, y/2, x, mid, 0,0, low, y/2-1, x);
	
	wrefresh(up);
	wrefresh(low);
	sleep(5);

	delwin(up);
	delwin(low);

	endwin();

	return 0;
}
