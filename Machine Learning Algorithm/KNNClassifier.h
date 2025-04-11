#pragma once

#include "Classifier.h"

/// @brief 
///
/// 
class KNNClassifier :public Classifier
{
	/// @brief 
	///
	/// 
	void train();

	/// @brief 
	///
	/// 
	void predict();
};


/// Class Diagram (inherits from Classifier)
///  - train()
///  - predict()
/// 
/// for this class, all functionality of the given functions will only print the function name
