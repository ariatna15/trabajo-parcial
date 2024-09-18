#pragma once
#include <iostream>
using namespace std;
using namespace System;

class Enemigo {
protected:
	double x, y;
	double dx, dy;
public:
	Enemigo(double _x, double _y);
	~Enemigo();

	double getX();
	double getY();

	void setX(double valor);
	void setY(double valor);

	void borrar();
	void mover(char direccion);
	void dibujar();
};

Enemigo::Enemigo(double _x, double _y) {
	this->x = _x;
	this->y = _y;
	this->dx = 0;
	this->dy = 0;
}

Enemigo::~Enemigo() {}

double Enemigo::getX() {
	return this->x;
}
double Enemigo::getY() {
	return this->y;
}

void Enemigo::setX(double valor) {
	this->x = valor;
}
void Enemigo::setY(double valor) {
	this->y = valor;
}

void Enemigo::borrar() {
	Console::SetCursorPosition(x, y); cout << " ";
}
void Enemigo::mover(char direccion) {
	if (direccion == 0) {
		if (y - 1 != 0) {
			y--;
		}
	}
	if (direccion == 1) {
		if (y + 1 != 39) {
			y++;
		}
	}
	if (direccion == 2) {
		if (x + 1 != 79) {
			x++;
		}
	}
	if (direccion == 3) {
		if (x - 1 != 0) {
			x--;
		}
	}
}
void Enemigo::dibujar() {
	Console::SetCursorPosition(x, y); cout << "X";
}
