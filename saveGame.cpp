#include "saveGame.h"

SaveFile::SaveFile(WINDOW * mm, int win_y1, int win_x1)    {

    wmove(mm, win_y1 / 2 + 8, win_x1 / 2 - 9);
    waddstr(mm, "Enter a save name:");
    wmove(mm, win_y1 / 2 + 9, win_x1 / 2 - 9);
    
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
    std::cout << std::endl;
    std::cout << "Save Name : " << saveName << std::endl;
    std::cout << "Save Level : " << Game.getLevel() << std::endl;
}

void SaveFile::saveProgress(game save_game)   {
    Game = save_game;
    writeSave(*this);
}

game SaveFile::pushGame()   {
    return Game;
}

void SaveFile::setGame(WINDOW * win, WINDOW * hud, int lvl, int px, int py, int ps, int ph, int pe[5][5], int pu[1][3])    {
    game temp(win, hud, lvl, px, py, ps, ph, pe, pu);
    Game = temp;
}

SaveFile * LoadGame(std::string save_name)   {
    std::ifstream ifile("Savegame.dat", std::ios::binary | std::ios::in);
    ifile.seekg(0, std::ios::beg);
    if (ifile.fail())   {
        ifile.close();
        std::cout << "Error loading game!" << std::endl;
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
    std::cout << "Save game not found" << std::endl;
    ifile.close();
    return NULL;
}

SaveFile * GetSave()   {
    system("clear");
    std::ifstream ifile("Savegame.dat", std::ios::binary | std::ios::in);
    ifile.seekg(0, std::ios::beg);
    if (ifile.fail())   {
        std::cout << "Error loading game!" << std::endl;
        ifile.close();
        return NULL;
    }
    SaveFile load_save;
    char select;
    while (ifile.read((char *) &load_save, sizeof(load_save)))   {
        load_save.displaySave();
        std::cout << "Select this save?" << std::endl;
        std::cin >> select;
        if (select == 'y' || select == 'Y') {
            ifile.close();
            return LoadGame(load_save.getSaveName());
        }
    }
    std::cout << "Starting new game by default" << std::endl;
    ifile.close();
    return NULL;
}

void writeSave(SaveFile save)   {
    std::ofstream ofile("Savegame.dat", std::ios::binary | std::ios::app);
    if (ofile.fail())   {
        std::cout << "Error writing save!" << std::endl;
        return;
    }
    ofile.write((char *) &save, sizeof(save));
    ofile.close();
}
