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
