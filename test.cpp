/***************************************************************
  File: test.cpp
  Author: William Ngo

  Description:
    This file contains a test program for the Traveling Salesman Problem(TSP) implementation.
    This was used to test the functionality of the AdjacencyMatrix, BruteForce, and GeneticAlgorithm 
    classes during development.
***************************************************************/

#include "adjacencymatrix.hpp"
#include "bruteforce.hpp"
#include "geneticalgorithm.hpp"
#include <iostream>

int main() {
    const int NUM_CITIES = 4;
    const int POPULATION_SIZE = 100;
    const int NUM_GENERATIONS = 5200;
    const double MUTATION_RATE = 0.8;

    AdjacencyMatrix matrix("distances.txt");
    matrix.printMatrix();
    std::cout << "Cost of path: " << matrix.getCost(new int[4]{1, 3, 2, 4}, 4) << std::endl << std::endl;
    
    std::cout << "Brute Force TSP:" << std::endl;
    BruteForce bruteForce(matrix, NUM_CITIES);
    bruteForce.solve();
    std::cout << "Best cost: " << bruteForce.getBestCost() << std::endl;
    std::cout << "Best path: " << bruteForce.getBestPath() << std::endl;

    std::cout << "\nGenetic Algorithm TSP:" << std::endl;
    GeneticAlgorithm genetic(matrix, NUM_CITIES, POPULATION_SIZE, NUM_GENERATIONS, MUTATION_RATE);
    genetic.solve();
    std::cout << "Best cost: " << genetic.getBestCost() << std::endl;
    std::cout << "Best path: " << genetic.getBestPath() << std::endl;

    return 0;
}