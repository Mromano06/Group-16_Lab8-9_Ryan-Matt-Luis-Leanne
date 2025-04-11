#include "utils.h"

void programContinue() {
	std::string option;
	std::cout << "Continuing Program? [Y/N] -> ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear Input Buffer
	std::cin >> option;
	if (option == "N" || option =="n") {
		std::cout << "This will Exit the Program, Are you Sure? [Y/N] -> ";
		std::cin >> option;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear Input Buffer
		if (option =="Y" || option =="y") {
			std::cout << "Exiting Program" << std::endl;
			exit(EXIT_SUCCESS);
		}
	}
}