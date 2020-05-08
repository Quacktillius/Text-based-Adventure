#include<iostream>
#include<string>
#include<fstream>
#include<chrono>
#include<thread>

class typewriter{
	std::string message;
	unsigned int pause;
	public:
		void setMessage(std::string);
		void setPause(unsigned int);
		std::string getMessage();
		unsigned int getPause();
		void display();
};
