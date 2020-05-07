#include "roll.h"

void rollTheIntro(WINDOW * up, int up_y, int up_x, WINDOW * mid, int mid_y, int mid_x, WINDOW * low, int low_y, int low_x) {
    
    int pause = 10;
    
    wmove(up, up_y / 2 - 0, up_x / 2 - 11);
    waddch(up, '_');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
        wmove(low, low_y / 2 - 1, low_x / 2 + 10);
        waddch(low, '_');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 12);
    waddch(up, '(');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
        wmove(low, low_y / 2 - 1, low_x / 2 + 11);
        waddch(low, ')');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    for(int i = 0; i < 8; i++) {
    wmove(up, up_y / 2 + 1, up_x / 2 - 11 + i);
    waddch(up, '_');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
        
        wmove(low, low_y / 2 - 2, low_x / 2 + 10 - i);
        waddch(low, '_');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    }
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 3);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
        wmove(low, low_y / 2 - 1, low_x / 2 + 2);
        waddch(low, '/');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 2);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
           
        wmove(low, low_y / 2 - 1, low_x / 2 + 1);
        waddch(low, '\\');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 1);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
               
        wmove(low, low_y / 2 - 1, low_x / 2 - 0);
        waddch(low, '/');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    wmove(up, up_y / 2 - 0, up_x / 2 - 0);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
         
        wmove(low, low_y / 2 - 0, low_x / 2 - 1);
        waddch(low, '/');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    wmove(up, up_y / 2 - 1, up_x / 2 - 0);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
         
        wmove(low, low_y / 2 + 1, low_x / 2 - 1);
        waddch(low, '\\');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    wmove(up, up_y / 2 - 1, up_x / 2 - 1);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
               
        wmove(low, low_y / 2 + 1, low_x / 2 - 0);
        waddch(low, '/');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    wmove(up, up_y / 2 - 0, up_x / 2 - 1);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
           
        wmove(low, low_y / 2 - 0, low_x / 2 - 0);
        waddch(low, '\\');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 0);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
         
        wmove(low, low_y / 2 - 1, low_x / 2 - 1);
        waddch(low, '\\');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    wmove(up, up_y / 2 + 1, up_x / 2 + 1);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
               
        wmove(low, low_y / 2 - 1, low_x / 2 - 2);
        waddch(low, '/');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    wmove(up, up_y / 2 + 1, up_x / 2 + 2);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
           
        wmove(low, low_y / 2 - 1, low_x / 2 - 3);
        waddch(low, '\\');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    for(int i = 0; i < 8; i++) {
        wmove(up, up_y / 2 + 1, up_x / 2 + 3 + i);
        waddch(up, '_');
        wrefresh(up);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
        
            wmove(low, low_y / 2 - 2, low_x / 2 - 4 - i);
            waddch(low, '_');
            wrefresh(low);
            std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    }
    wmove(up, up_y / 2 + 1, up_x / 2 + 10);
    waddch(up, ')');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
               
        wmove(low, low_y / 2 - 1, low_x / 2 - 12);
        waddch(low, '(');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
    wmove(up, up_y / 2 - 0, up_x / 2 + 9);
    waddch(up, '_');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
          
        wmove(low, low_y / 2 - 1, low_x / 2 - 11);
        waddch(low, '_');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
}
