#pragma once



class pos
{
public:
	pos(){};
	~pos(){};
	void set_col(int Col){col = Col;};
	void set_row(int Row){row = Row;};
	int get_col(){return col;};
	int get_row(){return row;};

private:
	int row;
	int col;
};

