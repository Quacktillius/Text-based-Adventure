#include"Cutscene.h"
void cutscene::play_cutscene(int cutscene_number){
	std::ifstream file_input;
	std::string cutscene_file = "Cutscene_" + std::to_string(cutscene_number) + ".txt";
	file_input.open(cutscene_file);
	while (std::getline(file_input, screen[0])) {
		for (int i = 1; i < height_cutscene; i++) std::getline(file_input, screen[i]);
		display();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		system("cls");
	}
}

void cutscene::display() {
	for (int i = 0; i < height_cutscene; i++) {
		std::cout << screen[i] << std::endl;
	}
	std::cout << std::flush;
}
