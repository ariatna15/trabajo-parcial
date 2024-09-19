#include "pch.h"
#include "Personaje.h"
#include "Funciones.h"
#include "Juego.h"
#include "conio.h"

int generarAleatorio(int max, int min) {
	return min + rand() % (max - min + 1);
}

int main() {

	srand(time(NULL));
	Console::SetWindowSize(120, 40);
	Console::CursorVisible = false;
	Personaje* Objpersonaje;
	Objpersonaje = new Personaje(60, 37);

	int aguaTotal = generarAleatorio(4,8);
	int semillaTotal = generarAleatorio(4,8);
	int residuoTotal = generarAleatorio(4,8);

	Juego* aguaAgarra = new Juego(1,5);
	Juego* semillaAgarra = new Juego(1, 2);
	Juego* residuoAgarra = new Juego(1, 7);

	for (int i = 0; i < aguaTotal; i++) {
		Agua* nuevoAgua = new Agua(generarAleatorio(5,110), generarAleatorio(5,30));
		aguaAgarra->agregarAgua(nuevoAgua);
	}

	for (int i = 0; i < semillaTotal; i++) {
		Semilla* nuevaSemilla = new Semilla(generarAleatorio(5,100), generarAleatorio(5,30));
		semillaAgarra->agregarSemilla(nuevaSemilla);
	}

	for (int i = 0; i < residuoTotal; i++) {
		Residuo* nuevoResiduo = new Residuo(generarAleatorio(5, 100), generarAleatorio(5, 30));
		residuoAgarra->agregarResiduo(nuevoResiduo);
	}


	char tecla;
	while (1) {
		Console::Clear();
		int op = menu();

		if (op == 1) {
			Console::Clear();
			cargando();
			cuadro();
			bool jugando = true;
			while (jugando) {
				if (_kbhit()) { //aqui debe ir funcion de juego
					tecla = toupper(_getch());
					Objpersonaje->borrar();
					Objpersonaje->mover(tecla);
					Objpersonaje->dibujar();
				}
				_sleep(100);
			}
			aguaAgarra->quitarAgua();
			semillaAgarra->quitarSemilla();
			residuoAgarra->quitarResiduo();


		}
		else if (op == 2) {
			creditos();

		}
		else if (op == 3) {
			instrucciones();

		}
		else if (op == 4) {
			salir();
		}
		else {

		}
		_sleep(100);



	}
	system("pause>0");
	return 0;
}

