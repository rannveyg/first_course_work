#include "FigStack.h"

void FigStack::push(Figure* fig) {
	fs.push(fig);
}

Figure* FigStack::top(){
	return fs.top();
}

void FigStack::del() {
	while (!fs.empty()) {
		fs.pop();
	}
}

bool FigStack::empty() {
	return fs.empty();
}


FigStack::~FigStack() {
	while (!fs.empty()) {
		fs.pop();
	}
}