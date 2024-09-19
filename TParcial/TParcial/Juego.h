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
		int aguaX = arregloAgua.at(i)->getX();
		int aguaY = arregloAgua.at(i)->getY();

		if ((px == aguaX || px == aguaX + 1 == px == aguaX - 1 || px == aguaX + 2 || px == aguaX - 2 || px == aguaX + 3 == px == aguaX - 3 || px == aguaX + 4 || px == aguaX - 4) == true &&
			(py == aguaY || py == aguaY + 1 == py == aguaY - 1 || py == aguaY + 2 || py == aguaY - 2 || py == aguaY + 3 || py == aguaY - 3 || py == aguaY + 4 || py == aguaY - 4) == true) {
			arregloAgua.at(i)->borrar();
			arregloAgua.erase(arregloAgua.begin() + i);
		}
	}
}
void Juego::quitarSemilla() {
	for (int i = 0; i < arregloSemilla.size(); i++) {
		int SemillaX = arregloSemilla.at(i)->getX();
		int SemillaY = arregloSemilla.at(i)->getY();

		if ((px == SemillaX || px == SemillaX + 1 || px == SemillaX - 1 || px == SemillaX + 2 || px == SemillaX - 2 || px == SemillaX + 3 ||px == SemillaX - 3 || px == SemillaX + 4 || px == SemillaX - 4) == true &&
			(py == SemillaY || py == SemillaY + 1 || py == SemillaY - 1 ||py == SemillaY + 2 || py == SemillaY - 2 || py == SemillaY + 3 ||py == SemillaY - 3 || py == SemillaY + 4 || py == SemillaY - 4) == true) {
			arregloSemilla.at(i)->borrar();
			arregloSemilla.erase(arregloSemilla.begin() + i);
		}
	}
}
void Juego::quitarResiduo() {
	for (int i = 0; i < arregloResiduo.size(); i++) {
		int ResiduoX = arregloResiduo.at(i)->getX();
		int ResiduoY = arregloResiduo.at(i)->getY();

		if ((px == ResiduoX || px == ResiduoX + 1 || px == ResiduoX - 1 || px == ResiduoX + 2 || px == ResiduoX - 2 || px == ResiduoX + 3 ||px == ResiduoX - 3 || px == ResiduoX + 4 || px == ResiduoX - 4) == true &&
			(py == ResiduoY || py == ResiduoY + 1 || py == ResiduoY - 1 || py == ResiduoY + 2 || py == ResiduoY - 2 || py == ResiduoY + 3 ||py == ResiduoY - 3 || py == ResiduoY + 4 || py == ResiduoY - 4) == true) {
			arregloResiduo.at(i)->borrar();
			arregloResiduo.erase(arregloResiduo.begin() + i);
		}
	}
}
