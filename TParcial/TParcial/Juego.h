#pragma once
#include "Personaje.h"
#include "ListaEnemigo.h"
#include "ListaRecursos.h"

class Juego : public Personaje, public ListaEnemigo, public ListaRecursos {
public:
	Juego(int x, int y);

	void quitarAgua();
	void quitarSemilla();
	void quitarResiduo();

};

Juego::Juego(int x, int y) : Personaje(x, y), ListaEnemigo(), ListaRecursos() {

}

void Juego::quitarAgua() {
	for (int i = 0; i < arregloAgua.size(); i++) {
		int aguaX = arregloAgua.at(i)->getX();
		int aguaY = arregloAgua.at(i)->getY();
		
		int personajeX = getPX();
		int personajeY = getPY();

		if ((personajeX >= aguaX - 4 && personajeX <= aguaX + 4) && (personajeY >= aguaY - 4 && personajeY <= aguaY + 4)) {
			arregloAgua.at(i)->borrar();
			arregloAgua.erase(arregloAgua.begin() + i);
		}
	}
}
void Juego::quitarSemilla() {
	for (int i = 0; i < arregloSemilla.size(); i++) {
		int SemillaX = arregloSemilla.at(i)->getX();
		int SemillaY = arregloSemilla.at(i)->getY();


		int personajeX = getPX();
		int personajeY = getPY();

		if ((personajeX >= SemillaX - 4 && personajeX <= SemillaX + 4) && (personajeY >= SemillaY - 4 && personajeY <= SemillaY + 4)) {
			arregloSemilla.at(i)->borrar();
			arregloSemilla.erase(arregloSemilla.begin() + i);
		}

	}
}
void Juego::quitarResiduo() {
	for (int i = 0; i < arregloResiduo.size(); i++) {
		int ResiduoX = arregloResiduo.at(i)->getX();
		int ResiduoY = arregloResiduo.at(i)->getY();

		int personajeX = getPX();
		int personajeY = getPY();

		if ((personajeX >= ResiduoX - 4 && personajeX <= ResiduoX + 4) && (personajeY >= ResiduoY - 4 && personajeY <= ResiduoY + 4)) {
			arregloResiduo.at(i)->borrar();
			arregloResiduo.erase(arregloResiduo.begin() + i);
		}
	}
}
