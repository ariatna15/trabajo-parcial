#pragma once
#include<iostream>
using namespace std;
using namespace System;

class Personaje {
protected:
	double x, y;
	double dx, dy;
public:
	Personaje(double _x, double _y);
	~Personaje();
	
	double getX();
	double getY();

	void borrar();
	void mover(char tecla);
	void dibujar();
};

Personaje::Personaje(double _x, double _y) {
	this->x = _x;
	this->y = _y;
	this->dx = 0;
	this->dy = 0;
}

Personaje::~Personaje() {};

double Personaje::getX() {
	return x;
}

double Personaje::getY() {
	return y;
}

void Personaje::borrar() {
	Console::SetCursorPosition(x, y); cout << " ";
}

void Personaje::mover(char tecla) {
	if (tecla == 'w') {
		if (y + 1 != 0) {
			y--;
		}
	}
	if (tecla == 's') {
		if (y + 1 != 39) {
			y++;
		}
	}
	if (tecla == 'd') {
		if (x + 1 != 79) {
			x++;
		}
	}
	if (tecla == 'a') {
		if (x - 1 != 0) {
			x--;
		}
	}
}

void Personaje::dibujar() {
	Console::SetCursorPosition(x, y); cout << "@";
}
