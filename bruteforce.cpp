/***************************************************************
  File: bruteforce.cpp
  Author: William Ngo

  Description:
    This file contains the BruteForce class implementation that contains
    the brute force algorithm to solve the Traveling Salesman Problem(TSP).
    The class takes an adjacency matrix that represents the distances between cities.
    It generates all possible permutations of city orders and calculates the total cost
    for each permutation, keeping track of the best (minimum cost) path found.
***************************************************************/

#include "bruteforce.hpp"

BruteForce::BruteForce(AdjacencyMatrix& matrix, int numCities) : matrix(matrix), numCities(numCities), bestCost(std::numeric_limits<double>::max()) {
    for (int i = 1; i <= numCities; i++) {
        order[i - 1] = i;
    }
}

void BruteForce::permutate(int s[], int size) {
    int m, k, p , q;
    m = size - 2;
    while(s[m] > s[m+1]) {
        m = m - 1;
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

void BruteForce::swap(int& input1, int& input2) {
    int temp = input1;
    input1 = input2;
    input2 = temp;
}

unsigned long BruteForce::factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void BruteForce::solve() {
    unsigned long numPermutations = factorial(numCities - 1);
    for (unsigned long i = 0; i < numPermutations; i++) {
        double cost = matrix.getCost(order, numCities);
        if (cost < bestCost) {
            bestCost = cost;
            for (int j = 0; j < numCities; j++) {
                bestPath[j] = order[j];
            }
        }
        permutate(order, numCities);
    }
}

double BruteForce::getBestCost() {
    return bestCost;
}

std::string BruteForce::getBestPath() {
    std::string path = "0 ";
    for (int i = 0; i < numCities; i++) {
        path += std::to_string(bestPath[i]) + " ";
    }
    path += "0";
    return path;
}