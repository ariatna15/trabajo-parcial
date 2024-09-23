#pragma once
#include <iostream>
#include <chrono>
#include "Funciones.h"
#include "Personaje.h"
#include "Juego.h"
#include <thread>
int generarAleatorio(int max, int min) {
    return min + rand() % (max - min + 1);
}
void iniciarJuego() {
    // Inicializar personaje
    Personaje* Objpersonaje = new Personaje(60, 37);
    Objpersonaje->mostrarVidas(Objpersonaje->getVidas());
    int aguaTotal = generarAleatorio(4, 8);
    int semillaTotal = generarAleatorio(4, 8);
    int residuoTotal = generarAleatorio(4, 8);
    int enemigoTotal = generarAleatorio(4, 10);
    // Crear objetos Juego para diferentes tipos de recursos y enemigos
    Juego* aguaAgarra = new Juego(1, 5);
    Juego* semillaAgarra = new Juego(1, 2);
    Juego* residuoAgarra = new Juego(1, 7);
    Juego* enemigoCaza = new Juego(1, 6);
    // Definir rangos para generar posiciones aleatorias de los recursos
    int xMax = 118;
    int yMax = 36;
    int xMin = 2;
    int yMin = 6;
    // Generar recursos de agua, semillas, residuos y enemigos
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
    // Iniciar el juego
    bool jugando = true;
    auto start = chrono::high_resolution_clock::now();  // Inicio del tiempo
    int tiempoLimite = 60;  // Límite de tiempo en segundos
    while (jugando) {
        // Si se detecta entrada del teclado, mover al personaje
        if (_kbhit()) {
            char tecla = toupper(_getch());
            Objpersonaje->borrarP();
            Objpersonaje->mover(tecla);
            Objpersonaje->dibujar();
        }
        
        _sleep(30);
        // Dibujar los recursos
        for (int i = 0; i < aguaAgarra->tamAgua(); i++) {
            Agua* nuevaAgua = aguaAgarra->obtenerAgua(i);
            nuevaAgua->borrar();
            nuevaAgua->dibujar();
        }
        for (int i = 0; i < semillaAgarra->tamSemilla(); i++) {
            Semilla* nuevaSemilla = semillaAgarra->obtenerSemilla(i);
            nuevaSemilla->borrar();
            nuevaSemilla->dibujar();
        }
        for (int i = 0; i < residuoAgarra->tamResiduo(); i++) {
            Residuo* nuevoResiduo = residuoAgarra->obtenerResiduo(i);
            nuevoResiduo->borrar();
            nuevoResiduo->dibujar();
        }
        for (int i = 0; i < enemigoCaza->tamEnemigo(); i++) {
            Enemigo* nuevoEnemigo = enemigoCaza->obtenerEnemigo(i);
            nuevoEnemigo->borrar();
            nuevoEnemigo->mover();
            nuevoEnemigo->dibujar();
        }
        
        aguaAgarra->quitarAgua(Objpersonaje);
        semillaAgarra->quitarSemilla(Objpersonaje);
        residuoAgarra->quitarResiduo(Objpersonaje);

        if (enemigoCaza->quitarPersonaje(Objpersonaje)) {}
        if (!Objpersonaje->estaVivo()) {
            game_over(); 
            jugando = false;
        }

        // Controlar el tiempo límite
        auto now = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = now - start;
        int tiempoRestante = tiempoLimite - static_cast<int>(elapsed.count());

        // Mostrar tiempo restante
        Console::SetCursorPosition(0, 2);
        cout << "TIEMPO RESTANTE: " << tiempoRestante << " SEGUNDOS" << endl;
        // Verificar si el tiempo ha terminado

        if (elapsed.count() >= tiempoLimite) {
            system("cls");
            game_over();  
            jugando = false;
        }
       
        int recursosRecoleccionados = aguaTotal - aguaAgarra->tamAgua() + semillaTotal - semillaAgarra->tamSemilla() + residuoTotal - residuoAgarra->tamResiduo();
        if (recursosRecoleccionados >= 0.7 * (aguaTotal + semillaTotal + residuoTotal)) {
            you_win();
            jugando = false;
        }
        // Simular un pequeño retraso para que el juego no consuma demasiados recursos
        
    }
}