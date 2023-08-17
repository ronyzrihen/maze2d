#pragma once
#include "Searcher.h"
#include <queue>

template <class T>
class CommonSearcher : public Searcher<T>
{
public:
	CommonSearcher(): m_evaluatedNodes(0){}

//Abstraction
public:
	virtual Solution<T> search(const Searchable<T>& s) = 0;
	virtual int getNumberOfNodesEvaluated() { return m_evaluatedNodes; };
	virtual void checkEfficiency(const Searchable<T>& s)
	{
		//Open Timer

		search(s);

		//Close Timer

		//Print time
	}

//Additional implementation
public:
	const State<T>& popOpenList() { m_evaluatedNodes++; return m_openList.top(); }

protected:
	int m_evaluatedNodes;
	std::priority_queue<State<T>> m_openList;
};

