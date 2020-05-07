#include "test.h"

int main() {
	// initialise ncurses stuff
	initscr();
	cbreak();
	
	//Main Menu
	int win_y, win_x, hud_y=5, hud_x;
	getmaxyx(stdscr, win_y, win_x);
	WINDOW * mm = newwin(win_y, win_x, 0, 0);

	store_win obj;
	obj.setwindow(mm);
	obj.sety(win_y);
	obj.setx(win_x);

	//SaveFile
	SaveFile * save = main_menu(mm, win_y, win_x);
	if (save == NULL)	{
		delwin(mm);
		endwin();
		exit(0);
	}

	noecho();
	nodelay(stdscr, TRUE);

	win_y -= 6;
	hud_x = win_x;
	WINDOW * win = newwin(win_y, win_x, 0, 0);
	WINDOW * hud = newwin(hud_y, hud_x, win_y + 1, 0);

	int count = 0;
	char c;

	int px = win_x / 2, py = (win_y / 6) * 5;

	(save -> pushGame()).setPos(px, py);

	int pe[5][5]={{2,5,0,-1,-1},{1,20,0,-1,-1},{4,30,0, -1,-1},{3,11,0,-1,-1},{6,15,0,-1,-1}};
	
	int pu[1][3] = {{3,7,1}};

	game game1(win, hud, (save -> pushGame()).getLevel(), (save -> pushGame()).getPlayerX(), (save -> pushGame()).getPlayerY(), (save -> pushGame().getPlayerSpeed()), (save -> pushGame().getPlayerScore()), (save -> pushGame().getPlayerHealth()), pe, pu);

	game1.generate_enemies(10000);
	game1.generate_powerups(700);

	while(count <= 10000){

		if (count % 500 == 0)	{
			game1.levelup();
		}

		if((c=getch()) != ERR) 
            c = game1.playerMove(c);

		if (c == 'p')	{
			//save game and exit
			wrefresh(win);
			wrefresh(hud);
			werase(win);
			werase(hud);
			delwin(win);
			delwin(hud);
			endwin();
			save -> saveProgress(game1);
			system("clear");
			delete save;
			exit(0);
		}


		if(game1.enemies_empty() && game1.get_bfb_used() == false && game1.get_player_countdown() <= 0)	{
			game1.add_enemies();
			game1.generate_enemies(5);
		}

		if(game1.powerups_empty())	{
			game1.add_powerups();
			game1.generate_powerups(2);
		}

		game1.display(win, hud);
		wrefresh(win);
		wrefresh(hud);

		std::this_thread::sleep_for(std::chrono::milliseconds(30));

		werase(win);
		werase(hud);

		game1.update(count);
		if(game1.isOver())	{
			save -> checksave();
			break;
		}

		count = (count + 1) % 1000000007;
	

	}
	game1.display(win, hud);

	// wrapping up ncurses output
	wrefresh(win);
	wrefresh(hud);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	//displaying You Lose
	werase(win);
	werase(hud);
	wmove(win, (win_y / 2) + 3, (win_x / 2) - 20);
	waddstr(win, "You Lost! Game over...");

	wrefresh(win);
	sleep(2);

	delwin(win);
	delwin(hud);
	endwin();
	
	delete save; 

	return 0;
}
