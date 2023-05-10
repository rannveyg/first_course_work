#include "CompositionFigure.h"

CompositionFigure::CompositionFigure(int x, int y, int R, COLORREF c) {
	int r = R * cos(180 / 8) + R * 0.07;
	oct = new Octagon(x, y, R, c);
	circ = new Circle(x, y, r, c);
}

void CompositionFigure::draw() {
	oct->draw();
	circ->draw();
}

void CompositionFigure::hide() {
	oct->hide();
	circ->hide();
}

void CompositionFigure::moveTo(int newX, int newY) {
	this->hide();
	Octagon& newOct = *oct;
	newOct.cx = newX;
	newOct.cy = newY;
	Circle& newCirc = *circ;
	newCirc.cx = newX;
	newCirc.cy = newY;
	this->draw();
}