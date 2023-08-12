#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int rows = 10;
const int cols = 10;
std::vector<std::vector<char>> maze(rows, std::vector<char>(cols, '#'));

void printMaze() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << maze[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

bool isValid(int x, int y) {
    return x >= 0 && x < rows&& y >= 0 && y < cols&& maze[x][y] == '#';
}

bool generateMaze(int x, int y) {
    maze[x][y] = ' '; // Mark the cell as visited

    // Define the possible directions (up, down, left, right)
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    // Shuffle the directions randomly
    for (int i = 0; i < 4; ++i) {
        int r = rand() % 4;
        std::swap(dx[i], dx[r]);
        std::swap(dy[i], dy[r]);
    }

    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY)) {
            maze[(x + newX) / 2][(y + newY) / 2] = ' '; // Carve a path
            if (generateMaze(newX, newY)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    srand(time(nullptr));

    // Generate the maze
    generateMaze(1, 1);

    // Mark the start and end
    maze[1][0] = 'S';
    maze[rows - 2][cols - 1] = 'E';

    // Print the maze
    printMaze();

    return 0;
}
