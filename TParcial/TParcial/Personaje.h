#pragma once
#include <iostream>
using namespace System;
using namespace std;

class Personaje {
private:
	int px, py;
	int pdx, pdy;
	int ancho, alto;
	
public:
	Personaje();
	Personaje(int _px, int _py);
	~Personaje();
	void borrarP();
	void mover(char tecla);
	void dibujar();

	int getPX();
	int getPY();
};
Personaje::Personaje() {
	this->px = 0;
	this->py = 0;
	this->pdx = 0;
	this->pdy = 0;
	this->ancho = Console::WindowWidth;
	this->alto = Console::WindowHeight;
}

Personaje::Personaje(int _px, int _py) {
	this->px = _px;
	this->py = _py;
	this->pdx = 0;
	this->pdy = 0;
	this->ancho = 0;
	this->alto = 0;
}
Personaje::~Personaje() {}

void Personaje::borrarP() {
	Console::SetCursorPosition(px, py); cout << "     ";
}

void Personaje::mover(char tecla) {
	if (tecla == 'W' && py > 5) {
		py--;
	}
	if (tecla == 'S' && py < 37) {
		py++;
	}
	if (tecla == 'D' && px < 116) {
		px++;
	}
	if (tecla == 'A' && px > 2) {
		px--;
	}
}

void Personaje::dibujar() {
	Console::SetCursorPosition(px, py); cout << "@";
}

int Personaje::getPX() {
	return this->px;
}

int Personaje::getPY() {
	return this->py;
}
