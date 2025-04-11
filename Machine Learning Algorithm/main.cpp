

#include <iostream>
#include "DataPercistance.h"
#include "ReadandWriteToFile.h"
#include "Classifier.h"
#include "NNClassifier.h"
#include "Menus.h"
#include "utils.h"

/// @brief main implementation
/// 
/// @param  void
/// @return 0

int main(void) {
	// Initial Startup
	std::cout << "Welcome to a Data Preciction Classifier Algorithm" << std::endl;

	//initialize variables
	int option = 0;
	int exitCndition = 0;
	Classifier* classifier = nullptr; // have to do 'nullptr' or else compiler hates me
	std::vector<DataPoint> unknownData;
	std::vector<DataPoint> dataPrediction;


	// 1 signifys nearest nieghbor
	while (option != 1) {

		option = classifierSelectionMenuStart();

		// check if input option is within valid range
		switch (option)
		{
		case 1:
			std::cout << "Nearest Neighbor Classifier Selected\n\nTraining Data required: (ex. trainingData.txt)" << std::endl;
			classifier = new NNClassifier();
			continue;
		case 2:
			std::cout << "Classifier 'K-NN' Not Implemented Yet\n" << std::endl;
			programContinue();
			option = 0; //reset option to re-prompt user
			continue;
		case 3:
			std::cout << "'Another' Classifier Not Implemented Yet\n" << std::endl;
			programContinue();
			option = 0; //reset option to re-prompt user
			continue;
		default:
			std::cout << "entered value is not within valid range [1-3]" << std::endl;
			option = 0; //reset option to re-prompt user
			std::cin.clear();//clear fail state (if there is one)
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear Input Buffer
		}


	}
	
	

	// Read Training Data from file and train classifier
	DataPercistance* dataHandler = new ReadandWriteToFile();
	ReadandWriteToFile::set(0); //set file Type as Training File
	std::vector<DataPoint> trainingData = dataHandler->read();
	classifier->train(trainingData);
	// prompt user to provide parameters for cleaning data (ex. values can only be between -1 and 1); **Not being implemented

	ReadandWriteToFile::set(1); //set file Type as testing File (no longer able to store data for training)
	

	// Use Algorithm
	while (exitCndition == 0) {
		system("CLS"); //clear console screen

		// User Prompt for two options: (and exit option being the third)
		std::cout << "Classifier Testing Terminal:" << std::endl;
		std::cout << "\t[1] Manual Data Testing \n\t[2] Auto Data Testing \n\t[3] exit program\nEnter your selection here -> ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear Input Buffer
		std::cin >> option;

		switch (option)
		{
		case 1:
			// Manually enter Values to sample data (x,y,z) (for testing known data)
			double x, y, z;
			while (true) {
				std::cout << "Enter data in format [x y z] -> ";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear Input Buffer
				std::cin >> x >> y >> z;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear Input Buffer
					std::cout << "Invalid input. Please enter three numeric values separated by spaces." << std::endl;
				}
				else {
					break; //valid input, (i know while true isnt the best but brain no work right now)
				}
			}
	
			if (unknownData.empty()){
				unknownData.emplace_back();	//ensures that unknownData is not empty
			}
			unknownData[0].addData(x);			//store entered data into a DataPoint
			unknownData[0].addData(y);
			unknownData[0].addData(z);
			
			//predict and print results
			dataPrediction.push_back(classifier->predict(unknownData[0]));
			for (DataPoint data : dataPrediction) {
				data.print();
			}
			

			// clear data so that there is no overlap if you switch between sections
			unknownData.clear();
			dataPrediction.clear();	

			programContinue();
			break;


		case 2:
			// Ask for file name of Unknown Data then read and predict values for each DataPoint
			unknownData = dataHandler->read();
			for (DataPoint data : unknownData) {	// for every DataPoint in vector of DataPoints
				dataPrediction.push_back(classifier->predict(data)); //push predicted DataPoint into dataPrediction vector
			}
			// Write predicted Data to a results.txt file
			dataHandler->write(dataPrediction);

			// clear data
			unknownData.clear();
			dataPrediction.clear();
			break;


		case 3: // exit program
			exitCndition = 1;	//exit while loop
			break;


		default: // invalid input
			std::cout << "Invalid Input" << std::endl;
			std::cin.clear();//clear fail state (if there is one)
			std::cin.ignore('\n'); // Discard Invalid input
			break;
		}
	}
	
	std::cout << "Exiting Program" << std::endl;
	return EXIT_SUCCESS;
}
