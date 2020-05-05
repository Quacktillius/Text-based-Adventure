#include "windowDetails.h"

store_win::store_win(WINDOW * w, int w_y, int w_x) {
    win = w;
    win_y = w_y;
    win_x = w_x;
}

WINDOW * store_win::getwindow() {
    return win;
}

int store_win::gety() {
    return win_y;
}

int store_win::getx() {
    return win_x;
}
