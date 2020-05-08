#include <ncurses.h>
#include "roll.h"
#include <unistd.h>

int main() {
	initscr();
	int y, x;
	getmaxyx(stdscr, y, x);

	WINDOW * up = newwin(y / 3, x, 0, 0);
	WINDOW * mid = newwin(y / 3, x, y / 3, 0);
	WINDOW * low = newwin(y / 3 - 2 , x, 2 * y / 3, 0);
	
	std::string message = "I hope this works! Time to type some cool stuff. oh yeahhhh";

	rollTheIntro(up, y/2, x, mid, 0,0, low, y/2-1, x,);
	
	wrefresh(up);
	wrefresh(low);
	sleep(5);

	delwin(up);
	delwin(low);

	endwin();

	return 0;
}
