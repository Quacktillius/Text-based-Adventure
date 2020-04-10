#include"typewriter.h"

void typewriter::setMessage(std::string s){
	message=s;
}

void typewriter::setPause(unsigned int p){
	pause=p;
}

unsigned int typewriter::getPause(){
	return pause;
}

std::string typewriter::getMessage(){
	return message;
}

void typewriter::display(){
	for(const char c: message){
		std::cout<<c;
		std::cout<<std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(pause));
	}
}
