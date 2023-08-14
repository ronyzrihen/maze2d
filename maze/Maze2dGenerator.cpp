//
// Created by Rony Zrihen on 10/08/2023.
//
#pragma once
#include "Maze2dGenerator.h"
#include "chrono"

using namespace std;
void Generator::measureAlgorithmTime(){

    auto startTime = std::chrono::steady_clock::now();
    generate_maze(10);
    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration<double>(endTime - startTime);
    cout << "It took " << duration.count() << " seconds.\n";

}
