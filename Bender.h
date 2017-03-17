#include <string>

#ifndef BENDER_H
#define BENDER_H

using namespace std;

class Bender {

	protected:
		string nombre;
		double HP;
		double defensa;
		double ofensa;
		int nivelDS;

	public:
		Bender();
		Bender(string, double, double, double, int);

		//Setters
		void setNombre(string);
		void setHP(double);
		void setDefensa(double);
		void setOfensa(double);
		void setNivelDS(double);

		//Getters
		string getNombre();
		double getHP();
		double getDefensa();
		double getOfensa();
		int getNivelDS();

		//Metodos de ataque
		virtual double ataqueR(double, double, double) = 0;
		virtual double ataqueE(Bender*, Bender*) = 0;
};

#endif