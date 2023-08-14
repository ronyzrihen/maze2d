#pragma once
#include "Searchable.h"
#include "d2Maze.h"

class d2MazeSearchable : public Searchable<string>
{
public:
    d2MazeSearchable(d2Maze& maze) : d_maze(&maze) {}

public:
	virtual State<string>* getStartState()
	{
        string s = d_maze->getStartPosition().get_position();
		State<string>* s1 = new State<string>(s);
		return s1;
	}

	virtual State<string>* getGoalState()
	{
        string s = d_maze->getGoalPsition().get_position();
		State<string>* s1 = new State<string>(s);
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

