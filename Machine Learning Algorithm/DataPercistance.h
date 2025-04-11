#pragma once

#include "DataPoint.h"
//#include <vector>


/// @brief 
///
/// 
class DataPercistance
{	
public:
	/// @brief 
	///
	/// 
	virtual std::vector<DataPoint> read();

	/// @brief 
	///
	/// 
	virtual void write(std::vector<DataPoint>& data);
};

//class diagram (should be abstract class)
// - read()
// - write()


// class that inherits from DataPercistance
// ReadandWriteToFile
// - read()
// - write()

//... can be continued later on for reading and writing to and from databases, etc...

