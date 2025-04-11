#pragma once

#include "DataPoint.h"
//#include <vector>

/// @class DataPersistance
/// @brief Abstract class for reading/writing data
///
/// 
class DataPercistance
{	
public:
	/// @brief Virtual read function
	/// @param DataPoint vector
	virtual std::vector<DataPoint> read();

	/// @brief Virtual write function
	/// @param DataPoint vector
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

