#pragma once

#include "DataPoint.h"

/// @class Classifier
/// @brief CLassifier interface 
class Classifier 
{
public:
	/// @brief virtual function train
	/// 
	/// @param  DataPoint vector
	virtual void train(std::vector<DataPoint>& trainingData);

	/// @brief virtual function predict
	/// 
	/// @param  DataPoint
	/// @return DataPoint with orientation
	virtual DataPoint predict(DataPoint& queryPoint);
};

/// Class Diagram (abstract class)
///  - train()
///  - predict()
