#include <iostream>
#include "Classifier.h"


void Classifier::train(std::vector<DataPoint>& trainingData) {
	printf("Abstract class 'Classifier' train() virtual function called");
}
DataPoint Classifier::predict(DataPoint& queryPoint) {
	printf("Abstract class 'Classifier' predict() virtual function called");
	DataPoint r;
	return r;
}