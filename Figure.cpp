
#include <iostream>
#include <conio.h>
#include "Figure.h"
using namespace std;

Figure::Figure() {
	hwnd = 0;
	if ((hwnd = GetConsoleWindow()) == 0) {
		cout << "Window not found\n";
		return;
	}
	if ((hdc = GetDC(hwnd)) == 0) {
		cout << "Error\n";
		return;
	}
	GetClientRect(hwnd, &rt);
}

Figure::~Figure() {
	ReleaseDC(hwnd, hdc);
}

void Figure::moveTo(int newX, int newY) {
	hide();
	cx = newX;
	cy = newY;
	draw();
}
