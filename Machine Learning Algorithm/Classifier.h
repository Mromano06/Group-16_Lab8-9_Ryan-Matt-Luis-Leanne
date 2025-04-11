#pragma once

#include "DataPoint.h"

/// @brief 
///
/// 
class Classifier 
{
public:
	/// @brief 
	/// 
	/// @param  
	/// @return 
	virtual void train(std::vector<DataPoint>& trainingData);

	/// @brief 
	/// 
	/// @param  
	/// @return
	virtual DataPoint predict(DataPoint& queryPoint);
};

/// Class Diagram (abstract class)
///  - train()
///  - predict()
