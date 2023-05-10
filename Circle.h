#pragma once
#include <iostream>
#include "Figure.h"

class Circle : public Figure {
private:
	int radius;
public:
	Circle(int x = 0, int y = 0, int r = 0, COLORREF c = RGB(0, 0, 0));
	void draw() override;
	void hide() override;
};
