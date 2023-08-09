#pragma once



class pos
{
public:
	pos(){};
	~pos(){};
	void set_col(int col){};
	void set_row(int row){};
	int get_col(){};
	int get_row(){};

private:
	int row;
	int col;
};

