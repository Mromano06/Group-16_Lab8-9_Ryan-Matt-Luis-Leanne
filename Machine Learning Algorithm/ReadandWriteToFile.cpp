#include "ReadandWriteToFile.h"

#include <iostream>
#include <fstream>
#include "utils.h"


int ReadandWriteToFile::fileType = 1; //initialize static value with default parameter (1 avaoids issues when reading test files)


std::vector<DataPoint> ReadandWriteToFile::read() {

	std::string fileName;
	std::cout << "Enter File Name Here -> ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear Input Buffer
	std::cin >> fileName;
	std::vector<DataPoint> dataPoints;	// create vector to store multiple data points
	std::ifstream fin;

	// ** this section is just for fun flavor text ** determine file length
	fin.open(fileName);
	if (!fin.is_open()) { // if not open recursively call read function
		std::cout << "Error Finding File Named " << fileName << std::endl;
		return read();	//recursively calls the read() function untill correct filename is entered
	}

	int totalLines = 0;
	std::string line;
	while (std::getline(fin, line)) {
		totalLines++;
	}
	fin.close();
	// ** end of for fun part **

	// reopen file for reading data
	fin.open(fileName);
	if (fin.is_open()) {
		std::cout << "Reading Data: This May Take a Moment" << std::endl;
		DataPoint d;
		int linesRead = 0;	// ** part of 'for fun' segment **
		while (fin >> d) {	//read individual data points
			dataPoints.push_back(d);	// push data points into vector

			// ** part of 'for fun' segment **
			linesRead++;
			int percentage = int(linesRead / totalLines) * 100;
			std::cout << "\rProgress: " << percentage << "% completed" << std::flush;	// display percent completion of file Read
			// ** end of 'for fun' segment **
			
		}
		// check if last line was partially read, but not stored
		if (fin.eof() && !d.getData().empty()){
			dataPoints.push_back(d);

			// ** part of 'for fun' segment **
			linesRead++; 
			int percentage = int(linesRead / totalLines) * 100;
			std::cout << "\rProgress: " << percentage << "% completed" << std::flush;	// display percent completion of file Read
			// ** end of 'for fun' segment **
		}
		fin.close();	// close file
	}
	else {
		std::cout << "Error Finding File Named " << fileName << std::endl;
		return read();	//recursively calls the read() function untill correct filename is entered
	}
	std::cout << "\nFinished Reading Data\n" << std::endl;

	

	// Continue Program query
	programContinue();
	return dataPoints;
}



void ReadandWriteToFile::write(std::vector<DataPoint>& data) {

	std::string fileName = "result.txt";
	std::ofstream fout;
	fout.open(fileName);
	if (fout.is_open()) {
		for (auto& d : data) {
			fout << d;
			d.display();	// display data stored to file to console
		}
		fout.flush(); //ensure all data is written to file
	}

	// Continue Program query
	programContinue();
	fout.close();
}



std::ifstream& operator >> (std::ifstream& fin, DataPoint& d) {
	std::vector<double> tempData;
	double value;
	d.data.clear();
	//process all values on line into temporary data vector
	while (fin >> value) {
		tempData.push_back(value);
		if (fin.peek() == ',') {
			fin.ignore();
		}
		else if (fin.peek()=='\n'|| fin.eof()) { //exit at end of file
			break;
		}
	}
	

	//Process last line so be stored as id if valid
	if (!tempData.empty()) {
		int lastValue = tempData.back();	//store last value in vector
		if (ReadandWriteToFile::get() == 0) {	//if given file is used for training
			//set lastValue as the id
			d.id = lastValue;
			tempData.pop_back();	//pop id out of vector
		}
		else {	// if given file is used for Testing or is Unknown Data 
			if (tempData.size() > 3) // if testing data is input instead of just unknown data
				tempData.pop_back();
			d.id = -1; // stored as -1 
		}
		d.data = tempData;	// save tempData vector to d.data
	}

	return fin;
}




std::ofstream& operator << (std::ofstream& fout, DataPoint& d) {
	for (auto& data : d.data) {
		fout << data << ",";
	}
	 //read last point in vector an dprint out a string depending on the value
	switch (d.id)
	{
	case 1:
		fout << d.id << ",Face up" << std::endl;
		return fout;
	case 2:
		fout << d.id << ",Face Down" << std::endl;
		return fout;
	case 3:
		fout << d.id << ",Portrait" << std::endl;
		return fout;
	case 4:
		fout << d.id << ",Portrait upside down" << std::endl;
		return fout;
	case 5:
		fout << d.id << ",Landscape left" << std::endl;
		return fout;
	case 6:
		fout << d.id << ",Landscape right" << std::endl;
		return fout;

	default:
		fout << d.id << ", Error Finding Orientation" << std::endl;
		return fout;
	}	
}


void ReadandWriteToFile::set(int f) {
	fileType = f;
}

int ReadandWriteToFile::get() {
	return fileType;
}