#pragma once
#include <iostream>
using namespace std;


class pos
{
public:
	pos(){};
	~pos(){};
	void set_col(int Col){col = Col;};
	void set_row(int Row){row = Row;};
	int get_col(){return col;};
	int get_row(){return row;};
    void print(ostream& out) { out << row<<","<<col; };

private:
	int row;
	int col;
};

ostream& operator<<(ostream& out, pos& source);
