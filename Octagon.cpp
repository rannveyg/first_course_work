
#include "Octagon.h"
# define M_PI           3.14159265358979323846 

Octagon::Octagon(int x, int y, int R, COLORREF c) {
	cx = x;
	cy = y;
	Radius = R;
	color = c;
}

void Octagon::draw() {
	const int N = 8;
	POINT points[N];
	double angle = 0;
	for (int i = 0; i < N; i++) {
		int x = cx + Radius * cos(angle * M_PI / 180);
		int y = cy + Radius * sin(angle * M_PI / 180);
		angle = angle + 360.0 / N;
		points[i] = { x, y };
	}
	const string name = "Octagon::draw()";
	if ((cx - Radius) <= rt.left) {
		throw Border(name, "Координата X выходит за пределы левой границы окна; X = ", cx);
	}
	if ((cx + Radius) >= rt.right) {
		throw Border(name, "Координата X выходит за пределы правой границы окна; X = ", cx);
	}
	if ((cy - Radius) <= rt.top) {
		throw Border(name, "Координата Y выходит за пределы верхней границы окна; Y = ", cy);
	}
	if ((cy + Radius) >= rt.bottom) {
		throw Border(name, "Координата Y выходит за пределы нижней границы окна; Y = ", cy);
	}
	HPEN    pen;
	HBRUSH  brush;
	pen = CreatePen(PS_SOLID, 2, RGB(0, 128, 0)); //тёмно-зелёное
	brush = CreateSolidBrush(color);
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Polygon(hdc, points, N);
	DeleteObject(pen);
	DeleteObject(brush);
}

void Octagon::hide() {
	const int N = 8;
	POINT points[N];
	double angle = 0;
	for (int i = 0; i < N; i++) {
		int x = cx + Radius * cos(angle * M_PI / 180);
		int y = cy + Radius * sin(angle * M_PI / 180);
		angle = angle + 360.0 / N;
		points[i] = { x, y };
	}
	HPEN    pen;
	HBRUSH  brush;
	pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));  //белое
	brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Polygon(hdc, points, N);
	DeleteObject(pen);
	DeleteObject(brush);
}

