/***************************************************************
  File: adjacencymatrix.hpp
  Author: William Ngo

  Description:
    This file contains the AdjacencyMatrix class declaration which is used to store the adjacency 
    matrix of a graph representing the distances between cities
***************************************************************/

#ifndef ADJAJENCYMATRIX_HPP
#define ADJAJENCYMATRIX_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdexcept>

const int MATRIX_SIZE = 20;

class AdjacencyMatrix {
    private:
        double matrix[MATRIX_SIZE][MATRIX_SIZE];
    public:
        AdjacencyMatrix(std::string inputFileName);
        double getCost(int order[], int size);
        void printMatrix();
};

#endif