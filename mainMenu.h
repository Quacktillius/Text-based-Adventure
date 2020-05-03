#ifndef MAIN_MENU
#define MAIN_MENU

#include <ncurses.h>
#include <cstdlib>
#include "saveGame.h"
#include <unistd.h>
#include <string>

SaveFile * main_menu(WINDOW * mm, int menu_y, int menu_x);

#endif