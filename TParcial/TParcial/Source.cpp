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
	Personaje* Objpersonaje = new Personaje(60, 37);

	int aguaTotal = generarAleatorio(4, 8);
	int semillaTotal = generarAleatorio(4, 8);
	int residuoTotal = generarAleatorio(4, 8);

	Juego* aguaAgarra = new Juego(1, 5);
	Juego* semillaAgarra = new Juego(1, 2);
	Juego* residuoAgarra = new Juego(1, 7);

	for (int i = 0; i < aguaTotal; i++) {
		Agua* nuevoAgua = new Agua(generarAleatorio(5, 43), generarAleatorio(5, 30));
		aguaAgarra->agregarAgua(nuevoAgua);
	}

	for (int i = 0; i < semillaTotal; i++) {
		Semilla* nuevaSemilla = new Semilla(generarAleatorio(5, 40), generarAleatorio(5, 50));
		semillaAgarra->agregarSemilla(nuevaSemilla);
	}

	for (int i = 0; i < residuoTotal; i++) {
		Residuo* nuevoResiduo = new Residuo(generarAleatorio(5, 20), generarAleatorio(5, 30));
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
				if (_kbhit()) {
					tecla = toupper(_getch());
					Objpersonaje->borrar();
					Objpersonaje->mover(tecla);
					Objpersonaje->dibujar();
				}
				_sleep(100);

				// Dibuja los recursos
				if (aguaAgarra->tamAgua() > 0) {
					for (int i = 0; i < aguaAgarra->tamAgua(); i++) {
						Agua* nuevaAgua = aguaAgarra->obtenerAgua(i);
						nuevaAgua->borrar();
						nuevaAgua->dibujar();
					}
				}

				if (semillaAgarra->tamSemilla() > 0) {
					for (int i = 0; i < semillaAgarra->tamSemilla(); i++) {
						Semilla* nuevaSemilla = semillaAgarra->obtenerSemilla(i);
						nuevaSemilla->borrar();
						nuevaSemilla->dibujar();
					}
				}

				if (residuoAgarra->tamResiduo() > 0) {
					for (int i = 0; i < residuoAgarra->tamResiduo(); i++) {
						Residuo* nuevoResiduo = residuoAgarra->obtenerResiduo(i);
						nuevoResiduo->borrar();
						nuevoResiduo->dibujar();
					}
				}

				// Verifica si el personaje ha recogido algún recurso
				aguaAgarra->quitarAgua();
				semillaAgarra->quitarSemilla();
				residuoAgarra->quitarResiduo();
			}
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
		_sleep(100);
	}

	system("pause>0");
	return 0;
}
