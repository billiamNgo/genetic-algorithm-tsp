# Genetic Algorithm for Traveling Salesman Problem(TSP) in C++

## Overview
This project implements two solutions for the classic Traveling Salesman Problem(TSP): a **brute-force algorithm** to find the optimal solution and a **Genetic Algorithm (GA)** for finding highly efficient, near-optimal solutions. The GA is designed to handle computationally challenging instances where brute-force is infeasible, consistently delivering results within 10% of the optimal route for the tested problem sizes.

This project was developed as an assignment for a Data Structures and Algorithms II course, focusing on advanced algorithmic design and optimization techniques.

**Note on Git History:** This repository represents the final, polished state of a completed university class project. While the original development involved iterative commits, this repository has been initialized with a clean commit history to present the final, well-structured codebase in a concise manner for portfolio purposes.

## Features
* **Brute-Force Algorithm:** Computes the true optimal tour cost by evaluating all possible permutations, ensuring a baseline for optimal comparison.
* **Genetic Algorithm Algorithm:** Utilizes a custom, mutation-based heuristic inspired by genetic algorithms to find high-quality approximate solutions efficiently.
    * **Core Heuristic Components:** Implements fitness evaluation (tour cost) using a single-elite strategy, targeted mutation of the elite path, and systematic permutation exploration.
    * **Configurable Parameters:** Allows user input for the number of cities, population size (influencing mutation and exploration attempts per generation), number of generations, and mutation percentage for experimentation.
* **Performance Comparison:** Outputs detailed results comparing the brute-force and GA solutions, including tour costs, runtimes, and the GA's percentage of optimal.

## Problem Background (Traveling Salesman Problem - TSP)
The Traveling Salesman Problem (TSP) is a well-known NP-hard problem: given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city? Brute-force solutions (checking all `(n-1)!` permutations) become computationally impossible for even a modest number of cities. Genetic Algorithms provide an effective heuristic for finding "good enough" solutions within reasonable timeframes when an exact solution is not feasible due to computational limits.

## Algorithm Details (Genetic Algorithm)

The Genetic Algorithm implemented here takes a unique approach that combines elements of iterative permutation search with a focus on improving a single best solution through mutation. Unlike traditional Genetic Algorithms that maintain and evolve a diverse population of solutions through genetic operators like crossover and selection, this implementation focuses on refining a single "elite" path.

The algorithm operates as follows:

1.  **Initialization:** An initial `elitePath` is established, representing the cities in sequential order (1 to N).
2.  **Iteration (Generations):** The algorithm iterates for a user-defined number of generations. In each generation:
    * **Mutation Phase:** A subset of "mutation attempts" (determined by `populationSize * mutationRate`) is performed. For each attempt, a copy of the current `elitePath` is created, and two random cities within this copy are swapped (simple 2-point mutation). If this mutated path yields a lower total cost than the current `elitePath`, it replaces the `elitePath`.
    * **Permutation Exploration Phase:** For the remainder of the "population" (determined by `populationSize * (1.0 - mutationRate)`), the algorithm explores new paths by iteratively generating the **next lexicographical permutation** of the cities (starting from a base order). Each generated permutation's cost is evaluated. If its cost is lower than the current `elitePath`'s cost, it replaces the `elitePath`.
    * **Note:** This phase does not involve random generation of new individuals but rather a systematic traversal through permutation space combined with direct replacement if a better path is found.

3.  **Key Differences from Canonical Genetic Algorithms:**
    * **No Explicit Population Storage:** The algorithm does not maintain a collection of `populationSize` distinct solutions across generations; instead, it focuses on continually improving a single `elitePath`.
    * **Absence of Crossover:** Standard crossover operators are challenging to apply directly to permutation-based problems like TSP, as they can easily generate invalid tours (with duplicate or missing cities). Implementing specialized permutation-aware crossover operators adds significant complexity. Therefore, this implementation strategically foregoes explicit crossover in favor of relying on mutation and systematic permutation exploration to generate new candidate solutions.
    * **Hybrid Search Strategy:** It combines targeted mutation on the best-known solution with a systematic (lexicographical) exploration of other permutations to find improvements, rather than relying solely on random population generation and selection/crossover processes.

4.  **Termination:** The algorithm runs for a fixed number of user-defined generations, returning the `elitePath` found as the best solution.

## Implementation Details

### Data Structures
* **Adjacency Matrix (C-style 2D Array):** Distances between cities are stored and managed using stack allocated C-style `double[][]` 2D array, representing the adjacency matrix. This approach was specifically required by the course guidelines for this project.

### Traveling Salesman Problem (TSP) Tour Representation
* **Fixed Start/End City (City 0):** The implementation of the TSP problem strictly maintains that **City 0 always serves as both the designated starting and ending point** for every tour. This means that the permutations generated and evaluated represent the sequence of *intermediate* cities to visit between the fixed start and end.
* **Cost Calculation:** Consequently, the `getCost()` function, which calculates the total cost of a tour, accounts for this fixed start/end point. It sums the distances between the cities in the `order` array (representing the intermediate sequence) and then explicitly adds:
    1.  The distance from the starting point (City 0) to the first city in the `order` array.
    2.  The distance from the last city in the `order` array back to the starting point (City 0).
    This ensures accurate tour cost calculation under the defined constraint.

## Project Structure
The repository includes the following key files:
* `main.cpp`: Main program logic, handles user input and orchestrates algorithm runs.
* `travelingsalesmanproblem.hpp`/`.cpp`: Core classes and logic for managing TSP data (e.g., adjacency matrix, tour representation).
* `bruteforce.hpp`/`.cpp`: Implementation of the brute-force permutation algorithm.
* `geneticalgorithm.hpp`/`.cpp`: Implementation of the Genetic Algorithm.
* `adjacencymatrix.hpp`/`.cpp`: Class containing C-style 2D array for city representation and cost calculation.
* `distances.txt`: Input file containing pre-defined distances between 20 cities.
* `makefile`: For easy compilation of the project.

## Setup and Compilation

This program is designed to run on a Linux environment.

1.  **Clone the repository:**
2.  **Ensure `distances.txt` is present:** Make sure the `distances.txt` file is in the same directory as the source code.
3.  **Compile the program:**
    ```bash
    make main
    ```
    This will create an executable named `main`.
4.  **Clean compiled files (optional after running):**
    ```bash
    make clean
    ```

## How to Run

After compilation, execute the program from the command line:

```bash
./main
```

The program will then interactively prompt you for the following input parameters:
* Number of cities to run (N): An integer representing the number of cities in the TSP instance. (e.g., 10, 11, 12)
* Population size (Individual tours per generation): An integer specifying the number of candidate tours to generate and evaluate in each generation.
* Number of generations: An integer defining how many evolutionary iterations the Genetic Algorithm will perform.
* Percentage of mutations: A decimal value representing the mutation rate (e.g., 0.1 for 10% mutation chance).

The program will then execute both the Brute Force and Genetic Algorithm solvers for the specified parameters and display their comparative results.
