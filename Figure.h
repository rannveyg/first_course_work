#pragma once
#include <iostream>
#include <windows.h>
#include <windowsx.h>
#include <string>

using namespace std;


class Figure {
public:
	Figure();
	virtual ~Figure() = 0;
	virtual void draw() = 0;
	virtual void hide() = 0;
	virtual void moveTo(int newX, int newY);
	class Border {
	public:
		string causer;
		string location;
		int coord;
		const string error = "Произошёл выход за границы окна. Виновник ошибки: ";
		Border(string a, string border, int c) {
			causer = a;
			location = border;
			coord = c;
		}
	};
protected:
	HWND hwnd;
	HDC hdc;
	RECT rt;
	COLORREF color;
public:
	int cx, cy;
};

