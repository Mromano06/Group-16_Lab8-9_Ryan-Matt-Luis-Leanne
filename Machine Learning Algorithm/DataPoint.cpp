#include "DataPoint.h"

#include <iostream>

void DataPoint::addData(double value) {
	data.emplace_back(value);	//place value at back of vector space 
}


std::vector<double>& DataPoint::getData() {
	return data;	//return data vector
}

void DataPoint::setId(int id) {
	this->id = id;	// set id
}

int DataPoint::getId() const {
	return id;	// return id
}


void DataPoint::print() {
	switch (id)
	{
	case 1:
		std::cout << "Face up" << std::endl;
		break;
	case 2:
		std::cout << "Face down" << std::endl;
		break;
	case 3:
		std::cout << "Portrait" << std::endl;
		break;
	case 4:
		std::cout << "Portrait upside down" << std::endl;
		break;
	case 5:
		std::cout << "Landscape left" << std::endl;
		break;
	case 6:
		std::cout << "Landscape right" << std::endl;
		break;

	default:
		std::cout << "Error Finding Orientation" << std::endl;
		break;
	}
}

void DataPoint::display() {
	for (double point : data) {
		std::cout << point << ",";
	}
	std::cout << id << ",";
	print();
}

//operator overloading for this class involving file I/O (fin/fout) is defined in ReadandWriteToFile.cpp

