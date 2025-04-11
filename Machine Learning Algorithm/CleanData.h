#pragma once
#include "DataPoint.h"
#include <stdbool.h>

/// @class CleanData
/// @brief Provides functionality to clean and validate data points based on user-defined constraints.
///
/// The `CleanData` class allows users to define maximum and minimum value constraints for data points.
/// It provides methods to prompt the user for these constraints, validate data points against them,
/// and clean a collection of data points by removing invalid entries.
class CleanData
{
    /// @brief The maximum allowed value for data points.
    /// 
    /// This static member stores the upper limit for valid data point values.
    /// It is initialized to a default value of 1.
    static double max;

    /// @brief The minimum allowed value for data points.
    /// 
    /// This static member stores the lower limit for valid data point values.
    /// It is initialized to a default value of -1.
    static double min;

public:
    /// @brief Prompts the user to set the maximum and minimum value constraints for data points.
    ///
    /// This method interacts with the user via the console to input the maximum and minimum
    /// values for valid data points. It ensures that the input is valid and updates the
    /// static `max` and `min` members accordingly.
    static void get();

    /// @brief Cleans a collection of data points by removing invalid entries.
    ///
    /// This method iterates through the provided vector of data points and removes any
    /// data points that do not meet the constraints defined by the `max` and `min` values.
    ///
    /// @param data A reference to a vector of `DataPoint` objects to be cleaned.
    /// @return A new vector containing only the valid data points.
    static std::vector<DataPoint> clean(std::vector<DataPoint>& data);

    /// @brief Checks if a data point is valid based on the defined constraints.
    ///
    /// This method evaluates whether all values in the given data point fall within
    /// the range defined by the `max` and `min` values.
    ///
    /// @param data The `DataPoint` object to be validated.
    /// @return `true` if the data point is valid, `false` otherwise.
    static bool check(DataPoint data);
};
