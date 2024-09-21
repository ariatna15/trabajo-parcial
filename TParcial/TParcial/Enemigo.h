#pragma once
#include <iostream>
using namespace std;
using namespace System;

class Enemigo {
protected:
	int x, y;
	int dx, dy;
public:
	Enemigo(int _x, int _y,int _dx, int _dy);
	~Enemigo();

	int getX();
	int getY();

	void setX(int valor);
	void setY(int valor);

	void borrar();
	void mover();
	void dibujar();
};

Enemigo::Enemigo(int _x, int _y, int _dx, int _dy) {
	this->x = _x;
	this->y = _y;
	this->dx = _dx;
	this->dy = _dy;
}

Enemigo::~Enemigo() {}

int Enemigo::getX() {
	return this->x;
}
int Enemigo::getY() {
	return this->y;
}

void Enemigo::setX(int valor) {
	this->x = valor;
}
void Enemigo::setY(int valor) {
	this->y = valor;
}

void Enemigo::borrar() {
	Console::SetCursorPosition(x, y); cout << " ";
}
void Enemigo::mover() {
	if (x < 3 || x + 1 >118) dx *= -1;
	if (y < 7 || y + 1 >35) dy *= -1;

	x = x + dx;
	y = y + dy;
}
void Enemigo::dibujar() {
	Console::ForegroundColor = ConsoleColor::Red;
	Console::SetCursorPosition(x, y); cout << "X";
	Console::ForegroundColor = ConsoleColor::White; 
}
