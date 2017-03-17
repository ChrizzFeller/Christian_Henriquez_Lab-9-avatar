#include "earthbenders.h"
#include <typeinfo>

using namespace std;

earthbenders::earthbenders() {
}

earthbenders::earthbenders(string pNombre, double pHP, double pDefensa, double pOfensa, int pnivelDS) : Bender(pNombre, pHP, pDefensa, pOfensa, pnivelDS) {
	debilidad = 0.25;
}

double earthbenders::getDebilidad() {
	return debilidad;
}

double earthbenders::ataqueR(double pOfensa1, double pDefensa2, double pHP2) {
	pOfensa1 = pOfensa1 - pDefensa2;
	if (pOfensa1 > 0)
	{
		pHP2 = pHP2 - pOfensa1;
		return pHP2;
	} else {
		return pHP2;
	}
}

double earthbenders::ataqueE(Bender* p1, Bender* p2) {
	double atk1 = p1 -> getOfensa();
	double def2 = p2 -> getDefensa();
	double hp2 = p2 -> getHP();
	if (typeid(*p2)==typeid(airbenders))
	{
		atk1 = atk1 * (p2 -> getDebilidad());
		atk1 = atk1 - def2;
		if (atk1 > 0)
		{
			hp2 = hp2 - atk1;
			return hp2;
		} else {
			return hp2;
		}
	} else {
		atk1 = atk1 - def2;
		if (atk1 > 0)
		{
			hp2 = hp2 - atk1;
			return hp2;
		} else {
			return hp2;
		}
	}
}

void espiar(Bender* p2) {
	string nombreT = p2 -> getNombre();
	cout << "Estos son los stats de: " << nombreT << endl;
	cout << "HP: " << (p2 -> getHP()) << endl;
	cout << "Ofensa: " << (p2 -> getOfensa()) << endl;
	cout << "Defensa: " << (p2 -> getDefensa()) << endl;
}