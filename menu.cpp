#include "menu.h"
using namespace std;
int menu() {
    int input;
    typewriter obj;
    obj.setMessage("INITIALISING...\n");
    obj.setPause(120);
    obj.display();
    //cout << "INITIALISING...\n";
    sleep(5);
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
    if (input!=1 && input!=2 && input!=3) {
        cout << "\nError. Reloading...";
	sleep(2);
	return menu();
    }
    return input;    
}
