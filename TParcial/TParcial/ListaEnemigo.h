#pragma once
#include "Enemigo.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace System;

class ListaEnemigo {
protected:
	vector<Enemigo*>arregloEnemigo;
public:
	ListaEnemigo();

	void agregarEnemigo(Enemigo* nuevo);

	Enemigo* obtenerEnemigo(int indice);

	int tamEnemigo();

	vector<Enemigo*> retornar();
};

ListaEnemigo::ListaEnemigo() {
	arregloEnemigo = vector<Enemigo*>();
}

void ListaEnemigo::agregarEnemigo(Enemigo* nuevo) {
	arregloEnemigo.push_back(nuevo);
}

Enemigo* ListaEnemigo::obtenerEnemigo(int indice) {
	return arregloEnemigo.at(indice);
}

int ListaEnemigo::tamEnemigo() {
	return arregloEnemigo.size();
}

vector<Enemigo*> ListaEnemigo::retornar() {
	return arregloEnemigo;
}
