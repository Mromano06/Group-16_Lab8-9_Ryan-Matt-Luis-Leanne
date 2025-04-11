#pragma once
#include <string>
#include <iostream>

// Continue Program asky
/// @brief Global function to ask to continue program
///
/// asks to continut program, and continues if Y or y is entered
/// if N or n is entered, asks if the usser is sure, as the program will exit 
/// if the user presses Y to confirm that they pressed N, program exits
/// if the user presses N to cancel confirmation, program continues
void programContinue();