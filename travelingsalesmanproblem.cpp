/***************************************************************
  File: travelingsalesmanproblem.cpp
  Author: William Ngo

  Description:
    This file contains the TravelingSalesmanProblem class implementation, which serves as the main interface
    for solving the Traveling Salesman Problem(TSP) using both brute force and genetic algorithm methods.
    This class takes a string input file name, the number of cities, population size, number of generations,
    and mutation rate as parameters. It provides methods to run the brute force and genetic algorithm solutions
    and prints the results including the optimal cost, path, and execution time for both methods to the console.

  Note: 
    The execution time is measured using the std::chrono library, which provides high-resolution clocks.
    The Timer struct is used to measure the execution time of the algorithms and store it in the class.
***************************************************************/

#include "travelingsalesmanproblem.hpp"

TravelingSalesmanProblem::TravelingSalesmanProblem(std::string inputFileName, int numCities, int populationSize, int numGenerations, double mutationRate)
    : matrix(inputFileName), bruteForce(matrix, numCities), geneticAlgorithm(matrix, numCities, populationSize, numGenerations, mutationRate) {
    this->numCities = numCities;
};

struct TravelingSalesmanProblem::Timer {
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
    TravelingSalesmanProblem& tsp;

    Timer(TravelingSalesmanProblem& tsp) : tsp(tsp) {
        start = std::chrono::steady_clock::now();
    }

    ~Timer() {
        end = std::chrono::steady_clock::now();
        duration = end - start;
        tsp.executionTime = duration.count();
    }
};

void TravelingSalesmanProblem::runBruteForce() {
    Timer timer(*this);
    bruteForce.solve();
}

void TravelingSalesmanProblem::runGeneticAlgorithm() {
    Timer timer(*this);
    geneticAlgorithm.solve();
}

void TravelingSalesmanProblem::run() {
    std::cout << "\nBrute Force TSP:" << std::endl;
    runBruteForce();
    std::cout << "numCities: " << numCities << std::endl <<
        "Optimal cost: " << bruteForce.getBestCost() << std::endl << 
        "Optimal path: " << bruteForce.getBestPath() << std::endl <<
        "Execution time: " << executionTime << std::endl;

    std::cout << "\nGenetic Algorithm TSP:" << std::endl;
    runGeneticAlgorithm();
    std::cout << "numCities: " << numCities << std::endl <<
        "GenAlg. cost: " << geneticAlgorithm.getBestCost() << std::endl <<
        "GenAlg. path: " << geneticAlgorithm.getBestPath() << std::endl <<
        "Execution time: " << executionTime << std::endl <<
        "Percent of optimal: " << (geneticAlgorithm.getBestCost() / bruteForce.getBestCost()) * 100 << "%" << std::endl;
        
}
