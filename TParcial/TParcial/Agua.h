#pragma once
#include <iostream>
using namespace std;
using namespace System;

class Agua {
protected:
	int x, y;
public:
	Agua(int _x, int _y);
	~Agua();

	int getX();
	int getY();

	void borrar();
	void dibujar();
};

Agua::Agua(int _x, int _y) {
	this->x = _x;
	this->y = _y;
}
Agua::~Agua() {}

int Agua::getX() {
	return this->x;
}
int Agua::getY() {
	return this->y;
}

void Agua::borrar() {
	Console::SetCursorPosition(x, y); cout << " ";
}
void Agua::dibujar() {
	Console::SetCursorPosition(x, y); cout << "~";
}
