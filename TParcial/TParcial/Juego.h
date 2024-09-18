#pragma once
#include "Personaje.h"
#include "ListaEnemigo.h"
#include "ListaRecursos.h"

class Juego : public Personaje, public ListaEnemigo, public ListaRecursos {
public:
	Juego(double x, double y);

	void quitarAgua();
	void quitarSemilla();
	void quitarResiduo();
};

Juego::Juego(double x, double y) : Personaje(x, y), ListaEnemigo(), ListaRecursos() {

}

void Juego::quitarAgua() {
	for (int i = 0; i < arregloAgua.size(); i++) {
		double aguaX = arregloAgua.at(i)->getX();
		double aguaY = arregloAgua.at(i)->getY();

		if()
	}
}
void Juego::quitarSemilla() {

}
void Juego::quitarResiduo() {

}

