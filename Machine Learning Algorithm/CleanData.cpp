#include "CleanData.h"
#include <iostream>

double CleanData::max = 1; //initialize static value with default parameter
double CleanData::min = -1; //initialize static value with default parameter

void CleanData::get() {
	// prompt user to get value limitations (max and min) 
	double maxV, minV;
	bool invalid = true;
	while (invalid) { 
		std::cout << "Enter Max and Min Values for the given data points" << std::endl;
		
		std::cout << "Enter your max value here -> ";
		std::cin >> maxV;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear Input Buffer
		std::cout << "Enter your min value here -> ";
		std::cin >> minV;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear Input Buffer
			std::cout << "Invalid input. Please enter two numeric values separated by spaces." << std::endl;
		} 
		else {
			invalid = false; //valid input, (i know while true isnt the best but brain no work right now) // matt brain work dw
		}
	}
	max = maxV;	//set max value
	min = minV; // set min value
}
std::vector<DataPoint> CleanData::clean(std::vector<DataPoint>& data) {
	// Not Implemented yet
	std::cout << "function not implemented yet" << std::endl;
	std::vector<DataPoint> cleanData;
	for (DataPoint d : data) {
		if (check(d) == true) {	//if data is valid, push valid point to new data vector
			cleanData.push_back(d);
		}
	}
	return cleanData;
}

bool CleanData::check(DataPoint data) {	//True = Data Valid, False = Data Invalid
	for (double p : data.getData()) {
		if (p < min || max < p)
			return false;
	}
	return true;
}