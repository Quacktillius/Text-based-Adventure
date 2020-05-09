#include "test.h"
#include "roll.h"

int main() {
	// initialize ncurses stuff
	initscr();
	cbreak();
	
	//Intro
	int intro_y, intro_x;
	getmaxyx(stdscr, intro_y, intro_x);
	WINDOW * up= newwin(intro_y / 3 - 0, intro_x, 0, 0);
	WINDOW * mid= newwin(intro_y / 3 - 1, intro_x, intro_y / 3, 0);
	WINDOW * low= newwin(intro_y / 3 - 1, intro_x, 2 * intro_y / 3, 0);
	std::string intro_message = "Get ready for a totally mediocre gaming experience.";
	rollTheIntro(up, intro_y/3, intro_x, mid, intro_y/3 - 1, intro_x, low, intro_y/3 - 1, intro_x, intro_message);
	sleep(2);
	werase(up);
	werase(mid);
	werase(low);
	wrefresh(up);
	wrefresh(mid);
	wrefresh(low);
	intro_message = "A game we've all played before,\nBut worse in almost every sense.";
	rollTheIntro(up, intro_y/3, intro_x, mid, intro_y/3 - 1, intro_x, low, intro_y/3 - 1, intro_x, intro_message);
	sleep(2);
	werase(up);
	werase(mid);
	werase(low);
	wrefresh(up);
	wrefresh(mid);
	wrefresh(low);
	intro_message = "\"The best Project undertaken this semester\"\n                      -Random guy we bribed";
	rollTheIntro(up, intro_y/3, intro_x, mid, intro_y/3 - 1, intro_x, low, intro_y/3 - 1, intro_x, intro_message);
	sleep(2);
	werase(up);
	werase(mid);
	werase(low);
	wrefresh(up);
	wrefresh(mid);
	wrefresh(low);
	intro_message = "We are honoured to present...";
	rollTheIntro(up, intro_y/3, intro_x, mid, intro_y/3 - 1, intro_x, low, intro_y/3 - 1, intro_x, intro_message);
	sleep(1);
	werase(up);
	werase(mid);
	werase(low);
	wrefresh(up);
	wrefresh(mid);
	wrefresh(low);
	delwin(up);
	delwin(mid);
	delwin(low);
	
	
	//Main Menu
	int win_y, win_x, hud_y=5, hud_x;
	getmaxyx(stdscr, win_y, win_x);
	WINDOW * mm = newwin(win_y, win_x, 0, 0);

	store_win obj;
	obj.setwindow(mm);
	obj.sety(win_y);
	obj.setx(win_x);

	//SaveFile
	main_menu(mm, win_y, win_x);
	game * newgame = new game;
	std::cerr << "Created new game\n";
	noecho();
	nodelay(stdscr, TRUE);

	win_y -= 6;
	hud_x = win_x;
	WINDOW * win = newwin(win_y, win_x, 0, 0);
	WINDOW * hud = newwin(hud_y, hud_x, win_y + 1, 0);

	int count = 1;
	char c;

	int px = win_x / 2, py = (win_y / 6) * 5;

	newgame -> setPos(px, py);

	std::cerr << "Set position\n";

	int pe[5][5]={{2,5,0,-1,-1},{1,20,0,-1,-1},{4,30,0, -1,-1},{3,11,0,-1,-1},{6,15,0,-1,-1}};
	
	int pu[1][3] = {{3,7,1}};

	std::cerr << "Got coordinates\n";

	game * game1 = new game(win, hud, newgame -> getLevel(), newgame -> getPlayerX(), newgame -> getPlayerY(), newgame -> getPlayerSpeed(), newgame -> getPlayerScore(), newgame -> getPlayerHealth(), pe, pu);
	delete newgame;
	std::cerr << "Created second game\n";

	game1 -> generate_enemies(10000);
	game1 -> generate_powerups(3000);

	while(true){

		if (count % 1000 == 0)	{
			game1 -> levelup();
		}

		std::cerr << "Got levelup " << count << "\n";

		if((c=getch()) != ERR) 
            c = game1 -> playerMove(c);

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
			system("clear");
			//delete newgame;
			exit(0);
		}

		std::cerr << "Done input " << count << "\n";

		if(game1 -> enemies_empty() && game1 -> get_bfb_used() == false)	{
			std::cerr << "Checked all conditions " << count << "\n";
			game1 -> add_enemies();
			std::cerr << "Added enemies to buffer " << count << "\n";
			game1 -> generate_enemies(25);
			std::cerr << "Generated new enemies " << count << "\n";
		}

		std::cerr << "spawned enemies " << count << "\n";

		if(game1 -> powerups_empty())	{
			game1 -> add_powerups();
			game1 -> generate_powerups(1);
		}

		std::cerr << "Done setup " << count << "\n";

		game1 -> display(win, hud);
		wrefresh(win);
		wrefresh(hud);

		std::this_thread::sleep_for(std::chrono::milliseconds(30));

		werase(win);
		werase(hud);

		std::cerr << "Done display " << count << "\n";

		game1 -> update(count);
		std::cerr << "Done update " << count << "\n";
		if(game1 -> isOver())	{
			std::cerr << "Game over " << count << "\n";
			saveLeaderboard(game1 -> getPlayerScore());
			break;
		}
		std::cerr << "Checked gameover " << count << "\n";
 		count = (count + 1) % 10000;
	

	}

	std::cerr << "Exited game loop " << count << "\n";
	game1 -> display(win, hud);
	delete game1;

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
	
	//delete newgame; 

	return 0;
}
