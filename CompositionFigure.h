
#pragma once
#include <iostream>
#include "Figure.h"
#include "Octagon.h"
#include "Circle.h"

class CompositionFigure {
private:
	Octagon* oct;
	Circle* circ;
public:
	CompositionFigure(int x, int y, int R, COLORREF c);
	void draw();
	void hide();
	void moveTo(int newX, int newY);
};

