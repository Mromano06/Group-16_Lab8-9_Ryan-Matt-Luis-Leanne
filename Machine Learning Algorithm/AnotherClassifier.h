#pragma once
#include "Classifier.h"
#include <string>
#include <vector>
#include <iostream>

/**
* @class AnotherClassifier
* @brief A placeholder class that implements the Classifier interface. Is not functional.
*
* This class is currently used to represent polymorphism and abstraction.
* All functions only print that they are not implemented
*/
class AnotherClassifier : public Classifier {
public:
	/**
	* @brief Prints a message to state that the function is not implemented
	* @param data A vector of data samples for training (not used).
	*
	*/
	void train(std::vector<DataPoint>& trainingData) override;

	/**
	* @brief Prints a message indicating prediction is not implemented.
	* @param input A queryPoint sample to classify (ignored).
	* @return A DataPoint.
	*
	*/
	DataPoint predict(DataPoint& queryPoint);

};


