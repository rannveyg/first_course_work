#include <iostream>
#include "Octagon.h"
#include "Circle.h"
#include "CompositionFigure.h"
#include "FigStack.h"
const int NotUsed = system("color F0");

int main() {
	setlocale(LC_ALL, "Ru");
	SetConsoleTitle((LPWSTR)L"21VP2_9_Figures");
	Figure* circ = new Circle (100, 200, 30, RGB(255, 0, 0));
	Figure* oct = new Octagon (478, 128, 67, RGB(255, 0, 0));
	CompositionFigure fig(300, 400, 50, RGB(255, 0, 0));
	FigStack fs;
	fs.push(circ);
	fs.push(oct);
	try {
		circ->draw();
		fs.top()->draw();
		fig.draw();
		Sleep(3000);
		circ->moveTo(160, 90);
		fs.top()->moveTo(120, 350);
		fig.moveTo(410, 220);
	}
	catch (Figure::Border border) {
		cout << border.error << border.causer << "\n" << border.location << border.coord << "\n";
	}
	Sleep(7000);
	return 0;
}

