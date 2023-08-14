#pragma once
#include "Searchable.h"
#include "d2Maze.h"

class d2MazeSearchable : public Searchable<pos>
{
public:
    d2MazeSearchable(d2Maze& maze) : d_maze(&maze) {}

public:
	virtual State<pos>* getStartState()
	{
		pos s = d_maze->getStartPosition();
		State<pos>* s1 = new State<pos>(s);
		return s1;
	}

	virtual State<pos>* getGoalState()
	{
		pos s = d_maze->getGoalPsition();
		State<pos>* s1 = new State<pos>(s);
		return s1;
	}

	virtual std::vector<State<string>*>* getAllPossibleStates(State<string>& s) 
	{
		std::vector<string> moves = d_maze->getPossibleMoves();
		std::vector<State<string>*>* smoves = new std::vector<State<string>*>();
		for(auto it = moves.begin(); it != moves.end(); ++it)
		{
			smoves->push_back(new State<string>(*it));
		}

		return smoves;

	};
private:
	d2Maze* d_maze;
};

