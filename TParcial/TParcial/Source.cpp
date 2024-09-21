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
	int enemigoTotal = generarAleatorio(4, 8);

	Juego* aguaAgarra = new Juego(1, 5);
	Juego* semillaAgarra = new Juego(1, 2);
	Juego* residuoAgarra = new Juego(1, 7);
	Juego* enemigoCaza = new Juego(1, 6);


	int xMax = 118; //del borde max del cuadro: x - 2
	int yMax = 36;  //del borde max del cuadro: y - 2  empezarán a generarse dentro de ese rango
	int xMin = 2;   //del borde min del cuadro: x + 2
	int yMin = 5;   //del borde min del cuadro: y + 2


	for (int i = 0; i < aguaTotal; i++) {
		Agua* nuevoAgua = new Agua(generarAleatorio(xMax, xMin), generarAleatorio(yMax, yMin));
		aguaAgarra->agregarAgua(nuevoAgua);
	}

	for (int i = 0; i < semillaTotal; i++) {
		Semilla* nuevaSemilla = new Semilla(generarAleatorio(xMax, xMin), generarAleatorio(yMax, yMin));
		semillaAgarra->agregarSemilla(nuevaSemilla);
	}

	for (int i = 0; i < residuoTotal; i++) {
		Residuo* nuevoResiduo = new Residuo(generarAleatorio(xMax, xMin), generarAleatorio(yMax, yMin));
		residuoAgarra->agregarResiduo(nuevoResiduo);
	}
	for (int i = 0; i < enemigoTotal; i++) {
		Enemigo* nuevoEnemigo = new Enemigo(generarAleatorio(xMax, xMin), generarAleatorio(yMax, yMin), 1, 1);
		enemigoCaza->agregarEnemigo(nuevoEnemigo);
	}

	char tecla;
	while (1) {
		Console::Clear();
		int op = menu();

		if (op == 1) {
			system("cls");
			cargando();
			cuadro();
			bool jugando = true;
			while (jugando) {
				if (_kbhit()) {
					tecla = toupper(_getch());
					Objpersonaje->borrarP();
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

				if (enemigoCaza->tamEnemigo() > 0) {
					for (int i = 0; i < enemigoCaza->tamEnemigo(); i++) {
						Enemigo* nuevoEnemigo = enemigoCaza->obtenerEnemigo(i);
						nuevoEnemigo->borrar();
						nuevoEnemigo->mover();
						nuevoEnemigo->dibujar();
					}
				}

				// Verifica si el personaje ha recogido algún recurso
				aguaAgarra->quitarAgua();
				semillaAgarra->quitarSemilla();
				residuoAgarra->quitarResiduo();
				enemigoCaza->quitarPersonaje();
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
		else {

		}

		system("pause>0");
	}
	return 0;
}