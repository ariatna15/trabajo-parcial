#include "Personaje.h"
#include "conio.h"

int main() {
	Console::SetWindowSize(180, 40);
	Console::CursorVisible = false;
	Personaje* Objpersonaje;
	Objpersonaje = new Personaje();

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
	return 0;
}