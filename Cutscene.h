#include<cstdlib>
#include<fstream>
#include<iostream>
#include<string>
#include<chrono>
#include<thread>

class cutscene {
	static const int height_cutscene = 7;
	std::string screen[height_cutscene];
public:
	void play_cutscene(int cutscene_number);
	void display();
};
