/***************************************************************
  Name: main.cpp
  Author: William Ngo

  Description:
    This file contains the main function for the Traveling Salesman Problem(TSP) program.
    It prompts the user for input parameters such as the number of cities, population size,
    number of generations, and mutation rate. It then creates an instance of the TravelingSalesmanProblem
    class and calls its run method to execute the TSP solution using both brute force and genetic algorithm methods.
***************************************************************/

#include "travelingsalesmanproblem.hpp"

const std::string DEFAULT_INPUT_FILE_NAME = "distances.txt";

int main() {
    int numCities;
    int populationSize;
    int numGenerations;
    double mutationRate;
    
    // Get user input
    std::cout << "Traveling Salesman Problem" << std::endl
                << "--------------------------" << std::endl;
    std::cout << "Enter the number of cities: " << std::flush;
    std::cin >> numCities;
    std::cout << "Enter the population size in a given generation: " << std::flush;
    std::cin >> populationSize;
    std::cout << "Enter the number of generations: " << std::flush;
    std::cin >> numGenerations;
    std::cout << "Enter the mutation rate(as decimal): " << std::flush;
    std::cin >> mutationRate;

    TravelingSalesmanProblem tsp(DEFAULT_INPUT_FILE_NAME, numCities, populationSize, numGenerations, mutationRate);
    tsp.run();
    return 0;
}