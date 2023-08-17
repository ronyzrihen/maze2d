#pragma once

#include "CommonSearcher.h"

template <class T>
class BFS : public CommonSearcher<T>
{

public:
	virtual Solution<T> search(const Searchable<T>& s) 
	{
		/*TODO search code*/ 
		cout << "\nSOLVING USING BFS ALGORITHM!!!\n";
		
		return Solution<T>(); 
	};
};



//template <class T>
//class BFS : public CommonSearcher <T> {
//public:
//    Solution<T> search(const Searchable<T>& s) override {
//        State<T> initialState;
//        initialState.state = s.getStartPosition();
//        m_openList.push(initialState);
//
//        while (!m_openList.empty()) {
//            State<T> currentState = m_openList.top();
//            m_openList.pop();
//            m_evaluatedNodes++;
//
//            if (currentState.state == s.getGoalPosition()) {
//                // Reconstruct the path
//                Solution<T> solution;
//                solution.path.push_back(currentState);
//
//                while (currentState.cameFrom) {
//                    currentState = *currentState.cameFrom;
//                    solution.path.push_back(currentState);
//                }
//
//                reverse(solution.path.begin(), solution.path.end());
//                return solution;
//            }
//
//            vector<T> possibleMoves = s.getPossibleMoves(currentState.state);
//            for (T nextState : possibleMoves) {
//                if (!isInOpenList(nextState) && !isInClosedList(nextState)) {
//                    State<T> nextStateState;
//                    nextStateState.state = nextState;
//                    nextStateState.cameFrom = make_shared<State<T>>(currentState);
//                    m_openList.push(nextStateState);
//                }
//            }
//        }
//
//        // No solution found
//        Solution<T> noSolution;
//        return noSolution;
//    }
//
//private:
//    bool isInOpenList(const T& state) {
//        priority_queue<State<T>> openListCopy = m_openList;
//        while (!openListCopy.empty()) {
//            if (openListCopy.top().state == state)
//                return true;
//            openListCopy.pop();
//        }
//        return false;
//    }
//
//    bool isInClosedList(const T& state) {
//        // Implement as needed
//        return false;
//    }
//
//
//};