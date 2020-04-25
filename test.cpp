#include"newGame.h"
#include<ncurses.h>
#include<unistd.h>
#include<chrono>
#include<thread>
int main() {
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	WINDOW * win = newwin(48, 80, 0, 0);
	int count=0;
	char c;
	int px=35, py=35;
	int pe[5][3]={{1,5,0},{1,20,0},{1,35,0},{1,40,0},{1,70,0}};
	game game1(px,py,pe);
	while(count++ <= 100){
		if((c=getch()) != ERR)
			game1.playerMove(c);
		game1.display(win);
		wrefresh(win);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		werase(win);
		game1.update(count);
		if(game1.isOver()) break;

	}
	wrefresh(win);
	wmove(win, 0, 0);
	waddstr(win, "You Lost! Game over...");
	wrefresh(win);
	sleep(2);
	delwin(win);
	endwin();
	return 0;
}
