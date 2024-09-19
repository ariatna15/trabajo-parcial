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
	Personaje(int _px, int _py, int _pdx, int _pdy, int pancho, int palto);
	~Personaje();
	void borrar();
	void mover();
	void dibujar();
	void direccion(char tecla);
};
Personaje::Personaje() {
	this->px = 90;
	this->py = 38;
	this->pdx = 0;
	this->pdy = 0;
	this->ancho = Console::WindowWidth;
	this->alto = Console::WindowHeight;
}

Personaje::Personaje(int _px, int _py, int _pdx, int _pdy, int pancho, int palto) {
	this->px = _px;
	this->py = _py;
	this->pdx = _pdx;
	this->pdy = _pdy;
	this->ancho = pancho;
	this->alto = palto;
}
Personaje::~Personaje() {}

void Personaje::borrar() {
	Console::SetCursorPosition(px, py); cout << "     ";
}

void Personaje::mover() {
	if (px < 0) px = 0;
	if (px >= ancho) px = ancho - 1;
	if (py < 0) py = 0;
	if (py >= alto) py = alto - 1;
	px += pdx;
	py += pdy;
}

void Personaje::dibujar() {
	Console::SetCursorPosition(px, py); cout << "@";
}

void Personaje::direccion(char tecla) {
	if (tecla == 'W') { //arriba
		pdy = -1, pdx = 0; //para q vaya recto en una sola direccion
	}
	else if (tecla == 'S') { //abajo
		pdy = 1, pdx = 0;
	}
	else if (tecla == 'D') { //derecha
		pdx = 2, pdy = 0;
	}
	else if (tecla == 'A') { //izquierda
		pdx = -2, pdy = 0;
	}
}
