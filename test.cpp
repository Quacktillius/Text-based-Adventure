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

	while(true){

		if (count % 1000 == 0)	{
			game1.levelup();
		}

		std::cerr << "Got levelup " << count << "\n";

		if((c=getch()) != ERR) 
            c = game1.playerMove(c);

		std::cerr << "Got input " << count << "\n";

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

		std::cerr << "Done input " << count << "\n";

		if(game1.enemies_empty() && game1.get_bfb_used() == false && game1.get_player_countdown() <= 0)	{
			std::cerr << "Checked all conditions " << count << "\n";
			game1.add_enemies();
			std::cerr << "Added enemies to buffer " << count << "\n";
			game1.generate_enemies(100);
			std::cerr << "Generated new enemies " << count << "\n";
		}

		std::cerr << "spawned enemies " << count << "\n";

		if(game1.powerups_empty())	{
			game1.add_powerups();
			game1.generate_powerups(40);
		}

		std::cerr << "Done setup " << count << "\n";

		game1.display(win, hud);
		wrefresh(win);
		wrefresh(hud);

		std::this_thread::sleep_for(std::chrono::milliseconds(30));

		werase(win);
		werase(hud);

		std::cerr << "Done display " << count << "\n";

		game1.update(count);
		std::cerr << "Done update " << count << "\n";
		if(game1.isOver())	{
			std::cerr << "Game over " << count << "\n";
			save -> checksave();
			saveLeaderboard(game1.getPlayerScore());
			break;
		}
		std::cerr << "Checked gameover " << count << "\n";
 		count = (count + 1) % 10000;
	

	}

	std::cerr << "Exited game loop " << count << "\n";
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
