#include"Cutscene.h"
void cutscene::play_cutscene(int cutscene_number){
	std::ifstream file_input;
	std::string cutscene_file = "Cutscene_" + cutscene_number;
	file_input.open(cutscene_file);
	while (1) {
		for (int i = 0; i < 25; i++) std::getline(file_input, screen[i]);
		if (screen[0].compare("") == 0) break;
		display();
		std::this_thread::sleep_for(std::chrono::milliseconds(66));
		system("clear");
	}
}

void cutscene::display() {
	for (int i = 0; i < 25; i++) {
		std::cout << screen[i] << std::endl;
	}
}
