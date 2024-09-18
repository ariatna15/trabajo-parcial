#pragma once
#include "Agua.h"
#include "Semilla.h"
#include "Residuo.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace System;

class ListaRecursos {
protected:
	vector<Agua*>arregloAgua;
	vector<Semilla*>arregloSemilla;
	vector<Residuo*>arregloResiduo;
public:
	ListaRecursos();

	void agregarAgua(Agua* nuevo);
	void agregarSemilla(Semilla* nuevo);
	void agregarResiduo(Residuo* nuevo);

	Agua* obtenerAgua(int indice);
	Semilla* obtenerSemilla(int indice);
	Residuo* obtenerResiduo(int indice);

	int tamAgua();
	int tamSemilla();
	int tamResiduo();

	vector<Agua*> retornarAgua();
	vector<Semilla*> retornarSemilla();
	vector<Residuo*> retornarResiduo();
};

ListaRecursos::ListaRecursos() {
	arregloAgua = vector<Agua*>();
	arregloSemilla = vector<Semilla*>();
	arregloResiduo = vector<Residuo*>();
}

void ListaRecursos::agregarAgua(Agua* nuevo) {
	arregloAgua.push_back(nuevo);
}
void ListaRecursos::agregarSemilla(Semilla* nuevo) {
	arregloSemilla.push_back(nuevo);
}
void ListaRecursos::agregarResiduo(Residuo* nuevo) {
	arregloResiduo.push_back(nuevo);
}

Agua* ListaRecursos::obtenerAgua(int indice) {
	return arregloAgua.at(indice);
}
Semilla* ListaRecursos::obtenerSemilla(int indice) {
	return arregloSemilla.at(indice);
}
Residuo* ListaRecursos::obtenerResiduo(int indice) {
	return arregloResiduo.at(indice);
}

int ListaRecursos::tamAgua() {
	return arregloAgua.size();
}
int ListaRecursos::tamSemilla() {
	return arregloSemilla.size();
}
int ListaRecursos::tamResiduo() {
	return arregloResiduo.size();
}

vector<Agua*> ListaRecursos::retornarAgua() {
	return arregloAgua;
}
vector<Semilla*> ListaRecursos::retornarSemilla() {
	return arregloSemilla;
}
vector<Residuo*> ListaRecursos::retornarResiduo() {
	return arregloResiduo;
}




