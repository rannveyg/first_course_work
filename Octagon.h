#pragma once
#include <iostream>
#include "Figure.h"

class Octagon : public Figure {
protected:
	int Radius;
public:
	Octagon(int x = 0, int y = 0, int R = 0, COLORREF c = RGB(0, 0, 0));
	void draw() override;
	void hide() override;
};
