#pragma once
#include <iostream>
#include "Figure.h"
#include <stack>
#include <list>
using namespace std;

class FigStack {
private:
	stack <Figure*, list<Figure* > > fs;
public:
	FigStack() {}
	void push(Figure* fig);
	Figure* top();
	void del();
	bool empty();
	~FigStack();
};
