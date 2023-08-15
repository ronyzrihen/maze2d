//
// Created by Rony Zrihen on 10/08/2023.
//
#pragma once
#include "Maze2dGenerator.h"
#include "chrono"
#include <time.h>

using namespace std;
string Generator::measureAlgorithmTime(){

  /*  auto startTime = std::chrono::steady_clock::now();
    generate_maze(10);
    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration<double>(endTime - startTime);
    cout << "It took " << duration.count() << " seconds.\n";*/
    time_t start_time, end_time, dif_time;
    char buff[1048];
    start_time=time(nullptr);
    generate_maze(10);
    end_time = time(nullptr);
    dif_time = end_time - start_time;
    ctime_s(buff,1048,&dif_time);
    return buff;
    

}
