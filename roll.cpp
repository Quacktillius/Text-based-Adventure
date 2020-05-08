#include "roll.h"

void rollTheIntro(WINDOW * up, int up_y, int up_x, WINDOW * mid, int mid_y, int mid_x, WINDOW * low, int low_y, int low_x, std::string message) {
    
    int pause = 20, message_pause = 5;
    int message_len = message.length();
    
    wmove(mid, mid_y / 2, mid_x / 2 - message_len / 2);
    
    wmove(up, up_y / 2 - 0, up_x / 2 - 11);
    waddch(up, '_');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
        wmove(low, low_y / 2 - 1, low_x / 2 + 10);
        waddch(low, '_');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            for(int i = 0; i < 4; i++) {
                if(i >= message_len)
                    break;
                waddch(mid, message[i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 12);
    waddch(up, '(');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
        wmove(low, low_y / 2 - 1, low_x / 2 + 11);
        waddch(low, ')');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            for(int i = 0; i < 4; i++) {
                if(4 + i >= message_len)
                    break;
                waddch(mid, message[4 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    
    for(int i = 0; i < 8; i++) {
    wmove(up, up_y / 2 + 1, up_x / 2 - 11 + i);
    waddch(up, '_');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
        
        wmove(low, low_y / 2 - 2, low_x / 2 + 10 - i);
        waddch(low, '_');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
        
            for(int i = 0; i < 4; i++) {
                if(8 + i >= message_len)
                    break;
                waddch(mid, message[8 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    }
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 3);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
        wmove(low, low_y / 2 - 1, low_x / 2 + 2);
        waddch(low, '/');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            for(int i = 0; i < 4; i++) {
                if(12 + i >= message_len)
                    break;
                waddch(mid, message[12 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 2);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
           
        wmove(low, low_y / 2 - 1, low_x / 2 + 1);
        waddch(low, '\\');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            for(int i = 0; i < 4; i++) {
                if(16 + i >= message_len)
                    break;
                waddch(mid, message[16 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 1);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
               
        wmove(low, low_y / 2 - 1, low_x / 2 - 0);
        waddch(low, '/');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            for(int i = 0; i < 4; i++) {
                if(20 + i >= message_len)
                    break;
                waddch(mid, message[20 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    
    wmove(up, up_y / 2 - 0, up_x / 2 - 0);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
         
        wmove(low, low_y / 2 - 0, low_x / 2 - 1);
        waddch(low, '/');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            for(int i = 0; i < 4; i++) {
                if(24 + i >= message_len)
                    break;
                waddch(mid, message[24 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    
    wmove(up, up_y / 2 - 1, up_x / 2 - 0);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
         
        wmove(low, low_y / 2 + 1, low_x / 2 - 1);
        waddch(low, '\\');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            for(int i = 0; i < 4; i++) {
                if(28 + i >= message_len)
                    break;
                waddch(mid, message[28 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    
    wmove(up, up_y / 2 - 1, up_x / 2 - 1);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
               
        wmove(low, low_y / 2 + 1, low_x / 2 - 0);
        waddch(low, '/');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            for(int i = 0; i < 4; i++) {
                if(32 + i >= message_len)
                    break;
                waddch(mid, message[32 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    
    wmove(up, up_y / 2 - 0, up_x / 2 - 1);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
           
        wmove(low, low_y / 2 - 0, low_x / 2 - 0);
        waddch(low, '\\');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            for(int i = 0; i < 4; i++) {
                if(36 + i >= message_len)
                    break;
                waddch(mid, message[36 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    
    wmove(up, up_y / 2 + 1, up_x / 2 - 0);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
         
        wmove(low, low_y / 2 - 1, low_x / 2 - 1);
        waddch(low, '\\');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            for(int i = 0; i < 4; i++) {
                if(40 + i >= message_len)
                    break;
                waddch(mid, message[40 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    
    wmove(up, up_y / 2 + 1, up_x / 2 + 1);
    waddch(up, '/');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
               
        wmove(low, low_y / 2 - 1, low_x / 2 - 2);
        waddch(low, '/');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            for(int i = 0; i < 4; i++) {
                if(44 + i >= message_len)
                    break;
                waddch(mid, message[44 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    
    wmove(up, up_y / 2 + 1, up_x / 2 + 2);
    waddch(up, '\\');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
           
        wmove(low, low_y / 2 - 1, low_x / 2 - 3);
        waddch(low, '\\');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            for(int i = 0; i < 4; i++) {
                if(48 + i >= message_len)
                    break;
                waddch(mid, message[48 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    
    for(int i = 0; i < 8; i++) {
        wmove(up, up_y / 2 + 1, up_x / 2 + 3 + i);
        waddch(up, '_');
        wrefresh(up);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
        
            wmove(low, low_y / 2 - 2, low_x / 2 - 4 - i);
            waddch(low, '_');
            wrefresh(low);
            std::this_thread::sleep_for(std::chrono::milliseconds(pause));
        
                for(int i = 0; i < 4; i++) {
                if(42 + i >= message_len)
                    break;
                waddch(mid, message[42 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    }
    wmove(up, up_y / 2 + 1, up_x / 2 + 10);
    waddch(up, ')');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
               
        wmove(low, low_y / 2 - 1, low_x / 2 - 12);
        waddch(low, '(');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            for(int i = 0; i < 4; i++) {
                if(46 + i >= message_len)
                    break;
                waddch(mid, message[46 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
    
    wmove(up, up_y / 2 - 0, up_x / 2 + 9);
    waddch(up, '_');
    wrefresh(up);
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
          
        wmove(low, low_y / 2 - 1, low_x / 2 - 11);
        waddch(low, '_');
        wrefresh(low);
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
    
            for(int i = 0; i < 4; i++) {
                if(50 + i >= message_len)
                    break;
                waddch(mid, message[50 + i]);
                wrefresh(mid);
                std::this_thread::sleep_for(std::chrono::milliseconds(message_pause));
            }
}
