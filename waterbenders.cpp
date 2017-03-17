#include "waterbenders.h"
#include "earthbenders.h"
#include <typeinfo>

using namespace std;

waterbenders::waterbenders() {
}

waterbenders::waterbenders(string pNombre, double pHP, double pDefensa, double pOfensa, int pnivelDS) : Bender(pNombre, pHP, pDefensa, pOfensa, pnivelDS) {
	debilidad = 0.25;
}

double waterbenders::getDebilidad() {
	return debilidad;
}

double waterbenders::ataqueR(double pOfensa1, double pDefensa2, double pHP2) {
	pOfensa1 = pOfensa1 - pDefensa2;
	if (pOfensa1 > 0)
	{
		pHP2 = pHP2 - pOfensa1;
		return pHP2;
	} else {
		return pHP2;
	}
}

double waterbenders::ataqueE(Bender* p1, Bender* p2) {
	double atk1 = p1 -> getOfensa();
	double def2 = p2 -> getDefensa();
	double hp2 = p2 -> getHP();
	if (typeid(*p2)==typeid(earthbenders))
	{
		atk1 = atk1 * (dynamic_cast<earthbenders*>(p2) -> getDebilidad());
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

double waterbenders::heal(double atk2, double hp1) {
	if (atk2 >= 110)
	{
		hp1 = hp1 + 75;
	} else {
		cout << "La ofensa del bender no es suficiente!" << endl;
		return hp1;
	}
}