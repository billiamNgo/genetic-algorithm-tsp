/***************************************************************
  File: travelingsalesmanproblem.hpp
  Author: William Ngo

  Description:
    This file contains the TravelingSalesmanProblem class declaration, which serves as the main interface
    for solving the Traveling Salesman Problem(TSP) using both brute force and genetic algorithm methods.
***************************************************************/

#ifndef TRAVELINGSALESMANPROBLEM_HPP
#define TRAVELINGSALESMANPROBLEM_HPP

#include "adjacencymatrix.hpp"
#include "bruteforce.hpp"
#include "geneticalgorithm.hpp"
#include <iostream>
#include <chrono>

class TravelingSalesmanProblem {
    private:
        AdjacencyMatrix matrix;
        BruteForce bruteForce;
        GeneticAlgorithm geneticAlgorithm;
        int numCities;
        double executionTime;
        void runBruteForce();
        void runGeneticAlgorithm();
        struct Timer;

    public:
        TravelingSalesmanProblem(std::string inputFileName, int numCities, int populationSize, int numGenerations, double mutationRate);
        void run();
};

#endif