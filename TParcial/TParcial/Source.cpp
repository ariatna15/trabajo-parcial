#include <iostream>
#include "Juego.h"
#include "Personaje.h"
#include "conio.h"
using namespace std;
using namespace System;

int generarAleatorio(int max, int min) {
	return min + rand() % (max - min + 1);
}


int main() {
	Console::SetWindowSize(180, 40);
	Console::CursorVisible = false;
	Personaje* Objpersonaje;
	Objpersonaje = new Personaje();

	int aguaTotal = generarAleatorio(4,9);
	int semillaTotal = generarAleatorio(4,9);
	int residuoTotal = generarAleatorio(4,9);

	char tecla;
	while (1) {
		if (_kbhit()) {
			tecla = toupper(_getch());
			Objpersonaje->borrar();
			Objpersonaje->direccion(tecla);
			Objpersonaje->mover();
			Objpersonaje->dibujar();
		}
		_sleep(100);

	}
	system("pause>0");
	return 0;
}
