#pragma once

#include <vector>
#include <string>

/// @brief Represents a data point with a vector of double values and an identifier.
/// 
/// The DataPoint class stores a vector of double values and an integer identifier.
/// It provides methods to add data to the vector and retrieve the data vector.
/// It also overloads the stream insertion and extraction operators for file I/O.
class DataPoint {
    std::vector<double> data; ///< The vector of double values representing the data.
    int id = -1; ///< The identifier for the data point.

public:
    /// @brief Adds a value to the data vector.
    /// @param value The value to be added to the data vector.
    void addData(double value);

    /// @brief Gets the data vector.
    /// @return A reference to the data vector.
    std::vector<double>& getData();

    /// @brief Sets the identifier for the data point.
    /// @param id The identifier to be set.
    void setId(int id);

    /// @brief Gets the identifier for the data point.
    /// @return The identifier of the data point.
    int getId() const;

    void print();

    void display();

    /// @brief Overloads the stream insertion operator for output.
    /// 
    /// Writes the DataPoint to the output file
    /// Writing data vector first, followed by the id and its corresponding description
    /// @param fout The output file stream.
    /// @param d The DataPoint object to be written to the file.
    /// @return A reference to the output file stream.
    friend std::ofstream& operator << (std::ofstream& fout, DataPoint& d);

    /// @brief Overloads the stream extraction operator for input.
    /// 
    /// Reads values form the input file stream into a DataPoint object
    /// Processes all values on the line into a temporary data vector
    /// if the file is for training, the last value is set a the id and removed from the data vector
    /// if the file is for testing, the id is set to -1
    /// saves the remaining vector values to a DataPoint vector
    /// @param fin The input file stream.
    /// @param d The DataPoint object to be read from the file.
    /// @return A reference to the input file stream.
    friend std::ifstream& operator >> (std::ifstream& fin, DataPoint& d);
};
