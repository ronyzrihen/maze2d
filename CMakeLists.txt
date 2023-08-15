cmake_minimum_required(VERSION 3.10)

project(maze2d)

set(CMAKE_CXX_STANDARD 17)  # Set the C++ standard you want to use (e.g., 11, 14, 17, etc.)

# Add your source files here
set(SOURCES
        main.cpp  # Add your main source file here
        )

add_executable(maze2d "maze/main.cpp" maze/Maze2dGenerator.cpp maze/generate_success.h maze/d2Maze.cpp maze/Cli.h maze/mymodel.cpp maze/exceptions.h maze/pos.cpp maze/Searchable.h maze/State.h maze/d2MazeSearchable.h maze/file.cpp maze/load_maze.h maze/save_maze.h maze/dir.h maze/file_size.h maze/file_size.h maze/Solution.h maze/Searcher.h maze/BFS.h maze/CommonSearcher.h maze/solve.h maze/display_solution.h maze/myview.cpp maze/MazeCompression.h maze/MazeCompression.cpp)
