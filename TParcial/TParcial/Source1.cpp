
#include "iostream"
#include "windows.h"
#include "conio.h"
#include "Menu.h"
#define ANCHOVENTANA 120
#define LARGOVENTANA 40
using namespace System;
using namespace std;

int menu(); // Declaración de la función que devuelve la opción del menú

int main()
{
    Console::SetWindowSize(ANCHOVENTANA, LARGOVENTANA);
    int opcion;
    bool continuar = true;

    while (continuar)
    {
        opcion = menu(); // Asignar el valor devuelto por la función `menu()`

        switch (opcion) {
        case 1:
            system("cls");
            Cargando();
            Cuadro();
            // Aquí irían las acciones para la opción 1
            break;
        case 2:
            creditos();
            
            break;
        case 3:
            Instrucciones();
            break;
        case 4:
            Salir();
            continuar = false; // Terminar el bucle
            break;
        default:
            Console::SetCursorPosition(50, 25);
            cout << "Opcion invalida, intenta de nuevo.";
            _getch(); // Espera una tecla para continuar
            break;
        }
    }
    return 0;
}
