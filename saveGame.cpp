#include "saveGame.h"

SaveFile::SaveFile()    {

    store_win obj;
    WINDOW * mm = obj.getwindow();
    int menu_y = obj.gety(), menu_x = obj.getx();
    wmove(mm, menu_y / 2 + 8, menu_x / 2 - 9);
    waddstr(mm, "Enter a save name: ");
    wmove(mm, menu_y / 2 + 9, menu_x / 2 - 9);
    
    nocbreak();
    echo();

    char inp = wgetch(mm);
    while (inp != '\n') {
        saveName.push_back(inp);
	inp = wgetch(mm);
    }

    cbreak();

    int win_x, win_y;
    getmaxyx(stdscr, win_y, win_x);
    win_y -= 6;
    Game.setPos(win_x / 2, (win_y / 6) * 5);
}

SaveFile::SaveFile(std::string save_name)   {
    saveName = save_name;
}

std::string SaveFile::getSaveName() {
    return saveName;
}

void SaveFile::displaySave()  {
    
    store_win obj;
    WINDOW * mm = obj.getwindow();
    int menu_y = obj.gety();
    int menu_x = obj.getx();

    
    std::string temp1 = "Save Name : " + saveName;
    int len_temp1 = temp1.length();
    wmove(mm, menu_y / 2 - 2, menu_x / 2 - len_temp1 / 2);
    waddstr(mm, temp1.c_str());

    temp1 = "Save Level : " + std::to_string(Game.getLevel());
    len_temp1 = temp1.length();
    wmove(mm, menu_y / 2 - 0, menu_x / 2 - len_temp1 / 2);
    waddstr(mm, temp1.c_str());

    wrefresh(mm);
    sleep(1);
}

void SaveFile::saveProgress(game save_game)   {
    Game = save_game;
    writeSave(*this);
}

game SaveFile::pushGame()   {
    return Game;
}

void SaveFile::setGame(WINDOW * win, WINDOW * hud, int lvl, int px, int py, int ps, int pscore, int ph, int pe[5][5], int pu[1][3])    {
    game temp(win, hud, lvl, px, py, ps, pscore, ph, pe, pu);
    Game = temp;
}

void SaveFile::saveLeaderboard()    {
    std::ifstream ifile("Leaderboard.txt", std::ios::in);
    std::ofstream ofile("Leaderboard1.txt", std::ios::out);
    int score = 0, prevscore = -1;
    int i = 0;
    bool added = false;
    while (ifile >> score)    {
        prevscore = score;
        if (score > Game.getPlayerScore())  {
            ofile << score << " ";
            i++;
            continue;
        }
        else if (score < Game.getPlayerScore() && !added) {
            added = true;
            ofile << Game.getPlayerScore() << " ";
            ofile << score << " ";
            i++;
        }
        else if (score < Game.getPlayerScore() && added)    {
            ofile << score << " ";
            i++;
        }
    }
    remove("Leaderboard.txt");
    rename("Leaderboard1.txt", "Leaderboard.txt");
    ofile.close();
    ifile.close();
}

SaveFile * LoadGame(std::string save_name)   {
   
    store_win obj;
    WINDOW * mm = obj.getwindow();
    int menu_y = obj.gety();
    int menu_x = obj.getx();

    std::ifstream ifile("Savegame.dat", std::ios::binary | std::ios::in);
    ifile.seekg(0, std::ios::beg);
    if (ifile.fail())   {
        ifile.close();

        werase(mm);
	wmove(mm, menu_y / 2, menu_x / 2 - 9);
	waddstr(mm, "Error loading game!");
        wrefresh(mm);
	sleep(1);

        return NULL;
    }
    //search the save file collection for the particular save we want
    SaveFile * load_save = new SaveFile("");
    while (ifile.read((char *) load_save, sizeof(*load_save)))    {
        if (load_save -> getSaveName() == save_name)    {
            //matching save file found
            ifile.close();
            return load_save;
        }
    }
    //if no match found, return NULL 
    werase(mm);
    wmove(mm, menu_y / 2, menu_x / 2 - 8);
    waddstr(mm, "Save game not found");
    wrefresh(mm);
    sleep(1);

    ifile.close();
    return NULL;
}

SaveFile * GetSave()   {
    
    store_win obj;
    WINDOW * mm = obj.getwindow();
    int menu_y = obj.gety();
    int menu_x = obj.getx();

    werase(mm);
    
    std::ifstream ifile("Savegame.dat", std::ios::binary | std::ios::in);
    ifile.seekg(0, std::ios::beg);
    if (ifile.fail())   {
        wmove(mm, menu_y / 2 - 3, menu_x / 2 - 10);
	    waddstr(mm, "Error loading game!");
        wrefresh(mm);
	    sleep(1);
        ifile.close();
        return NULL;
    }
    SaveFile load_save;
    char select;
    while (ifile.read((char *) &load_save, sizeof(load_save)))   {
        load_save.displaySave();

	    wmove(mm, menu_y / 2 + 2, menu_x / 2 - 10);
	    waddstr(mm, "Select this save? ");
        wrefresh(mm);
	    select = wgetch(mm);
        
        if (select == 'y' || select == 'Y') {
            ifile.close();
            return LoadGame(load_save.getSaveName());
        }
    }
    wmove(mm, menu_y / 2, menu_x / 2 - 14);
    waddstr(mm, "Starting new game by default");
    wrefresh(mm);
    sleep(1);
    ifile.close();
    return NULL;
}

void writeSave(SaveFile save)   {
    std::ofstream ofile("Savegame.dat", std::ios::binary | std::ios::app);
    if (ofile.fail())   {
        std::cout << "Error writing save!" << std::endl;
        ofile.close();
        return;
    }
    ofile.write((char *) &save, sizeof(save));
    ofile.close();
}
void SaveFile::checksave() {
    std::ifstream ifile("Savegame.dat", std::ios::binary | std::ios::in);
    if (ifile.fail())   {
        ifile.close();
        return;
    }
    SaveFile * temp = new SaveFile("");
    while(ifile.read((char *) temp, sizeof(*temp))) {
        if (temp -> getName() == saveName)  {
            removeSave(temp);            
            break;
        }
    }
    ifile.close();
    delete temp;
}

void removeSave(SaveFile * save)  {
    std::ofstream ofile("Savegame1.dat", std::ios::binary | std::ios::out | std::ios::beg);
    std::ifstream ifile("Savegame.dat", std::ios::binary | std::ios::in | std::ios::beg);
    SaveFile * temp = new SaveFile("");
    while (ifile.read((char * ) temp, sizeof(*temp)))   {
        if (temp -> getName() == save -> getName())  {
            continue;
        }
        ofile.write((char * )temp, sizeof(*temp));
    }
    remove("Savegame.dat");
    rename("Savegame1.dat", "Savegame.dat");
    ifile.close();
    ofile.close();
    delete temp;
}

std::string SaveFile::getName() {
    return saveName;
}

void displayLeaderBoard(WINDOW * mm, int menu_y, int menu_x)   {
    werase(mm);
    std::ifstream ifile("Leaderboard.txt", std::ios::in);
    int score = 0;
    int i = 1;
    wmove(mm, menu_y / 2 - 8, menu_x / 2 - 7);
    waddstr(mm, "LEADERBOARD");
    while (ifile >> score && i <= 10)  {
        wmove(mm, menu_y / 2 - 8 + i, menu_x / 2 - 7);
        std::string output = "Rank #" + std::to_string(i) + "    " + std::to_string(score); 
        waddstr(mm, output.c_str());
        i++;
    }
    wrefresh(mm);
    wgetch(mm);
    werase(mm);
    ifile.close();
}