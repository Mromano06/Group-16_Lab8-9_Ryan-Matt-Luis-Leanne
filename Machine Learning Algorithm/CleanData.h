#pragma once
#include "DataPoint.h"

/// @brief 
///
/// Assuming data is already clean upon arrival 
/// @note This class is currently not implemented
/// 
class CleanData
{
	static double max;
	static double min;
public:
	static void get();
	static void clean(std::vector<DataPoint>& data);
};

// this calss can clean data based on conditions (for example, data must be betweeen -1 and 1)