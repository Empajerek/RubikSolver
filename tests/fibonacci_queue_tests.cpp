#include <iostream>
#include <queue>
#include <cassert>
#include <iomanip>
#include "../include/fibonacci_queue.hpp"

void printProgressBar(int progress, int total, int barWidth = 80) {
    float percent = static_cast<float>(progress) / total;
    int progressBarWidth = static_cast<int>(percent * barWidth);

    std::cout << "[";
    for(int i = 0; i < barWidth; ++i){
        if(i < progressBarWidth)
            std::cout << "=";
        else
            std::cout << " ";
    }

    std::cout << "] " << std::fixed << std::setprecision(1) << (percent * 100.0) << "%\r";
    std::cout.flush();
}

int main() {
    std::cout << "Testing implementation of Fibonacci_queue module." << std::endl;
    // Seed for random number generation
    std::srand(std::time(0));

    // Number of tests
    const int numTests = 10;

    for(int test = 0; test < numTests; ++test) {
        printProgressBar(test, numTests);
        std::priority_queue<int> stdPQ;
        Fibonacci_queue<int> myPQ;

        // Perform random operations
        for (int operation = 0; operation < 100; ++operation) {
            int randomValue = std::rand();

            // Insert random value
            stdPQ.push(randomValue);
            myPQ.Insert(randomValue);

            // Check if the top element is the same
            if (!stdPQ.empty()) {
                assert(stdPQ.top() == myPQ.Show_min());
            }

            // Perform pop operation
            if (std::rand() % 2 == 0) {
                if (!stdPQ.empty()) {
                    stdPQ.pop();
                    myPQ.Extract_min();
                }
            }
        }
    }

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}