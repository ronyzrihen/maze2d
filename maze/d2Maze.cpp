//
// Created by Rony Zrihen on 10/08/2023.
//
#include "d2Maze.h"
using namespace std;

d2Maze::d2Maze(vector<int> binaryMaze){

    m_dim = binaryToDecimal(extract_int(binaryMaze));

    start.set_row(binaryToDecimal(extract_int(binaryMaze)));
    start.set_col(binaryToDecimal( extract_int(binaryMaze)));

    end.set_row(binaryToDecimal( extract_int(binaryMaze)));
    end.set_col(binaryToDecimal( extract_int(binaryMaze)));

    player.set_row(binaryToDecimal( extract_int(binaryMaze)));
    player.set_col(binaryToDecimal( extract_int(binaryMaze)));


    for(int i = 0 ; i < m_dim ; i++){

        vector<Cell> cells;

        for(int j = 0 ; j < m_dim ; j++){
            Cell cell ;
            if(*(binaryMaze.begin()))
            {cell.visited = true;}
            else{cell.visited = false;}
            binaryMaze.erase(binaryMaze.begin());

            if(*(binaryMaze.begin()))
            {cell.topWall = true;}
            else{cell.topWall = false;}
            binaryMaze.erase(binaryMaze.begin());

            if(*(binaryMaze.begin()))
            {cell.rightWall = true;}
            else{cell.rightWall = false;}
            binaryMaze.erase(binaryMaze.begin());

            if(*(binaryMaze.begin()))
            {cell.bottomWall = true;}
            else{cell.bottomWall = false;}
            binaryMaze.erase(binaryMaze.begin());

            if(*(binaryMaze.begin()))
            {cell.leftWall = true;}
            else{cell.leftWall = false;}
            binaryMaze.erase(binaryMaze.begin());

            cells.push_back(cell);
        }
        maze.push_back(cells);
    }
m_size = binaryMaze.size();
}

vector<int> d2Maze::GetData(){

    vector<int> binary_data;
    decimalToBinary(m_dim,binary_data);
    binary_data.push_back(-1);

    decimalToBinary(start.get_row(),binary_data);
    binary_data.push_back(-1);
    decimalToBinary(start.get_col(),binary_data);
    binary_data.push_back(-1);

    decimalToBinary(end.get_row(),binary_data);
    binary_data.push_back(-1);
    decimalToBinary(end.get_col(),binary_data);
    binary_data.push_back(-1);

    decimalToBinary(player.get_row(),binary_data);
    binary_data.push_back(-1);
    decimalToBinary(player.get_col(),binary_data);
    binary_data.push_back(-1);


    for(auto row : maze){
        for(auto col : row){
            binary_data.push_back(col.visited);
            binary_data.push_back(col.topWall);
            binary_data.push_back(col.rightWall);
            binary_data.push_back(col.bottomWall);
            binary_data.push_back(col.leftWall);
        }
    }

    return binary_data;
}

//int extract_int(int decimalNumber){
//    int number = 0, i = 0, rem;
//    while (decimalNumber!=0) {
//        rem = decimalNumber % 10;
//        decimalNumber /= 10;
//        number += (rem * pow(2, i));
//        ++i;
//   }
//    return number;
//}
int d2Maze::extract_int(vector<int>& binaryMaze){
    int number = 0;
    while(*(binaryMaze.begin()) != -1){
        number *= 10;
        number += *(binaryMaze.begin());
        binaryMaze.erase(binaryMaze.begin());
    }
    binaryMaze.erase(binaryMaze.begin());
    return number;
}

int d2Maze::binaryToDecimal(int binaryNumber) {
    int decimalNumber = 0;
    int base = 2;
    int power = 0;

    while (binaryNumber > 0) {
        int digit = binaryNumber % 10;
        decimalNumber += digit * pow(base, power);
        power++;
        binaryNumber /= 10;
    }

    return decimalNumber;
}

void d2Maze::decimalToBinary(int decimalNumber, vector<int>& binary_vec) {
    stack<int> binaryDigits;

    if(decimalNumber == 0)
        binaryDigits.push(0);

    while (decimalNumber > 0) {
        binaryDigits.push(decimalNumber % 2);
        decimalNumber /= 2;
    }

    while (!binaryDigits.empty()) {
        binary_vec.push_back(binaryDigits.top());
        binaryDigits.pop();
    }
}

d2Maze::d2Maze(int size) : m_dim(size), maze(size, vector<Cell>(size)){

    int i = rand() % size;
    int j = rand() % size;
    start.set_col(i);
    start.set_row(0);
    player.set_col(i);
    player.set_row(0);
    end.set_col(j);
    end.set_row(size-1);

    m_size = GetData().size();
};


    void d2Maze::move_up(){

    if( player.get_row() <= m_size && player.get_row() > 0 && !maze[player.get_row()][player.get_col()].topWall ){
        player.set_row(player.get_row()-1);
        cout << "THAT'S A WALL\n";
    }

}

    void d2Maze::move_down(){

    if(player.get_row() < m_size && player.get_row() >= 0 && !(maze[player.get_row()][player.get_col()].bottomWall) ){
        player.set_row(player.get_row()+1);
        return;
    }
        cout << "THAT'S A WALL\n";

}
    void d2Maze::move_left(){

    if(player.get_col() <= m_size && player.get_col() > 0 && !maze[player.get_row()][player.get_col()].leftWall ){
        player.set_col(player.get_col()-1);
        return;
    }
        cout << "THAT'S A WALL\n";
}

    void d2Maze::move_right(){

    if(player.get_col() < m_size && player.get_col() >= 0 && !maze[player.get_row()][player.get_col()].rightWall ){
        player.set_col(player.get_col()+1);
        return;
    }
        cout << "THAT'S A WALL\n";
}

vector<string> d2Maze::getPossibleMoves() {

    vector<string> dirList;
    int count = 0;
    if (!maze[player.get_row()][player.get_col()].rightWall)
        dirList.push_back("right");
    if (!maze[player.get_row()][player.get_col()].leftWall)
        dirList.push_back("left");
    if (!maze[player.get_row()][player.get_col()].topWall)
        dirList.push_back("top");
    if (!maze[player.get_row()][player.get_col()].bottomWall)
        dirList.push_back("bottom");

    return dirList;
}