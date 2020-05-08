#ifndef _SAVEGAME_H
#define _SAVEGAME_H

#include "newGame.h"
#include "windowDetails.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ncurses.h>

class SaveFile  {
    game Game;
    std::string saveName;
public:
    std::string getSaveName();
    void displaySave();
    void saveProgress(game save_game);
    game pushGame();
    void setGame(WINDOW * win, WINDOW * hud,int,int,int,int,int,int,int[5][5],int[1][3]);
    void checksave();
    std::string getName();
    SaveFile();
    SaveFile(std::string);
};

SaveFile * LoadGame(std::string save_name);
SaveFile * GetSave();
void writeSave(SaveFile save);
void removeSave(SaveFile * save);
void displayLeaderBoard(WINDOW * mm, int menu_y, int menu_x);
void saveLeaderboard(int score);

#endif
