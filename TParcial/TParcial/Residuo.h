#pragma once
#include <iostream>
using namespace std;
using namespace System;

class Residuo {
protected:
	int x, y;
public:
	Residuo(int _x, int _y);
	~Residuo();

	int getX();
	int getY();

	void borrar();
	void dibujar();
};

Residuo::Residuo(int _x, int _y) {
	this->x = _x;
	this->y = _y;
}
Residuo::~Residuo() {}

int Residuo::getX() {
	return this->x;
}
int Residuo::getY() {
	return this->y;
}

void Residuo::borrar() {
	Console::SetCursorPosition(x, y); cout << " ";
}
void Residuo::dibujar() {
	Console::SetCursorPosition(x, y); cout << "#";
}
