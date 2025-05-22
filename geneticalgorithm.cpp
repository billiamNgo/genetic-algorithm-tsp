/***************************************************************
  File: geneticalgorithm.cpp
  Author: William Ngo

  Description:
    This file contains the GeneticAlgorithm class implementation that contains
    the genetic algorithm to solve the Traveling Salesman Problem(TSP).
    The class takes an adjacency matrix that represents the distances between cities.
    It performs mutations on the elite and generates new paths, keeping track of the best(minimum cost) path found.
***************************************************************/

#include "geneticalgorithm.hpp"

GeneticAlgorithm::GeneticAlgorithm(AdjacencyMatrix& matrix, int numCities, int populationSize, int numGenerations, double mutationRate) 
    : matrix(matrix), numCities(numCities), populationSize(populationSize), numGenerations(numGenerations), mutationRate(mutationRate), bestCost(std::numeric_limits<double>::max()) {
    for (int i = 1; i <= numCities; i++) {
        order[i - 1] = i;
        elitePath[i - 1] = i;
    }
}

void GeneticAlgorithm::permutate(int s[], int size) {
    int m, k, p , q;
    m = size - 2;
    while(s[m] > s[m+1]) {
        m = m - 1;
    }
    if (m < 0) {
        return;
    }
    k = size - 1;
    while(s[m] > s[k]) {
        k = k - 1;
    }
    swap(s[m],s[k]);
    p = m + 1;
    q = size - 1;
    while( p < q) {
       swap(s[p],s[q]);
       p++;
       q--;
    }
}

void GeneticAlgorithm::swap(int& input1, int& input2) {
    int temp = input1;
    input1 = input2;
    input2 = temp;
}

void GeneticAlgorithm::solve() {
    //Loop through the number of generations
    for (int i = 0; i < numGenerations; i++) {
        int mutation[numCities];
        for (int j = 0; j < numCities; j++) {
            mutation[j] = elitePath[j];
        }
        
        //Perform mutations as per mutation rate
        for (int j = 0; j < populationSize * mutationRate; j++) {
            int index1 = rand() % numCities;
            int index2 = rand() % numCities;
            swap(mutation[index1], mutation[index2]);

            //Test mutation for best cost
            double mutationCost = matrix.getCost(mutation, numCities);
            if (mutationCost < bestCost) {
                bestCost = mutationCost;
                for (int k = 0; k < numCities; k++) {
                    elitePath[k] = mutation[k];
                }
            }
        }

        //New paths for the rest of the population
        for (int j = 0; j < populationSize * (1.0 - mutationRate); j++) {
            double cost = matrix.getCost(order, numCities);
            //Test new path for best cost
            if (cost < bestCost) {
                bestCost = cost;
                for (int k = 0; k < numCities; k++) {
                    elitePath[k] = order[k];
                }
            }
            permutate(order, numCities);
        }
    }
}

double GeneticAlgorithm::getBestCost() {
    return bestCost;
}

std::string GeneticAlgorithm::getBestPath() {
    std::string path = "0 ";
    for (int i = 0; i < numCities; i++) {
        path += std::to_string(elitePath[i]) + " ";
    }
    path += "0";
    return path;
}