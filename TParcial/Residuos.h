#pragma once
#include <iostream>
#include "Recursos.h"
using namespace std;
using namespace System;

class Residuos : public Movimiento {
public:
	Residuos(double _x, double _y, double _dx, double _dy);
	~Residuos();

	void borrar();
	void dibujar();
};

Residuos::Residuos(double _x, double _y, double _dx, double _dy) : Movimiento(_x, _y, _dx, _dy) {

}

Residuos::~Residuos() {}

void Residuos::borrar() {
	Console::SetCursorPosition(x, y); cout << " ";
}

void Residuos::dibujar() {
	Console::SetCursorPosition(x, y); cout << "#";
}
