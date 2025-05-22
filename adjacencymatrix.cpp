/***************************************************************
  File: adjacencymatrix.cpp
  Author: William Ngo

  Description:
    This file contains the AdjacencyMatrix class implementation, which stores the adjacency
    matrix representing distances between cities for the Traveling Salesman Problem(TSP).
    Provides methods to load the matrix from a file, print it, and calculate
    the total cost of a tour that starts and ends at city 0.

  Note:
    The getCost() method assumes the tour order does NOT include the starting city (0).
    The path is: 0 -> order[0] -> ... -> order[size-1] -> 0
***************************************************************/

#include "adjacencymatrix.hpp"

AdjacencyMatrix::AdjacencyMatrix(std::string inputFileName) {
    std::ifstream inFS(inputFileName);
    if (!inFS.is_open()) {
        throw std::runtime_error("Input file could not be opened: " + inputFileName);
    }
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (i == j) {
                matrix[i][j] = 0.0;
            } else {
                std::string value;
                if (!(getline(inFS, value))) {
                    throw std::runtime_error("Error reading matrix from file: " + inputFileName);
                }
                matrix[i][j] = std::stod(value);
            }
        }
    }
}

double AdjacencyMatrix::getCost(int order[], int size) {
    double totalCost = 0.0;
    for (int i = 0; i < size - 1; i++) {
        totalCost += matrix[order[i]][order[i + 1]];
    }
    totalCost += matrix[0][order[0]];   //starting point to first city
    totalCost += matrix[order[size - 1]][0];    //return to starting point
    return totalCost;
}

void AdjacencyMatrix::printMatrix() {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            std::cout << std::setw(6) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}