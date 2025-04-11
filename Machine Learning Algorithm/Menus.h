#pragma once

#define MAIN_MENU_OPTIONS		 3
#define OPTION_NAME_LENGTH		20		

/// @brief Global funtion to start main menu
/// @return int to determine action
int classifierSelectionMenuStart();

/// @brief Global function, uses the arrow position to print out current selection
/// @param arrowPos 
void classifierSelectionMenu(int arrowPos);