#pragma once
#include <iostream>
using namespace System;
using namespace std;
class Personaje {
private:
    int px, py;
    int pdx, pdy;
    int ancho, alto;
    int vidas;  // Atributo para almacenar las vidas del personaje
public:
    Personaje();
    Personaje(int _px, int _py);
    ~Personaje();
    void borrarP();
    void mover(char tecla);
    void dibujar();
    int getPX();
    int getPY();
    int getVidas();      // Método para obtener el número de vidas
    void mostrarVidas(int vidas);
    void reducirVida();   // Método para reducir una vida
    bool estaVivo();      // Verificar si el personaje tiene vidas restantes
};
// Constructor por defecto
Personaje::Personaje() {
    this->px = 0;
    this->py = 0;
    this->pdx = 0;
    this->pdy = 0;
    this->ancho = Console::WindowWidth;
    this->alto = Console::WindowHeight;
    this->vidas = 3;  // Inicializar con 3 vidas
}
// Constructor con parámetros
Personaje::Personaje(int _px, int _py) {
    this->px = _px;
    this->py = _py;
    this->pdx = 0;
    this->pdy = 0;
    this->ancho = 0;
    this->alto = 0;
    this->vidas = 3;  // Inicializar con 3 vidas
}
// Destructor
Personaje::~Personaje() {}
// Borrar personaje de la pantalla
void Personaje::borrarP() {
    Console::SetCursorPosition(px, py); cout << "     ";
}
// Mover personaje según la tecla ingresada
void Personaje::mover(char tecla) {
    if (tecla == 'W' && py > 5) {
        py--;
    }
    if (tecla == 'S' && py < 37) {
        py++;
    }
    if (tecla == 'D' && px < 116) {
        px++;
    }
    if (tecla == 'A' && px > 2) {
        px--;
    }
}
// Dibujar personaje en pantalla
void Personaje::dibujar() {
    Console::SetCursorPosition(px, py); cout << "@";

}
// Obtener posición X
int Personaje::getPX() {
    return this->px;
}
// Obtener posición Y
int Personaje::getPY() {
    return this->py;
}
// Obtener el número de vidas
int Personaje::getVidas() {
    return this->vidas;
}
void Personaje::mostrarVidas(int vidas) {
    Console::SetCursorPosition(110, 2);
    cout << "VIDAS: " << vidas << " ";
}
// Reducir una vida
void Personaje::reducirVida() {
    if (vidas > 0) {
        vidas--;
    }
}
// Verificar si el personaje tiene vidas restantes
bool Personaje::estaVivo() {
    return vidas > 0;
}