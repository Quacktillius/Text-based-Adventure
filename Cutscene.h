#include<cstdlib>
#include<fstream>
#include<iostream>
#include<string>
#include<chrono>
#include<thread>

class cutscene {
	std::string screen[25];
public:
	void play_cutscene(int cutscene_number);
	void display();
};
