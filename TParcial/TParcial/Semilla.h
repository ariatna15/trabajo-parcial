#pragma once
#include <iostream>
using namespace std;
using namespace System;

class Semilla {
protected:
	int x, y;
public:
	Semilla(int _x, int _y);
	~Semilla();

	int getX();
	int getY();

	void borrar();
	void dibujar();
};

Semilla::Semilla(int _x, int _y) {
	this->x = _x;
	this->y = _y;
}
Semilla::~Semilla() {}

int Semilla::getX() {
	return this->x;
}
int Semilla::getY() {
	return this->y;
}

void Semilla::borrar() {
	Console::SetCursorPosition(x, y); cout << " ";
}
void Semilla::dibujar() {
	Console::SetCursorPosition(x, y); cout << "*";
}
