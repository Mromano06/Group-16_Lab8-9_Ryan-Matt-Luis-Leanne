#pragma once

#include "Classifier.h"
#include "DataPoint.h"
#include <vector>

/// @brief Nearest Neighbor Classifier (not Neural Network)
///
/// The NNClassifier class implements a simple nearest neighbor classifier
/// It provides methods to train the classifier with training data and predict the class of a query point
class NNClassifier : public Classifier
{
public:
    /// @brief Train the classifier with the given training data
    /// 
    /// This function stores the provided training data in the classifier for future predictions.
    /// 
    /// @param trainingData A vector of DataPoint objects representing the training data
    void train(std::vector<DataPoint>& trainingData);

    /// @brief Predict the class of the query point by finding its nearest neighbor
    /// 
    /// This function finds the nearest neighbor of the query point in the training data, 
    /// updates the query point's ID to match the nearest neighbor's ID, and returns the updated query point
    /// 
    /// @param queryPoint A DataPoint object to be predicted
    /// @return DataPoint The updated query point with the predicted ID from it's nearest neighbor
    DataPoint predict(DataPoint& queryPoint);

private:
    /// @brief The Training data used by the classifier
    ///
    /// a vector of DataPoint objects representing training data
    std::vector<DataPoint> trainingData_;

    /// @brief Calculate the Euclidean distance between two data points
    /// 
    /// This function calculates the Euclidean distance between two DataPoint objects 
    /// by iterating through their data vectors, computing the squared differences between each point, 
    /// summing them up, and taking the square root of the sum
    /// 
    /// @param p1 The first data point
    /// @param p2 The second data point
    /// @return double The Euclidean distance between the two data points
    double euclideanDistance(DataPoint& p1, DataPoint& p2);
};
