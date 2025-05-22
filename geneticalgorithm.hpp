/***************************************************************
  File: geneticalgorithm.hpp
  Author: William Ngo

  Description:
    This file contains the GeneticAlgorithm class declaration that contains
    the genetic algorithm to solve the Traveling Salesman Problem(TSP).
***************************************************************/

#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP

#include "adjacencymatrix.hpp"
#include <limits>
#include <string>
#include <cstdlib>

class GeneticAlgorithm {
    private:
        AdjacencyMatrix matrix;
        int numCities;
        int populationSize;
        int numGenerations;
        double mutationRate;
        int order[MATRIX_SIZE];
        int elitePath[MATRIX_SIZE + 1];
        double bestCost;
        void permutate(int s[], int size);
        void swap(int& input1, int& input2);

    public:
        GeneticAlgorithm(AdjacencyMatrix& matrix, int numCities, int populationSize, int numGenerations, double mutationRate);
        void solve();
        double getBestCost();
        std::string getBestPath();
};

#endif