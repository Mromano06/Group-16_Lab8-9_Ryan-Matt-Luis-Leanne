#pragma once
#include "DataPoint.h"
#include <stdbool.h>

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
	static std::vector<DataPoint> clean(std::vector<DataPoint>& data);
	static bool check(DataPoint data); 
};

// this calss can clean data based on conditions (for example, data must be betweeen -1 and 1)