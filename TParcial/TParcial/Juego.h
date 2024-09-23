#pragma once
#include "Personaje.h"
#include "ListaEnemigo.h"
#include "ListaRecursos.h"
class Juego : public Personaje, public ListaEnemigo, public ListaRecursos {
public:
	Juego(int x, int y);
	void quitarAgua(Personaje* personaje);
	void quitarSemilla(Personaje* personaje);
	void quitarResiduo(Personaje* personaje);
	bool quitarPersonaje(Personaje* personaje);
};
Juego::Juego(int x, int y) : Personaje(x, y), ListaEnemigo(), ListaRecursos() {
}
void Juego::quitarAgua(Personaje* personaje) {
	for (int i = 0; i < arregloAgua.size(); i++) {
		Agua* agua = arregloAgua[i];
		if (agua->getX() == personaje->getPX() && agua->getY() == personaje->getPY()) {
			delete agua;
			arregloAgua.erase(arregloAgua.begin() + i);
			i--;
		}
	}
}
void Juego::quitarSemilla(Personaje* personaje) {
	for (int i = 0; i < arregloSemilla.size(); i++) {
		Semilla* semilla = arregloSemilla[i];
		if (semilla->getX() == personaje->getPX() && semilla->getY() == personaje->getPY()) {
			delete semilla;
			arregloSemilla.erase(arregloSemilla.begin() + i);
			i--;
		}
	}
}
void Juego::quitarResiduo(Personaje* personaje) {
	for (int i = 0; i < arregloResiduo.size(); i++) {
		Residuo* residuo = arregloResiduo[i];
		if (residuo->getX() == personaje->getPX() && residuo->getY() == personaje->getPY()) {
			delete residuo;
			arregloResiduo.erase(arregloResiduo.begin() + i);
			i--;
		}
	}
}
bool Juego::quitarPersonaje(Personaje* personaje) {
	for (int i = 0; i < arregloEnemigo.size(); i++) {
		int EnemigoX = arregloEnemigo.at(i)->getX();
		int EnemigoY = arregloEnemigo.at(i)->getY();
		int personajeX = personaje->getPX();
		int personajeY = personaje->getPY();
		// Verificar colisión
		if ((personajeX >= EnemigoX -1 && personajeX <= EnemigoX +1) &&
			(personajeY >= EnemigoY -1 && personajeY <= EnemigoY +1)) {
			if (personaje->estaVivo()) {
				personaje->reducirVida();  // Reducir una vida
				personaje->mostrarVidas(personaje->getVidas());  // Mostrar vidas restantes
			}
			return true;  // Se detectó una colisión
		}
	}
	return false;  // No hubo colisión
}