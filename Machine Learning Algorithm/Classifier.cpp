#include <iostream>
#include "Classifier.h"


void Classifier::train(std::vector<DataPoint>& trainingData) {
	std::cout << "Abstract class 'Classifier' train() virtual function called" <<std::endl;
}
DataPoint Classifier::predict(DataPoint& queryPoint) {
	std::cout << "Abstract class 'Classifier' predict() virtual function called" << std::endl;
	DataPoint r;
	return r;
}