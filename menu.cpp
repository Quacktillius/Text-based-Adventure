#include "menu.h"

using namespace std;

int menu() {

    int input = 0;

    //display "INITIALISING..." with typewriter effect
    typewriter obj;
    obj.setMessage("INITIALISING...\n");
    obj.setPause(120);
    obj.display();
    
    //display Game Title
    sleep(5);
    while (input < 1 || input > 3)  {
        system("clear");
        cout << "           ___      _        _     _   _____      _     _     \n";
        cout << "          / _ \\    | |      (_)   | | /  __ \\    (_)   (_)    \n";
        cout << "         / /_\\ \\___| |_ _ __ _  __| | | /  \\/_ __ _ ___ _ ___ \n";
        cout << "         |  _  / __| __| '__| |/ _` | | |   | '__| / __| / __|\n";
        cout << "         | | | \\__ \\ |_| |  | | (_| | | \\__/\\ |  | \\__ \\ \\__ \\\n";
        cout << "         \\_| |_/___/\\__|_|  |_|\\__,_|  \\____/_|  |_|___/_|___/\n";
        cout << endl << endl;
        cout << "        1* NEW GAME\n";
        cout << "        2* LOAD GAME\n";
        cout << "        3* EXIT\n";
        cout << endl << endl;
        cout << "PLEASE SELECT AN OPTION: ";

        cin >> input;
      
        switch(input)   {
            case 1: 
            case 2: 
            case 3: break;
            default: cout << "ERROR, PLEASE TRY AGAIN..." << endl;
                    sleep(2);
        }
    }
	sleep(2);
	return input;

}