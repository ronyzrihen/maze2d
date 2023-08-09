#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

const int mazeSize = 8; // Adjust the size of the maze as needed

struct Cell {
    bool visited;
    bool topWall;
    bool bottomWall;
    bool leftWall;
    bool rightWall;

    Cell() : visited(false), topWall(true), bottomWall(true), leftWall(true), rightWall(true) {}
};

vector<vector<Cell>> maze(mazeSize, vector<Cell>(mazeSize));
//stack<pair<int, int>> path;

void generateMaze(int row, int col) {
    maze[row][col].visited = true;

    int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int dirOrder[4] = { 0, 1, 2, 3 };
    for (int i = 0; i < 4; ++i) {
        int j = rand() % 4;
        swap(dirOrder[i], dirOrder[j]);
    }

    for (int i = 0; i < 4; ++i) {
        int newRow = row + directions[dirOrder[i]][0];
        int newCol = col + directions[dirOrder[i]][1];

        if (newRow >= 0 && newRow < mazeSize && newCol >= 0 && newCol < mazeSize && !maze[newRow][newCol].visited) {
            maze[row][col].visited = true;

            if (dirOrder[i] == 0) {
                maze[row][col].topWall = false;
                maze[newRow][newCol].bottomWall = false;
            }
            else if (dirOrder[i] == 1) {
                maze[row][col].bottomWall = false;
                maze[newRow][newCol].topWall = false;
            }
            else if (dirOrder[i] == 2) {
                maze[row][col].leftWall = false;
                maze[newRow][newCol].rightWall = false;
            }
            else if (dirOrder[i] == 3) {
                maze[row][col].rightWall = false;
                maze[newRow][newCol].leftWall = false;
            }

            generateMaze(newRow, newCol);
        }
    }
}

//void ensureSolution(int row, int col) {
//    if (row < 0 || row >= mazeSize || col < 0 || col >= mazeSize || maze[row][col].visited) {
//        return;
//    }
//
//    maze[row][col].visited = true;
//
//    int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//    for (int i = 0; i < 4; ++i) {
//        int newRow = row + directions[i][0];
//        int newCol = col + directions[i][1];
//
//        if (newRow >= 0 && newRow < mazeSize && newCol >= 0 && newCol < mazeSize) {
//            if (!maze[newRow][newCol].visited) {
//                if (directions[i][0] == -1) {
//                    maze[row][col].topWall = false;
//                    maze[newRow][newCol].bottomWall = false;
//                }
//                else if (directions[i][0] == 1) {
//                    maze[row][col].bottomWall = false;
//                    maze[newRow][newCol].topWall = false;
//                }
//                else if (directions[i][1] == -1) {
//                    maze[row][col].leftWall = false;
//                    maze[newRow][newCol].rightWall = false;
//                }
//                else if (directions[i][1] == 1) {
//                    maze[row][col].rightWall = false;
//                    maze[newRow][newCol].leftWall = false;
//                }
//
//                ensureSolution(newRow, newCol);
//            }
//        }
//    }
//}

void printMaze() {
    for (int i = 0; i < mazeSize; ++i) {
        for (int j = 0; j < mazeSize; ++j) {
            cout << (maze[i][j].topWall ? "###" : "# #");
        }
        cout << "#" << endl;

        for (int j = 0; j < mazeSize; ++j) {
            cout << (maze[i][j].leftWall ? "#" : " ");
            cout << (i == 0 && j == 0 ? "s" : (i == mazeSize - 1 && j == mazeSize - 1 ? "e" : " "));
            cout << (j == mazeSize - 1 ? "#" : " ");
        }
        cout << endl;

        for (int j = 0; j < mazeSize; ++j) {
            cout << (maze[i][j].leftWall ? "#" : " ");
            cout << " ";
            cout << (maze[i][j].rightWall ? "#" : " ");
        }
        cout << (maze[i][mazeSize - 1].rightWall ? "#" : " ") << endl;
    }

    for (int j = 0; j < mazeSize; ++j) {
        cout << "###";
    }
    cout << "#" << endl;
}

//int main() {
//    srand(time(nullptr));
//
//    generateMaze(0,0);
//    /*ensureSolution(0, 0);*/
//    printMaze();
//
//    return 0;
//}
