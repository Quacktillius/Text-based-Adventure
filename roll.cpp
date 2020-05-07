#include "roll.h"

void rollTheIntro(WINDOW * up, int up_y, int up_x, WINDOW * mid, int mid_y, int mid_x, WINDOW * low, int low_y, int low_x) {
    wmove(up, up_y / 2 - 0, up_x / 2 - 11);
    waddch(up, '_');
    std::this_thread::sleep_for(std::chrono::milliseconds());
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 12);
    waddch(up '(');
    std::this_thread::sleep_for(std::chrono::milliseconds());
    
    for(int i = 0; i < 8; i++) {
    wmove(up, up_y / 2 + 1, up_x / 2 - 11 + i);
    waddch(up, '_');
    std::this_thread::sleep_for(std::chrono::milliseconds());
    }
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 2);
    waddch(up, '/');
    std::this_thread::sleep_for(std::chrono::milliseconds());
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 1);
    waddch(up, '\');
    std::this_thread::sleep_for(std::chrono::milliseconds());
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 0);
    waddch(up, '/');
    std::this_thread::sleep_for(std::chrono::milliseconds());
    
    wmove(up, up_y / 2 - 0, up_x / 2 + 1);
    waddch(up, '/');
    std::this_thread::sleep_for(std::chrono::milliseconds());
    
    wmove(up, up_y / 2 - 1, up_x / 2 + 1);
    waddch(up, '\');
    std::this_thread::sleep_for(std::chrono::milliseconds());
    
    wmove(up, up_y / 2 - 1, up_x / 2 - 0);
    waddch(up, '/');
    std::this_thread::sleep_for(std::chrono::milliseconds());
    
    wmove(up, up_y / 2 - 0, up_x / 2 - 0);
    waddch(up, '\');
    std::this_thread::sleep_for(std::chrono::milliseconds());
    
    wmove(up, up_y / 2 + 1, up_x / 2 + 1);
    waddch(up, '\');
    std::this_thread::sleep_for(std::chrono::milliseconds());
    
    wmove(up, up_y / 2 + 1, up_x / 2 + 2);
    waddch(up, '/');
    std::this_thread::sleep_for(std::chrono::milliseconds());
    
    wmove(up, up_y / 2 + 1, up_x / 2 + 3);
    waddch(up, '\');
    std::this_thread::sleep_for(std::chrono::milliseconds());
    
    for(int i = 0; i < 8; i++) {
        wmove(up, up_y / 2 + 1, up_x / 2 + 4 + i);
        waddch(up, '_');
        std::this_thread::sleep_for(std::chrono::milliseconds());
    }
    wmove(up, up_y / 2 + 1, up_x / 2 + 11);
    waddch(up, ')');
    std::this_thread::sleep_for(std::chrono::milliseconds());
    
    wmove(up, up_y / 2 - 0, up_x / 2 + 10);
    waddch(up, '_');
    std::this_thread::sleep_for(std::chrono::milliseconds());
}
