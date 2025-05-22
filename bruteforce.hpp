/***************************************************************
  File: bruteforce.hpp
  Author: William Ngo

  Description:
    This file contains the BruteForce class declaration that contains
    the brute force algorithm to solve the Traveling Salesman Problem(TSP).
***************************************************************/

#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP

#include "adjacencymatrix.hpp"
#include <limits>
#include <string>
#include <iostream>

class BruteForce {
    private:
        AdjacencyMatrix matrix;
        int numCities;
        int bestPath[MATRIX_SIZE + 1];
        int order[MATRIX_SIZE];
        double bestCost;
        void permutate(int s[], int size);
        void swap(int& input1, int& input2);
        unsigned long factorial(int n);
        
    public:
        BruteForce(AdjacencyMatrix& matrix, int numCities);
        void solve();
        double getBestCost();
        std::string getBestPath();
};

#endif