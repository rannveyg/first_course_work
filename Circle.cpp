#include "Circle.h"
#include "FigStack.h"

Circle::Circle(int x, int y, int r, COLORREF c) {
	cx = x;
	cy = y;
	radius = r;
	color = c;
}

void Circle::draw() {
	HPEN pen;
	HBRUSH brush;
	const string name = "Circle::draw()";
		if ((cx - radius) <= rt.left) {
		throw Border (name, "Координата X выходит за пределы левой границы окна; X = ", cx);
	}
	if ((cx + radius) >= rt.right) {
		throw Border (name, "Координата X выходит за пределы правой границы окна; X = ", cx);
	}
	if ((cy - radius) <= rt.top) {
		throw Border (name, "Координата Y выходит за пределы верхней границы окна; Y = ", cy);
	}
	if ((cy + radius) >= rt.bottom) {
		throw Border(name, "Координата Y выходит за пределы нижней границы окна; Y = ", cy);
	}
	pen = CreatePen(PS_SOLID, 2, RGB(0, 128, 0)); //тёмно-зелёное
	brush = CreateSolidBrush(color);
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Ellipse(hdc, cx - radius, cy - radius, cx + radius, cy + radius);
	DeleteObject(pen);
	DeleteObject(brush);
}

void Circle::hide() {
	HPEN pen;
	HBRUSH brush;
	pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); //белое
	brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Ellipse(hdc, cx - radius, cy - radius, cx + radius, cy + radius);
	DeleteObject(pen);
	DeleteObject(brush);
}
