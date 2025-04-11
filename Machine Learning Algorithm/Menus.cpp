#include "Menus.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

int classifierSelectionMenuStart() {
	int arrowPos = 1;
	system("cls");
	classifierSelectionMenu(arrowPos);

	while (1) {
		int keyPressed = _getch(); // takes input
		switch (keyPressed) {

		case 13: // enter key
			if (arrowPos == 1 || arrowPos == 2 || arrowPos == 3) {
			system("cls");
			return arrowPos;
			}
			break;

		case 27: // escape key
			exit(EXIT_SUCCESS);
			break;

		case 72: // up arrow
			if (arrowPos == 1)
				arrowPos = MAIN_MENU_OPTIONS + 1;
			classifierSelectionMenu(--arrowPos);
			break;

		case 80: // down arrow
			if (arrowPos == MAIN_MENU_OPTIONS)
				arrowPos = 0;
			classifierSelectionMenu(++arrowPos);
			break;

		}

		
	}
}

void classifierSelectionMenu(int arrowPos) {
	system("cls");

	std::cout << "Classifier Selection\n" << std::endl;

	char options[][OPTION_NAME_LENGTH] = { "Nearest Nieghbor",
		"K-Nearest Nieghbor", "Another" };

	for (int i = 0; i < MAIN_MENU_OPTIONS; i++) {
		if (arrowPos == i + 1)  // print arrow if at that position
			std::cout << "--> " << options[i] << std::endl;

		else
			std::cout << "    " << options[i] << std::endl;
	}

	std::cout << std::endl; // for better formatting

}