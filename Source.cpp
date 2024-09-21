#include "Personaje.h"
#include "conio.h"
#include "Funciones.h"
#include "Tiempo.h"
#include "Juego.h"



int main() {
	srand(time(NULL));
	Console::SetWindowSize(120, 40);
	Console::CursorVisible = false;
	

	char tecla;
	while (1) {
		Console::Clear();
		int op = menu();

		if (op == 1) {
			system("cls");
			cargando();
			cuadro();
			iniciarJuego();
			
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
