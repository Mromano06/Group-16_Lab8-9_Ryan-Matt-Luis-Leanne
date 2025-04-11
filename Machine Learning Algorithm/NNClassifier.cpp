#include <iostream>
#include "NNClassifier.h"

#include <cmath>




void NNClassifier::train(std::vector<DataPoint>& trainingData) {
	this->trainingData_ = trainingData;
}

 
DataPoint NNClassifier::predict(DataPoint& queryPoint) {
	//verify that training data is notempty, and throw an exception if empty //TODO: Create Exception class for this circumstance

	DataPoint nearestNeighbor = trainingData_[0];	// initialize nearestNeighbor to first point in training data
	double minDistance = euclideanDistance(queryPoint, trainingData_[0]); // initialize minDistance to between the same point and queryPoint

	for (int i = 0; i < trainingData_.size(); i++) { // loop through every element in trainingData
		double distance = euclideanDistance(queryPoint, trainingData_[i]); //find distance between each point
		if (distance < minDistance) { //if calculated distance is smaller than current minDistance
			minDistance = distance;	// update minDistance
			nearestNeighbor = trainingData_[i]; // update nearestNeighbor
		}
	}

	//updateQuery point ID to match the NearestNeighbors ID (this is the data that I need from predict)
	queryPoint.setId(nearestNeighbor.getId());
	return queryPoint; //return updated query point
}


double NNClassifier::euclideanDistance(DataPoint& p1, DataPoint& p2) {
	// retrieve data vectors from dataPoints
	std::vector<double>& point1 = p1.getData();
	std::vector<double>& point2 = p2.getData();

	double sum = 0.0;	//initialized double to store calculated values from calculation
	for (int i = 0; i < point1.size(); i++) { // begin calculation  "sqrt ( pow(x2-x1,2) + pow(y2-y1,2) + pow(z2-z1,2) )"
		sum += std::pow(point1[i] - point2[i], 2);	// iterate throug x,y,z and calculate the sum of each "pow(x2-x1,2) + pow(y2-y1,2) + pow(z2-z1,2)"
	}

	return std::sqrt(sum);	// return sqrt(sum) to finish calculation

}