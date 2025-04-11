#pragma once
#include "DataPercistance.h"
#include <string>
#include <vector>

/// @brief Class for reading and writing DataPoint objects to and from files.
/// 
/// This class inherits from DataPercistance and provides implementations
/// for reading and writing DataPoint objects to and from files.
class ReadandWriteToFile : public DataPercistance {

    static int fileType;   // 0 for training, 1 for testing

public:


    /// @brief Sets the static member variable 'fileType' to the given value
    /// @param f 
    static void set(int f);

    /// @brief Returns the value of the static member variable 'fileType'
    /// @return 
    static int get();

    /// @brief Reads DataPoint objects from a file.
    /// 
    /// Prompts the user to enter the name of the file to read from and sets the file type based on user input
    /// Recursively prompts the user to enter the correct filename if the file is not found.
    /// Reads DataPoint objects from the specified file and returns them as a vector.
    /// @return A vector of DataPoint objects read from the file.
    std::vector<DataPoint> read();

    /// @brief Writes DataPoint objects to a file.
    /// 
    /// Writes the given vector of DataPoint objects to a file named "result.txt".
    /// Opens file for writing and writes each DataPoint to the file using an overloaded << operator
    /// @param data A reference to a vector of DataPoint objects to be written to the file.
    void write(std::vector<DataPoint>& data);
};

