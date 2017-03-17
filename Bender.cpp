#include "Bender.h"

using namespace std;

Bender::Bender() {
}

Bender::Bender(string pNombre, double pHP, double pDefensa, double pOfensa, int pnivelDS) {
	nombre = pNombre;
	HP = pHP;
	defensa = pDefensa;
	ofensa = pOfensa;
	nivelDS = pnivelDS;
}

void Bender::setNombre(string pNombre) {
	nombre = pNombre;
}

void Bender::setHP(double pHP) {
	HP = pHP;
}

void Bender::setDefensa(double pDefensa) {
	defensa = pDefensa;
}

void Bender::setOfensa(double pOfensa) {
	ofensa = pOfensa;
}

void Bender::setNivelDS(int pnivelDS) {
	nivelDS = pnivelDS;
}

string Bender::getNombre() {
	return nombre;
}

double Bender::getHP() {
	return HP;
}

double Bender::getDefensa() {
	return defensa;
}

double Bender::getOfensa() {
	return ofensa;
}

int Bender::getNivelDS() {
	return nivelDS;
}