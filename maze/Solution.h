#pragma once
#include <iostream>
#include <vector>
#include "State.h"

template <class T>
class Solution
{
public:
	Solution() {};
	~Solution() {};

private:
	std::vector<unique_ptr<State<T>>> m_solution;
};

