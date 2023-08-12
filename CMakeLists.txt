cmake_minimum_required(VERSION 3.10)

project(maze2d)

set(CMAKE_CXX_STANDARD 17)  # Set the C++ standard you want to use (e.g., 11, 14, 17, etc.)

# Add your source files here
set(SOURCES
        main.cpp  # Add your main source file here
        )

add_executable(maze2d "maze/main.cpp" maze/myview.cpp maze/Maze2dGenerator.cpp maze/generate_success.h maze/d2Maze.cpp maze/demo.h maze/Cli.h maze/Cli.cpp maze/mycontroller.cpp maze/display.cpp maze/mymodel.cpp maze/exceptions.h)
