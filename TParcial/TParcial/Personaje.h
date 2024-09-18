#pragma once
#include <iostream>
using namespace System;
using namespace std;

class Personaje {
private:
	int x, y;
	int dx, dy;
	int ancho, alto;
public:
	Personaje();
	Personaje(int px, int py, int pdx, int pdy, int pancho, int palto);
	~Personaje();
	void borrar();
	void mover();
	void dibujar();
	void direccion(char tecla);
};
Personaje::Personaje() {
	this->x = 90;
	this->y = 38;
	this->dx = 0;
	this->dy = 0;
	this->ancho = Console::WindowWidth;
	this->alto = Console::WindowHeight;
}

Personaje::Personaje(int px, int py, int pdx, int pdy, int pancho, int palto) {
	this->x = px;
	this->y = py;
	this->dx = pdx;
	this->dy = pdy;
	this->ancho = pancho;
	this->alto = palto;
}
Personaje::~Personaje() {}

void Personaje::borrar() {
	Console::SetCursorPosition(x, y); cout << "     ";
}

void Personaje::mover() {
	if (x < 0) x = 0;
	if (x >= ancho) x = ancho - 1;
	if (y < 0) y = 0;
	if (y >= alto) y = alto - 1;
	x += dx;
	y += dy;
}

void Personaje::dibujar() {
	Console::SetCursorPosition(x, y); cout << "@";
}

void Personaje::direccion(char tecla) {
	if (tecla == 'W') { //arriba
		dy = -1, dx = 0; //para q vaya recto en una sola direccion
	}
	else if (tecla == 'S') { //abajo
		dy = 1, dx = 0;
	}
	else if (tecla == 'D') { //derecha
		dx = 2, dy = 0;
	}
	else if (tecla == 'A') { //izquierda
		dx = -2, dy = 0;
	}
}
